# Time:  O(n^4)
# Space: O(n)

import collections


# sort, brute force, hash table
class Solution(object):
    def wordSquares(self, words):
        """
        :type words: List[str]
        :rtype: List[List[str]]
        """
        words.sort()
        lookup = collections.defaultdict(list)
        for i, w in enumerate(words):
            lookup[w[0]].append(i)
            lookup[w[0], w[3]].append(i)
        result = []
        for i in xrange(len(words)):
            for j in lookup[words[i][0]]:
                if j == i:
                    continue
                for k in lookup[words[i][3]]:
                    if k in (i, j):
                        continue
                    for l in lookup[words[j][3], words[k][3]]:
                        if l in (i, j, k):
                            continue
                        result.append([words[i], words[j], words[k], words[l]])
        return result


# Time:  O(n^4)
# Space: O(1)
# sort, brute force
class Solution2(object):
    def wordSquares(self, words):
        """
        :type words: List[str]
        :rtype: List[List[str]]
        """
        words.sort()
        result = []
        for i in xrange(len(words)):
            for j in xrange(len(words)):
                if j == i or words[j][0] != words[i][0]:
                    continue
                for k in xrange(len(words)):
                    if k in (i, j) or words[k][0] != words[i][3]:
                        continue
                    for l in xrange(len(words)):
                        if l in (i, j, k) or words[l][0] != words[j][3] or words[l][3] != words[k][3]:
                            continue
                        result.append([words[i], words[j], words[k], words[l]])
        return result
