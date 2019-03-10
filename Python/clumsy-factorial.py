# Time:  O(1)
# Space: O(1)

# observation:
# i*(i-1)/(i-2) = i+1+2/(i-2)
#     if i = 3  => i*(i-1)/(i-2) = i + 3
#     if i = 4  => i*(i-1)/(i-2) = i + 2
#     if i >= 5 => i*(i-1)/(i-2) = i + 1
#
# clumsy(N):
#     if N = 1 => N
#     if N = 2 => N
#     if N = 3 => N + 3
#     if N = 4 => N + 2 + 1 = N + 3
#     if N > 4 and N % 4 == 1 => N + 1 + (... = 0) + 2 - 1           = N + 2
#     if N > 4 and N % 4 == 2 => N + 1 + (... = 0) + 3 - 2 * 1       = N + 2
#     if N > 4 and N % 4 == 3 => N + 1 + (... = 0) + 4 - 3 * 2 / 1   = N - 1
#     if N > 4 and N % 4 == 0 => N + 1 + (... = 0) + 5 - (4*3/2) + 1 = N + 1

class Solution(object):
    def clumsy(self, N):
        """
        :type N: int
        :rtype: int
        """
        if N <= 2:
            return N
        if N <= 4:
            return N+3
        
        if N % 4 == 0:
            return N+1
        elif N % 4 <= 2:
            return N+2
        return N-1
