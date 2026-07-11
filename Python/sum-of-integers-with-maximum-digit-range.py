# Time:  O(nlogr)
# Space: O(1)

# array
class Solution(object):
    def maxDigitRange(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def count(n):
            mx, mn = -1, 10
            while n:
                n, r = divmod(n, 10)
                mx = max(mx, r)
                mn = min(mn, r)
            return mx-mn
        
        result = mx = 0
        for x in nums:
            v = count(x)
            if v > mx:
                mx = v
                result = x
            elif v == mx:
                result += x
        return result


# Time:  O(nlogr)
# Space: O(1)
# array
class Solution2(object):
    def maxDigitRange(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def count(n):
            mx, mn = -1, 10
            while n:
                n, r = divmod(n, 10)
                mx = max(mx, r)
                mn = min(mn, r)
            return mx-mn
        
        mx = max(count(x) for x in nums)
        return sum(x for x in nums if count(x) == mx)
