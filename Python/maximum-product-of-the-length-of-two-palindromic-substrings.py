# Time:  O(n)
# Space: O(n)

# manacher
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

        def accumulate(arr, fn):
            curr = arr[0]
            yield curr
            for i in xrange(1, len(arr)):
                curr = fn(curr, arr[i])
                yield curr

        def find_max_len(s):
            P = manacher(s)
            intervals = [[(i-2)//2-P[i]//2, (i-2)//2+P[i]//2] for i in xrange(2,len(P)-2, 2)]
            dp = [0]*len(s)
            for l, r in reversed(intervals): 
                dp[r] = r-l+1
            for i in reversed(xrange(len(s)-1)):
                dp[i] = max(dp[i], dp[i+1]-2)
            return list(accumulate(dp[:-1], max))
        
        l1, l2 = find_max_len(s), find_max_len(s[::-1])[::-1]
        return max(x*y for x, y in itertools.izip(l1, l2))
