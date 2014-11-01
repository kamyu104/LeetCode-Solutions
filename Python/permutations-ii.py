# Time:  O(n!)
# Space: O(n)
#
# Given a collection of numbers that might contain duplicates, return all possible unique permutations.
# 
# For example,
# [1,1,2] have the following unique permutations:
# [1,1,2], [1,2,1], and [2,1,1].
#


class Solution:
    # @param num, a list of integer
    # @return a list of lists of integers
    def permuteUnique(self, nums):
        solutions = [[]]
        
        for num in nums:
            next = []
            for solution in solutions:
                for i in xrange(len(solution) + 1):
                    candidate = solution[:i] + [num] + solution[i:]
                    if candidate not in next:
                        next.append(candidate)
                
            solutions = next 
            
        return solutions

if __name__ == "__main__":
    print Solution().permuteUnique([1, 1, 2])
    print Solution().permuteUnique([1, -1, 1, 2, -1, 2, 2, -1])


