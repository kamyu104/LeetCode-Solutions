# Time:  O(nlogm), m is the max of nums
# Space: O(1)

# math, stack
class Solution(object):
    def replaceNonCoprimes(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        def gcd(a, b):  # Time: O(log(min(a, b)))
            while b:
                a, b = b, a%b
            return a

        result = []
        for x in nums:
            while True:
                g = gcd(result[-1] if result else 1, x)
                if g == 1:
                    break
                x *= result.pop()//g
            result.append(x)
        return result
