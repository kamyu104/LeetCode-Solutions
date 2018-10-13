# Time:  O(n * 4^n / n^(3/2)) ~= n * Catalan numbers = n * (C(2n, n) - C(2n, n - 1)),
#                                due to the size of the results is Catalan numbers,
#                                and every way of evaluation is the length of the string,
#                                so the time complexity is at most n * Catalan numbers.
# Space: O(n * 4^n / n^(3/2)), the cache size of lookup is at most n * Catalan numbers.

import operator
import re


class Solution(object):
    # @param {string} input
    # @return {integer[]}
    def diffWaysToCompute(self, input):
        tokens = re.split('(\D)', input)
        nums = map(int, tokens[::2])
        ops = map({'+': operator.add, '-': operator.sub, '*': operator.mul}.get, tokens[1::2])
        lookup = [[None for _ in xrange(len(nums))] for _ in xrange(len(nums))]

        def diffWaysToComputeRecu(left, right):
            if left == right:
                return [nums[left]]
            if lookup[left][right]:
                return lookup[left][right]
            lookup[left][right] = [ops[i](x, y)
                                   for i in xrange(left, right)
                                   for x in diffWaysToComputeRecu(left, i)
                                   for y in diffWaysToComputeRecu(i + 1, right)]
            return lookup[left][right]

        return diffWaysToComputeRecu(0, len(nums) - 1)

class Solution2(object):
    # @param {string} input
    # @return {integer[]}
    def diffWaysToCompute(self, input):
        lookup = [[None for _ in xrange(len(input) + 1)] for _ in xrange(len(input) + 1)]
        ops = {'+': operator.add, '-': operator.sub, '*': operator.mul}

        def diffWaysToComputeRecu(left, right):
            if lookup[left][right]:
                return lookup[left][right]
            result = []
            for i in xrange(left, right):
                if input[i] in ops:
                    for x in diffWaysToComputeRecu(left, i):
                        for y in diffWaysToComputeRecu(i + 1, right):
                            result.append(ops[input[i]](x, y))

            if not result:
                result = [int(input[left:right])]
            lookup[left][right] = result
            return lookup[left][right]

        return diffWaysToComputeRecu(0, len(input))

