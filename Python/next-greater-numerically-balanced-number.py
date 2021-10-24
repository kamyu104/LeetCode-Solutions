# Time:  O(log110) = O(1)
# Space: O(110) = O(1)

import bisect


class Solution(object):
    def nextBeautifulNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        # obtained by generating all candidates' permutations in solution2
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

# Time:  O(l * p) = O(1), p is the count of permutations, l is the max length of numbers
# Space: O(c) = O(1)
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

        s = list(str(n))
        balanced = ['1',
                    '22',
                    '122', '333',
                    '1333', '4444',
                    '14444', '22333', '55555',
                    '122333', '155555', '224444', '666666']  # obtained by manually enumerating min number of permutations in each length
        result = 1224444
        for x in balanced:
            x = list(x)
            if len(x) < len(s):
                continue
            if len(x) > len(s):
                result = min(result, int("".join(x)))
                continue
            while True:
                d = int("".join(x))
                if d > n:
                    result = min(result, int("".join(x)))
                if not next_permutation(x, 0, len(x)):
                    break
        return result
