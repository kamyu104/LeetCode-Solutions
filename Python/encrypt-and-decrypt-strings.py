# Time:  ctor:    O(m + d), m is len(keys), d is sum(len(x) for x in dictionary)
#        encrypt: O(n)
#        decrypt: O(n)
# Space: O(m + d)

import collections
import itertools


# freq table
class Encrypter(object):

    def __init__(self, keys, values, dictionary):
        """
        :type keys: List[str]
        :type values: List[str]
        :type dictionary: List[str]
        """
        self.__lookup = {k: v for k, v in itertools.izip(keys, values)}
        self.__cnt = collections.Counter(self.encrypt(x) for x in dictionary)
        
    def encrypt(self, word1):
        """
        :type word1: str
        :rtype: str
        """
        if any(c not in self.__lookup for c in word1):
            return ""
        return "".join(self.__lookup[c] for c in word1)

    def decrypt(self, word2):
        """
        :type word2: str
        :rtype: int
        """
        return self.__cnt[word2]
