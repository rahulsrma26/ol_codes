from __future__ import absolute_import
from __future__ import division
from __future__ import print_function

import os
import sys
import shutil
import requests
from datetime import datetime
from urllib.parse import urlsplit
from bs4 import BeautifulSoup


def main():
    if len(sys.argv) != 3:
        print('usage {} <code-force-url> <language>'.format(sys.argv[0]))
        return

    # print(sys.argv)
    url = sys.argv[1]
    comps = urlsplit(url).path.split('/')
    dir_name = 'CF{}-D2-{}'.format(comps[2], comps[4])

    if os.path.isdir(dir_name):
        print(dir_name, 'already exist')
    else:
        print(dir_name, 'created')
        os.mkdir(dir_name)

    try:
        print('test(s) found =', _populate_tests(url, dir_name))
    except Exception as e:
        print(e)
        return

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


def _populate_tests(url, dir_name):
    response = requests.get(url)
    if response.status_code != 200:
        print(response)
        return -1

    soup = BeautifulSoup(response.text, 'html.parser')
    count = 0
    for div in soup.find('div', {'class': 'sample-test'}):
        dtype = div['class'][0]
        if dtype == 'input':
            count += 1
        elif dtype != 'output':
            continue
        with open(os.path.join(dir_name, 'test_{}.{}'.format(count, dtype)), 'w') as f:
            f.write(div.find('pre').get_text('\n'))
    return count


def _create_copy(src, dst, url):
    with open(src, 'r', encoding='utf-8') as in_file:
        text = in_file.read()
        text = text.replace('<<<date_now>>>', str(datetime.date(datetime.now())))
        text = text.replace('<<<src_url>>>', url)
        with open(dst, 'w', encoding='utf-8') as out_file:
            out_file.write(text)


if __name__ == '__main__':
    main()
