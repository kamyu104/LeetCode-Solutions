# Time:  O(n + klogk) on average
# Space: O(n)

# Given a non-empty list of words, return the k most frequent elements.
#
# Your answer should be sorted by frequency from highest to lowest.
# If two words have the same frequency, then the word with the lower alphabetical order comes first.
#
# Example 1:
# Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
# Output: ["i", "love"]
# Explanation: "i" and "love" are the two most frequent words.
#     Note that "i" comes before "love" due to a lower alphabetical order.
# Example 2:
# Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
# Output: ["the", "is", "sunny", "day"]
# Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
#     with the number of occurrence being 4, 3, 2 and 1 respectively.
# Note:
# You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
# Input words contain only lowercase letters.
#
# Follow up:
# Try to solve it in O(n log k) time and O(n) extra space.
# Can you solve it in O(n) time with only O(k) extra space?

# Quick Select Solution

import collections
import heapq
from random import randint


class Solution(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        counts = collections.Counter(words)
        p = []
        for key, val in counts.iteritems():
            p.append((-val, key))
        self.kthElement(p, k)

        result = []
        sorted_p = sorted(p[:k])
        for i in xrange(k):
            result.append(sorted_p[i][1])
        return result

    def kthElement(self, nums, k):  # O(n) on average
        def PartitionAroundPivot(left, right, pivot_idx, nums):
            pivot_value = nums[pivot_idx]
            new_pivot_idx = left
            nums[pivot_idx], nums[right] = nums[right], nums[pivot_idx]
            for i in xrange(left, right):
                if nums[i] < pivot_value:
                    nums[i], nums[new_pivot_idx] = nums[new_pivot_idx], nums[i]
                    new_pivot_idx += 1

            nums[right], nums[new_pivot_idx] = nums[new_pivot_idx], nums[right]
            return new_pivot_idx

        left, right = 0, len(nums) - 1
        while left <= right:
            pivot_idx = randint(left, right)
            new_pivot_idx = PartitionAroundPivot(left, right, pivot_idx, nums)
            if new_pivot_idx == k - 1:
                return
            elif new_pivot_idx > k - 1:
                right = new_pivot_idx - 1
            else:  # new_pivot_idx < k - 1.
                left = new_pivot_idx + 1


# Time:  O(nlogk)
# Space: O(n)
# Heap Solution
class Solution2(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        class MinHeapObj(object):
            def __init__(self,val):
                self.val = val
            def __lt__(self,other):
                return self.val[1] > other.val[1] if self.val[0] == other.val[0] else \
                       self.val < other.val
            def __eq__(self,other):
                return self.val == other.val
            def __str__(self):
                return str(self.val)

        counts = collections.Counter(words)
        min_heap = []
        for word, count in counts.iteritems():
            heapq.heappush(min_heap, MinHeapObj((count, word)))
            if len(min_heap) == k+1:
                heapq.heappop(min_heap)
        result = []
        while min_heap:
            result.append(heapq.heappop(min_heap).val[1])
        return result[::-1]


# Time:  O(n + klogk) ~ O(n + nlogn)
# Space: O(n)
# Bucket Sort Solution
class Solution3(object):
    def topKFrequent(self, words, k):
        """
        :type words: List[str]
        :type k: int
        :rtype: List[str]
        """
        counts = collections.Counter(words)
        buckets = [[] for _ in xrange(len(words)+1)]
        for word, count in counts.iteritems():
            buckets[count].append(word)
        pairs = []
        for i in reversed(xrange(len(words))):
            for word in buckets[i]:
                pairs.append((-i, word))
            if len(pairs) >= k:
                break
        pairs.sort()
        return [pair[1] for pair in pairs[:k]]
