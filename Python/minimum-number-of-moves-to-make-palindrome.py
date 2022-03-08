# Time:  O(nlogn)
# Space: O(n)

class BIT(object):  # 0-indexed
    def __init__(self, n):
        self.__bit = [0]*(n+1)

    def add(self, i, val):
        i += 1
        while i < len(self.__bit):
            self.__bit[i] += val
            i += (i & -i)

    def query(self, i):
        i += 1
        ret = 0
        while i > 0:
            ret += self.__bit[i]
            i -= (i & -i)
        return ret


# greedy, bit, fenwick tree
class Solution(object):
    def minMovesToMakePalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        idxs = [[] for _ in xrange(26)]
        for i, c in enumerate(s):
            idxs[ord(c)-ord('a')].append(i)
        targets, pairs = [0]*len(s), []
        for c, idx in enumerate(idxs):
            for i in xrange(len(idx)//2):
                pairs.append((idx[i], idx[~i]))
            if len(idx)%2:
                targets[idx[len(idx)//2]] = len(s)//2
        pairs.sort()
        for i, (l, r) in enumerate(pairs):
            targets[l], targets[r] = i, (len(s)-1)-i
        bit = BIT(len(s))
        result = 0
        for i in targets:
            result += i-bit.query(i-1)  # move from bit.query(i-1) to i
            bit.add(i, 1)
        return result


# Time:  O(n^2)
# Space: O(n)
# greedy
class Solution2(object):
    def minMovesToMakePalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = list(s)
        result = 0
        while s:
            i = s.index(s[-1])
            if i == len(s)-1:
                result += i//2
            else:
                result += i
                s.pop(i)
            s.pop()
        return result
