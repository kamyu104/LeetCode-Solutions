# Time:  O(q + n * t)
# Space: O(t + n + q)

# radix sort
class Solution(object):
    def smallestTrimmedNumbers(self, nums, queries):
        """
        :type nums: List[str]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        max_t = max(t for _, t in queries)
        lookup = [[] for _ in xrange(max_t+1)]
        for i, (k, t) in enumerate(queries):
            lookup[t].append((k, i))
        result = [0]*len(queries)
        idxs = range(len(nums))
        for l in xrange(1, max_t+1):
            cnt = [0]*10
            for i in idxs:
                d = int(nums[i][-l])
                cnt[d] += 1
            for d in xrange(9):
                cnt[d+1] += cnt[d]
            new_idxs = [0]*len(nums)
            for i in reversed(idxs):
                d = int(nums[i][-l])
                cnt[d] -= 1
                new_idxs[cnt[d]] = i
            idxs = new_idxs
            for k, i in lookup[l]:
                result[i] = idxs[k-1]
        return result

            
# Time:  O(q * n * t) on average
# Space: O(n + q)
import random


# quick select
class Solution2(object):
    def smallestTrimmedNumbers(self, nums, queries):
        """
        :type nums: List[str]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def nth_element(nums, n, compare=lambda a, b: a < b):
            def tri_partition(nums, left, right, target, compare):
                mid = left
                while mid <= right:
                    if nums[mid] == target:
                        mid += 1
                    elif compare(nums[mid], target):
                        nums[left], nums[mid] = nums[mid], nums[left]
                        left += 1
                        mid += 1
                    else:
                        nums[mid], nums[right] = nums[right], nums[mid]
                        right -= 1
                return left, right

            left, right = 0, len(nums)-1
            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx], compare)
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1

        def compare(a, b):
            for i in xrange(len(nums[a])-t, len(nums[a])):
                if nums[a][i] < nums[b][i]:
                    return True
                if nums[a][i] > nums[b][i]:
                    return False
            return cmp(a, b) < 0

        result = []
        idxs = range(len(nums))
        for k, t in queries:
            nth_element(idxs, k-1, compare=compare)
            result.append(idxs[k-1])
        return result


# Time:  O(q + nlogn * t)
# Space: O(t + n + q)
# sort
class Solution3(object):
    def smallestTrimmedNumbers(self, nums, queries):
        """
        :type nums: List[str]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def compare(a, b):
            for i in xrange(len(nums[a])-t, len(nums[a])):
                if nums[a][i] < nums[b][i]:
                    return -1
                if nums[a][i] > nums[b][i]:
                    return 1
            return cmp(a, b)

        max_t = max(t for _, t in queries)
        lookup = [[] for _ in xrange(max_t+1)]
        for i, (k, t) in enumerate(queries):
            lookup[t].append((k, i))
        result = [0]*len(queries)
        idxs = range(len(nums))
        for t in xrange(1, max_t+1):
            if not lookup[t]:
                continue
            idxs.sort(cmp=compare)
            for k, i in lookup[t]:
                result[i] = idxs[k-1]
        return result
