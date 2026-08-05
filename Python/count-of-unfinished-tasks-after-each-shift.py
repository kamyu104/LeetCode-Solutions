# Time:  O(n + mlogn)
# Space: O(n)

# prefix sum, binary search
class Solution(object):
    def countTasks(self, tasks, shifts):
        """
        :type tasks: List[int]
        :type shifts: List[int]
        :rtype: List[int]
        """
        prefix = [0]*(len(tasks)+1)
        for i in xrange(len(tasks)):
            prefix[i+1] = prefix[i]+tasks[i]
        result = [0]*len(shifts)
        total = 0
        for i in xrange(len(shifts)):
            total += shifts[i]
            if total >= prefix[-1]:
                total = 0
                continue
            result[i] = len(prefix)-bisect.bisect_right(prefix, total)
        return result
