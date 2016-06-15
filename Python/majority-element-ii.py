# Time:  O(n)
# Space: O(1)

# Given an integer array of size n, 
# find all elements that appear more than [n/3] times. 
# The algorithm should run in linear time and in O(1) space.

class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        k, n, cnts = 3, len(nums), collections.defaultdict(int)

        for i in nums:
            cnts[i] += 1
            # Detecting k items in cnts, at least one of them must have exactly
            # one in it. We will discard those k items by one for each.
            # This action keeps the same mojority numbers in the remaining numbers.
            # Because if x / n  > 1 / k is true, then (x - 1) / (n - k) > 1 / k is also true.
            if len(cnts) == k:
                for j in cnts.keys():
                    cnts[j] -= 1
                    if cnts[j] == 0:
                        del cnts[j]

        # Resets cnts for the following counting.
        for i in cnts.keys():
            cnts[i] = 0

        # Counts the occurrence of each candidate integer.
        for i in nums:
            if i in cnts:
                cnts[i] += 1

        # Selects the integer which occurs > [n / k] times.
        result = []
        for i in cnts.keys():
            if cnts[i] > n / k:
                result.append(i)

        return result
