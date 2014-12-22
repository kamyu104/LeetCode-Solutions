# Time:  O(n)
# Space: O(1)
#
# Given an array of size n, find the majority element.
# The majority element is the element that appears more than [n/2] times.
# 
# You may assume that the array is non-empty and the majority element always exist in the array.
#

class Solution:
    # @param num, a list of integers
    # @return an integer
    def majorityElement(self, num):
        idx, cnt = 0, 1
        
        for i in xrange(1, len(num)):
            if num[idx] == num[i]:
                cnt += 1
            else:
                cnt -= 1
                if cnt == 0:
                    idx = i
                    cnt = 1
        
        return num[idx]

if __name__ == "__main__":
    print Solution().majorityElement([1, 2, 3, 4, 5, 5, 5, 5, 5, 5, 6])