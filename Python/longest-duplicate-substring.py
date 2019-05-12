# Time:  O(nlogn)
# Space: O(n)

import collections


class Solution(object):
    def longestDupSubstring(self, S):
        """
        :type S: str
        :rtype: str
        """
        M = 10**9+7
        D = 26

        def check(S, L):
            if L < 0:
                print L
            p = pow(D, L, M)
            curr = reduce(lambda x, y: (D*x+ord(y)-ord('a')) % M, S[:L], 0)
            lookup = collections.defaultdict(list)
            lookup[curr].append(L-1)
            for i in xrange(L, len(S)):
                curr = ((D*curr) % M + ord(S[i])-ord('a') -
                        ((ord(S[i-L])-ord('a'))*p) % M) % M
                if curr in lookup:
                    for j in lookup[curr]:  # check if same string when hash is the same
                        if S[j-L+1:j+1] == S[i-L+1:i+1]:
                            return i-L+1
                lookup[curr].append(i)
            return 0

        left, right = 0, len(S)-1
        while left <= right:
            mid = left + (right-left)//2
            if not check(S, mid):
                right = mid-1
            else:
                left = mid+1
        result = check(S, right)
        return S[result:result + right]
