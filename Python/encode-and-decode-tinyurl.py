# Time:  O(1)
# Space: O(n)

import random


class Codec(object):
    def __init__(self):
        self.__random_length = 6
        self.__tiny_url = "http://tinyurl.com/"
        self.__alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"
        self.__lookup = {}

    def encode(self, longUrl):
        """Encodes a URL to a shortened URL.

        :type longUrl: str
        :rtype: str
        """
        def getRand():
            rand = []
            for _ in xrange(self.__random_length):
                rand += self.__alphabet[random.randint(0, len(self.__alphabet)-1)]
            return "".join(rand)

        key = getRand()
        while key in self.__lookup:
            key = getRand()
        self.__lookup[key] = longUrl
        return self.__tiny_url + key

    def decode(self, shortUrl):
        """Decodes a shortened URL to its original URL.

        :type shortUrl: str
        :rtype: str
        """
        return self.__lookup[shortUrl[len(self.__tiny_url):]]


from hashlib import sha256


class Codec2(object):

    def __init__(self):
        self._cache = {}
        self.url = 'http://tinyurl.com/'

    def encode(self, long_url):
        """Encodes a URL to a shortened URL.

        :type long_url: str
        :rtype: str
        """
        key = sha256(long_url.encode()).hexdigest()[:6]
        self._cache[key] = long_url
        return self.url + key

    def decode(self, short_url):
        """Decodes a shortened URL to its original URL.

        :type short_url: str
        :rtype: str
        """
        key = short_url.replace(self.url, '')
        return self._cache[key]


