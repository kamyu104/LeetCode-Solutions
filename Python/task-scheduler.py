# Time:  O(n)
# Space: O(26) = O(1)

# Given a char array representing tasks CPU need to do.
# It contains capital letters A to Z where different letters represent
# different tasks.Tasks could be done without original order.
# Each task could be done in one interval.
# For each interval, CPU could finish one task or just be idle.
#
# However, there is a non-negative cooling interval n that
# means between two same tasks, there must be at least n intervals that
# CPU are doing different tasks or just be idle.
#
# You need to return the least number of intervals the CPU
# will take to finish all the given tasks.
#
# Example 1:
# Input: tasks = ['A','A','A','B','B','B'], n = 2
# Output: 8
# Explanation: A -> B -> idle -> A -> B -> idle -> A -> B.
# Note:
# The number of tasks is in the range [1, 10000].
# The integer n is in the range [0, 100].

class Solution(object):
    def leastInterval(self, tasks, n):
        """
        :type tasks: List[str]
        :type n: int
        :rtype: int
        """
        count = collections.defaultdict(int)
        max_count = 0
        for task in tasks:
            count[task] += 1
            max_count = max(max_count, count[task])
        
        result = (max_count-1) * (n+1)
        for count in count.values():
            if count == max_count:
                result += 1
        return max(result, len(tasks))
