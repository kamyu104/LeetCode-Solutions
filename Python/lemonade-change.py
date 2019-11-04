# Time:  O(n)
# Space: O(1)

import collections


class Solution(object):
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """
        coins = [20, 10, 5]
        counts = collections.defaultdict(int)
        for bill in bills:
            counts[bill] += 1
            change = bill - coins[-1]
            for coin in coins:
                if change == 0:
                    break
                if change >= coin:
                    count = min(counts[coin], change//coin)
                    counts[coin] -= count
                    change -= coin * count
            if change != 0:
                return False
        return True


class Solution2(object):
    def lemonadeChange(self, bills):
        """
        :type bills: List[int]
        :rtype: bool
        """
        five, ten = 0, 0
        for bill in bills:
            if bill == 5:
                five += 1
            elif bill == 10:
                if not five:
                    return False
                five -= 1
                ten += 1
            else:
                if ten and five:
                    ten -= 1
                    five -= 1
                elif five >= 3:
                    five -= 3
                else:
                    return False
        return True

