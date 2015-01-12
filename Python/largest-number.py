# Time:  O(n^2)
# Space: O(n)
#
# Given a list of non negative integers, arrange them such that they form the largest number.
# 
# For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
# 
# Note: The result may be very large, so you need to return a string instead of an integer.
#

class Solution:
    # @param num, a list of integers
    # @return a string
    def largestNumber(self, num):
        largest = ""
        none_zero = False
        for n in sorted(num, cmp=self.cmp_items):
            if n != 0:
                none_zero = True
            if none_zero:
                largest += "{}".format(n)
        
        if largest == "":
            largest = "0"
    
        return largest

    def cmp_items(self, a, b):
        if a == b:
            return 0
        elif "{}{}".format(a, b) > "{}{}".format(b, a):
            return -1
        else:
            return 1

if __name__ == "__main__":
    num = [3, 30, 34, 5, 9]
    print Solution().largestNumber(num) 
