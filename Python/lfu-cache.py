# Time:  O(1), per operation
# Space: O(k), k is the capacity of cache

# Design and implement a data structure for Least Frequently Used (LFU) cache.
# It should support the following operations: get and put.
#
# get(key) - Get the value (will always be positive) of the key
# if the key exists in the cache, otherwise return -1.
# put(key, value) - Set or insert the value if the key is not already present.
# When the cache reaches its capacity,
# it should invalidate the least frequently used item before inserting a new item.
# For the purpose of this problem, when there is a tie
# (i.e., two or more keys that have the same frequency),
# the least recently used key would be evicted.
#
# Follow up:
# Could you do both operations in O(1) time complexity?
#
# Example:
#
# LFUCache cache = new LFUCache( 2 /* capacity */ );
#
# cache.put(1, 1);
# cache.put(2, 2);
# cache.get(1);       // returns 1
# cache.put(3, 3);    // evicts key 2
# cache.get(2);       // returns -1 (not found)
# cache.get(3);       // returns 3.
# cache.put(4, 4);    // evicts key 1.
# cache.get(1);       // returns -1 (not found)
# cache.get(3);       // returns 3
# cache.get(4);       // returns 4

import collections


class ListNode(object):
    def __init__(self, key, value, freq):
        self.key = key
        self.val = value
        self.freq = freq
        self.next = None
        self.prev = None


class LinkedList(object):
    def __init__(self):
        self.head = None
        self.tail = None

    def append(self, node):
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


class LFUCache(object):

    def __init__(self, capacity):
        """
        :type capacity: int
        """
        self.__capa = capacity
        self.__size = 0
        self.__min_freq = 0
        self.__freq_to_nodes = collections.defaultdict(LinkedList)
        self.__key_to_node = {}


    def get(self, key):
        """
        :type key: int
        :rtype: int
        """
        if key not in self.__key_to_node:
            return -1

        old_node = self.__key_to_node[key]
        self.__key_to_node[key] = ListNode(key, old_node.val, old_node.freq)
        self.__freq_to_nodes[old_node.freq].delete(old_node)
        if not self.__freq_to_nodes[self.__key_to_node[key].freq].head:
            del self.__freq_to_nodes[self.__key_to_node[key].freq]
            if self.__min_freq == self.__key_to_node[key].freq:
                self.__min_freq += 1

        self.__key_to_node[key].freq += 1
        self.__freq_to_nodes[self.__key_to_node[key].freq].append(self.__key_to_node[key])

        return self.__key_to_node[key].val


    def put(self, key, value):
        """
        :type key: int
        :type value: int
        :rtype: void
        """
        if self.__capa <= 0:
            return

        if self.get(key) != -1:
            self.__key_to_node[key].val = value
            return

        if self.__size == self.__capa:
            del self.__key_to_node[self.__freq_to_nodes[self.__min_freq].head.key]
            self.__freq_to_nodes[self.__min_freq].delete(self.__freq_to_nodes[self.__min_freq].head)
            if not self.__freq_to_nodes[self.__min_freq].head:
                del self.__freq_to_nodes[self.__min_freq]
            self.__size -= 1

        self.__min_freq = 1
        self.__key_to_node[key] = ListNode(key, value, self.__min_freq)
        self.__freq_to_nodes[self.__key_to_node[key].freq].append(self.__key_to_node[key])
        self.__size += 1

# Your LFUCache object will be instantiated and called as such:
# obj = LFUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
