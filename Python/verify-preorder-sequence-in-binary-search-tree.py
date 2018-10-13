# Time:  O(n)
# Space: O(1)

class Solution(object):
    # @param {integer[]} preorder
    # @return {boolean}
    def verifyPreorder(self, preorder):
        low, i = float("-inf"), -1
        for p in preorder:
            if p < low:
                return False
            while i >= 0 and p > preorder[i]:
                low = preorder[i]
                i -= 1
            i += 1
            preorder[i] = p
        return True

# Time:  O(n)
# Space: O(h)
class Solution2(object):
    # @param {integer[]} preorder
    # @return {boolean}
    def verifyPreorder(self, preorder):
        low = float("-inf")
        path = []
        for p in preorder:
            if p < low:
                return False
            while path and p > path[-1]:
                low = path[-1]
                path.pop()
            path.append(p)
        return True

