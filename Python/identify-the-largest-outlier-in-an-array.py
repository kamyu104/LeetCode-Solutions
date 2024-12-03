# Time:  O(n)
# Space: O(n)

# freq table
class Solution(object):
    def getLargestOutlier(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = float("-inf")
        total = sum(nums)
        cnt = collections.defaultdict(int)
        for x in nums:
            cnt[x] += 1
        for x in nums:
            if (total-x)%2:
                continue
            target = (total-x)//2
            if target in cnt and (cnt[target]-int(target == x) >= 1):
                result = max(result, x)
        return result
