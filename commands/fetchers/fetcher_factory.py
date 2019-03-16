from urllib.parse import urlsplit
from .code_force import CodeForce
from .spoj import SPOJ


class FetcherFactory:
    def __init__(self):
        self._fetchers = {}

    def register(self, key, fetcher):
        self._fetchers[key] = fetcher

    def get(self, url):
        key = urlsplit(url).netloc
        return self._fetchers.get(key)(url)


factory = FetcherFactory()
factory.register('codeforces.com', CodeForce)
factory.register('www.spoj.com', SPOJ)
