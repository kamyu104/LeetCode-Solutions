# Time:  O(2^n)
# Space: O(1)
#
# Given a collection of integers that might contain duplicates, S, return all possible subsets.
# 
# Note:
# Elements in a subset must be in non-descending order.
# The solution set must not contain duplicate subsets.
# For example,
# If S = [1,2,2], a solution is:
# 
# [
#   [2],
#   [1],
#   [1,2,2],
#   [2,2],
#   [1,2],
#   []
# ]
#

class Solution:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        result = []
        i, count = 0, 1 << len(S)
        S = sorted(S)
        
        while i < count:
            cur = []
            for j in xrange(len(S)):
                if i & 1 << j:
                    cur.append(S[j])
            if cur not in result:
                result.append(cur)
            i += 1
            
        return result

class Solution2:
    # @param num, a list of integer
    # @return a list of lists of integer
    def subsetsWithDup(self, S):
        result = []
        self.subsetsWithDupRecu(result, [], sorted(S))
        return result
    
    def subsetsWithDupRecu(self, result, cur, S):
        if len(S) == 0  and cur not in result:
            result.append(cur)
        elif S:
            self.subsetsWithDupRecu(result, cur, S[1:])
            self.subsetsWithDupRecu(result, cur + [S[0]], S[1:])
        
if __name__ == "__main__":
    print Solution().subsetsWithDup([1, 2, 2])