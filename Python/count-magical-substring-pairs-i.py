# Time:  O(26 * n)
# Space: O(n)

import bisect


# hash table
class Solution(object):
    def countMagicalPairs(self, s):
        nxt, lookup1 = [len(s)]*len(s), [len(s)]*26
        for i in reversed(xrange(len(s))):
            nxt[i] = lookup1[ord(s[i])-ord('a')]
            lookup1[ord(s[i])-ord('a')] = i
        right = [i for i in xrange(len(s)) if lookup1[ord(s[i])-ord('a')] == i]
        result = 0
        left, lookup2 = [], [-1]*26
        for i in xrange(len(s)-1):
            if lookup2[ord(s[i])-ord('a')] != -1:
                left.remove(lookup2[ord(s[i])-ord('a')])
            left.insert(0, i)
            lookup2[ord(s[i])-ord('a')] = i
            right.pop(0)
            if nxt[i] != len(s):
                bisect.insort(right, nxt[i])
            for d in xrange(min(len(left), len(right))):
                result += (left[d]-(left[d+1] if d+1 < len(left) else -1))*((right[d+1] if d+1 < len(right) else len(s))-right[d])
        return result


# Time:  O(26 * n)
# Space: O(26 * n)
# prefix sum, hash table
class Solution2(object):
    def countMagicalPairs(self, s):
        """
        :type s: str
        :rtype: int
        """
        right = [[] for _ in xrange(len(s))]
        order, lookup = [], [-1]*26
        for i in reversed(xrange(1, len(s))):
            if lookup[ord(s[i])-ord('a')] != -1:
                order.remove(s[i])
            order.insert(0, s[i])
            lookup[ord(s[i])-ord('a')] = i
            arr = [lookup[ord(x)-ord('a')] for x in order]
            right[i] = [(arr[j+1] if j+1 < len(arr) else len(s))-arr[j]
                        for j in xrange(len(arr))]
        result, order, lookup = 0, [], [-1]*26
        for i in xrange(len(s)-1):
            if lookup[ord(s[i])-ord('a')] != -1:
                order.remove(s[i])
            order.insert(0, s[i])
            lookup[ord(s[i])-ord('a')] = i
            arr = [lookup[ord(x)-ord('a')] for x in order]
            for j in xrange(min(len(arr), len(right[i+1]))):
                result += (arr[j]-(arr[j+1] if j+1 < len(arr) else -1))*right[i+1][j]
        return result


# Time:  O(n^2)
# Space: O(1)
# brute force, bitmasks
class Solution3(object):
    def countMagicalPairs(self, s):
        """
        :type s: str
        :rtype: int
        """
        result = 0
        for j in xrange(len(s)-1):
            left, mask = [], 0
            for i in reversed(xrange(j+1)):
                if not mask&(1<<(ord(s[i])-ord('a'))):
                    mask |= 1<<(ord(s[i])-ord('a'))
                    left.append(0)
                left[-1] += 1
            right, d, mask = 0, -1, 0
            for k in xrange(j+1, len(s)):
                if not mask&(1<<(ord(s[k])-ord('a'))):
                    if 0 <= d < len(left):
                        result += left[d]*right
                    mask |= 1<<(ord(s[k])-ord('a'))
                    right, d = 0, d+1
                right += 1
            if d < len(left):
                result += left[d]*right
        return result
