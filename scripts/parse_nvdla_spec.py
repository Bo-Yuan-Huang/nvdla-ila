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
                except BaseException:
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


def IsPingPongReg(name):
    return (name[:2] == 'D_')


def RegGroupRaw(name, group_id):
    return '{0}_g{1}'.format(name, group_id)


def RegGroupMacro(name, group_id):
    return RegGroupRaw(name, group_id).upper()


def RegGroupStr(name, group_id):
    return RegGroupRaw(name, group_id).lower()


def RegNameMacro(unit, name):
    macro = '{0}_{1}'.format(unit, name)
    return macro.upper()


def FormatSpecFileName(file_prefix, tag):
    file_name = '{0}_{1}.txt'.format(file_prefix.lower(), tag.lower())
    return file_name


def FormatHeaderFileName(file_prefix, tag):
    file_name = '{0}_{1}.h'.format(file_prefix.lower(), tag.lower())
    return file_name


def FormatSourceFileName(file_prefix, tag):
    file_name = '{0}_{1}.cc'.format(file_prefix.lower(), tag.lower())
    return file_name


def FormatGuardTag(file_prefix, tag):
    guard_tag = '{0}_{1}_H__'.format(file_prefix.upper(), tag.upper())
    return guard_tag


def FormatHeaderFileComment(file_prefix, tag):
    file_name = FormatHeaderFileName(file_prefix, tag)
    comment = '// File Name: {0}\n'.format(file_name)
    return comment


def FormatSourceFileComment(file_prefix, tag):
    file_name = FormatSourceFileName(file_prefix, tag)
    comment = '// File Name: {0}\n'.format(file_name)
    return comment


def NameSpaceHead():
    lines = []
    lines.append('\n')
    lines.append('// namespace ilang\n')
    lines.append('namespace ilang {\n\n')
    lines.append('\n')
    return lines


def NameSpaceTail():
    lines = []
    lines.append('\n')
    lines.append('}; // namespace ilang\n\n')
    lines.append('\n')
    return lines


def GenHeaderHead(file_prefix, tag):
    lines = []

    header_file_comment = FormatHeaderFileComment(file_prefix, tag)
    lines.append(header_file_comment)
    lines.append('\n')

    guard_tag = FormatGuardTag(file_prefix, tag)
    lines.append('#ifndef {0}\n'.format(guard_tag))
    lines.append('#define {0}\n'.format(guard_tag))
    lines.append('\n')

    #namespace_begin = NameSpaceHead()
    #lines = lines + namespace_begin

    return lines


def GenHeaderTail(file_prefix, tag):
    lines = []

    #namespace_end = NameSpaceTail()
    #lines = lines + namespace_end

    guard_tag = FormatGuardTag(file_prefix, tag)
    lines.append('#endif // {0}\n'.format(guard_tag))
    lines.append('\n')

    return lines
