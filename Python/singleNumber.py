class Solution:
    # @param A, a list of integer
    # @return an integer
    def singleNumber(self, A):
        ans = 0
        for x in A:
            ans ^= x
        return ans

if __name__ == '__main__':
    print (Solution().singleNumber([1, 1, 2, 2, 3]))