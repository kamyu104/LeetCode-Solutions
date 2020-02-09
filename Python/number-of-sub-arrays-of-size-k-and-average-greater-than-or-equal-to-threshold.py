# Time:  O(n)
# Space: O(1)

import itertools


class Solution(object):
    def numOfSubarrays(self, arr, k, threshold):
        """
        :type arr: List[int]
        :type k: int
        :type threshold: int
        :rtype: int
        """
        result, curr = 0, sum(itertools.islice(arr, 0, k-1))
        for i in xrange(k-1, len(arr)):
            curr += arr[i]-(arr[i-k] if i-k >= 0 else 0)
            result += int(curr >= threshold*k)
        return result
    

# Time:  O(n)
# Space: O(n)
class Solution2(object):
    def numOfSubarrays(self, arr, k, threshold):
        """
        :type arr: List[int]
        :type k: int
        :type threshold: int
        :rtype: int
        """
        accu = [0]
        for x in arr:
            accu.append(accu[-1]+x)
        result = 0
        for i in xrange(len(accu)-k):
            if accu[i+k]-accu[i] >= threshold*k:
                result += 1
        return result
