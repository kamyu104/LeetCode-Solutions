# Time:  O(t! / (n1! * n2! * ... nk!)), t is the total number of tickets,
#                                       ni is the number of the ticket which from is city i,
#                                       k is the total number of cities.
# Space: O(t)

import collections


class Solution(object):
    def findItinerary(self, tickets):
        """
        :type tickets: List[List[str]]
        :rtype: List[str]
        """
        def route_helper(origin, ticket_cnt, graph, ans):
            if ticket_cnt == 0:
                return True

            for i, (dest, valid)  in enumerate(graph[origin]):
                if valid:
                    graph[origin][i][1] = False
                    ans.append(dest)
                    if route_helper(dest, ticket_cnt - 1, graph, ans):
                        return ans
                    ans.pop()
                    graph[origin][i][1] = True
            return False

        graph = collections.defaultdict(list)
        for ticket in tickets:
            graph[ticket[0]].append([ticket[1], True])
        for k in graph.keys():
            graph[k].sort()

        origin = "JFK"
        ans = [origin]
        route_helper(origin, len(tickets), graph, ans)
        return ans

