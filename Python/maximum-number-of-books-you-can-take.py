# Time:  O(n)
# Space: O(n)

# mono stack
class Solution(object):
    def maximumBooks(self, books):
        """
        :type books: List[int]
        :rtype: int
        """
        def count(right, l):
            left = max(right-l+1, 0)
            return (left+right)*(right-left+1)//2
        
        result = curr = 0
        stk = [-1]
        for i in xrange(len(books)):
            while stk[-1] != -1 and books[stk[-1]] >= books[i]-(i-stk[-1]):
                j = stk.pop()
                curr -= count(books[j], j-stk[-1])
            curr += count(books[i], i-stk[-1])
            stk.append(i)
            result = max(result, curr)
        return result
