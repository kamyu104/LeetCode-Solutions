# Time:  O(m^2), m = len(requests)
# Space: O(m)

# sort, dp
class Solution(object):
    def elevatorRequests(self, n, start, requests):
        """
        :type n: int
        :type start: int
        :type requests: List[int]
        :rtype: int
        """
        INF = float("inf")
        if start not in requests:
            requests.append(start)
        requests.sort()
        k = requests.index(start)
        dp = [[INF]*len(requests) for _ in xrange(2)]
        dp[0][k] = dp[1][k] = 0
        for l in xrange(1, len(requests)):
            new_dp = [[INF]*len(requests) for _ in xrange(2)]
            for i in xrange(max(k-l+1, 0), min(len(requests)-l, k)+1):
                j = i+(l-1)
                if i-1 >= 0:
                    new_dp[0][i-1] = min(new_dp[0][i-1],
                                         dp[0][i]+(requests[i]-requests[i-1])*(len(requests)-l),
                                         dp[1][i]+(requests[j]-requests[i-1])*(len(requests)-l))
                if j+1 < len(requests):
                    new_dp[1][i] = min(new_dp[1][i], 
                                       dp[0][i]+(requests[j+1]-requests[i])*(len(requests)-l),
                                       dp[1][i]+(requests[j+1]-requests[j])*(len(requests)-l))
            dp = new_dp
        return min(dp[0][0], dp[1][0])
