# Time:  O(n)
# Space: O(1)

# greedy
class Solution(object):
    def minAdjacentSwaps(self, nums, a, b):
        """
        :type nums: List[int]
        :type a: int
        :type b: int
        :rtype: int
        """
        MOD = 10**9+7
        result = cnt1 = cnt2 = 0
        for x in nums:
            if x < a:
                result = (result+(cnt1+cnt2))%MOD
            elif x <= b:
                cnt1 += 1
                result = (result+cnt2)%MOD
            else:
                cnt2 += 1
        return result
