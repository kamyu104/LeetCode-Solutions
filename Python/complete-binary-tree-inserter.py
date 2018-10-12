# Time:  ctor:     O(n)
#        insert:   O(1)
#        get_root: O(1)
# Space: O(n)

class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class CBTInserter(object):

    def __init__(self, root):
        """
        :type root: TreeNode
        """
        self.__tree = [root]
        for i in self.__tree:
            if i.left:
                self.__tree.append(i.left)
            if i.right:
                self.__tree.append(i.right)        

    def insert(self, v):
        """
        :type v: int
        :rtype: int
        """
        n = len(self.__tree)
        self.__tree.append(TreeNode(v))
        if n % 2:
            self.__tree[(n-1)//2].left = self.__tree[-1]
        else:
            self.__tree[(n-1)//2].right = self.__tree[-1]
        return self.__tree[(n-1)//2].val

    def get_root(self):
        """
        :rtype: TreeNode
        """
        return self.__tree[0]



