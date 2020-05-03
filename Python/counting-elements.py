# Time:  O(n)
# Space: O(n)

class Solution(object):
    def countElements(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        lookup = set(arr)
        return sum(1 for x in arr if x+1 in lookup)


# Time:  O(nlogn)
# Space: O(1)
class Solution(object):
    def countElements(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        arr.sort()
        result, l = 0, 1
        for i in xrange(len(arr)-1):
            if arr[i] == arr[i+1]:
                l += 1
                continue
            if arr[i]+1 == arr[i+1]:
                result += l
            l = 1
        return result
