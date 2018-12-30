# Time:  O(n)
# Space: O(h)

class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec(object):

    def encode(self, root):
        """Encodes an n-ary tree to a binary tree.
        
        :type root: Node
        :rtype: TreeNode
        """
        def encodeHelper(root, parent, index):
            if not root:
                return None
            node = TreeNode(root.val)
            if index+1 < len(parent.children):
                node.left = encodeHelper(parent.children[index+1], parent, index+1)
            if root.children:
                node.right = encodeHelper(root.children[0], root, 0)
            return node

        if not root:
            return None
        node = TreeNode(root.val)
        if root.children:
            node.right = encodeHelper(root.children[0], root, 0)
        return node

    def decode(self, data):
        """Decodes your binary tree to an n-ary tree.
        
        :type data: TreeNode
        :rtype: Node
        """
        def decodeHelper(root, parent):
            if not root:
                return
            children = []
            node = Node(root.val, children)
            decodeHelper(root.right, node)
            parent.children.append(node)
            decodeHelper(root.left, parent)

        if not data:
            return None
        children = []
        node = Node(data.val, children)
        decodeHelper(data.right, node)
        return node
        


