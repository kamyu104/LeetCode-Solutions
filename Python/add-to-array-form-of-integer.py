# Time:  O(n + logk)
# Space: O(1)

class Solution(object):
    def addToArrayForm(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: List[int]
        """
        A.reverse()
        carry, i = K, 0
        A[i] += carry
        carry, A[i] = divmod(A[i], 10)
        while carry:
            i += 1
            if i < len(A):
                A[i] += carry
            else:
                A.append(carry)
            carry, A[i] = divmod(A[i], 10)
        A.reverse()
        return A
