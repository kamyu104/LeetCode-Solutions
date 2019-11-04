# Time:  O(n^2)
# Space: O(n)

class Solution(object):
    def transformArray(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        def is_changable(arr):
            return any(arr[i-1] > arr[i] < arr[i+1] or 
                       arr[i-1] < arr[i] > arr[i+1]
                       for i in xrange(1, len(arr)-1))
        
        while is_changable(arr):
            new_arr = arr[:]
            for i in xrange(1, len(arr)-1):
                new_arr[i] += arr[i-1] > arr[i] < arr[i+1]
                new_arr[i] -= arr[i-1] < arr[i] > arr[i+1]
            arr = new_arr
        return arr
