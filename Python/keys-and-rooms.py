# Time:  O(n!)
# Space: O(n)

class Solution(object):
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        lookup = set([0])
        stack = [0]
        while stack:
            node = stack.pop()
            for nei in rooms[node]:
                if nei not in lookup:
                    lookup.add(nei)
                    if len(lookup) == len(rooms):
                        return True
                    stack.append(nei)
        return len(lookup) == len(rooms)

