from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import os
import sys
from glob import glob
import subprocess


def _cpp_compile(srcpath, outpath):
    cmd = ['g++', '-o', outpath] + sys.argv[2:] + [srcpath]
    print(' '.join(cmd))
    subprocess.call(cmd)
    return outpath


FILE_MAPPING = {'.cpp': _cpp_compile}


def main():
    if len(sys.argv) < 2:
        print('usage {} <filename> [compiler args excluding output]'.format(
            sys.argv[0]))
        return

    bin_dir = os.path.join('.', 'bin')
    if not os.path.isdir(bin_dir):
        os.mkdir(bin_dir)

    filename, ext = os.path.splitext(sys.argv[1])
    binary = os.path.join(bin_dir, filename)
    if os.name == 'nt':
        binary = binary + '.exe'

    if os.path.isfile(binary):
        os.remove(binary)

    if ext not in FILE_MAPPING:
        print('unknown file type', ext)

    compiler = FILE_MAPPING[ext]
    binary = compiler(sys.argv[1], binary)

    if not os.path.isfile(binary):
        return

    test_files = glob('test*.input')
    test_files.sort(key=os.path.getmtime)
    tests = [os.path.splitext(os.path.basename(f))[0] for f in test_files]
    line_length = 40
    print('=' * line_length)

    for test in tests:
        in_file = test + '.input'

        out_file = os.path.join(bin_dir, test + '.output')
        if os.path.isfile(out_file):
            os.remove(out_file)

        subprocess.run(
            '{} < {} > {}'.format(binary, in_file, out_file),
            shell=True,
            check=True)

        in_text = _read_txt(in_file)
        out_text = _read_txt(out_file).strip()
        if out_text is None:
            print(test, 'RUNTIME ERROR')
        else:
            gt_text = _read_txt(test + '.output').strip()
            status = 'FAILED'
            if gt_text is None:
                status = 'RUN'
            elif gt_text == out_text:
                status = 'PASSED'
            print(test, status)
            if status != 'PASSED':
                print('-' * line_length)
                print(in_text)
                if status != 'RUN':
                    print('-' * line_length)
                    print(gt_text)
                print('-' * line_length)
                print(out_text)
        print('=' * line_length)


def _read_txt(filepath):
    if not os.path.isfile(filepath):
        return None
    with open(filepath, 'r') as f:
        return f.read()


if __name__ == '__main__':
    main()
