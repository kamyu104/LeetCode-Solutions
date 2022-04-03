# Time:  O(n)
# Space: O(1)

# combinatorics, number theory
class Solution(object):
    def triangularSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        def exp_mod(p, mod):
            result = [p]
            while result[-1]*p%10 != result[0]:
                 result.append(result[-1]*p%10)
            return [result[-1]]+result[:-1]

        def inv_mod(x, mod):
            y = x
            while y*x%10 != 1:
                y = y*x%10
            return y

        def factor_p(x, p, cnt, diff):
            if x == 0:
                return x, cnt
            while x%p == 0:
                x //= p
                cnt += diff
            return x, cnt
    
        EXP = {p:exp_mod(p, 10) for p in (2, 5)}  # {2:[6, 2, 4, 8], 5:[5]}           
        INV = {i:inv_mod(i, 10) for i in xrange(1, 10) if i%2 and i%5}  # {1:1, 3:7, 7:3, 9:9}
        result = 0
        nCr = 1
        cnt = {2:0, 5:0}
        for i in xrange(len(nums)):
            if not cnt[2] and not cnt[5]:
                result = (result + nCr*nums[i])%10
            elif cnt[2] and not cnt[5]:
                result = (result + nCr*EXP[2][cnt[2]%len(EXP[2])]*nums[i])%10
            elif not cnt[2] and cnt[5]:
                result = (result + nCr*EXP[5][cnt[5]%len(EXP[5])]*nums[i])%10
            mul, cnt[2] = factor_p((len(nums)-1)-i, 2, cnt[2], 1)
            mul, cnt[5] = factor_p(mul, 5, cnt[5], 1)
            div, cnt[2] = factor_p(i+1, 2, cnt[2], -1)
            div, cnt[5] = factor_p(div, 5, cnt[5], -1)
            nCr = nCr*mul%10
            nCr = nCr*INV[div%10]%10
        return result

    
# Time:  O(n^2)
# Space: O(n)
# combinatorics
class Solution2(object):
    def triangularSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        result = 0
        nCr = 1
        for i in xrange(len(nums)):
            result = (result+nCr*nums[i])%10
            nCr *= (len(nums)-1)-i
            nCr //= i+1
        return result


# Time:  O(n^2)
# Space: O(1)
# simulation
class Solution3(object):
    def triangularSum(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        for i in reversed(xrange(len(nums))):
            for j in xrange(i):
                nums[j] = (nums[j]+nums[j+1])%10
        return nums[0]
