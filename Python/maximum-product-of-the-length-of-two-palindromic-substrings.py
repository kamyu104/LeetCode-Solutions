# Time:  O(n)
# Space: O(n)

import collections


class Solution(object):
    def maxProduct(self, s):
        """
        :type s: str
        :rtype: int
        """
        def manacher(s):
            s = '^#' + '#'.join(s) + '#$'
            P = [0]*len(s)
            C, R = 0, 0
            for i in xrange(1, len(s)-1):
                i_mirror = 2*C-i
                if R > i:
                    P[i] = min(R-i, P[i_mirror])
                while s[i+1+P[i]] == s[i-1-P[i]]:
                    P[i] += 1
                if i+P[i] > R:
                    C, R = i, i+P[i]
            return P

        P = manacher(s)
        q = collections.deque()
        left = [0]
        for i in xrange(len(s)):
            while q and q[0][1] < i:
                q.popleft()
            left.append(max(left[-1], 1+2*(i-q[0][0]) if q else 1))
            q.append((i, i+P[2*i+2]//2))
        q = collections.deque()
        result = right = 0
        for i in reversed(xrange(len(s))):
            while q and q[0][1] > i:
                q.popleft()
            right = max(right, 1+2*(q[0][0]-i) if q else 1)
            q.append((i, i-P[2*i+2]//2))
            result = max(result, left[i]*right)
        return result


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def maxProduct(self, s):
        """
        :type s: str
        :rtype: int
        """
        def manacher(s):
            s = '^#' + '#'.join(s) + '#$'
            P = [0]*len(s)
            C, R = 0, 0
            for i in xrange(1, len(s)-1):
                i_mirror = 2*C-i
                if R > i:
                    P[i] = min(R-i, P[i_mirror])
                while s[i+1+P[i]] == s[i-1-P[i]]:
                    P[i] += 1
                if i+P[i] > R:
                    C, R = i, i+P[i]
            return P

        import operator
        def accumulate(iterable, func=operator.add, initial=None):
            it = iter(iterable)
            total = initial
            if initial is None:
                try:
                    total = next(it)
                except StopIteration:
                    return
            yield total
            for element in it:
                total = func(total, element)
                yield total

        def fin_max_len(s):
            P = manacher(s)
            intervals = [[(i-2)//2-P[i]//2, (i-2)//2+P[i]//2] for i in xrange(2,len(P)-2, 2)]
            dp = [0]*len(s)
            for l, r in reversed(intervals): 
                dp[r] = r-l+1
            for i in reversed(xrange(len(s)-1)):
                dp[i] = max(dp[i], dp[i+1]-2)
            return list(accumulate(dp, max, 0))
        
        l1, l2 = fin_max_len(s), fin_max_len(s[::-1])[::-1]
        return max(x*y for x, y in itertools.izip(l1, l2))
