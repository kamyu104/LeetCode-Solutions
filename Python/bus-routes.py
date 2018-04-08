# Time:  O(|V| + |E|)
# Space: O(|V| + |E|)

# We have a list of bus routes. Each routes[i] is a bus route that
# the i-th bus repeats forever. For example if routes[0] = [1, 5, 7],
# this means that the first bus (0-th indexed) travels in the sequence
# 1->5->7->1->5->7->1->... forever.
#
# We start at bus stop S (initially not on a bus), and we want to go to bus
# stop T.
# Travelling by buses only, what is the least number of buses we must take to
# reach our destination?
# Return -1 if it is not possible.
#
# Example:
# Input:
# routes = [[1, 2, 7], [3, 6, 7]]
# S = 1
# T = 6
# Output: 2
# Explanation:
# The best strategy is take the first bus to the bus stop 7,
# then take the second bus to the bus stop 6.
#
# Note:
# - 1 <= routes.length <= 500.
# - 1 <= routes[i].length <= 500.
# - 0 <= routes[i][j] < 10 ^ 6.

import collections


class Solution(object):
    def numBusesToDestination(self, routes, S, T):
        """
        :type routes: List[List[int]]
        :type S: int
        :type T: int
        :rtype: int
        """
        if S == T:
            return 0

        to_route = collections.defaultdict(set)
        for i, route in enumerate(routes):
            for stop in route:
                to_route[stop].add(i)

        result = 1
        q = [S]
        lookup = set([S])
        while q:
            next_q = []
            for stop in q:
                for i in to_route[stop]:
                    for next_stop in routes[i]:
                        if next_stop in lookup:
                            continue
                        if next_stop == T:
                            return result
                        next_q.append(next_stop)
                        to_route[next_stop].remove(i)
                        lookup.add(next_stop)
            q = next_q
            result += 1

        return -1
