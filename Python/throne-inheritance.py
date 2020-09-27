# Time:  ctor:    O(1)
#        birth:   O(1)
#        death:   O(1)
#        inherit: O(n)
# Space: O(n)

import collections


class ThroneInheritance(object):

    def __init__(self, kingName):
        """
        :type kingName: str
        """
        self.__king = kingName
        self.__family_tree = collections.defaultdict(list)
        self.__dead = set()
        

    def birth(self, parentName, childName):
        """
        :type parentName: str
        :type childName: str
        :rtype: None
        """
        self.__family_tree[parentName].append(childName)


    def death(self, name):
        """
        :type name: str
        :rtype: None
        """
        self.__dead.add(name)
        
    
    def getInheritanceOrder(self):
        """
        :rtype: List[str]
        """
        result = []
        stk = [self.__king]
        while stk:  # preorder traversal
            node = stk.pop()
            if node not in self.__dead:
                result.append(node)
            if node not in self.__family_tree:
                continue
            for child in reversed(self.__family_tree[node]):
                stk.append(child)
        return result

