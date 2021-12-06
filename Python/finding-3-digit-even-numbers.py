# Time:  O(1) ~ O(n), n is 10^3
# Space: O(1)

class Solution(object):
    def findEvenNumbers(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        k = 3
        def backtracking(curr, cnt, result):
            if len(curr) == k:
                result.append(reduce(lambda x, y: x*10+y, curr))
                return
            for i, c in enumerate(cnt):
                if c == 0 or (not curr and i == 0) or (len(curr) == k-1 and i%2 != 0):
                    continue
                cnt[i] -= 1
                curr.append(i)
                backtracking(curr, cnt, result)
                curr.pop()
                cnt[i] += 1

        cnt = [0]*10
        for d in digits:
            cnt[d] += 1
        result = []
        backtracking([], cnt, result)
        return result


# Time:  O(n), n is 10^3
# Space: O(1)
import collections


class Solution2(object):
    def findEvenNumbers(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        result, cnt = [], collections.Counter(digits)
        for i in xrange(1, 10):
            for j in xrange(10):
                for k in xrange(0, 10, 2):
                    if cnt[i] > 0 and cnt[j] > (j == i) and cnt[k] > (k == i) + (k == j):
                        result.append(i*100 + j*10 + k)
        return result


# Time:  O(1) ~ O(n), n is 10^3
# Space: O(1)
import collections


class Node(object):
    def __init__(self, val=None, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right


class Solution3(object):
    def findEvenNumbers(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        k = 3
        def backtracking(curr, dummy, result):
            if len(curr) == k:
                result.append(reduce(lambda x, y: x*10+y, curr))
                return
            node = dummy.right
            while node:
                if (not curr and node.val[0] == 0) or (len(curr) == k-1 and node.val[0]%2 != 0):
                    node = node.right
                    continue
                node.val[1] -= 1
                if node.val[1] == 0:
                    if node.left:
                        node.left.right = node.right
                    if node.right:
                        node.right.left = node.left
                curr.append(node.val[0])
                backtracking(curr, dummy, result)
                curr.pop()
                if node.val[1] == 0:
                    if node.left:
                        node.left.right = node
                    if node.right:
                        node.right.left = node
                node.val[1] += 1
                node = node.right

        prev = dummy = Node()
        for digit, cnt in sorted(map(list, collections.Counter(digits).iteritems())):
            prev.right = Node(val=[digit, cnt], left=prev)
            prev = prev.right
        result = []
        backtracking([], dummy, result)
        return result


# Time:  O(1) ~ O(nlogn), n is 10^3
# Space: O(1)
import collections


class Solution4(object):
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
