# Time:  O(1)
# Space: O(k)

class MyCircularQueue(object):

    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the queue to be k.
        :type k: int
        """
        self.__start = 0
        self.__size = 0
        self.__buffer = [0] * k

    def enQueue(self, value):
        """
        Insert an element into the circular queue. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False
        self.__buffer[(self.__start+self.__size) % len(self.__buffer)] = value
        self.__size += 1
        return True

    def deQueue(self):
        """
        Delete an element from the circular queue. Return true if the operation is successful.
        :rtype: bool
        """
        if self.isEmpty():
            return False
        self.__start = (self.__start+1) % len(self.__buffer)
        self.__size -= 1
        return True

    def Front(self):
        """
        Get the front item from the queue.
        :rtype: int
        """
        return -1 if self.isEmpty() else self.__buffer[self.__start]

    def Rear(self):
        """
        Get the last item from the queue.
        :rtype: int
        """
        return -1 if self.isEmpty() else self.__buffer[(self.__start+self.__size-1) % len(self.__buffer)]

    def isEmpty(self):
        """
        Checks whether the circular queue is empty or not.
        :rtype: bool
        """
        return self.__size == 0

    def isFull(self):
        """
        Checks whether the circular queue is full or not.
        :rtype: bool
        """
        return self.__size == len(self.__buffer)



