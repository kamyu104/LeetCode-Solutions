# Time:  O(n * m)
# Space: O(n)

import collections


class Solution(object):
    def differByOne(self, dict):
        """
        :type dict: List[str]
        :rtype: bool
        """
        MOD, P = 10**9+7, 113

        hashes = [0]*len(dict)
        for i, word in enumerate(dict):
            for c in word:
                hashes[i] = (P*hashes[i] + (ord(c)-ord('a'))) % MOD

        base = 1
        for p in reversed(xrange(len(dict[0]))):        
            lookup = collections.defaultdict(list)
            for i, word in enumerate(dict):
                new_hash = (hashes[i] - base*(ord(word[p])-ord('a'))) % MOD
                if new_hash in lookup:
                    for j in lookup[new_hash]:
                        if dict[j][:p]+dict[j][p+1:] == word[:p]+word[p+1:]:
                            return True
                lookup[new_hash].append(i)
            base = P*base % MOD
        return False
