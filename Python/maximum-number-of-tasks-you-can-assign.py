# Time:  O(n * (logn)^2)
# Space: O(n)

from sortedcontainers import SortedList


class Solution(object):
    def maxTaskAssign(self, tasks, workers, pills, strength):
        """
        :type tasks: List[int]
        :type workers: List[int]
        :type pills: int
        :type strength: int
        :rtype: int
        """
        def check(tasks, workers, pills, strength, x):
            w = SortedList(workers[-x:])
            for task in tasks[-x:]:  # greedily assign
                i = w.bisect_left(task)
                if i != len(w):
                    w.pop(i)
                    continue
                if pills:
                    i = w.bisect_left(task-strength)
                    if i != len(w):
                        w.pop(i)
                        pills -= 1
                        continue
                return False
            return True

        tasks.sort(reverse=True)
        workers.sort()
        left, right = 1, min(len(workers), len(tasks))
        while left <= right:
            mid = left + (right-left)//2
            if not check(tasks, workers, pills, strength, mid):
                right = mid-1
            else:
                left = mid+1
        return right


# Time:  O(n^2 * logn)
# Space: O(n)
class Solution2(object):
    def maxTaskAssign(self, tasks, workers, pills, strength):
        """
        :type tasks: List[int]
        :type workers: List[int]
        :type pills: int
        :type strength: int
        :rtype: int
        """
        def check(tasks, workers, pills, strength, x):
            w = workers[-x:]
            for task in tasks[-x:]:  # greedily assign
                i = bisect.bisect_left(w, task)
                if i != len(w):
                    w.pop(i)
                    continue
                if pills:
                    i = bisect.bisect_left(w, task-strength)
                    if i != len(w):
                        w.pop(i)
                        pills -= 1
                        continue
                return False
            return True

        tasks.sort(reverse=True)
        workers.sort()
        left, right = 1, min(len(workers), len(tasks))
        while left <= right:
            mid = left + (right-left)//2
            if not check(tasks, workers, pills, strength, mid):
                right = mid-1
            else:
                left = mid+1
        return right
