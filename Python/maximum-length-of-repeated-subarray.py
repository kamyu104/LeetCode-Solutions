# Time:  O(m * n)
# Space: O(min(m, n))

import collections


class Solution(object):
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        if len(A) < len(B): return self.findLength(B, A)
        result = 0
        dp = [[0] * (len(B)+1) for _ in xrange(2)]
        for i in xrange(len(A)):
            for j in xrange(len(B)):
                if A[i] == B[j]:
                    dp[(i+1)%2][j+1] = dp[i%2][j]+1
                else:
                    dp[(i+1)%2][j+1] = 0
            result = max(result, max(dp[(i+1)%2]))
        return result


# Time:  O(m * n * log(min(m, n)))
# Space: O(min(m, n))
# Binary search + rolling hash solution (226 ms)
class Solution2(object):
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        if len(A) > len(B): return self.findLength(B, A)
        M, p = 10**9+7, 113
        p_inv = pow(p, M-2, M)
        def check(guess):
            def rolling_hashes(source, length):
                if length == 0:
                    yield 0, 0
                    return

                val, power = 0, 1
                for i, x in enumerate(source):
                    val = (val + x*power) % M
                    if i < length - 1:
                        power = (power*p) % M
                    else:
                        yield val, i-(length-1)
                        val = (val-source[i-(length-1)])*p_inv % M

            hashes = collections.defaultdict(list)
            for hash_val, i in rolling_hashes(A, guess):
                hashes[hash_val].append(i)
            for hash_val, j in rolling_hashes(B, guess):
                if any(A[i:i+guess] == B[j:j+guess] for i in hashes[hash_val]):
                    return True
            return False

        left, right = 0, min(len(A), len(B)) + 1
        while left < right:
            mid = left + (right-left)/2
            if not check(mid):  # find the min idx such that check(idx) == false
                right = mid
            else:
                left = mid+1
        return left-1


# Time:  O(m * n * min(m, n) * log(min(m, n)))
# Space: O(min(m^2, n^2))
# Binary search (122 ms)
class Solution3(object):
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        if len(A) > len(B): return self.findLength(B, A)

        def check(length):
            lookup = set(A[i:i+length] \
                       for i in xrange(len(A)-length+1))
            return any(B[j:j+length] in lookup \
                       for j in xrange(len(B)-length+1))

        A = ''.join(map(chr, A))
        B = ''.join(map(chr, B))
        left, right = 0, min(len(A), len(B)) + 1
        while left < right:
            mid = left + (right-left)/2
            if not check(mid):  # find the min idx such that check(idx) == false
                right = mid
            else:
                left = mid+1
        return left-1

