# Time:  O(e + q * |V|!), |V| is the number of variables
# Space: O(e)

# Equations are given in the format A / B = k,
# where A and B are variables represented as strings,
# and k is a real number (floating point number).
# Given some queries, return the answers.
# If the answer does not exist, return -1.0.
#
# Example:
# Given a / b = 2.0, b / c = 3.0.
# queries are: a / c = ?, b / a = ?, a / e = ?, a / a = ?, x / x = ? .
# return [6.0, 0.5, -1.0, 1.0, -1.0 ].
#
# The input is:
# vector<pair<string, string>> euqations, vector<double>& values, vector<pair<string, string>> query .
#
# where equations.size() == values.size(),the values are positive.
# this represents the equations.return vector<double>. .
# The example above: equations = [ ["a", "b"], ["b", "c"] ].
# values = [2.0, 3.0]. queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ].
#
# The input is always valid. You may assume that
# evaluating the queries will result in no division by zero and there is no contradiction.

import collections


class Solution(object):
    def calcEquation(self, equations, values, query):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type query: List[List[str]]
        :rtype: List[float]
        """
        def check(up, down, lookup, visited):
            if up in lookup and down in lookup[up]:
                return (True, lookup[up][down])
            for k, v in lookup[up].iteritems():
                if k not in visited:
                    visited.add(k)
                    tmp = check(k, down, lookup, visited)
                    if tmp[0]:
                        return (True, v * tmp[1])
            return (False, 0)

        lookup = collections.defaultdict(dict)
        for i, e in enumerate(equations):
            lookup[e[0]][e[1]] = values[i]
            if values[i]:
                lookup[e[1]][e[0]] = 1.0 / values[i]

        result = []
        for q in query:
            visited = set()
            tmp = check(q[0], q[1], lookup, visited)
            result.append(tmp[1] if tmp[0] else -1)
        return result
