#!/usr/bin/python3

import argparse
import os
from string import Template
import parse_nvdla_spec as nvdla


def CsbWrInstrName(var_name):
    return 'CsbWr_{0}'.format(var_name.upper())


def GenPPSMHeader(spec, out_file, unit, append):
    if append:
        mode = 'a'
    else:
        mode = 'w'

    with open(out_file, mode) as fw:
        # header
        header = nvdla.GenHeaderHead('ppsm', unit)
        for l in header:
            fw.write(l)

        fw.write('\n')
        fw.write('#include <ilang/ilang++.h>\n')
        fw.write('\n')

        # start of namespace
        namespace_begin = nvdla.NameSpaceHead()
        for l in namespace_begin:
            fw.write(l)

        # body
        var_pairs = nvdla.ParseNvDlaSpec(spec)
        for var in var_pairs:
            # skip if not duplicated register groups
            if not nvdla.IsPingPongReg(var['name']):
                continue

            var_name_macro = nvdla.RegNameMacro(unit, var['name'])
            func_dec = 'void CsbWrPpsm_{0}(Ila& m);\n'.format(var_name_macro)
            fw.write(func_dec)

        # end of namespace
        namespace_end = nvdla.NameSpaceTail()
        for l in namespace_end:
            fw.write(l)

        # tail
        tail = nvdla.GenHeaderTail('ppsm', unit)
        for l in tail:
            fw.write(l)


def GenPPSM(spec, out_file, unit, append):
    with open('data/ping_pong_synch_mech.cc.in', 'r') as fr:
        template_raw = fr.read()
        template = Template(template_raw)

    if append:
        mode = 'a'
    else:
        mode = 'w'

    with open(out_file, mode) as fw:
        # header
        file_name_comment = nvdla.FormatSourceFileComment('ppsm', unit)
        fw.write(file_name_comment)
        fw.write('\n')

        fw.write('#include <ilang/ilang++.h>\n')
        fw.write('#include <nvdla/configs/modeling_config.h>\n')
        fw.write('#include <nvdla/configs/state_info.h>\n')
        fw.write('#include <nvdla/utils.h>\n')
        fw.write('\n')

        namespace_begin = nvdla.NameSpaceHead()
        for l in namespace_begin:
            fw.write(l)

        # body
        var_pairs = nvdla.ParseNvDlaSpec(spec)
        for var in var_pairs:
            # skip if not duplicated register groups
            if not nvdla.IsPingPongReg(var['name']):
                continue

            var_name_macro = nvdla.RegNameMacro(unit, var['name'])

            d = {}
            d['var_name_macro'] = var_name_macro
            d['instr_name'] = CsbWrInstrName(var_name_macro)
            d['mmio_addr'] = '{0}_ADDR'.format(var_name_macro)
            d['pointer'] = '{0}_S_POINTER'.format(unit.upper())
            d['status'] = '{0}_S_STATUS'.format(unit.upper())
            d['var_name_g0'] = nvdla.RegGroupMacro(var_name_macro, 0)
            d['var_name_g1'] = nvdla.RegGroupMacro(var_name_macro, 1)

            ppsm_i = template.safe_substitute(d)
            fw.write(ppsm_i)

        # tail
        namespace_end = nvdla.NameSpaceTail()
        for l in namespace_end:
            fw.write(l)


if __name__ == '__main__':
    parser = argparse.ArgumentParser(
        description='Generate ping-pong synch. mech. code')
    parser.add_argument('unit', type=str, help='sub-unit name (e.g. "cdma")')
    parser.add_argument('spec', type=str, help='input spec file')
    parser.add_argument('odst', type=str, help='output file')
    parser.add_argument('--append', action='store_true', help='append to file')
    args = parser.parse_args()

    GenPPSM(args.spec, args.odst, args.unit, args.append)
