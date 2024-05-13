# Time:  O(q * (logr)^2)
# Space: O(1)

# binary search, combinatorics, bitmasks, fast exponentiation
class Solution(object):
    def findProductsOfElements(self, queries):
        """
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        def binary_search(left, right, check):
            while left <= right:
                mid = left + ((right-left)>>1)
                if check(mid):
                    right = mid-1
                else:
                    left = mid+1
            return left
    
        def f(x):
            def count1(x):
                result = i = 0
                while 1<<i <= x:
                    mask = (1<<(i+1))-1
                    result += ((x&~mask)>>1)+max((x&mask)-(1<<i)+1, 0)
                    i += 1
                return result
 
            def count2(x):
                result = i = 0
                while 1<<i <= x:
                    mask = (1<<(i+1))-1
                    result += (((x&~mask)>>1)+max((x&mask)-(1<<i)+1, 0))*i
                    i += 1
                return result
            
            y = binary_search(1, x-1, lambda i: count1(i) >= x)
            result = count2(y-1)
            x -= count1(y-1)
            i = 0
            while 1<<i <= y:
                if y&(1<<i):
                    result += i
                    x -= 1
                    if x == 0:
                        break
                i += 1
            return result
        
        return [pow(2, f(right+1)-f(left), mod) for left, right, mod in queries]
