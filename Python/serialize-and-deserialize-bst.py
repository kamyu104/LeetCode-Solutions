# Time:  O(n)
# Space: O(h)

import collections


class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None


class Codec(object):

    def serialize(self, root):
        """Encodes a tree to a single string.

        :type root: TreeNode
        :rtype: str
        """
        def serializeHelper(node, vals):
            if node:
                vals.append(node.val)
                serializeHelper(node.left, vals)
                serializeHelper(node.right, vals)

        vals = []
        serializeHelper(root, vals)

        return ' '.join(map(str, vals))


    def deserialize(self, data):
        """Decodes your encoded data to tree.

        :type data: str
        :rtype: TreeNode
        """
        def deserializeHelper(minVal, maxVal, vals):
            if not vals:
                return None

            if minVal < vals[0] < maxVal:
                val = vals.popleft()
                node = TreeNode(val)
                node.left = deserializeHelper(minVal, val, vals)
                node.right = deserializeHelper(val, maxVal, vals)
                return node
            else:
                return None

        vals = collections.deque([int(val) for val in data.split()])

        return deserializeHelper(float('-inf'), float('inf'), vals)



