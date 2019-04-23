#!/usr/bin/python3

import argparse
import os
import parse_nvdla_spec as nvdla

def GenStateDefine(unit, spec, odir, append):
    if not os.path.exists(odir):
        os.mkdir(odir)

    file_prefix = 'state_define'
    out_file_name = nvdla.FormatSourceFileName(file_prefix, unit)
    out_file = os.path.join(odir, out_file_name)

    if append:
        mode = 'a'
    else:
        mode = 'w'

    with open(out_file, mode) as fw:
        # header
        file_name_comment = nvdla.FormatSourceFileComment(file_prefix, unit)
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
        fw.write('void StateDefine_{0} (Ila& m) {{\n'.format(unit.lower()))

        var_pairs = nvdla.ParseNvDlaSpec(spec)
        for var in var_pairs:
            # comment
            fw.write('// {0}\n'.format(var['desp']))
            # create state var
            fw.write('NewState(m, {0}_{1}, {0}_{1}_BWID);\n'.format(unit.upper(), \
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
    parser = argparse.ArgumentParser(description='Generate state variable define code')
    parser.add_argument('unit', type=str, help='sub-unit name (e.g. "cdma")')
    parser.add_argument('spec', type=str, help='input spec file (e.g. "spec_cdma.txt")')
    parser.add_argument('odir', type=str, help='output directory')
    parser.add_argument('--append', dest='append', type=bool, help='append to file')
    args = parser.parse_args()

    GenStateDefine(args.unit, args.spec, args.odir, args.append)
