#!/usr/bin/python

from enum import Enum

class SpecState(Enum):
    NAME = 1
    ADDR = 2
    DESP = 3

def ParseNvDlaSpec(in_file):
    state = SpecState.NAME
    result = []

    with open(in_file, 'r') as fr:
        for line in fr:
            if state is SpecState.NAME:
                name = line.strip('\n')
                state = SpecState.ADDR

            elif state is SpecState.ADDR:
                addr = line.strip('\n')
                state = SpecState.DESP

                try:
                    val = int(addr, 16)
                except:
                    print('Fail handling address value', addr)

            else:
                desp = line.strip('\n')
                state = SpecState.NAME
        
                pair = {}
                pair['name'] = name
                pair['addr'] = addr
                pair['desp'] = desp
                result.append(pair)

    return result

def GenHeader(file_pre, guard_pre, tag):

    file_name = '{0}_{1}.h'.format(file_pre.lower(), tag.lower())
    guard_name = '{0}_{1}_H__'.format(guard_pre.upper(), tag.upper())

    lines = []
    lines.append('\n')
    lines.append('// File Name: {0}\n'.format(file_name))
    lines.append('\n')
    lines.append('#ifndef {0}\n'.format(guard_name))
    lines.append('#define {0}\n'.format(guard_name))
    lines.append('\n')
    lines.append('/// \\namespace ilang\n')
    lines.append('namespace ilang {\n\n')
    lines.append('\n')

    return lines

def GenTail(guard_pre, tag):
    guard_name = '{0}_{1}_H__'.format(guard_pre.upper(), tag.upper())

    lines = []
    lines.append('\n')
    lines.append('}; // namespace ilnag\n\n')
    lines.append('#endif // {0}\n'.format(guard_name))
    lines.append('\n')

    return lines

