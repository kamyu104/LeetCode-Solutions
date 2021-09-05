# Time:  ctor:    O(n)
#        lock:    O(1)
#        unlock:  O(1)
#        upgrade: O(n)
# Space: O(n)

class LockingTree(object):

    def __init__(self, parent):
        """
        :type parent: List[int]
        """
        self.__parent = parent
        self.__children = [[] for _ in xrange(len(parent))]
        for i, x in enumerate(parent):
            if x != -1:
                self.__children[x].append(i)
        self.__locked = {}

    def lock(self, num, user):
        """
        :type num: int
        :type user: int
        :rtype: bool
        """
        if num in self.__locked:
            return False
        self.__locked[num] = user
        return True

    def unlock(self, num, user):
        """
        :type num: int
        :type user: int
        :rtype: bool
        """
        if self.__locked.get(num) != user:
            return False
        del self.__locked[num]
        return True

    def upgrade(self, num, user):
        """
        :type num: int
        :type user: int
        :rtype: bool
        """
        node = num
        while node != -1:
            if node in self.__locked:
                return False
            node = self.__parent[node]
        result = False
        stk = [num]
        while stk:
            node = stk.pop()
            if node in self.__locked:
                del self.__locked[node]
                result = True
            for child in self.__children[node]:
                stk.append(child)
        if result:
            self.__locked[num] = user
        return result
