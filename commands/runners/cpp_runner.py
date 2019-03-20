import os
from .base_runner import BaseRunner


class CppRunner(BaseRunner):

    def compile(self):
        fname, _ = os.path.splitext(self.src_name)
        self.dst_path = os.path.join(self.src_dir, self.bin_dir, fname)

        if os.name == 'nt':
            self.dst_path += '.exe'

        if os.path.isfile(self.dst_path):
            os.remove(self.dst_path)

        self.shell(f'g++ -I{self.lib_path} -std=c++17 -O2 -Wall -D LOCAL -o {self.dst_path} {self.src_path}')

        return os.path.isfile(self.dst_path)


    def run(self, args):
        self.shell(f'{self.dst_path} {args}', True)
