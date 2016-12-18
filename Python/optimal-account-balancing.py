# Time:  O(2^n), n is the size of debt.
# Space: O(2^n)

class Solution(object):
    def minTransfers(self, transactions):
        """
        :type transactions: List[List[int]]
        :rtype: int
        """
        account = collections.defaultdict(int)
        for transaction in transactions:
            account[transaction[0]] += transaction[2]
            account[transaction[1]] -= transaction[2]

        debt = []
        for v in account.values():
            if v:
                debt.append(v)
            
        if not debt:
            return 0

        n = 1 << len(debt)
        dp, subset = [float("inf")] * n, []
        for i in xrange(1, n):
            net_debt, number = 0, 0
            for j in xrange(len(debt)):
                if i & 1 << j:
                    net_debt += debt[j]
                    number += 1
            if net_debt == 0:
                dp[i] = number - 1
                for s in subset:
                    if (i & s) == s:
                        dp[i] = min(dp[i], dp[s] + dp[i - s])
                subset.append(i)
        return dp[-1]
