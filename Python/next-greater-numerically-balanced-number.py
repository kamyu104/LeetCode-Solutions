# Time:  O(logc) = O(1)
# Space: O(c) = O(1)

import bisect


class Solution(object):
    def nextBeautifulNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        # precomputed by generating all balanced's permutations in solution2
        # candidates = sorted(set(int("".join(perm)) for x in [1, 22, 122, 333, 1333, 4444, 14444, 22333, 55555, 122333, 155555, 224444, 666666] for perm in itertools.permutations(str(x)))) + [1224444]
        candidates = [     1,     22,    122,    212,    221,    333  , 1333,   3133,   3313,   3331,
                        4444,  14444,  22333,  23233,  23323,  23332,  32233,  32323,  32332,  33223,
                       33232,  33322,  41444,  44144,  44414,  44441,  55555, 122333, 123233, 123323,
                      123332, 132233, 132323, 132332, 133223, 133232, 133322, 155555, 212333, 213233,
                      213323, 213332, 221333, 223133, 223313, 223331, 224444, 231233, 231323, 231332,
                      232133, 232313, 232331, 233123, 233132, 233213, 233231, 233312, 233321, 242444,
                      244244, 244424, 244442, 312233, 312323, 312332, 313223, 313232, 313322, 321233,
                      321323, 321332, 322133, 322313, 322331, 323123, 323132, 323213, 323231, 323312,
                      323321, 331223, 331232, 331322, 332123, 332132, 332213, 332231, 332312, 332321,
                      333122, 333212, 333221, 422444, 424244, 424424, 424442, 442244, 442424, 442442,
                      444224, 444242, 444422, 515555, 551555, 555155, 555515, 555551, 666666, 1224444]
        return candidates[bisect.bisect_right(candidates, n)]


# Time:  O(l * c) = O(1), c is the count of all balanced's permutations, l is the max length of permutations
# Space: O(l * b) = O(1), b is the count of balanced
class Solution2(object):
    def nextBeautifulNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        def next_permutation(nums, begin, end):
            def reverse(nums, begin, end):
                left, right = begin, end-1
                while left < right:
                    nums[left], nums[right] = nums[right], nums[left]
                    left += 1
                    right -= 1

            k, l = begin-1, begin
            for i in reversed(xrange(begin, end-1)):
                if nums[i] < nums[i+1]:
                    k = i
                    break
            else:
                reverse(nums, begin, end)
                return False
            for i in reversed(xrange(k+1, end)):
                if nums[i] > nums[k]:
                    l = i
                    break
            nums[k], nums[l] = nums[l], nums[k]
            reverse(nums, k+1, end)
            return True

        # obtained by manually enumerating min number of permutations in each length
        balanced = [1,
                    22,
                    122, 333,
                    1333, 4444,
                    14444, 22333, 55555,
                    122333, 155555, 224444, 666666]
        s = list(str(n))
        result = 1224444
        for x in balanced:
            x = list(str(x))
            if len(x) < len(s):
                continue
            if len(x) > len(s):
                result = min(result, int("".join(x)))
                continue
            while True:
                if x > s:
                    result = min(result, int("".join(x)))
                if not next_permutation(x, 0, len(x)):  # distinct permutations
                    break
        return result


# Time:  O(l * c) = O(1), c is the count of all balanced's permutations, l is the max length of permutations
# Space: O(l * b) = O(1), b is the count of balanced
import itertools


class Solution3(object):
    def nextBeautifulNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        # obtained by manually enumerating min number of permutations in each length
        balanced = [1,
                    22,
                    122, 333,
                    1333, 4444,
                    14444, 22333, 55555,
                    122333, 155555, 224444, 666666]
        s = tuple(str(n))
        result = 1224444
        for x in balanced:
            x = tuple(str(x))
            if len(x) < len(s):
                continue
            if len(x) > len(s):
                result = min(result, int("".join(x)))
                continue
            for perm in itertools.permutations(x):  # not distinct permutations
                if perm > s:
                    result = min(result, int("".join(perm)))
        return result
