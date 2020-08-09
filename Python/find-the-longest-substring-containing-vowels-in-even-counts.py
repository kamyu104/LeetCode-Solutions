# Time:  O(n)
# Space: O(1)

class Solution(object):
    def findTheLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        VOWELS = "aeiou"
        result, mask, lookup = 0, 0, [len(s)]*(2**len(VOWELS))
        lookup[0] = -1
        for i, c in enumerate(s):
            index = VOWELS.find(c)
            mask ^= (1 << index) if index >= 0 else 0
            if lookup[mask] == len(s):
                lookup[mask] = i
            result = max(result, i-lookup[mask])
        return result
