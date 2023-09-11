# Time:  O(nlogn + mlogm)
# Space: O(n + m)

# sort, two pointers
class Solution(object):
    def maximumCoins(self, heroes, monsters, coins):
        """
        :type heroes: List[int]
        :type monsters: List[int]
        :type coins: List[int]
        :rtype: List[int]
        """
        idx1 = range(len(heroes))
        idx1.sort(key=lambda x: heroes[x])
        idx2 = range(len(monsters))
        idx2.sort(key=lambda x: monsters[x])
        result = [0]*len(idx1)
        i = curr = 0
        for idx in idx1:
            for i in xrange(i, len(idx2)):
                if monsters[idx2[i]] > heroes[idx]:
                    break
                curr += coins[idx2[i]]
            else:
                i = len(idx2)
            result[idx] = curr
        return result
