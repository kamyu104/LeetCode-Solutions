# Time:  O(n)
# Space: O(n)
#
# Design and implement a TwoSum class. It should support the following operations: add and find.
# 
# add - Add the number to an internal data structure.
# find - Find if there exists any pair of numbers which sum is equal to the value.
# 
# For example,
# add(1); add(3); add(5);
# find(4) -> true
# find(7) -> false
#

class TwoSum:

    # initialize your data structure here
    def __init__(self):
        self.lookup = collections.defaultdict(int)
        

    # @return nothing
    def add(self, number):
        self.lookup[number] += 1


    # @param value, an integer
    # @return a Boolean
    def find(self, value):
        for key in self.lookup:
            num = value - key
            if num in self.lookup and (num != key or self.lookup[key] > 1):
                return True
        return False

if __name__ == "__main__":
    Sol = TwoSum()
    
    for i in (1, 3, 5):
        Sol.add(i)
    
    for i in (4, 7):
        print Sol.find(i)
                
                
