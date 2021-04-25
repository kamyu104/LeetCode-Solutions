# Time:  O(n)
# Space: O(1)

class Solution(object):
    def longestBeautifulSubstring(self, word):
        """
        :type word: str
        :rtype: int
        """
        result = 0
        l = cnt = 1
        for i in xrange(len(word)-1):
            if word[i] > word[i+1]:
                l = cnt = 1
            else:
                l += 1
                cnt += int(word[i] < word[i+1])
            if cnt == 5:
                result = max(result, l)
        return result
