# Time:  O(nlogr)
# Space: O(1)

class Solution(object):
    def kthSmallestPrimeFraction(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: List[int]
        """
        def check(mid, A, K, result):
            tmp = [0]*2
            count = 0
            j = 0
            for i in xrange(len(A)):
                while j < len(A):
                    if i < j and A[i] < A[j]*mid:
                        if tmp[0] == 0 or \
                           tmp[0]*A[j] < tmp[1]*A[i]:
                            tmp[0] = A[i]
                            tmp[1] = A[j]
                        break
                    j += 1
                count += len(A)-j
            if count == K:
                result[:] = tmp
            return count >= K

        result = []
        left, right = 0.0, 1.0
        while right-left > 1e-8:
            mid = left + (right-left) / 2.0
            if check(mid, A, K, result):
                right = mid
            else:
                left = mid
            if result:
                break
        return result

