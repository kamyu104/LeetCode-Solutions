# Time:  O(n)
# Space: O(h)

class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children


class Codec(object):

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: Node
        :rtype: str
        """
        def dfs(node, vals):
            if not node:
                return
            vals.append(str(node.val))
            for child in node.children:
                dfs(child, vals)
            vals.append("#")
        
        vals = []
        dfs(root, vals)
        return " ".join(vals)


    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: Node
        """
        def isplit(source, sep):
            sepsize = len(sep)
            start = 0
            while True:
                idx = source.find(sep, start)
                if idx == -1:
                    yield source[start:]
                    return
                yield source[start:idx]
                start = idx + sepsize
                
        def dfs(vals):
            val = next(vals)
            if val == "#":
                return None
            root = Node(int(val), [])
            child = dfs(vals)
            while child:
                root.children.append(child)
                child = dfs(vals)
            return root

        if not data:
            return None
    
        return dfs(iter(isplit(data, ' ')))
        


