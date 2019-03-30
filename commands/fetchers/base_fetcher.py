import requests
from abc import ABC, abstractmethod


class BaseFetcher(ABC):
    def __init__(self, url):
        self.parser = self.__class__.__name__
        self.url = url

        response = requests.get(url)
        if response.status_code != 200:
            print(f'response.status_code = {response.status_code}')
        self.text = response.text


    @abstractmethod
    def dirname(self):
        pass


    @abstractmethod
    def tests(self):
        pass
