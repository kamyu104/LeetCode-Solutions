# Time:  O(1)
# Space: O(n)

# Design a HashMap without using any built-in hash table libraries.
#
# To be specific, your design should include these two functions:
#
# put(key, value) : Insert a (key, value) pair into the HashMap.
#                   If the value already exists in the HashMap, update the value.
# get(key): Returns the value to which the specified key is mapped,
#           or -1 if this map contains no mapping for the key.
# remove(key) : Remove the mapping for the value key if this map contains the mapping for the key.
#
# Example:
#
# MyHashMap hashMap = new MyHashMap();
# hashMap.put(1, 1);          
# hashMap.put(2, 2);         
# hashMap.get(1);            // returns 1
# hashMap.get(3);            // returns -1 (not found)
# hashMap.put(2, 1);          // update the existing value
# hashMap.get(2);            // returns 1 
# hashMap.remove(2);          // remove the mapping for 2
# hashMap.get(2);            // returns -1 (not found) 
#
# Note:
# - All values will be in the range of [1, 1000000].
# - The number of operations will be in the range of [1, 10000].
# - Please do not use the built-in HashMap library.


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


class MyHashMap(object):

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.__data = [LinkedList() for _ in xrange(10000)]

    def put(self, key, value):
        """
        value will always be positive.
        :type key: int
        :type value: int
        :rtype: void
        """
        l = self.__data[key % len(self.__data)]
        node = l.find(key)
        if node:
            node.val = value
        else:
            l.insert(ListNode(key, value))

    def get(self, key):
        """
        Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key
        :type key: int
        :rtype: int
        """
        l = self.__data[key % len(self.__data)]
        node = l.find(key)
        if node:
            return node.val
        else:
            return -1

    def remove(self, key):
        """
        Removes the mapping of the specified value key if this map contains a mapping for the key
        :type key: int
        :rtype: void
        """
        l = self.__data[key % len(self.__data)]
        node = l.find(key)
        if node:
            l.delete(node)


# Your MyHashMap object will be instantiated and called as such:
# obj = MyHashMap()
# obj.put(key,value)
# param_2 = obj.get(key)
# obj.remove(key)
