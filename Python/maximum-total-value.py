# Time:  O(nlogr)
# Space: O(1)

# binary search
class Solution(object):
    def maxTotalValue(self, value, decay, m):
        """
        :type value: List[int]
        :type decay: List[int]
        :type m: int
        :rtype: int
        """
        MOD = 10**9+7
        def binary_search(left, right, check):
            while left <= right:
                mid = left+(right-left)//2
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left

        def total(x):
            result = cnt = 0
            for i in xrange(len(value)):
                if value[i]-x < 0:
                    continue
                t = (value[i]-x)//decay[i]+1
                result = (result+(value[i]+(value[i]-decay[i]*(t-1)))*(t//2))%MOD if t%2 == 0 else (result+(value[i]-decay[i]*((t-1)//2))*t)%MOD
                cnt += t
            return result, cnt
    
        def check(x):
            return total(x)[1] <= m
        
        if check(1):
            return total(1)[0]
        x = binary_search(2, max(value), check)
        result, cnt = total(x)
        result = (result+(m-cnt)*(x-1))%MOD
        return result
