# Time:  O(n)
# Space: O(n)

# stack, greedy
class Solution(object):
    def canRemoveAll(self, types, colors, groupSize):
        """
        :type types: List[int]
        :type colors: List[int]
        :type groupSize: List[int]
        :rtype: bool
        """
        stk = []
        for i in xrange(len(types)):
            if not (stk and types[stk[-1][0]] == types[i] and colors[stk[-1][0]] == colors[i]):
                stk.append([i, 0])
            stk[-1][1] += 1
            if stk[-1][1] == groupSize[types[i]]:
                stk.pop()
        return not stk
