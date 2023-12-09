# Time:  O(26 * (n + q))
# Space: O(26 * n)

# freq table, prefix sum
class Solution(object):
    def sameEndSubstringCount(self, s, queries):
        """
        :type s: str
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        prefix = [[0]*26]
        for i in xrange(len(s)):
            prefix.append(prefix[-1][:])
            prefix[-1][ord(s[i])-ord('a')] += 1
        result = [0]*len(queries)
        for i, (l, r) in enumerate(queries):
            for j in xrange(26):
                cnt = prefix[r+1][j]-prefix[l][j]
                result[i] += (1+cnt)*cnt//2
        return result
