# Time:  O(nlogn)
# Space: O(n)

import collections


class Solution(object):
    def longestRepeatingSubstring(self, S):
        """
        :type S: str
        :rtype: int
        """
        M = 10**9+7
        D = 26

        def check(S, L):
            p = pow(D, L, M)
            curr = reduce(lambda x, y: (D*x+ord(y)-ord('a')) % M, S[:L], 0)
            lookup = collections.defaultdict(list)
            lookup[curr].append(L-1)
            result = 0
            for i in xrange(L, len(S)):
                curr = ((D*curr) % M + ord(S[i])-ord('a') -
                        ((ord(S[i-L])-ord('a'))*p) % M) % M
                if curr in lookup:
                    for j in lookup[curr]:
                        if S[j-L+1:j+1] == S[i-L+1:i+1]:
                            if result == 0:
                                result = i
                            return result-L+1
                lookup[curr].append(i)
            return result

        left, right = 0, len(S)-1
        while left <= right:
            mid = left + (right-left)//2
            if not check(S, mid):
                right = mid-1
            else:
                left = mid+1
        return right
        
