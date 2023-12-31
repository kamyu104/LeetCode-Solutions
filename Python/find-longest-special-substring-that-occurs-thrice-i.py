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


# Time:  O(26 + n^2)
# Space: O(26 + n^2)
# string, brute force, freq table
class Solution2(object):
    def maximumLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        lookup = [[0] for _ in xrange(26)]
        result = 0
        for i, c in enumerate(s):
            curr = lookup[ord(c)-ord('a')]
            for j in xrange(i, len(s)):
                if s[j] != s[i]:
                    break
                if j-i+1 == len(curr):
                    curr.append(0)
                curr[j-i+1] += 1
                if curr[j-i+1] == 3:
                    result = max(result, j-i+1)
        return result if result else -1
