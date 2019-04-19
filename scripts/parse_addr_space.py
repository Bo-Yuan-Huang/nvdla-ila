#!/usr/bin/python3

import argparse

def Convert(in_file, out_file, prefix):
    if prefix != None:
        with open(out_file, 'w') as fw:
            fw.write('// ============================================================================\n')
            fw.write('// Instruction-Level Abstraction of Nvidia Deep Learning Accelerator (NVDLA)\n')
            fw.write('//\n')
            fw.write('// This ILA description is derived based on the NVDLA specification and design,\n')
            fw.write('// which is licensed under "NVIDIA Open NVDLA License and Agreement v1.0".\n')
            fw.write('// Check "LICENSE" which comes with this distribution for more information.\n')
            fw.write('// ============================================================================\n')
            fw.write('\n')
            fw.write('// File Name: addr_{0}.h\n'.format(prefix.lower()))
            fw.write('\n')
            fw.write('#ifndef NVDLA_ADDR_{0}_H__\n'.format(prefix.upper()))
            fw.write('#define NVDLA_ADDR_{0}_H__\n'.format(prefix.upper()))
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
                    fw.write('// {0}\n'.format(desp));
                    fw.write('#define {0} {1}\n'.format(name, addr));
                    #fw.write('#define {0} {1} // {2}\n'.format(name, addr, desp));

    if prefix != None:
        with open(out_file, 'a') as fw:
            fw.write('\n')
            fw.write('}; // namespace ilang\n\n')
            fw.write('#endif // NVDLA_ADDR_{0}_H__\n'.format(prefix.upper()))

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description="Convert NVDLA addr. space to C macro")
    parser.add_argument('input', type=str, help='input file')
    parser.add_argument('output', type=str, help='output file')
    parser.add_argument('--prefix', dest='prefix', type=str, help='prefix')
    args = parser.parse_args()

    Convert(args.input, args.output, args.prefix);
