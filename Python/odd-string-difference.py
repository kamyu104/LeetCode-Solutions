# Time:  O(m * n), m is the number of words, n is the length of each word
# Space: O(1)

import collections


# freq table
class Solution(object):
    def oddString(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        for i in xrange(len(words[0])-1):
            lookup = collections.defaultdict(list)
            for j, w in enumerate(words):
                if len(lookup[ord(w[i+1])-ord(w[i])]) < 2:
                    lookup[ord(w[i+1])-ord(w[i])].append(j)
            if len(lookup) == 2:
                return next(words[l[0]] for l in lookup.itervalues() if len(l) == 1)


# Time:  O(m * n), m is the number of words, n is the length of each word
# Space: O(n)
import collections


# freq table
class Solution2(object):
    def oddString(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        cnt = collections.Counter(tuple(ord(w[i+1])-ord(w[i]) for i in xrange(len(w)-1)) for w in words)
        target = next(k for k, v in cnt.iteritems() if v == 1)
        return next(w for w in words if tuple(ord(w[i+1])-ord(w[i]) for i in xrange(len(w)-1)) == target)
