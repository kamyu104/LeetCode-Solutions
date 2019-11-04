# Time:  O(logn) on average for each operation
# Space: O(n)

# see proof in references:
# 1. https://kunigami.blog/2012/09/25/skip-lists-in-python/
# 2. https://opendatastructures.org/ods-cpp/4_4_Analysis_Skiplists.html
# 3. https://brilliant.org/wiki/skip-lists/
import random


class SkipNode(object):
    def __init__(self, level=0, num=None):
        self.num = num
        self.nexts = [None]*level


class Skiplist(object):
    P_NUMERATOR, P_DENOMINATOR = 1, 2  # P = 1/4 in redis implementation
    MAX_LEVEL = 32  # enough for 2^32 elements

    def __init__(self):
        self.__head = SkipNode()
        self.__len = 0

    def search(self, target):
        """
        :type target: int
        :rtype: bool
        """
        return True if self.__find(target, self.__find_prev_nodes(target)) else False
        
    def add(self, num):
        """
        :type num: int
        :rtype: None
        """
        node = SkipNode(self.__random_level(), num)
        if len(self.__head.nexts) < len(node.nexts): 
            self.__head.nexts.extend([None]*(len(node.nexts)-len(self.__head.nexts)))
        prevs = self.__find_prev_nodes(num)
        for i in xrange(len(node.nexts)):
            node.nexts[i] = prevs[i].nexts[i]
            prevs[i].nexts[i] = node
        self.__len += 1

    def erase(self, num):
        """
        :type num: int
        :rtype: bool
        """
        prevs = self.__find_prev_nodes(num)
        curr = self.__find(num, prevs)
        if not curr:
            return False
        self.__len -= 1   
        for i in reversed(xrange(len(curr.nexts))):
            prevs[i].nexts[i] = curr.nexts[i]
            if not self.__head.nexts[i]:
                self.__head.nexts.pop()
        return True
    
    def __find(self, num, prevs):
        if prevs:
            candidate = prevs[0].nexts[0]
            if candidate and candidate.num == num:
                return candidate
        return None

    def __find_prev_nodes(self, num):
        prevs = [None]*len(self.__head.nexts)
        curr = self.__head
        for i in reversed(xrange(len(self.__head.nexts))):
            while curr.nexts[i] and curr.nexts[i].num < num:
                curr = curr.nexts[i]
            prevs[i] = curr
        return prevs

    def __random_level(self):
        level = 1
        while random.randint(1, Skiplist.P_DENOMINATOR) <= Skiplist.P_NUMERATOR and \
              level < Skiplist.MAX_LEVEL:
            level += 1
        return level

    def __len__(self):
        return self.__len
    
    def __str__(self):
        result = []
        for i in reversed(xrange(len(self.__head.nexts))):
            result.append([])
            curr = self.__head.nexts[i]
            while curr:
                result[-1].append(str(curr.num))
                curr = curr.nexts[i]
        return "\n".join(map(lambda x: "->".join(x), result))
