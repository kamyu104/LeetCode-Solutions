# Time:  O(n)
# Space: O(n)

class Node(object):
    def __init__(self, value):
        self.val = value
        self.next = self.prev = None


class MyLinkedList(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__head = self.__tail = Node(-1)
        self.__head.next = self.__tail
        self.__tail.prev = self.__head
        self.__size = 0

    def get(self, index):
        """
        Get the value of the index-th node in the linked list. If the index is invalid, return -1.
        :type index: int
        :rtype: int
        """
        if 0 <= index <= self.__size // 2:
            return self.__forward(0, index, self.__head.next).val
        elif self.__size // 2 < index < self.__size:
            return self.__backward(self.__size, index, self.__tail).val
        return -1

    def addAtHead(self, val):
        """
        Add a node of value val before the first element of the linked list.
        After the insertion, the new node will be the first node of the linked list.
        :type val: int
        :rtype: void
        """
        self.__add(self.__head, val)

    def addAtTail(self, val):
        """
        Append a node of value val to the last element of the linked list.
        :type val: int
        :rtype: void
        """
        self.__add(self.__tail.prev, val)

    def addAtIndex(self, index, val):
        """
        Add a node of value val before the index-th node in the linked list.
        If index equals to the length of linked list,
        the node will be appended to the end of linked list.
        If index is greater than the length, the node will not be inserted.
        :type index: int
        :type val: int
        :rtype: void
        """
        if 0 <= index <= self.__size // 2:
            self.__add(self.__forward(0, index, self.__head.next).prev, val)
        elif self.__size // 2 < index <= self.__size:
            self.__add(self.__backward(self.__size, index, self.__tail).prev, val)

    def deleteAtIndex(self, index):
        """
        Delete the index-th node in the linked list, if the index is valid.
        :type index: int
        :rtype: void
        """
        if 0 <= index <= self.__size // 2:
            self.__remove(self.__forward(0, index, self.__head.next))
        elif self.__size // 2 < index < self.__size:
            self.__remove(self.__backward(self.__size, index, self.__tail))

    def __add(self, preNode, val):
        node = Node(val)
        node.prev = preNode
        node.next = preNode.next
        node.prev.next = node.next.prev = node
        self.__size += 1
        
    def __remove(self, node):
        node.prev.next = node.next
        node.next.prev = node.prev
        self.__size -= 1
        
    def __forward(self, start, end, curr):
        while start != end:
            start += 1
            curr = curr.next
        return curr
    
    def __backward(self, start, end, curr):
        while start != end:
            start -= 1
            curr = curr.prev
        return curr



