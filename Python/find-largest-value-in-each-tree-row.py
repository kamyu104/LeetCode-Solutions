# Time:  O(n)
# Space: O(h)

class Solution(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        def largestValuesHelper(root, depth, result):
            if not root:
                return
            if depth == len(result):
                result.append(root.val)
            else:
                result[depth] = max(result[depth], root.val)
            largestValuesHelper(root.left, depth+1, result)
            largestValuesHelper(root.right, depth+1, result)

        result = []
        largestValuesHelper(root, 0, result)
        return result


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def largestValues(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        result = []
        curr = [root]
        while any(curr):
            result.append(max(node.val for node in curr))
            curr = [child for node in curr for child in (node.left, node.right) if child]
        return result


