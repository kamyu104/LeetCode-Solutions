# Time:  O(n)
# Space: O(n)

# There is a garden with N slots. In each slot, there is a flower.
# The N flowers will bloom one by one in N days. In each day,
# there will be exactly one flower blooming and it will be in the status of blooming since then.
#
# Given an array flowers consists of number from 1 to N.
# Each number in the array represents the place where the flower will open in that day.
#
# For example, flowers[i] = x means that the unique flower that blooms at day i
# will be at position x, where i and x will be in the range from 1 to N.
#
# Also given an integer k, you need to output in which day there exists two flowers
# in the status of blooming, and also the number of flowers between them is k and
# these flowers are not blooming.
#
# If there isn't such day, output -1.
#
# Example 1:
# Input: 
# flowers: [1,3,2]
# k: 1
# Output: 2
# Explanation: In the second day, the first and the third flower have become blooming.
#
# Example 2:
# Input: 
# flowers: [1,2,3]
# k: 1
# Output: -1
# Note:
# The given array will be in the range [1, 20000].

class Solution(object):
    def kEmptySlots(self, flowers, k):
        """
        :type flowers: List[int]
        :type k: int
        :rtype: int
        """
        days = [0] * len(flowers)
        for i in xrange(len(flowers)):
            days[flowers[i]-1] = i
        result = float("inf")
        i, left, right = 0, 0, k+1
        while right < len(days):
            if days[i] < days[left] or days[i] <= days[right]:  
                if i == right:
                    result = min(result, max(days[left], days[right]))
                left, right = i, k+1+i;
            i += 1
        return -1 if result == float("inf") else result+1
        
