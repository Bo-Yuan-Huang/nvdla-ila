#!/usr/bin/python3

import argparse
import parse_nvdla_spec as nvdla

def GenStateInfo(in_file, out_file, prefix, append):
    if append:
        mode = 'a'
    else:
        mode = 'w'

    with open(out_file, mode) as fw:
        # header
        header = nvdla.GenHeader('state_info', 'STATE_INFO', prefix)
        for l in header:
            fw.write(l)

        # body
        var_pairs = nvdla.ParseNvDlaSpec(in_file)
        for var in var_pairs:
            # comment
            fw.write('// {0}\n'.format(var['desp']))
            # name
            fw.write('#define {0}_{1}_NAME "{2}_{3}"\n'.format(prefix.upper(), \
                                                               var['name'].upper(), \
                                                               prefix.lower(), \
                                                               var['name'].lower()))
            # bit width
            fw.write('#define {0}_{1}_BWID 32\n'.format(prefix.upper(), \
                                                           var['name'].upper()))

        # tail
        tail = nvdla.GenTail('STATE_INFO', prefix)
        for l in tail:
            fw.write(l)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Generate state info macro")
    parser.add_argument('input', type=str, help='input file')
    parser.add_argument('output', type=str, help='output file')
    parser.add_argument('prefix', type=str, help='prefix')
    parser.add_argument('--append', dest='append', type=bool, help='append')
    args = parser.parse_args()

    GenStateInfo(args.input, args.output, args.prefix, args.append);
