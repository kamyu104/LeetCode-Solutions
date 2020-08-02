# Time:  O(n^3)
# Space: O(1)

class Solution(object):
    def countGoodTriplets(self, arr, a, b, c):
        """
        :type arr: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: int
        """
        return sum(abs(arr[i]-arr[j]) <= a and
                   abs(arr[j]-arr[k]) <= b and
                   abs(arr[k]-arr[i]) <= c 
                   for i in xrange(len(arr)-2)
                       for j in xrange(i+1, len(arr)-1)
                           for k in xrange(j+1, len(arr)))
  
