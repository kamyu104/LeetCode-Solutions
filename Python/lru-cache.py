# Time:  O(1), per operation.
# Space: O(k), k is the capacity of cache.

import collections


# using OrderedDict
class LRUCache(object):
    def __init__(self, capacity):
        self.cache = collections.OrderedDict()
        self.capacity = capacity

    def get(self, key):
        if key not in self.cache:
            return -1
        val = self.cache[key]
        self.__update(key, val)
        return val

    def put(self, key, val):
        if key not in self.cache and len(self.cache) == self.capacity:
            self.cache.popitem(last=False)
        self.__update(key, val)
    
    def __update(self, key, val):
        if key in self.cache:
            del self.cache[key]
        self.cache[key] = val


# Time:  O(1), per operation.
# Space: O(k), k is the capacity of cache.


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

class LRUCache2(object):

    def __init__(self, capacity):
        self.list = LinkedList()
        self.dict = {}
        self.capacity = capacity

    def get(self, key):
        if key not in self.dict:
            return -1
        val = self.dict[key].val
        self.__update(key, val)
        return val

    def put(self, key, val):
        if key not in self.dict and len(self.dict) == self.capacity:
            del self.dict[self.list.head.key]
            self.list.delete(self.list.head)
        self.__update(key, val)

    def __update(self, key, val):
        if key in self.dict:
            self.list.delete(self.dict[key])
        node = ListNode(key, val)
        self.list.insert(node)
        self.dict[key] = node
