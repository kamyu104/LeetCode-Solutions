# Time:  O(n)
# Space: O(n)

class Solution(object):
    def canFormArray(self, arr, pieces):
        """
        :type arr: List[int]
        :type pieces: List[List[int]]
        :rtype: bool
        """
        lookup = {x[0]: i for i, x in enumerate(pieces)}
        i = 0
        while i < len(arr): 
            if arr[i] not in lookup:
                return False
            for c in pieces[lookup[arr[i]]]:
                if i == len(arr) or arr[i] != c:
                    return False
                i += 1
        return True 
