# Time:  O(n + 26)
# Space: O(26)

# freq table, sliding window, two pointers
class Solution(object):
    def maximumLengthSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        COUNT = 2
        result = 0
        cnt = [0]*26
        left = invalid_cnt = 0
        for right, x in enumerate(s):
            if cnt[ord(x)-ord('a')] == COUNT:
                invalid_cnt += 1
            cnt[ord(x)-ord('a')] += 1
            if invalid_cnt:
                cnt[ord(s[left])-ord('a')] -= 1
                if cnt[ord(s[left])-ord('a')] == COUNT:
                    invalid_cnt -= 1
                left += 1
        return right-left+1


# Time:  O(n + 26)
# Space: O(26)
# freq table, sliding window, two pointers
class Solution2(object):
    def maximumLengthSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        COUNT = 2
        result = 0
        cnt = [0]*26
        left = 0
        for right, x in enumerate(s):
            cnt[ord(x)-ord('a')] += 1
            while cnt[ord(x)-ord('a')] > COUNT:
                cnt[ord(s[left])-ord('a')] -= 1
                left += 1
            result = max(result, right-left+1)
        return result
