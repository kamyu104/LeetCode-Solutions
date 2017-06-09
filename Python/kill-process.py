# Time:  O(n)
# Space: O(n)

# Given n processes, each process has a unique PID (process id)
# and its PPID (parent process id).
#
# Each process only has one parent process, but may have one or more children processes.
# This is just like a tree structure. Only one process has PPID that is 0,
# which means this process has no parent process. All the PIDs will be distinct positive integers.
#
# We use two list of integers to represent a list of processes,
# where the first list contains PID for each process
# and the second list contains the corresponding PPID.
#
# Now given the two lists, and a PID representing a process you want to kill,
# return a list of PIDs of processes that will be killed in the end.
# You should assume that when a process is killed,
# all its children processes will be killed.
# No order is required for the final answer.
#
# Example 1:
# Input: 
# pid =  [1, 3, 10, 5]
# ppid = [3, 0, 5, 3]
# kill = 5
# Output: [5,10]
# Explanation: 
#           3
#          /   \
#         1     5
#              /
#             10
# Kill 5 will also kill 10.
# Note:
# The given kill id is guaranteed to be one of the given PIDs.
# n >= 1.

# DFS solution.
class Solution(object):
    def killProcess(self, pid, ppid, kill):
        """
        :type pid: List[int]
        :type ppid: List[int]
        :type kill: int
        :rtype: List[int]
        """
        def killAll(pid, children, killed):
            killed.append(pid)
            for child in children[pid]:
                killAll(child, children, killed)

        result = []
        children = collections.defaultdict(set)
        for i in xrange(len(pid)):
            children[ppid[i]].add(pid[i])
        killAll(kill, children, result)
        return result


# Time:  O(n)
# Space: O(n)
# BFS solution.
class Solution2(object):
    def killProcess(self, pid, ppid, kill):
        """
        :type pid: List[int]
        :type ppid: List[int]
        :type kill: int
        :rtype: List[int]
        """
        def killAll(pid, children, killed):
            killed.append(pid)
            for child in children[pid]:
                killAll(child, children, killed)

        result = []
        children = collections.defaultdict(set)
        for i in xrange(len(pid)):
            children[ppid[i]].add(pid[i])
        q = collections.deque()
        q.append(kill)
        while q:
            p = q.popleft()
            result.append(p);
            for child in children[p]:
                q.append(child)
        return result
