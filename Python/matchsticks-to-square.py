# Time:  O(n * s * 2^n), s is the number of subset of which sum equals to side length.
# Space: O(n * (2^n + s))

class Solution(object):
    def makesquare(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        total_len = sum(nums)
        if total_len % 4:
            return False

        side_len = total_len / 4
        fullset = (1 << len(nums)) - 1

        used_subsets = []
        valid_half_subsets = [0] * (1 << len(nums))

        for subset in xrange(fullset+1):
            subset_total_len = 0
            for i in xrange(len(nums)):
                if subset & (1 << i):
                    subset_total_len += nums[i]

            if subset_total_len == side_len:
                for used_subset in used_subsets:
                    if (used_subset & subset) == 0:
                        valid_half_subset = used_subset | subset
                        valid_half_subsets[valid_half_subset] = True
                        if valid_half_subsets[fullset ^ valid_half_subset]:
                            return True
                used_subsets.append(subset)

        return False

