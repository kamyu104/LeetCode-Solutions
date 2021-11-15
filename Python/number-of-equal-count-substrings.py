# Time:  O(26 * n) = O(n)
# Space: O(26) = O(1)

class Solution(object):
    def equalCountSubstrings(self, s, count):
        """
        :type s: str
        :type count: int
        :rtype: int
        """
        result = 0
        for l in xrange(1, min(len(set(s)), len(s)//count)+1):
            cnt, equal_cnt = collections.Counter(), 0
            for i, c in enumerate(s):
                cnt[c] += 1
                equal_cnt += (cnt[c] == count)
                if i >= count*l:
                    equal_cnt -= (cnt[s[i-count*l]] == count)
                    cnt[s[i-count*l]] -= 1
                result += (equal_cnt == l)
        return result
