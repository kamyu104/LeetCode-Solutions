# Time:  O(logn) on average for each operation
# Space: O(n)

# see proof in reference : https://kunigami.blog/2012/09/25/skip-lists-in-python/

import random

class SkipNode(object):
    def __init__(self, height=0, num=None):
        self.num = num
        self.next = [None]*height


class Skiplist(object):
    P = 2

    def __init__(self):
        self.__head = SkipNode()
        self.__len = 0
        self.__max_height = 0

    def search(self, target):
        """
        :type target: int
        :rtype: bool
        """
        prev_nodes = self.__find_prev_nodes(target)
        return self.__find(target, prev_nodes)
        
    def add(self, num):
        """
        :type num: int
        :rtype: None
        """
        node = SkipNode(self.__random_height(), num)
        self.__max_height = max(self.__max_height, len(node.next))
        self.__head.next.extend([None]*(self.__max_height-len(self.__head.next)))
        prev_nodes = self.__find_prev_nodes(num)
        for i in xrange(len(node.next)):
            node.next[i] = prev_nodes[i].next[i]
            prev_nodes[i].next[i] = node
        self.__len += 1

    def erase(self, num):
        """
        :type num: int
        :rtype: bool
        """
        prev_nodes = self.__find_prev_nodes(num)
        curr_level_node = self.__find(num, prev_nodes)
        if not curr_level_node:
            return False
        self.__len -= 1   
        for i in reversed(xrange(len(curr_level_node.next))):
            prev_nodes[i].next[i] = curr_level_node.next[i]
            if not self.__head.next[i]:
                self.__max_height -= 1
                self.__head.next.pop()
        return True
    
    def __find(self, target, prev_nodes):
        """
        :type target: int
        :rtype: bool
        """
        if prev_nodes:
            candidate = prev_nodes[0].next[0]
            if candidate and candidate.num == target:
                return candidate
        return None

    def __find_prev_nodes(self, num):
        prev_nodes = {}
        curr_level_node = self.__head
        for i in reversed(xrange(self.__max_height)):
            while curr_level_node.next[i] and curr_level_node.next[i].num < num:
                curr_level_node = curr_level_node.next[i]
            prev_nodes[i] = curr_level_node
        return prev_nodes

    def __random_height(self):
        height = 1
        while random.randint(1, Skiplist.P) != 1:
            height += 1
        return height
    
    def __str__(self):
        result = []
        for i in reversed(xrange(len(self.__head.next))):
            result.append([])
            x = self.__head
            while x.next[i]:
                result[-1].append(str(x.next[i].num))
                x = x.next[i]
        return "\n".join(map(lambda x: "->".join(x), result))
