from urllib.parse import urlsplit
from bs4 import BeautifulSoup

from .base_fetcher import BaseFetcher


class CodeForceFetcher(BaseFetcher):

    def dirname(self):
        comps = urlsplit(self.url).path.split('/')
        return 'CF{}-D2-{}'.format(comps[2], comps[4])

    def tests(self):
        soup = BeautifulSoup(self.text, 'html.parser')

        previous = None
        for div in soup.find('div', {'class': 'sample-test'}):
            dtype = div['class'][0]
            text = div.find('pre').get_text('\n')
            if dtype == 'input':
                previous = text
            elif dtype == 'output':
                yield previous, text
