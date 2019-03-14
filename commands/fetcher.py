import os
import sys
import shutil
from datetime import datetime

from fetchers import fetcher_factory as ff


def main():
    if len(sys.argv) != 3:
        print('usage {} <code-force-url> <language>'.format(sys.argv[0]))
        return

    url = sys.argv[1]
    site = ff.factory.get(url)
    dir_name = site.dirname()

    # create directory
    if os.path.isdir(dir_name):
        print(dir_name, 'already exist')
    else:
        print(dir_name, 'created')
        os.mkdir(dir_name)

    # create test(s)
    for idx, test in enumerate(site.tests(), 1):
        inp, out = test
        _create_file(os.path.join(dir_name, f'test_{idx}.input'), inp)
        _create_file(os.path.join(dir_name, f'test_{idx}.output'), out)
        print(f'test_{idx}')

    # copying the content of sample dir
    sample_dir = os.path.join(os.path.dirname(sys.argv[0]), 'sample', sys.argv[2])
    if not os.path.isdir(sample_dir):
        print(sample_dir, 'not found')
        return

    for filename in os.listdir(sample_dir):
        filepath = os.path.join(sample_dir, filename)
        if os.path.isfile(filepath) and filename[0] != '.':
            dstpath = os.path.join(dir_name, filename)
            if not os.path.isfile(dstpath):
                if 'main' in filename.lower():
                    _create_copy(filepath, dstpath, url)
                else:
                    shutil.copyfile(filepath, dstpath)
                print(filename, 'created')
            else:
                print(filename, 'already exist')


def _create_file(path, text):
    with open(path, 'w') as f:
        f.write(text)


def _create_copy(src, dst, url):
    with open(src, 'r', encoding='utf-8') as in_file:
        text = in_file.read()
        text = text.replace('<<<date_now>>>', str(datetime.date(datetime.now())))
        text = text.replace('<<<src_url>>>', url)
        with open(dst, 'w', encoding='utf-8') as out_file:
            out_file.write(text)


if __name__ == '__main__':
    main()
