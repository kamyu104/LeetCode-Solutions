# Time:  O(n)
# Space: O(n)

# prefix sum, freq table
class Solution(object):
    def countMajoritySubarrays(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        cnt = [0]*((2*len(nums)+1)+1)
        prefix = [0]*((2*len(nums)+1)+1)
        prefix[0] = cnt[0] = 1
        result = curr = 0
        for x in nums:
            curr += +1 if x == target else -1
            cnt[curr] += 1
            prefix[curr] = prefix[curr-1]+cnt[curr]
            result += prefix[curr-1]
        return result
