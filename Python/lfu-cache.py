# Time:  O(1), per operation
# Space: O(k), k is the capacity of cache

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


