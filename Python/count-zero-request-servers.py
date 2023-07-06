# Time:  O(nlogn + mlogm)
# Space: O(n + m)

# sort, line sweep
class Solution(object):
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
