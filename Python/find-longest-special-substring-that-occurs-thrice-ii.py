# Time:  O(26 * 3 + n * 3)
# Space: O(26 * 3)

# string, hash table
class Solution(object):
    def maximumLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        lookup = [[0]*3 for _ in xrange(26)]
        result = cnt = 0
        for i, c in enumerate(s):
            cnt += 1
            if i+1 != len(s) and s[i+1] == s[i]:
                continue
            curr = lookup[ord(c)-ord('a')]
            for j in xrange(len(curr)):
                if curr[j] < cnt:
                    cnt, curr[j] = curr[j], cnt
            cnt = 0
            result = max(result, max(curr[0]-2, min(curr[0]-1, curr[1]), curr[2]))
        return result if result else -1
