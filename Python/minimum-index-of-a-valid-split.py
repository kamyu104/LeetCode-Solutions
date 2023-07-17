# Time:  O(n)
# Space: O(1)

# Boyer–Moore majority vote algorithm, linear search
class Solution(object):
    def minimumIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def boyer_moore_majority_vote():
            m, cnt = nums[0], 1
            for i in xrange(1, len(nums)):
                if m == nums[i]:
                    cnt += 1
                else:
                    cnt -= 1
                    if cnt == 0:
                        m = nums[i]
                        cnt = 1
            return m
        
        m = boyer_moore_majority_vote()
        total, cnt = nums.count(m), 0
        for i, x in enumerate(nums):
            if x == m:
                cnt += 1
            if cnt*2 > i+1 and (total-cnt)*2 > len(nums)-(i+1):
                return i
        return -1
