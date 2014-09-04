# Time:  O(n)
# Space: O(n)
#
# There are N children standing in a line. Each child is assigned a rating value.
# 
# You are giving candies to these children subjected to the following requirements:
# 
# Each child must have at least one candy.
# Children with a higher rating get more candies than their neighbors.
# What is the minimum candies you must give?
#
import operator

class Solution:
    # @param ratings, a list of integer
    # @return an integer
    def candy(self, ratings):
        candies = [1 for i in range(len(ratings))]
        for i in range(1, len(ratings)):
            if ratings[i] > ratings[i - 1]:
                candies[i] = candies[i - 1] + 1
        
        for i in reversed(range(1, len(ratings))):
            if ratings[i - 1] > ratings[i] and candies[i - 1] <= candies[i]:
                candies[i - 1] = candies[i] + 1
        
        return reduce(operator.add, candies)
        
if __name__ == "__main__":
    result = Solution().candy([1, 2, 3, 2, 3, 5, 2, 5])
    print result