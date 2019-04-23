#!/usr/bin/python3

import argparse
import parse_nvdla_spec as nvdla

def GenAddrSpace(in_file, out_file, prefix, append):
    if append:
        mode = 'a'
    else:
        mode = 'w'

    with open(out_file, mode) as fw:
        # header 
        header = nvdla.GenHeader('addr', 'NVDLA_ADDR', prefix)
        for l in header:
            fw.write(l)

        # body
        var_pairs = nvdla.ParseNvDlaSpec(in_file)
        for var in var_pairs:
            # comments
            fw.write('// {0}\n'.format(var['desp']))
            # define address space
            fw.write('#define {0}_{1}_ADDR {2}\n'.format(prefix.upper(), \
                                                         var['name'].upper(), \
                                                         var['addr']))

        # tail
        tail = nvdla.GenTail('NVDLA_ADDR', prefix)
        for l in tail:
            fw.write(l)

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Generate address space macro")
    parser.add_argument('input', type=str, help='input file')
    parser.add_argument('output', type=str, help='output file')
    parser.add_argument('prefix', type=str, help='prefix')
    parser.add_argument('--append', dest='append', type=bool, help='append the file')
    args = parser.parse_args()

    GenAddrSpace(args.input, args.output, args.prefix, args.append);
