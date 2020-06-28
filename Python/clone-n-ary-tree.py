# Time:  O(n)
# Space: O(h)

# Definition for a Node.
class Node(object):
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children if children is not None else []


class Solution(object):
    def cloneTree(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        result = [None]
        stk = [(1, (root, result))]
        while stk:
            step, params = stk.pop()
            if step == 1:
                node, ret = params
                if not node:
                    continue
                ret[0] = Node(node.val)
                for child in reversed(node.children):
                    ret1 = [None]
                    stk.append((2, (ret1, ret)))
                    stk.append((1, (child, ret1)))
            else:
                ret1, ret = params
                ret[0].children.append(ret1[0])
        return result[0]


# Time:  O(n)
# Space: O(h)
class Solution2(object):
    def cloneTree(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        def dfs(node):
            if not node:
                return None
            copy = Node(node.val)
            for child in node.children:
                copy.children.append(dfs(child))
            return copy
        
        return dfs(root)
