# Time:  O(n)
# Space: O(1)

class Solution(object):
    def sumOddLengthSubarrays(self, arr):
        """
        :type arr: List[int]
        :rtype: int
        """
        def ceil_divide(a, b):
            return (a+(b-1))//b
 
        # begin\pos |0   i       (n-1)
        # ----------------------------
        # 0          --101....      ↑
        # 1           -010....    i-0+1
        # i            101....      ↓
        #              ← (n-1-i+1) →
        #
        # for each number x with its position i, we want to know how many odd length subarrays is with x,
        # as the graph depicted above,
        # (begin, pos) pair represents a subarray arr[begin:pos+1] containing x, marked 1 if odd length else 0,
        # so the total number of 0 and 1 are exactly the total number of subarrays with x, which is (i-0+1)*((len(arr)-1)-i+1),
        # because the number of 1 is always equal to or one more than the number of 0, (always begins with 1010... and alternatively flips)
        # so there are ceil((i-0+1)*((len(arr)-1)-i+1)/2) odd length subarrays with x
        # 
        return sum(x * ceil_divide((i-0+1)*((len(arr)-1)-i+1), 2) for i, x in enumerate(arr))
