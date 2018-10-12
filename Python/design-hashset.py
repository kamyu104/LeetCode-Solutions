# Time:  O(1)
# Space: O(n)

class ListNode(object):
    def __init__(self, key, val):
        self.val = val
        self.key = key
        self.next = None
        self.prev = None


class LinkedList(object):
    def __init__(self):
        self.head = None
        self.tail = None

    def insert(self, node):
        node.next, node.prev = None, None  # avoid dirty node
        if self.head is None:
            self.head = node
        else:
            self.tail.next = node
            node.prev = self.tail
        self.tail = node

    def delete(self, node):
        if node.prev:
            node.prev.next = node.next
        else:
            self.head = node.next
        if node.next:
            node.next.prev = node.prev
        else:
            self.tail = node.prev
        node.next, node.prev = None, None  # make node clean

    def find(self, key):
        curr = self.head
        while curr:
            if curr.key == key:
                break
            curr = curr.next
        return curr


class MyHashSet(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__data = [LinkedList() for _ in xrange(10000)]

    def add(self, key):
        """
        :type key: int
        :rtype: void
        """
        l = self.__data[key % len(self.__data)]
        node = l.find(key)
        if not node:
            l.insert(ListNode(key, 0))

    def remove(self, key):
        """
        :type key: int
        :rtype: void
        """
        l = self.__data[key % len(self.__data)]
        node = l.find(key)
        if node:
            l.delete(node)

    def contains(self, key):
        """
        Returns true if this set did not already contain the specified element
        :type key: int
        :rtype: bool
        """
        l = self.__data[key % len(self.__data)]
        node = l.find(key)
        return node is not None



