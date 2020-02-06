# Time:  O(nlogn)
# Space: O(n)

# 1. other solution is to apply kasai's algorithm, refer to the link below:
# - https://leetcode.com/problems/longest-duplicate-substring/discuss/290852/Suffix-array-clear-solution
# 2. the best solution is to apply ukkonen's algorithm, refer to the link below:
# - https://leetcode.com/problems/longest-duplicate-substring/discuss/312999/best-java-on-complexity-and-on-space-solution-suffix-tree-67ms

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
            p = pow(D, L, M)
            curr = reduce(lambda x, y: (D*x+ord(y)-ord('a')) % M, S[:L], 0)
            lookup = collections.defaultdict(list)
            lookup[curr].append(L-1)
            for i in xrange(L, len(S)):
                curr = ((D*curr) % M + ord(S[i])-ord('a') -
                        ((ord(S[i-L])-ord('a'))*p) % M) % M
                if curr in lookup:
                    for j in lookup[curr]:  # check if string is the same when hash is the same
                        if S[j-L+1:j+1] == S[i-L+1:i+1]:
                            return i-L+1
                lookup[curr].append(i)
            return 0

        left, right = 1, len(S)-1
        while left <= right:
            mid = left + (right-left)//2
            if not check(S, mid):
                right = mid-1
            else:
                left = mid+1
        result = check(S, right)
        return S[result:result + right]
