class Solution:
    def checkPossibility(self, nums: List[int]) -> bool:
        wrong_idx = -1
        for i in range(len(nums) - 1):
            if(nums[i] > nums[i+1]):
                if(wrong_idx != -1):
                    return False
                wrong_idx = i
        if(wrong_idx == -1):
            return True
        elif(wrong_idx == 0 or wrong_idx == len(nums) -2):
            return True
        elif(nums[wrong_idx -1] <= nums[wrong_idx+1]):
            return True
        elif(nums[wrong_idx] <= nums[wrong_idx+2]):
            return True
        else:
            return False
