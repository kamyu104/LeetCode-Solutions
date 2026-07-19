# Time:  O(n * r * l)
# Space: O(n)

# dp
class Solution(object):
    def minCost(self, source, target, rules, costs):
        """
        :type source: str
        :type target: str
        :type rules: List[List[str]]
        :type costs: List[int]
        :rtype: int
        """
        INF = float("inf")
        dp = [INF]*(len(source)+1)
        dp[0] = 0
        for i in xrange(len(source)):
            if dp[i] is INF:
                continue
            if source[i] == target[i]:
                dp[i+1] = min(dp[i+1], dp[i])
            for j, (p, r) in enumerate(rules):
                c = costs[j]
                if i+len(p) >= len(dp):
                    continue
                for k in xrange(len(p)):
                    if r[k] != target[i+k]:
                        break
                    if p[k] == '*':
                        c += 1
                    elif p[k] != source[i+k]:
                        break
                else:
                    dp[i+len(p)] = min(dp[i+len(p)], dp[i]+c)
        return dp[-1] if dp[-1] is not INF else -1
