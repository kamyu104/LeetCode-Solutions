# Time:  O(n)
# Space: O(1)

class Solution(object):
    def maximumNumber(self, num, change):
        """
        :type num: str
        :type change: List[int]
        :rtype: str
        """
        mutated = False
        result = map(int, list(num))
        for i, d in enumerate(result):
            if change[d] < d:
                if mutated:
                    break
            elif change[d] > d:
                result[i] = str(change[d])
                mutated = True
        return "".join(map(str, result))
