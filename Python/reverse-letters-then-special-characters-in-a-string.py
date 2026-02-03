# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def reverseByType(self, s):
        """
        :type s: str
        :rtype: str
        """
        def reverse(s, check):
            left, right = 0, len(s)-1
            while left < right:
                if not check(s[left]):
                    left += 1
                elif not check(s[right]):
                    right -= 1
                else:
                    s[left], s[right] = s[right], s[left]
                    left += 1
                    right -= 1

        result = list(s)
        reverse(result, lambda x: x.isalpha())
        reverse(result, lambda x: not x.isalpha())
        return "".join(result)
