# Time:  O(n)
# Space: O(1)

class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        i, j = 0, 0
        while j < len(chars):
            if j+1 == len(chars) or chars[j] != chars[j+1]:
                chars[i] = chars[j]
                i += 1
                j += 1
            else:
                k = j
                while j < len(chars) and chars[j] == chars[k]:
                    j += 1
                chars[i] = chars[k]
                i += 1
                n, left = j-k, i
                while n > 0:
                    chars[i] = chr(n%10+ord('0'))
                    n /= 10
                    i += 1
                right = i-1
                while left < right:
                    chars[left], chars[right] = chars[right], chars[left]
                    left += 1
                    right -= 1
        return i
