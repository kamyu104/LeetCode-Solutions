# Time:  O(n)
# Space: O(1)
#
# Given an integer array of size n, 
# find all elements that appear more than [n/3] times. 
# The algorithm should run in linear time and in O(1) space.
#

class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def majorityElement(self, nums):
        k, n, hash = 3, len(nums), {}

        for i in nums:
            if i not in hash:
                hash[i] = 1
            else:
                hash[i] += 1
            # Detecting k items in hash, at least one of them must have exactly
            # one in it. We will discard those k items by one for each.
            # This action keeps the same mojority numbers in the remaining numbers.
            # Because if x / n  > 1 / k is true, then (x - 1) / (n - k) > 1 / k is also true.
            if len(hash) == k:
                for i in hash.keys():
                    if hash[i] == 0:
                        del hash[i]

        # Resets hash for the following counting.
        for i in hash.keys():
            hash[i] = 0

        # Counts the occurrence of each candidate integer.
        for i in nums:
            if i in hash:
                hash[i] += 1

        # Selects the integer which occurs > [n / k] times.
        ret = []
        for i in hash.keys():
            if hash[i] > n / k:
                ret.append(i)

        return ret
