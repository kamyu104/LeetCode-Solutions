# Time:  O(n)
# Space: O(h)

class Solution(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        def findBottomLeftValueHelper(root, curr_depth, max_depth, bottom_left_value):
            if not root:
                return max_depth, bottom_left_value
            if not root.left and not root.right and curr_depth+1 > max_depth:
                return curr_depth+1, root.val
            max_depth, bottom_left_value = findBottomLeftValueHelper(root.left, curr_depth+1, max_depth, bottom_left_value)
            max_depth, bottom_left_value = findBottomLeftValueHelper(root.right, curr_depth+1, max_depth, bottom_left_value)
            return max_depth, bottom_left_value

        result, max_depth = 0, 0
        return findBottomLeftValueHelper(root, 0, max_depth, result)[1]


# Time:  O(n)
# Space: O()
import collections


class Solution2(object):
    def findBottomLeftValue(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        last_node, q = None, collections.deque([root])
        while q:
            last_node = q.popleft()
            q.extend([n for n in [last_node.right, last_node.left] if n])
        return last_node.val

