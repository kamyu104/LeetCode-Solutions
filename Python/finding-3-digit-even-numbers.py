# Time:  O(n), n is 10^3
# Space: O(1)

import collections


class Solution(object):
    def findEvenNumbers(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        result, cnt = [], collections.Counter(digits)
        for i in xrange(1, 10):
            for j in xrange(10):
                for k in xrange(0, 10, 2):
                    if cnt[i] > 0 and cnt[j] > (i == j) and cnt[k] > (k == i) + (k == j):
                        result.append(i*100 + j*10 + k)
        return result


# Time:  O(1) ~ O(nlogn), n is 10^3
# Space: O(1)
import collections


class Solution2(object):
    def findEvenNumbers(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        k = 3
        def backtracking(curr, digit_cnt, result):
            if len(curr) == k:
                result.append(reduce(lambda x, y: x*10+y, curr))
                return
            for i, (digit, cnt) in enumerate(digit_cnt):
                if (not curr and digit == 0) or (len(curr) == k-1 and digit%2 != 0):
                    continue
                digit_cnt[i][1] -= 1
                digit_cnt[i], digit_cnt[-1] = digit_cnt[-1], digit_cnt[i]
                removed = []
                if digit_cnt[-1][1] == 0:
                    removed = digit_cnt.pop()
                curr.append(digit)
                backtracking(curr, digit_cnt, result)
                curr.pop()
                if removed:
                    digit_cnt.append(removed)
                digit_cnt[i], digit_cnt[-1] = digit_cnt[-1], digit_cnt[i]
                digit_cnt[i][1] += 1

        cnt = collections.Counter(digits)
        digit_cnt = map(list, cnt.iteritems())
        result = []
        backtracking([], digit_cnt, result)
        result.sort()
        return result
