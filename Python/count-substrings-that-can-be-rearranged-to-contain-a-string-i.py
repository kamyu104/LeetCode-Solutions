# Time:  O(n + 26)
# Space: O(26)

# two pointers, sliding window, freq table
class Solution(object):
    def validSubstringCount(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        cnt = [0]*26
        curr = 0
        for x in word2:
            curr += int(cnt[ord(x)-ord('a')] == 0)
            cnt[ord(x)-ord('a')] += 1
        result = left = 0
        for right in xrange(len(word1)):
            cnt[ord(word1[right])-ord('a')] -= 1
            curr -= int(cnt[ord(word1[right])-ord('a')] == 0)
            while not curr:
                result += len(word1)-right
                curr += int(cnt[ord(word1[left])-ord('a')] == 0)
                cnt[ord(word1[left])-ord('a')] += 1
                left += 1
        return result
