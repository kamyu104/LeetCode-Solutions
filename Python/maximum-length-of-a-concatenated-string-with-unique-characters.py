# Time:  O(n) ~ O(2^n)
# Space: O(1) ~ O(2^n)

power = [1]
log2 = {1:0}
for i in xrange(1, 26):
    power.append(power[-1]<<1)
    log2[power[i]] = i


class Solution(object):
    def maxLength(self, arr):
        """
        :type arr: List[str]
        :rtype: int
        """
        def bitset(s):
            result = 0
            for c in s:
                if result & power[ord(c)-ord('a')]:
                    return 0
                result |= power[ord(c)-ord('a')]
            return result
        
        def number_of_one(n):
            result = 0
            while n:
                n &= n-1
                result += 1
            return result

        dp = [0]
        for x in arr:
            x_set = bitset(x)
            if not x_set:
                continue
            curr_len = len(dp)
            for i in xrange(curr_len):
                if dp[i] & x_set:
                    continue
                dp.append(dp[i] | x_set)
        return max(number_of_one(s_set) for s_set in dp)


# Time:  O(2^n)
# Space: O(1)
class Solution2(object):
    def maxLength(self, arr):
        """
        :type arr: List[str]
        :rtype: int
        """ 
        def bitset(s):
            result = 0
            for c in s:
                if result & power[ord(c)-ord('a')]:
                    return 0
                result |= power[ord(c)-ord('a')]
            return result
    
        bitsets = [bitset(x) for x in arr]
        result = 0
        for i in xrange(power[len(arr)]):
            curr_bitset, curr_len = 0, 0
            while i:
                j = i & -i  # rightmost bit
                i ^= j
                j = log2[j]  # log2(j)
                if not bitsets[j] or (curr_bitset & bitsets[j]):
                    break
                curr_bitset |= bitsets[j]
                curr_len += len(arr[j])
            else:
                result = max(result, curr_len)
        return result
