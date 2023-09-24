# Time:  O(n)
# Space: O(n)

# mono stack
class Solution(object):
    def maximumSumOfHeights(self, maxHeights):
        """
        :type maxHeights: List[int]
        :rtype: int
        """
        left = [0]*len(maxHeights)
        stk = [-1]
        curr = 0
        for i in xrange(len(maxHeights)):
            while stk[-1] != stk[0] and maxHeights[stk[-1]] >= maxHeights[i]:
                j = stk.pop()
                curr -= (j-stk[-1])*maxHeights[j]
            curr += (i-stk[-1])*maxHeights[i]
            stk.append(i)
            left[i] = curr
        stk = [len(maxHeights)]
        result = right = curr = 0
        for i in reversed(xrange(len(maxHeights))):
            while stk[-1] != stk[0] and maxHeights[stk[-1]] >= maxHeights[i]:
                j = stk.pop()
                curr -= (stk[-1]-j)*maxHeights[j]
            curr += (stk[-1]-i)*maxHeights[i]
            stk.append(i)
            right = curr
            result = max(result, left[i]+right-maxHeights[i])
        return result
