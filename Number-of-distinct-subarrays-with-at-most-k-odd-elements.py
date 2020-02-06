# Time:  O(n^2)
# Space: O(t), t is the size of trie

import collections


class Solution(object):
    def distinctSubarraysWithKOdds(self, A, K):
        def countDistinct(A, left, right, trie):  # Time: O(n), Space: O(t)
            result = 0
            for i in xrange(left, right):
                if A[i] not in trie:
                    result += 1
                trie = trie[A[i]]
            return result
        
        def atMostK(A, K):  # Time: O(n^2), Space: O(t)
            _trie = lambda: collections.defaultdict(_trie)
            trie = _trie()
            result, left, count = 0, 0, 0
            for right in xrange(len(A)):
                count += A[right]%2
                while count > K:
                    result += countDistinct(A, left, right, trie)
                    count -= A[left]%2
                    left += 1
            for i in xrange(left, len(A)):
                result += countDistinct(A, i, len(A), trie)
            return result
        
        return atMostK(A, K)

sol = Solution()
cases = [([3, 2, 3, 4], 1),
         ([1, 3, 9, 5], 2),
         ([3, 2, 3, 2], 1),
         ([2, 2, 5, 6, 9, 2, 11, 9, 2, 11, 12], 1)]
for t in cases:
    print sol.distinctSubarraysWithKOdds(*t)
