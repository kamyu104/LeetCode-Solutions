# Time:  O(n * 2^n)
# Space: O(1)

class Solution(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums.sort()
        result = [[]]
        for i in xrange(len(nums)):
            size = len(result)
            for j in xrange(size):
                result.append(list(result[j]))
                result[-1].append(nums[i])
        return result


# Time:  O(n * 2^n)
# Space: O(1)
class Solution2(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        result = []
        i, count = 0, 1 << len(nums)
        nums.sort()

        while i < count:
            cur = []
            for j in xrange(len(nums)):
                if i & 1 << j:
                    cur.append(nums[j])
            result.append(cur)
            i += 1

        return result


# Time:  O(n * 2^n)
# Space: O(1)
class Solution3(object):
    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        return self.subsetsRecu([], sorted(nums))

    def subsetsRecu(self, cur, nums):
        if not nums:
            return [cur]

        return self.subsetsRecu(cur, nums[1:]) + self.subsetsRecu(cur + [nums[0]], nums[1:])


