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

class LRUCache(object):

    # @param capacity, an integer
    def __init__(self, capacity):
        self.list = LinkedList()
        self.dict = {}
        self.capacity = capacity

    def _insert(self, key, val):
        node = ListNode(key, val)
        self.list.insert(node)
        self.dict[key] = node


    # @return an integer
    def get(self, key):
        if key in self.dict:
            val = self.dict[key].val
            self.list.delete(self.dict[key])
            self._insert(key, val)
            return val
        return -1


    # @param key, an integer
    # @param value, an integer
    # @return nothing
    def put(self, key, val):
        if key in self.dict:
            self.list.delete(self.dict[key])
        elif len(self.dict) == self.capacity:
            del self.dict[self.list.head.key]
            self.list.delete(self.list.head)
        self._insert(key, val)


import collections
class LRUCache2(object):
    def __init__(self, capacity):
        self.cache = collections.OrderedDict()
        self.capacity = capacity

    def get(self, key):
        if key not in self.cache:
            return -1
        val = self.cache[key]
        del self.cache[key]
        self.cache[key] = val
        return val

    def put(self, key, value):
        if key in self.cache:
            del self.cache[key]
        elif len(self.cache) == self.capacity:
            self.cache.popitem(last=False)
        self.cache[key] = value


