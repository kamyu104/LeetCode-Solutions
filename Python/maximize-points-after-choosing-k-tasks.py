# Time:  O(nlogn)
# Space: O(n)

# sort, greedy
class Solution(object):
    def maxPoints(self, technique1, technique2, k):
        """
        :type technique1: List[int]
        :type technique2: List[int]
        :type k: int
        :rtype: int
        """
        idxs = range(len(technique1))
        idxs.sort(key=lambda i: technique1[i]-technique2[i], reverse=True)
        return sum(technique1[idxs[i]] if i < k else max(technique1[idxs[i]], technique2[idxs[i]]) for i in xrange(len(technique1)))


# Time:  O(n)
# Space: O(n)
import random


# quick select, greedy
class Solution_TLE(object):
    def maxPoints(self, technique1, technique2, k):
        """
        :type technique1: List[int]
        :type technique2: List[int]
        :type k: int
        :rtype: int
        """
        def nth_element(nums, n, left=0, compare=lambda a, b: a < b):
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
            
            right = len(nums)-1
            while left <= right:
                pivot_idx = random.randint(left, right)
                pivot_left, pivot_right = tri_partition(nums, left, right, nums[pivot_idx], compare)
                if pivot_left <= n <= pivot_right:
                    return
                elif pivot_left > n:
                    right = pivot_left-1
                else:  # pivot_right < n.
                    left = pivot_right+1

        idxs = range(len(technique1))
        nth_element(idxs, k-1, compare=lambda a, b: technique1[a]-technique2[a] > technique1[b]-technique2[b])
        return sum(technique1[idxs[i]] if i < k else max(technique1[idxs[i]], technique2[idxs[i]]) for i in xrange(len(technique1)))
