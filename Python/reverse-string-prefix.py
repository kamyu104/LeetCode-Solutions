# Time:  O(n)
# Space: O(1)

# string
class Solution(object):
    def reversePrefix(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: str
        """
        def reverse(arr, left, right):
            while left < right:
                arr[left], arr[right] = arr[right], arr[left]
                left += 1
                right -=1
            return arr

        return "".join(reverse(list(s), 0, k-1))
