from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import os
import sys
from glob import glob
from colorama import Fore, Style

from runners import runner_factory as rf

LINE_LENGTH = 40


def main():
    if len(sys.argv) != 3:
        print('usage {} <filename> <library-path>'.format(sys.argv[0]))
        return

    bin_dir = 'bin'
    runner = rf.factory.get(sys.argv[1], bin_dir, sys.argv[2])
    if not runner.compile():
        return

    test_files = glob('test*.input')
    test_files.sort(key=os.path.getmtime)
    tests = [os.path.splitext(os.path.basename(f))[0] for f in test_files]
    print('=' * LINE_LENGTH)

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
            status = None
            if gt_text is None:
                status = 'FAILED'
                print(f'{test} {Fore.YELLOW}RUN{Style.RESET_ALL}')
            elif gt_text == out_text:
                status = 'PASSED'
                print(f'{test} {Fore.GREEN}PASSED{Style.RESET_ALL}')
            else:
                status = 'FAILED'
                print(f'{test} {Fore.RED}FAILED{Style.RESET_ALL}')
            if status != 'PASSED':
                print('-' * LINE_LENGTH, '[input]')
                print(in_text)
                if gt_text is not None:
                    _compare(out_text, gt_text)
                else:
                    print('-' * LINE_LENGTH, '[output]')
                    print(f'{Fore.YELLOW}' + out_text + f'{Style.RESET_ALL}')
        print('=' * LINE_LENGTH)


def _compare(out_text, gt_text):
    out_text = out_text.split('\n')
    gt_text = gt_text.split('\n')
    if len(out_text) != len(gt_text):
        print('-' * LINE_LENGTH, '[output]')
        print(out_text)
        print('-' * LINE_LENGTH, '[answer]')
        print(gt_text)
    else:
        colors = [
            f'{Fore.GREEN}' if a == b else f'{Fore.RED}'
            for a, b in zip(out_text, gt_text)
        ]
        print('-' * LINE_LENGTH, '[output]')
        for color, text in zip(colors, out_text):
            print(color + text + f'{Style.RESET_ALL}')
        print('-' * LINE_LENGTH, '[answer]')
        for color, text in zip(colors, gt_text):
            print(color + text + f'{Style.RESET_ALL}')


def _read_txt(filepath):
    if not os.path.isfile(filepath):
        return None
    with open(filepath, 'r') as f:
        return '\n'.join([l.strip() for l in f])


if __name__ == '__main__':
    main()
