# Time:  O(n^3)
# Space: O(n^2)

# A game on an undirected graph is played by two players, Mouse and Cat, who alternate turns.
#
# The graph is given as follows: graph[a] is a list of all nodes b such that ab is an edge of the graph.
#
# Mouse starts at node 1 and goes first, Cat starts at node 2 and goes second, and there is a Hole at node 0.
#
# During each player's turn, they must travel along one edge of the graph that meets where they are.
# For example, if the Mouse is at node 1, it must travel to any node in graph[1].
#
# Additionally, it is not allowed for the Cat to travel to the Hole (node 0.)
#
# Then, the game can end in 3 ways:
#
# If ever the Cat occupies the same node as the Mouse, the Cat wins.
# If ever the Mouse reaches the Hole, the Mouse wins.
# If ever a position is repeated
# (ie. the players are in the same position as a previous turn,
# and it is the same player's turn to move), the game is a draw.
# Given a graph, and assuming both players play optimally,
# return 1 if the game is won by Mouse, 2 if the game is won by Cat, and 0 if the game is a draw.
#
# Example 1:
#
# Input: [[2,5],[3],[0,4,5],[1,4,5],[2,3],[0,2,3]]
# Output: 0
# Explanation:
# 4---3---1
# |   |
# 2---5
#  \ /
#   0
#
# Note:
# - 3 <= graph.length <= 50
# - It is guaranteed that graph[1] is non-empty.
# - It is guaranteed that graph[2] contains a non-zero element. 
                                
class Solution(object):
    def catMouseGame(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        HOLE, MOUSE_START, CAT_START = range(3)
        DRAW, MOUSE, CAT = range(3)

        def move(lookup, i, other_i, is_mouse_turn):
            key = (i, other_i, is_mouse_turn)
            if key in lookup:
                return lookup[key]

            lookup[key] = DRAW
            if is_mouse_turn:
                skip, target, win, lose = other_i, HOLE, MOUSE, CAT
            else:
                skip, target, win, lose = HOLE, other_i, CAT, MOUSE                
            for nei in graph[i]:
                if nei == target:
                    result = win
                    break
            else:
                result = lose
                for nei in graph[i]:                
                    if nei == skip:
                        continue
                    tmp = move(lookup, other_i, nei, not is_mouse_turn)
                    if tmp == win:
                        result = win
                        break
                    if tmp == DRAW:
                        result = DRAW
            lookup[key] = result
            return result

        return move({}, MOUSE_START, CAT_START, True)
