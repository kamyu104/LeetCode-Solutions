class Solution:
    def triangularSum(self, nums: List[int]) -> int:
        l1 = []

        while len(nums) != 1:
            for i in range(len(nums)-1):
                number = (nums[i] + nums[i+1]) % 10
                l1.append(number)
            nums = l1[:]
            l1 = []
        return nums[0]
