import os
from abc import ABC, abstractmethod
import subprocess


class BaseRunner(ABC):
    def __init__(self, src_path, bin_dir, lib_path):
        self.parser = self.__class__.__name__
        self.src_path = src_path
        self.src_dir = os.path.dirname(self.src_path)
        self.src_name = os.path.basename(self.src_path)
        self.bin_dir = bin_dir
        self.lib_path = lib_path
        if not os.path.isdir(bin_dir):
            os.makedirs(bin_dir)

    def shell(self, cmd, silent=False):
        self.cmd = cmd
        if not silent:
            print(cmd)
        subprocess.run(cmd, shell=True, check=True)

    @abstractmethod
    def compile(self):
        pass

    @abstractmethod
    def run(self, args):
        pass
