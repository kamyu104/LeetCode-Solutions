# Time:  O(1)
# Space: O(k)

# Design your implementation of the circular double-ended queue (deque).
# Your implementation should support following operations:
#
# MyCircularDeque(k): Constructor, set the size of the deque to be k.
# insertFront(): Adds an item at the front of Deque. Return true if the operation is successful.
# insertLast(): Adds an item at the rear of Deque. Return true if the operation is successful.
# deleteFront(): Deletes an item from the front of Deque. Return true if the operation is successful.
# deleteLast(): Deletes an item from the rear of Deque. Return true if the operation is successful.
# getFront(): Gets the front item from the Deque. If the deque is empty, return -1.
# getRear(): Gets the last item from Deque. If the deque is empty, return -1.
# isEmpty(): Checks whether Deque is empty or not. 
# isFull(): Checks whether Deque is full or not.
#
# Example:
#
# MyCircularDeque circularDeque = new MycircularDeque(3); // set the size to be 3
# circularDeque.insertLast(1);			// return true
# circularDeque.insertLast(2);			// return true
# circularDeque.insertFront(3);			// return true
# circularDeque.insertFront(4);			// return false, the queue is full
# circularDeque.getRear();  				// return 32
# circularDeque.isFull();				// return true
# circularDeque.deleteLast();			// return true
# circularDeque.insertFront(4);			// return true
# circularDeque.getFront();				// return 4
#
# Note:
# - All values will be in the range of [1, 1000].
# - The number of operations will be in the range of [1, 1000].
# - Please do not use the built-in Deque library.

class MyCircularDeque(object):

    def __init__(self, k):
        """
        Initialize your data structure here. Set the size of the deque to be k.
        :type k: int
        """
        self.__start = 0
        self.__size = 0
        self.__buffer = [0] * k

    def insertFront(self, value):
        """
        Adds an item at the front of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False
        self.__start = (self.__start-1) % len(self.__buffer)
        self.__buffer[self.__start] = value
        self.__size += 1
        return True

    def insertLast(self, value):
        """
        Adds an item at the rear of Deque. Return true if the operation is successful.
        :type value: int
        :rtype: bool
        """
        if self.isFull():
            return False
        self.__buffer[(self.__start+self.__size) % len(self.__buffer)] = value
        self.__size += 1
        return True

    def deleteFront(self):
        """
        Deletes an item from the front of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.isEmpty():
            return False
        self.__start = (self.__start+1) % len(self.__buffer)
        self.__size -= 1
        return True

    def deleteLast(self):
        """
        Deletes an item from the rear of Deque. Return true if the operation is successful.
        :rtype: bool
        """
        if self.isEmpty():
            return False
        self.__size -= 1
        return True

    def getFront(self):
        """
        Get the front item from the deque.
        :rtype: int
        """
        return -1 if self.isEmpty() else self.__buffer[self.__start]

    def getRear(self):
        """
        Get the last item from the deque.
        :rtype: int
        """
        return -1 if self.isEmpty() else self.__buffer[(self.__start+self.__size-1) % len(self.__buffer)]

    def isEmpty(self):
        """
        Checks whether the circular deque is empty or not.
        :rtype: bool
        """
        return self.__size == 0

    def isFull(self):
        """
        Checks whether the circular deque is full or not.
        :rtype: bool
        """
        return self.__size == len(self.__buffer)


# Your MyCircularDeque object will be instantiated and called as such:
# obj = MyCircularDeque(k)
# param_1 = obj.insertFront(value)
# param_2 = obj.insertLast(value)
# param_3 = obj.deleteFront()
# param_4 = obj.deleteLast()
# param_5 = obj.getFront()
# param_6 = obj.getRear()
# param_7 = obj.isEmpty()
# param_8 = obj.isFull()
