# Time:  O(nlogn)
# Space: O(n)


import collections


class Solution:
    def invalidTransactions(self, transactions):
        AMOUNT, MINUTES = 1000, 60
        trans = map(lambda x: (x[0], int(x[1]), int(x[2]), x[3]),
                    (transaction.split(',') for transaction in transactions))
        trans.sort(key=lambda t: t[1])
        trans_indexes = collections.defaultdict(list)
        for i, t in enumerate(trans):
            trans_indexes[t[0]].append(i)
        result = []
        for name, indexes in trans_indexes.iteritems():
            left, right = 0, 0
            for i, t_index in enumerate(indexes):
                t = trans[t_index]
                if (t[2] > AMOUNT):
                    result.append("{},{},{},{}".format(*t))
                    continue
                while left+1 < len(indexes) and trans[indexes[left]][1] < t[1]-MINUTES:
                    left += 1
                while right+1 < len(indexes) and trans[indexes[right+1]][1] <= t[1]+MINUTES:
                    right += 1
                for i in xrange(left, right+1):
                    if trans[indexes[i]][3] != t[3]:
                        result.append("{},{},{},{}".format(*t))
                        break
        return result
