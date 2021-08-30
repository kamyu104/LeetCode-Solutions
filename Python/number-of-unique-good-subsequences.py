# Time:  O(n)
# Space: O(1)

class Solution(object):
    def numberOfUniqueGoodSubsequences(self, binary):
        """
        :type binary: str
        :rtype: int
        """
        MOD = 10**9+7
        ends0, ends1 = 0, 0
        has_zero = False
        for b in binary:
            if b == '1':
                ends1 = (ends0+ends1+1)%MOD  # curr subsequences end with 1 is all prev distinct subsequences appended by 1 and plus "1"
            else:
                ends0 = (ends0+ends1)%MOD  # curr subsequences end with 0 is all prev distinct subsequences appended by 0 and don't plus "0"
                has_zero = True
        return (ends0+ends1+int(has_zero))%MOD  # add "0" if has_zero
