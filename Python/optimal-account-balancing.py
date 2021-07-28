# Time:  O(n * 2^n), n is the size of the debt.
# Space: O(2^n)

import collections


class Solution(object):
    def minTransfers(self, transactions):
        """
        :type transactions: List[List[int]]
        :rtype: int
        """
        accounts = collections.defaultdict(int)
        for src, dst, amount in transactions:
            accounts[src] += amount
            accounts[dst] -= amount

        debts = [account for account in accounts.itervalues() if account]

        dp = [0]*(2**len(debts))
        sums = [0]*(2**len(debts))
        for i in xrange(len(dp)):
            bit = 1
            for j in xrange(len(debts)):
                if (i & bit) == 0:
                    nxt = i | bit
                    sums[nxt] = sums[i]+debts[j]
                    if sums[nxt] == 0:
                        dp[nxt] = max(dp[nxt], dp[i]+1)
                    else:
                        dp[nxt] = max(dp[nxt], dp[i])
                bit <<= 1
        return len(debts)-dp[-1]
