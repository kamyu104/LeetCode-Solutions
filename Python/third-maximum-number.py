# Time:  O(n)
# Space: O(1)

class Solution(object):
    def thirdMax(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        count = 0
        top = [float("-inf")] * 3
        for num in nums:
            if num > top[0]:
                top[0], top[1], top[2] = num, top[0], top[1]
                count += 1
            elif num != top[0] and num > top[1]:
                top[1], top[2] = num, top[1]
                count += 1
            elif num != top[0] and num != top[1] and num >= top[2]:
                top[2] = num
                count += 1

        if count < 3:
            return top[0]

        return top[2]

