# Time:  O(logn)
# Space: O(1)

# counting sort
class Solution(object):
    def largestInteger(self, num):
        """
        :type num: int
        :rtype: int
        """
        def count(num):
            cnt = [0]*10
            while num:
                num, d = divmod(num, 10)
                cnt[d] += 1
            return cnt

        cnt = count(num)
        result = 0
        idx = [0, 1]
        base = 1
        while num:
            num, d = divmod(num, 10)
            while not cnt[idx[d%2]]:
                idx[d%2] += 2
            cnt[idx[d%2]] -= 1
            result += idx[d%2]*base
            base *= 10
        return result
