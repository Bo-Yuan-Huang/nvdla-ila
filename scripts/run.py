#!/usr/bin/python3

import argparse
import distutils.spawn
import os
import os.path
import subprocess

import parse_nvdla_spec as nvdla
from gen_state_info import GenStateInfo
from gen_state_init import GenStateInit
from gen_state_define import GenStateDefine

FORMAT = ''

def EnsurePath(dir_path):
    if not os.path.exists(dir_path):
        os.path.mkdir(dir_path)

def AddLicenseHeader(dst_file):
    subprocess.run(['cp', 'data/license_header.h.in', dst_file])

def Format(target_file):
    subprocess.run([FORMAT, '-i', target_file])

def SpecFilePath(unit):
    spec_file_name = nvdla.FormatSpecFileName('spec', unit)
    spec_file_full = os.path.join(spec_dir, spec_file_name)
    return spec_file_full

def GenAllStateInfo(spec_dir, dst_dir, units):
    for unit in units:
        out_file_name = nvdla.FormatHeaderFileName('state_info', unit)
        out_file_full = os.path.join(dst_dir, out_file_name)

        AddLicenseHeader(out_file_full)

        spec_file = SpecFilePath(unit)

        GenStateInfo(spec_file, out_file_full, unit, True)

        Format(out_file_full)

    return

def GenAllStateDefine(spec_dir, dst_dir, unit):
    for unit in units:
        out_file_name = nvdla.FormatSourceFileName('state_define', unit)
        out_file_full = os.path.join(dst_dir, out_file_name)

        AddLicenseHeader(out_file_full)

        spec_file = SpecFilePath(unit)

        GenStateDefine(spec_file, out_file_full, unit, True)

        Format(out_file_full)

    return 

def GenAllStateInit(spec_dir, dst_dir, unit):
    for unit in units:
        out_file_name = nvdla.FormatSourceFileName('state_init', unit)
        out_file_full = os.path.join(dst_dir, out_file_name)

        AddLicenseHeader(out_file_full)

        spec_file = SpecFilePath(unit)

        GenStateInit(spec_file, out_file_full, unit, True)

        Format(out_file_full)

    return

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description='Scripts entry point')
    parser.add_argument('--all', action='store_true', help='run all options')
    parser.add_argument('--info', action='store_true', help='generate state info (macro)')
    parser.add_argument('--define', action='store_true', help='generate state definition')
    parser.add_argument('--init', action='store_true', help='generate state init constraints')
    parser.add_argument('--format', dest='format', type=str, default='', help='clang-format exec')
    args = parser.parse_args()

    spec_dir = 'data'
    src_dir = 'src'
    header_dir = 'include/nvdla'
    units = ['bdma', 'cacc', 'cdma', 'cdp', 'cdp_rdma', 'cmac_a', 'cmac_b', \
             'csc', 'glb', 'mcif', 'pdp', 'pdp_rdma', 'rubik', 'sdp', \
             'sdp_rdma', 'sramif']

    if (args.format is ''):
        FORMAT = distutils.spawn.find_executable('clang-format')
        if FORMAT is None:
            print('No formatter found')
    else:
        FORMAT = args.format

    if (args.info or args.all):
        dst_dir = os.path.join(header_dir, 'configs')
        EnsurePath(dst_dir)
        GenAllStateInfo(spec_dir, dst_dir, units)

    if (args.define or args.all):
        dst_dir = os.path.join(src_dir, 'state_define')
        EnsurePath(dst_dir)
        GenAllStateDefine(spec_dir, dst_dir, units)

    if (args.init or args.all):
        dst_dir = os.path.join(src_dir, 'state_init')
        EnsurePath(dst_dir)
        GenAllStateInit(spec_dir, dst_dir, units)
