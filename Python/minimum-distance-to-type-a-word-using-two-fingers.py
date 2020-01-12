# Time:  O(26n)
# Space: O(26)

class Solution(object):
    def minimumDistance(self, word):
        """
        :type word: str
        :rtype: int
        """
        def distance(a, b):
            return abs(a//6 - b//6) + abs(a%6 - b%6)

        dp = [0]*26
        for i in xrange(len(word)-1):
            b, c = ord(word[i])-ord('A'), ord(word[i+1])-ord('A')
            dp[b] = max(dp[a] - distance(a, c) + distance(b, c) for a in xrange(26))
        return sum(distance(ord(word[i])-ord('A'), ord(word[i+1])-ord('A')) for i in xrange(len(word)-1)) - max(dp)


# Time:  O(52n)
# Space: O(52)
class Solution2(object):
    def minimumDistance(self, word):
        """
        :type word: str
        :rtype: int
        """
        def distance(a, b):
            if -1 in [a, b]:
                return 0
            return abs(a//6 - b//6) + abs(a%6 - b%6)

        dp = {(-1, -1): 0}
        for c in word:
            c = ord(c)-ord('A')
            new_dp = {}
            for a, b in dp:
                new_dp[c, b] = min(new_dp.get((c, b), float("inf")), dp[a, b] + distance(a, c))
                new_dp[a, c] = min(new_dp.get((a, c), float("inf")), dp[a, b] + distance(b, c))
            dp = new_dp
        return min(dp.itervalues())
