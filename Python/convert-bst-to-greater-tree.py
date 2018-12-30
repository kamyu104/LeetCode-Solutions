# Time:  O(n)
# Space: O(h)

class Solution(object):
    def convertBST(self, root):
        """
        :type root: TreeNode
        :rtype: TreeNode
        """
        def convertBSTHelper(root, cur_sum):
            if not root:
                return cur_sum

            if root.right:
                cur_sum = convertBSTHelper(root.right, cur_sum)
            cur_sum += root.val
            root.val = cur_sum
            if root.left:
                cur_sum = convertBSTHelper(root.left, cur_sum)
            return cur_sum

        convertBSTHelper(root, 0)
        return root

