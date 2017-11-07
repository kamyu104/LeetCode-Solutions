# Time:  push:    O(1)
#        pop:     O(n), there is no built-in SortedDict in python. If applied, it could be reduced to O(logn)
#        popMax:  O(n)
#        top:     O(1)
#        peekMax: O(1)
# Space: O(n), n is the number of values in the current stack
    
class MaxStack(object):

    def __init__(self):
        """
        initialize your data structure here.
        """
        self.__idx_to_val = collections.defaultdict(int)
        self.__val_to_idxs = collections.defaultdict(list)
        self.__top = None
        self.__max = None
        

    def push(self, x):
        """
        :type x: int
        :rtype: void
        """
        idx = (self.__val_to_idxs[self.__top][-1]+1) if self.__val_to_idxs else 0
        self.__idx_to_val[idx] = x
        self.__val_to_idxs[x].append(idx)
        self.__top = x
        self.__max = max(self.__max, x)


    def pop(self):
        """
        :rtype: int
        """
        val = self.__top
        self.remove(val)
        return val
    

    def top(self):
        """
        :rtype: int
        """
        return  self.__top

    
    def peekMax(self):
        """
        :rtype: int
        """
        return  self.__max

    
    def popMax(self):
        """
        :rtype: int
        """
        val = self.__max
        self.remove(val)
        return val
    
        
    def remove(self, val):
        idx = self.__val_to_idxs[val][-1]
        self.__val_to_idxs[val].pop();
        if not self.__val_to_idxs[val]:
            del self.__val_to_idxs[val]
        del self.__idx_to_val[idx]
        self.__top = self.__idx_to_val[max(self.__idx_to_val.keys())] if self.__idx_to_val else None
        self.__max = max(self.__val_to_idxs.keys()) if self.__val_to_idxs else None
            

# Your MaxStack object will be instantiated and called as such:
# obj = MaxStack()
# obj.push(x)
# param_2 = obj.pop()
# param_3 = obj.top()
# param_4 = obj.peekMax()
# param_5 = obj.popMax()
