# Time:  O(n + m)
# Space: O(1)

import itertools


# string, hash table
class Solution(object):
    def decodeMessage(self, key, message):
        """
        :type key: str
        :type message: str
        :rtype: str
        """
        f = lambda x: ord(x)-ord('a')
        lookup = [-1]*26
        i = 0
        for x in itertools.imap(f, key):
            if x < 0 or lookup[x] != -1:
                continue
            lookup[x] = i
            i += 1
        return "".join(itertools.imap(lambda x: chr(ord('a')+x), (lookup[x] if x >= 0 else x for x in itertools.imap(f, message))))
    
