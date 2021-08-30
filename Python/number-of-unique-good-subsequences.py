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
                ends1 = (ends1+ends0+1)%MOD  # add extra ends0 new distinct subsequences and add one "1"*count_of_curr_1s
            else:
                ends0 = (ends0+ends1)%MOD  # add extra ends1 new distinct subsequences and don't add one "0"*count_of_curr_0s
                has_zero = True
        return (ends0+ends1+int(has_zero))%MOD  # add "0" if has_zero
