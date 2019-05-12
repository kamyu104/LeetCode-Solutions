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

        def check(A, L):
            if L < 0:
                print L
            p = pow(D, L, M)
            curr = reduce(lambda x, y: (D*x + y) % M, A[:L], 0)
            lookup = collections.defaultdict(list)
            lookup[curr].append(L-1)
            for i in xrange(L, len(S)):
                curr = (D*curr + A[i] - A[i-L]*p) % M
                if curr in lookup:
                    for j in lookup[curr]:  # check if same string when hash is the smae
                        if A[j-L+1:j+1] == A[i-L+1:i+1]:
                            return i-L+1
                lookup[curr].append(i)
            return 0

        A = [ord(c)-ord('a') for c in S]
        result, left, right = 0, 0, len(S)
        while left <= right:
            mid = left + (right-left)//2
            if not check(A, mid):
                right = mid-1
            else:
                left = mid+1
        result = check(A, right)
        return S[result:result+right]
