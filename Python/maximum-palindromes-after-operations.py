# Time:  O(n * l + nlogn)
# Space: O(n)

# freq table, greedy, sort
class Solution(object):
    def maxPalindromesAfterOperations(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        cnt = [0]*26
        for w in words:
            for c in w:
                cnt[ord(c)-ord('a')] += 1
        curr = sum(x//2 for x in cnt)
        for i, l in enumerate(sorted(map(len, words))):
            curr -= l//2
            if curr < 0:
                return i
        return len(words)
