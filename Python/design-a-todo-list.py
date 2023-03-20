# Time:  ctor:           O(1)
#        addTask:        O(l + logn), n is the number of user's tasks, l is the max length of a task
#        getAllTasks:    O(r), r is the length of result
#        getTasksForTag: O(r * c), r is the length of result, c is the length of the tag
#        completeTask:   O(l + logn)
# Space: O(n * l)

from sortedcontainers import SortedList


# sortedlist
class TodoList(object):

    def __init__(self):
        self.__tasks = []
        self.__user_task_ids = collections.defaultdict(SortedList)

    def addTask(self, userId, taskDescription, dueDate, tags):
        """
        :type userId: int
        :type taskDescription: str
        :type dueDate: int
        :type tags: List[str]
        :rtype: int
        """
        self.__tasks.append([dueDate, taskDescription, set(tags)])
        self.__user_task_ids[userId].add((dueDate, len(self.__tasks)))
        return len(self.__tasks)

    def getAllTasks(self, userId):
        """
        :type userId: int
        :rtype: List[str]
        """
        if userId not in self.__user_task_ids:
            return []
        return [self.__tasks[i-1][1] for _, i in self.__user_task_ids[userId]]

    def getTasksForTag(self, userId, tag):
        """
        :type userId: int
        :type tag: str
        :rtype: List[str]
        """
        if userId not in self.__user_task_ids:
            return []
        return [self.__tasks[i-1][1] for _, i in self.__user_task_ids[userId] if tag in self.__tasks[i-1][-1]]

    def completeTask(self, userId, taskId):
        """
        :type userId: int
        :type taskId: int
        :rtype: None
        """
        if not (taskId-1 < len(self.__tasks) and userId in self.__user_task_ids):
            return
        self.__user_task_ids[userId].discard((self.__tasks[taskId-1][0], taskId))


# Time:  ctor:           O(1)
#        addTask:        O(l + t * logn), n is the number of user's tasks, l is the max length of a task, t is the number of tags
#        getAllTasks:    O(r), r is the length of result
#        getTasksForTag: O(r), r is the length of result
#        completeTask:   O(l + t * logn)
# Space: O(n * (l + t))
from sortedcontainers import SortedList


# sortedlist
class TodoList2(object):

    def __init__(self):
        self.__tasks = []
        self.__user_task_ids = collections.defaultdict(SortedList)

    def addTask(self, userId, taskDescription, dueDate, tags):
        """
        :type userId: int
        :type taskDescription: str
        :type dueDate: int
        :type tags: List[str]
        :rtype: int
        """
        self.__tasks.append([dueDate, taskDescription, set(tags)])
        self.__user_task_ids[userId].add((dueDate, len(self.__tasks)))
        for tag in self.__tasks[-1][-1]:
            self.__user_task_ids[userId, tag].add((dueDate, len(self.__tasks)))
        return len(self.__tasks)

    def getAllTasks(self, userId):
        """
        :type userId: int
        :rtype: List[str]
        """
        if userId not in self.__user_task_ids:
            return []
        return [self.__tasks[i-1][1] for _, i in self.__user_task_ids[userId]]

    def getTasksForTag(self, userId, tag):
        """
        :type userId: int
        :type tag: str
        :rtype: List[str]
        """
        if (userId, tag) not in self.__user_task_ids:
            return []
        return [self.__tasks[i-1][1] for _, i in self.__user_task_ids[userId, tag]]

    def completeTask(self, userId, taskId):
        """
        :type userId: int
        :type taskId: int
        :rtype: None
        """
        if not (taskId-1 < len(self.__tasks) and userId in self.__user_task_ids):
            return
        self.__user_task_ids[userId].discard((self.__tasks[taskId-1][0], taskId))
        for tag in self.__tasks[taskId-1][-1]:
            self.__user_task_ids[userId, tag].discard((self.__tasks[taskId-1][0], taskId))
