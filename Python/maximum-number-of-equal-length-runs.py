# Time:  O(n)
# Space: O(sqrt(n))

# freq table
class Solution(object):
    def maxSameLengthRuns(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = collections.defaultdict(int)
        l = 0
        for i in xrange(len(s)):
            l += 1
            if i+1 == len(s) or s[i+1] != s[i]:
                cnt[l] += 1
                l = 0
        return max(cnt.itervalues())


# Time:  O(n)
# Space: O(n)
# freq table
class Solution2(object):
    def maxSameLengthRuns(self, s):
        """
        :type s: str
        :rtype: int
        """
        cnt = [0]*(len(s)+1)
        l = 0
        for i in xrange(len(s)):
            l += 1
            if i+1 == len(s) or s[i+1] != s[i]:
                cnt[l] += 1
                l = 0
        return max(cnt)
