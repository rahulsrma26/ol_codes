from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import os
import sys
from glob import glob

from runners import runner_factory as rf


def main():
    if len(sys.argv) != 3:
        print('usage {} <filename> <library-path>'.format(
            sys.argv[0]))
        return

    bin_dir = 'bin'
    runner = rf.factory.get(sys.argv[1], bin_dir, sys.argv[2])
    if not runner.compile():
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

        runner.run(f'< {in_file} > {out_file}')

        in_text = _read_txt(in_file)
        out_text = _read_txt(out_file).strip()
        if out_text is None:
            print(test, 'RUNTIME ERROR')
        else:
            gt_text = _read_txt(test + '.output')
            status = 'FAILED'
            if gt_text is None:
                status = 'RUN'
            elif gt_text == out_text:
                status = 'PASSED'
            print(test, status)
            if status != 'PASSED':
                print('-' * line_length)
                print(in_text)
                print('-' * line_length)
                print(out_text)
                if status != 'RUN':
                    print('-' * line_length)
                    print(gt_text)
        print('=' * line_length)


def _read_txt(filepath):
    if not os.path.isfile(filepath):
        return None
    with open(filepath, 'r') as f:
        return '\n'.join([l.strip() for l in f])


if __name__ == '__main__':
    main()
