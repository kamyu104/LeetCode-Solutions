# Time:  O(nlogn + mlogm)
# Space: O(n + m)

# sort, two pointers
class Solution(object):
    def countServers(self, n, logs, x, queries):
        """
        :type n: int
        :type logs: List[List[int]]
        :type x: int
        :type queries: List[int]
        :rtype: List[int]
        """
        logs.sort(key=lambda x:x[1])
        result = [0]*len(queries)
        cnt = [0]*n
        curr = left = right = 0
        for t, i in sorted((t, i) for i, t in enumerate(queries)):
            while right < len(logs) and logs[right][1] <= t:
                if cnt[logs[right][0]-1] == 0:
                    curr += 1
                cnt[logs[right][0]-1] += 1
                right += 1
            while left < right and logs[left][1] < t-x:
                cnt[logs[left][0]-1] -= 1
                if cnt[logs[left][0]-1] == 0:
                    curr -= 1
                left += 1
            result[i] = n-curr
        return result


# Time:  O(nlogn + mlogm)
# Space: O(n + m)
# sort, line sweep
class Solution2(object):
    def countServers(self, n, logs, x, queries):
        """
        :type n: int
        :type logs: List[List[int]]
        :type x: int
        :type queries: List[int]
        :rtype: List[int]
        """
        events = []
        for sid, t in logs:
            events.append((t, +1, sid-1))
            events.append((t+x+1, -1, sid-1))
        events.append((float("inf"), 0, 0))
        events.sort()

        events2 = []
        for i, t in enumerate(queries):
            events2.append((t, i))
        events2.sort(reverse=True)

        result = [0]*len(queries)
        cnt = [0]*n
        curr = 0
        for t, c, i in events:
            while events2 and events2[-1][0] < t:                
                result[events2.pop()[1]] += n-curr
            if cnt[i] == 0:
                curr += 1
            cnt[i] += c
            if cnt[i] == 0:
                curr -= 1
        return result
