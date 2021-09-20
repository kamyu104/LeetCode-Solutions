# Time:  O(n + klogk), k is the distinct number of changed
# Space: O(k)

class Solution(object):
    def findOriginalArray(self, changed):
        """
        :type changed: List[int]
        :rtype: List[int]
        """
        if len(changed)%2:
            return []
        cnts = collections.Counter(changed)
        for x in sorted(cnts.iterkeys()):
            if cnts[x] > cnts[2*x]:
                return []
            cnts[2*x] -= cnts[x] if x else cnts[x]//2
        return list(cnts.elements())
