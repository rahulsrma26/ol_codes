from urllib.parse import urlsplit
from bs4 import BeautifulSoup

from .base_fetcher import BaseFetcher


class LeetCodeFetcher(BaseFetcher):

    def dirname(self):
        comps = urlsplit(self.url).path.split('/')
        if len(comps) <= 5:
            return 'LC-{}'.format(comps[2])
        return 'LC-{}-{}'.format(comps[-2], comps[-1])

    def tests(self):
        print('As there is no standard HTML without login, test-case fetching is not supported.')
        yield from ()
