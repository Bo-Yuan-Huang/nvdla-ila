#!/usr/bin/python3

import argparse

def Convert(in_file, out_file, prefix, append):
    if prefix != None:
        if append:
            mode = 'a'
        else:
            mode = 'w'
        with open(out_file, mode) as fw:
            fw.write('// File Name: state_info_{0}.h\n'.format(prefix.lower()))
            fw.write('\n')
            fw.write('#ifndef STATE_INFO_{0}_H__\n'.format(prefix.upper()))
            fw.write('#define STATE_INFO_{0}_H__\n'.format(prefix.upper()))
            fw.write('\n')
            fw.write('/// \\namespace ilang\n')
            fw.write('namespace ilang {\n\n')

    counter = 0;
    with open(in_file, 'r') as fr:
        with open(out_file, 'a') as fw:
            for line in fr:
                if counter == 0:
                    name = line.strip('\n')
                    if prefix != None:
                        name = '{0}_{1}'.format(prefix.upper(), name)
                    counter = 1;
                elif counter == 1:
                    addr = line.strip('\n')
                    counter = 2;
                else:
                    desp = line.strip('\n')
                    counter = 0;
                    fw.write('// {0}\n'.format(desp))
                    fw.write('#define {0}_NAME "{1}"\n'.format(name.upper(), name.lower()))
                    fw.write('\n')

    if prefix != None:
        with open(out_file, 'a') as fw:
            fw.write('\n')
            fw.write('}; // namespace ilang\n\n')
            fw.write('#endif // STATE_INFO_{0}_H__\n'.format(prefix.upper()))

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Convert NVDLA csb regs to C")
    parser.add_argument('input', type=str, help='input file')
    parser.add_argument('output', type=str, help='output file')
    parser.add_argument('--prefix', dest='prefix', type=str, help='prefix')
    parser.add_argument('--append', dest='append', type=bool, help='append')
    args = parser.parse_args()

    Convert(args.input, args.output, args.prefix, args.append);
