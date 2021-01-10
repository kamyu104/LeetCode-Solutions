# Time:  O(k^n * logr), the real complexity shoud be much less, but hard to analyze
# Space: O(n + k)

class Solution(object):
    def minimumTimeRequired(self, jobs, k):
        """
        :type jobs: List[int]
        :type k: int
        :rtype: int
        """
        def backtracking(jobs, i, cap, counts):
            if i == len(jobs):
                return True
            for j in xrange(len(counts)):
                if counts[j]+jobs[i] <= cap:
                    counts[j] += jobs[i]
                    if backtracking(jobs, i+1, cap, counts):
                        return True
                    counts[j] -= jobs[i]
                if counts[j] == 0:
                    break
            return False

        jobs.sort(reverse=True)
        left, right = max(jobs), sum(jobs)
        while left <= right:
            mid = left + (right-left)//2
            if backtracking(jobs, 0, mid, [0]*k):
                right = mid-1
            else:
                left = mid+1
        return left


# Time:  O(k * k^n), the real complexity shoud be less, but hard to analyze
# Space: O(n + k)
class Solution2(object):
    def minimumTimeRequired(self, jobs, k):
        """
        :type jobs: List[int]
        :type k: int
        :rtype: int
        """
        def backtracking(jobs, i, counts, result):
            if i == len(jobs):
                result[0] = min(result[0], max(counts))
                return
            for j in xrange(len(counts)):
                if counts[j]+jobs[i] <= result[0]:
                    counts[j] += jobs[i]
                    backtracking(jobs, i+1, counts, result)
                    counts[j] -= jobs[i]
                if counts[j] == 0:
                    break

        jobs.sort(reverse=False)
        result = [sum(jobs)]
        backtracking(jobs, 0, [0]*k, result)
        return result[0]
