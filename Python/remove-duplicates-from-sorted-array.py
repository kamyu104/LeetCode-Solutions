# Time:  O(n)
# Space: O(1)

class Solution(object):
    # @param a list of integers
    # @return an integer
    def removeDuplicates(self, A):
        if not A:
            return 0

        last = 0
        for i in xrange(len(A)):
            if A[last] != A[i]:
                last += 1
                A[last] = A[i]
        return last + 1

