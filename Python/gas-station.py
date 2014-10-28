# Time:  O(n)
# Space: O(1)
#
# There are N gas stations along a circular route, where the amount of gas at station i is gas[i].
# 
# You have a car with an unlimited gas tank and it costs cost[i] of gas to travel from station i to its next station (i+1).
# You begin the journey with an empty tank at one of the gas stations.
# 
# Return the starting gas station's index if you can travel around the circuit once, otherwise return -1.
# 
# Note:
# The solution is guaranteed to be unique.
#

class Solution:
    # @param gas, a list of integers
    # @param cost, a list of integers
    # @return an integer
    def canCompleteCircuit(self, gas, cost):
        start, total_sum, current_sum = 0, 0, 0
        for i in xrange(len(gas)):
            diff = gas[i] - cost[i]
            current_sum += diff
            total_sum += diff
            if current_sum < 0:
                start = i + 1
                current_sum = 0
        if total_sum >= 0:
            return start
        
        return -1

if __name__ == "__main__":
    print Solution().canCompleteCircuit([1, 2, 3], [3, 2, 1])
    print Solution().canCompleteCircuit([1, 2, 3], [2, 2, 2])
    print Solution().canCompleteCircuit([1, 2, 3], [1, 2, 3])
    print Solution().canCompleteCircuit([1, 2, 3], [1, 2, 4])
