# Time:  O(n + logc), c is the number of candies
# Space: O(1)

class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        # find max integer p s.t. sum(1 + 2 + ... + p) <= C
        # => remaining : 0 <= C-(1+p)*p/2 < p+1
        # => -2p-2 < p^2+p-2C <= 0
        # => 2C+1/4 < (p+3/2)^2 and (p+1/2)^2 <= 2C+1/4
        # => sqrt(2C+1/4)-3/2 < p <= sqrt(2C+1/4)-1/2
        # => p = floor(sqrt(2C+1/4)-1/2)
        p = int((2*candies + 0.25)**0.5 - 0.5) 
        remaining = candies - (p+1)*p//2
        rows, cols = divmod(p, num_people)
        
        result = [0]*num_people
        for i in xrange(num_people):
            result[i] = (i+1)*(rows+1) + (rows*(rows+1)//2)*num_people if i < cols else \
                        (i+1)*rows + ((rows-1)*rows//2)*num_people
        result[cols] += remaining
        return result


# Time:  O(n + logc), c is the number of candies
# Space: O(1)
class Solution2(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        # find max integer p s.t. sum(1 + 2 + ... + p) <= C
        left, right = 1, candies
        while left <= right:
            mid = left + (right-left)//2
            if not ((mid <= candies*2 // (mid+1))):
                right = mid-1
            else:
                left = mid+1
        p = right
        remaining = candies - (p+1)*p//2
        rows, cols = divmod(p, num_people)
        
        result = [0]*num_people
        for i in xrange(num_people):
            result[i] = (i+1)*(rows+1) + (rows*(rows+1)//2)*num_people if i < cols else \
                        (i+1)*rows + ((rows-1)*rows//2)*num_people
        result[cols] += remaining
        return result


# Time:  O(sqrt(c)), c is the number of candies
# Space: O(1)
class Solution3(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        result = [0]*num_people
        i = 0
        while candies != 0:
            result[i % num_people] += min(candies, i+1)
            candies -= min(candies, i+1)
            i += 1
        return result
