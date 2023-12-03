# Time:  O(26 + d * n), d = len(set(word))
# Space: O(26)

# freq table, two pointers
class Solution(object):
    def countCompleteSubstrings(self, word, k):
        """
        :type word: str
        :type k: int
        :rtype: int
        """
        result = valid = 0
        cnt = [0]*26
        for c in xrange(1, len(set(word))+1):
            left = 0
            for right in xrange(len(word)):
                cnt[ord(word[right])-ord('a')] += 1
                curr = cnt[ord(word[right])-ord('a')]
                valid += 1 if curr == k else -1 if curr == k+1 else 0
                if right-1 >= 0 and abs(ord(word[right])-ord(word[right-1])) > 2:
                    while left < right:
                        curr = cnt[ord(word[left])-ord('a')]
                        valid -= 1 if curr == k else -1 if curr == k+1 else 0
                        cnt[ord(word[left])-ord('a')] -= 1
                        left += 1
                elif right-left+1 == c*k+1:
                    curr = cnt[ord(word[left])-ord('a')]
                    valid -= 1 if curr == k else -1 if curr == k+1 else 0
                    cnt[ord(word[left])-ord('a')] -= 1
                    left += 1
                if valid == c:
                    result += 1
            while left < len(word):
                curr = cnt[ord(word[left])-ord('a')]
                valid -= 1 if curr == k else -1 if curr == k+1 else 0
                cnt[ord(word[left])-ord('a')] -= 1
                left += 1
        return result
