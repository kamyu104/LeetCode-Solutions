# Time:  O(n + 26^3 * logn)
# Space: O(n)

import bisect


# hash table, binary search
class Solution(object):
    def maxSubstringLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        def check(left, right):
            for x in idxs:
                if not x or x[-1] < left or x[0] > right or (left <= x[0] and x[-1] <= right):
                    continue
                i = bisect.bisect_left(x, left)
                if i != len(x) and x[i] <= right:
                    return False
            return True

        idxs = [[] for _ in xrange(26)]
        for i, x in enumerate(s):
            idxs[ord(x)-ord('a')].append(i)
        result = -1
        for x in idxs:
            if not x:
                continue
            left = x[0]
            for y in idxs:
                if not y:
                    continue
                right = y[-1]
                if left <= right and result < right-left+1 != len(s) and check(left, right):
                    result = right-left+1
        return result


# Time:  O(n + 26^3 * logn)
# Space: O(n)
import bisect


# hash table, binary search
class Solution2(object):
    def maxSubstringLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        def check(left, right):
            for x in idxs:
                if not x:
                    continue
                l = bisect.bisect_left(x, left)
                r = bisect.bisect_right(x, right)-1
                if not (r-l+1 == len(x) or r-l+1 == 0):
                    return False
            return True

        idxs = [[] for _ in xrange(26)]
        for i, x in enumerate(s):
            idxs[ord(x)-ord('a')].append(i)
        result = -1
        for x in idxs:
            if not x:
                continue
            left = x[0]
            for y in idxs:
                if not y:
                    continue
                right = y[-1]
                if left <= right and right-left+1 != len(s) and check(left, right):
                    result = max(result, right-left+1)
        return result


# Time:  O(26 * n)
# Space: O(26)
# freq table, two pointers
class Solution3(object):
    def maxSubstringLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        def update(x, d, distinct, valid):
            x = ord(x)-ord('a')
            if cnt2[x] == cnt[x]:
                valid -= 1
            if cnt2[x] == 0:
                distinct += 1
            cnt2[x] += d
            if cnt2[x] == 0:
                distinct -= 1
            if cnt2[x] == cnt[x]:
                valid += 1
            return distinct, valid
                
        cnt = [0]*26
        for x in s:
            cnt[ord(x)-ord('a')] += 1
        result = -1
        for l in xrange(1, sum(x != 0 for x in cnt)):
            cnt2 = [0]*26
            left = distinct = valid = 0
            for right in xrange(len(s)):
                distinct, valid = update(s[right], +1, distinct, valid)
                while distinct == l+1:
                    distinct, valid = update(s[left], -1, distinct, valid)
                    left += 1
                if valid == l:
                    result = max(result, right-left+1)
        return result


# Time:  O(26^2 * n)
# Space: O(26)
# hash table, brute force
class Solution5(object):
    def maxSubstringLength(self, s):
        """
        :type s: str
        :rtype: int
        """
        def check(l, r):
            return all(l <= left[ord(s[i])-ord('a')] and right[ord(s[i])-ord('a')] <= r for i in xrange(l, r+1))

        left, right = [-1]*26, [-1]*26
        for i, x in enumerate(s):
            x = ord(x)-ord('a')
            if left[x] == -1:
                left[x] = i
            right[x] = i
        result = -1
        for l in left:
            if l == -1:
                continue
            for r in right:
                if r == -1:
                    continue
                if l <= r and result < r-l+1 != len(s) and check(l, r):
                    result = r-l+1
        return result
