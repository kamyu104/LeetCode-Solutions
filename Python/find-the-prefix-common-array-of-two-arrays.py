# Time:  O(n)
# Space: O(n)

# freq table
class Solution(object):
    def findThePrefixCommonArray(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        result = [0]*len(A)
        cnt = collections.Counter()
        curr = 0
        for i, (a, b) in enumerate(itertools.izip(A, B)):
            cnt[a] += 1
            if cnt[a] == 2:
                curr += 1
            cnt[b] += 1
            if cnt[b] == 2:
                curr += 1
            result[i] = curr
        return result
