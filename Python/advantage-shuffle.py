# Time:  O(nlogn)
# Space: O(n)

# Given two arrays A and B of equal size, the advantage of A with respect to B
# is the number of indices i for which A[i] > B[i].
#
# Return any permutation of A that maximizes its advantage with respect to B.
#
# Example 1:
#
# Input: A = [2,7,11,15], B = [1,10,4,11]
# Output: [2,11,7,15]
# Example 2:
#
# Input: A = [12,24,8,32], B = [13,25,32,11]
# Output: [24,32,8,12]
#
# Note:
# - 1 <= A.length = B.length <= 10000
# - 0 <= A[i] <= 10^9
# - 0 <= B[i] <= 10^9

class Solution(object):
    def advantageCount(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: List[int]
        """
        sortedA = sorted(A)
        sortedB = sorted(B)

        candidates = {b: [] for b in B}
        others = []
        j = 0
        for a in sortedA:
            if a > sortedB[j]:
                candidates[sortedB[j]].append(a)
                j += 1
            else:
                others.append(a)
        return [candidates[b].pop() if candidates[b] else others.pop()
                for b in B]
