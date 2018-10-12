# Time:  O(n)
# Space: O(h)

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Solution(object):
    def constructFromPrePost(self, pre, post):
        """
        :type pre: List[int]
        :type post: List[int]
        :rtype: TreeNode
        """
        stack = [TreeNode(pre[0])]
        j = 0
        for i in xrange(1, len(pre)):
            node = TreeNode(pre[i])
            while stack[-1].val == post[j]:
                stack.pop()
                j += 1
            if not stack[-1].left:
                stack[-1].left = node
            else:
                stack[-1].right = node
            stack.append(node)
        return stack[0]


# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def constructFromPrePost(self, pre, post):
        """
        :type pre: List[int]
        :type post: List[int]
        :rtype: TreeNode
        """
        def constructFromPrePostHelper(pre, pre_s, pre_e, post, post_s, post_e, post_entry_idx_map):
            if pre_s >= pre_e or post_s >= post_e:
                return None
            node = TreeNode(pre[pre_s])
            if pre_e-pre_s > 1:
                left_tree_size = post_entry_idx_map[pre[pre_s+1]]-post_s+1
                node.left = constructFromPrePostHelper(pre, pre_s+1, pre_s+1+left_tree_size, 
                                                       post, post_s, post_s+left_tree_size,
                                                       post_entry_idx_map)
                node.right = constructFromPrePostHelper(pre, pre_s+1+left_tree_size, pre_e,
                                                        post, post_s+left_tree_size, post_e-1,
                                                        post_entry_idx_map)
            return node

        post_entry_idx_map = {}
        for i, val in enumerate(post):
            post_entry_idx_map[val] = i
        return constructFromPrePostHelper(pre, 0, len(pre), post, 0, len(post), post_entry_idx_map)

