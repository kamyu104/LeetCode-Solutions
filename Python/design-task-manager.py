# Time:  ctor:    O(tlogt)
#        add:     O(logt)
#        edit:    O(logt)
#        rmv:     O(logt)
#        execTop: O(logt)
# Space: O(t)

from sortedcontainers import SortedList


# sorted list
class TaskManager(object):

    def __init__(self, tasks):
        """
        :type tasks: List[List[int]]
        """
        self.__lookup = {}
        self.__sl = SortedList()
        for userId, taskId, priority in tasks:
            self.add(userId, taskId, priority)

    def add(self, userId, taskId, priority):
        """
        :type userId: int
        :type taskId: int
        :type priority: int
        :rtype: None
        """
        self.__sl.add((priority, taskId, userId))
        self.__lookup[taskId] = (userId, priority)

    def edit(self, taskId, newPriority):
        """
        :type taskId: int
        :type newPriority: int
        :rtype: None
        """
        userId, _ = self.__lookup[taskId]
        self.rmv(taskId)
        self.add(userId, taskId, newPriority)

    def rmv(self, taskId):
        """
        :type taskId: int
        :rtype: None
        """
        userId, priority = self.__lookup.pop(taskId)
        self.__sl.remove((priority, taskId, userId))

    def execTop(self):
        """
        :rtype: int
        """
        if not self.__sl:
            return -1
        _, taskId, userId = self.__sl[-1]
        self.rmv(taskId)
        return userId
