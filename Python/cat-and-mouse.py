# Time:  O(n^3)
# Space: O(n^2)

class Solution(object):
    def catMouseGame(self, graph):
        """
        :type graph: List[List[int]]
        :rtype: int
        """
        HOLE, MOUSE_START, CAT_START = range(3)
        DRAW, MOUSE, CAT = range(3)

        def move(graph, lookup, i, other_i, is_mouse_turn):
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
                    tmp = move(graph, lookup, other_i, nei, not is_mouse_turn)
                    if tmp == win:
                        result = win
                        break
                    if tmp == DRAW:
                        result = DRAW
            lookup[key] = result
            return result

        return move(graph, {}, MOUSE_START, CAT_START, True)

