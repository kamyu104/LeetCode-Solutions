# Time:  O(nlogn)
# Space: O(n)

class Solution(object):
    def oddEvenJumps(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        def findNext(idx):
            result = [None]*len(idx)
            stack = []
            for i in idx:
                while stack and stack[-1] < i:
                    result[stack.pop()] = i
                stack.append(i)
            return result
        
        idx = sorted(range(len(A)), key = lambda i: A[i])
        next_higher = findNext(idx)
        idx.sort(key = lambda i: -A[i])
        next_lower = findNext(idx)

        odd, even = [False]*len(A), [False]*len(A)
        odd[-1], even[-1] = True, True
        for i in reversed(xrange(len(A)-1)):
            if next_higher[i]:
                odd[i] = even[next_higher[i]]
            if next_lower[i]:
                even[i] = odd[next_lower[i]]
        return sum(odd)
