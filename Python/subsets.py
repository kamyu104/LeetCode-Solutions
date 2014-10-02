# Time:  O(2^n)
# Space: O(1)
#
# Given a set of distinct integers, S, return all possible subsets.
# 
# Note:
# Elements in a subset must be in non-descending order.
# The solution set must not contain duplicate subsets.
# For example,
# If S = [1,2,3], a solution is:
# 
# [
#   [3],
#   [1],
#   [2],
#   [1,2,3],
#   [1,3],
#   [2,3],
#   [1,2],
#   []
# ]
#

class Solution:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        result = []
        i, count = 0, 1 << len(S)
        S = sorted(S)
        
        while i < count:
            cur = []
            for j in xrange(len(S)):
                if i & 1 << j:
                    cur.append(S[j])
            result.append(cur)
            i += 1
            
        return result

class Solution2:
    # @param S, a list of integer
    # @return a list of lists of integer
    def subsets(self, S):
        return self.subsetsRecu([], sorted(S))
    
    def subsetsRecu(self, cur, S):
        if len(S) == 0:
            return [cur]
        
        return self.subsetsRecu(cur, S[1:]) + self.subsetsRecu(cur + [S[0]], S[1:])
        
if __name__ == "__main__":
    print Solution().subsets([1, 2, 3])