#!/bin/python3

import argparse
import os
import subprocess

from gen_state_define import GenStateDefine

def FormatFileName(dst_dir, prefix, unit, postfix):
    file_name = os.path.join(dst_dir, \
                             '{pre}_{unit}.{post}'.format(pre=prefix, \
                                                          unit=unit, \
                                                          post=postfix))
    return file_name
 
def RunGenStateDefine(spec_dir, dst_dir, unit):
    if not os.path.exists(dst_dir):
        os.mkdir(dst_dir)

    dst_file_name = FormatFileName(dst_dir, 'state_define', unit, 'cc')
    src_file_name = FormatFileName(spec_dir, 'spec', unit, 'txt')

    subprocess.run(['cp', 'data/license_header.h.in', dst_file_name])

    GenStateDefine(unit, src_file_name, dst_dir, True)

    subprocess.run(['clang-format', '-i', dst_file_name])
   
    return

if __name__ == '__main__':
    #parser = argparse.ArgumentParser(description='Entry point of running scripts')
    RunGenStateDefine('data', '.', 'cdma')
