# Time:  O(k * log(min(n, m, k))), where n is the size of num1, and m is the size of num2.
# Space: O(min(n, m, k))

# You are given two integer arrays nums1
# and nums2 sorted in ascending order and an integer k.
#
# Define a pair (u,v) which consists of one element
# from the first array and one element from the second array.
#
# Find the k pairs (u1,v1),(u2,v2) ...(uk,vk) with the smallest sums.
#
# Example 1:
# Given nums1 = [1,7,11], nums2 = [2,4,6],  k = 3
#
# Return: [1,2],[1,4],[1,6]
#
# The first 3 pairs are returned from the sequence:
# [1,2],[1,4],[1,6],[7,2],[7,4],[11,2],[7,6],[11,4],[11,6]
# Example 2:
# Given nums1 = [1,1,2], nums2 = [1,2,3],  k = 2
#
# Return: [1,1],[1,1]
#
# The first 2 pairs are returned from the sequence:
# [1,1],[1,1],[1,2],[2,1],[1,2],[2,2],[1,3],[1,3],[2,3]
# Example 3:
# Given nums1 = [1,2], nums2 = [3],  k = 3 
#
# Return: [1,3],[2,3]
#
# All possible pairs are returned from the sequence:
# [1,3],[2,3]

from heapq import heappush, heappop

class Solution(object):
    def kSmallestPairs(self, nums1, nums2, k):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :type k: int
        :rtype: List[List[int]]
        """
        pairs = []
        if len(nums1) > len(nums2):
            tmp = self.kSmallestPairs(nums2, nums1, k)
            for pair in tmp:
                pairs.append([pair[1], pair[0]])
            return pairs

        min_heap = []
        def push(i, j):
            if i < len(nums1) and j < len(nums2):
                heappush(min_heap, [nums1[i] + nums2[j], i, j])

        push(0, 0)
        while min_heap and len(pairs) < k:
            _, i, j = heappop(min_heap)
            pairs.append([nums1[i], nums2[j]])
            push(i, j + 1)
            if j == 0:
                push(i + 1, 0)  # at most queue min(n, m) space
        return pairs
