# Time:  O(n)
# Space: O(n)

# greedy, counting sort
class Solution(object):
    def maximumImportance(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        def inplace_counting_sort(nums, reverse=False):  # Time: O(n)
            count = [0]*(max(nums)+1)
            for num in nums:
                count[num] += 1
            for i in xrange(1, len(count)):
                count[i] += count[i-1]
            for i in reversed(xrange(len(nums))):  # inplace but unstable sort
                while nums[i] >= 0:
                    count[nums[i]] -= 1
                    j = count[nums[i]]
                    nums[i], nums[j] = nums[j], ~nums[i]
            for i in xrange(len(nums)):
                nums[i] = ~nums[i]  # restore values
            if reverse:  # unstable sort
                nums.reverse()

        degree = [0]*n
        for a, b in roads:
            degree[a] += 1
            degree[b] += 1
        inplace_counting_sort(degree)
        return sum(i*x for i, x in enumerate(degree, 1))


# Time:  O(nlogn)
# Space: O(1)
# greedy, sort
class Solution2(object):
    def maximumImportance(self, n, roads):
        """
        :type n: int
        :type roads: List[List[int]]
        :rtype: int
        """
        degree = [0]*n
        for a, b in roads:
            degree[a] += 1
            degree[b] += 1
        degree.sort()
        return sum(i*x for i, x in enumerate(degree, 1))
