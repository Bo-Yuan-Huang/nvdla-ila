#!/usr/bin/python3

import argparse
import os
import parse_nvdla_spec as nvdla

def GenStateInit(spec, out_file, unit, append):
    if append:
        mode = 'a'
    else:
        mode = 'w'

    with open(out_file, mode) as fw:
        # header
        file_name_comment = nvdla.FormatSourceFileComment('state_init', unit)
        fw.write(file_name_comment)
        fw.write('\n')

        fw.write('#include <ilang/ilang++.h>\n')
        fw.write('#include <nvdla/configs/state_info.h>\n')
        fw.write('#include <nvdla/utils.h>\n')
        fw.write('\n')

        namespace_begin = nvdla.NameSpaceHead()
        for l in namespace_begin:
            fw.write(l)

        # body
        fw.write('// FIXME this is auto-generated placeholder\n\n')
        fw.write('void StateInit{0} (Ila& m) {{\n'.format(unit.title()))

        var_pairs = nvdla.ParseNvDlaSpec(spec)
        for var in var_pairs:
            # comment
            fw.write('// {0}\n'.format(var['desp']))
            # create state var
            fw.write('m.AddInit(m.state({0}_{1}) == 0);\n'.format(unit.upper(), \
                                                                  var['name'].upper()))
            # line break
            fw.write('\n')

        fw.write('return;\n')
        fw.write('}\n')

        # tail
        namespace_end = nvdla.NameSpaceTail()
        for l in namespace_end:
            fw.write(l)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Generate state variable initial condition')
    parser.add_argument('unit', type=str, help='sub-unit name (e.g. "cdma")')
    parser.add_argument('spec', type=str, help='input spec file (e.g. "spec_cdma.txt")')
    parser.add_argument('odst', type=str, help='output file')
    parser.add_argument('--append', dest='append', type=bool, help='append to file')
    args = parser.parse_args()

    GenStateInit(args.spec, args.odst, args.unit, args.append)
