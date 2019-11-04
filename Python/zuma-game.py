# for this problem, it should either relax time limit or
# add a description that a ball can be only inserted beside a ball with same color

import collections


# Time:  O((b+h) * h!*(b+h-1)!/(b-1)!)
# Space: O((b+h) * h!*(b+h-1)!/(b-1)!)
# brute force solution
class Solution_TLE_BUT_CORRECT(object):
    def findMinStep(self, board, hand):
        """
        :type board: str
        :type hand: str
        :rtype: int
        """
        def shrink(s):  # Time: O(n), Space: O(n)
            stack = []
            start = 0
            for i in xrange(len(s)+1):
                if i == len(s) or s[i] != s[start]:
                    if stack and stack[-1][0] == s[start]:
                        stack[-1][1] += i - start
                        if stack[-1][1] >= 3:
                            stack.pop()
                    elif s and i - start < 3:
                        stack += [s[start], i - start],
                    start = i
            result = []
            for p in stack:
                result += [p[0]] * p[1]
            return result

        def findMinStepHelper(board, hand, lookup):
            if not board: return 0
            if not hand: return float("inf")
            if tuple(hand) in lookup[tuple(board)]: return lookup[tuple(board)][tuple(hand)]

            result = float("inf")
            for i in xrange(len(hand)):
                for j in xrange(len(board)+1):
                    next_board = shrink(board[0:j] + hand[i:i+1] + board[j:])
                    next_hand = hand[0:i] + hand[i+1:]
                    result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 1)
            lookup[tuple(board)][tuple(hand)] = result
            return result

        lookup = collections.defaultdict(dict)
        board, hand = list(board), list(hand)
        result = findMinStepHelper(board, hand, lookup)
        return -1 if result == float("inf") else result


# Time:  O(b * b! * h!)
# Space: O(b * b! * h!)
# if a ball can be only inserted beside a ball with same color,
# we can do by this solution
class Solution_WRONG_GREEDY_BUT_ACCEPT(object):
    def findMinStep(self, board, hand):
        """
        :type board: str
        :type hand: str
        :rtype: int
        """
        def shrink(s):  # Time: O(n), Space: O(n)
            stack = []
            start = 0
            for i in xrange(len(s)+1):
                if i == len(s) or s[i] != s[start]:
                    if stack and stack[-1][0] == s[start]:
                        stack[-1][1] += i - start
                        if stack[-1][1] >= 3:
                            stack.pop()
                    elif s and i - start < 3:
                        stack += [s[start], i - start],
                    start = i
            result = []
            for p in stack:
                result += [p[0]] * p[1]
            return result

        def find(board, c, j):
            for i in xrange(j, len(board)):
                if board[i] == c:
                    return i
            return -1

        def findMinStepHelper(board, hand, lookup):
            if not board: return 0
            if not hand: return float("inf")
            if tuple(hand) in lookup[tuple(board)]: return lookup[tuple(board)][tuple(hand)]

            result = float("inf")
            for i in xrange(len(hand)):
                j = 0
                while j < len(board):
                    k = find(board, hand[i], j)
                    if k == -1:
                        break

                    if k < len(board) - 1 and board[k] == board[k+1]:
                        next_board = shrink(board[0:k] + board[k+2:])
                        next_hand = hand[0:i] + hand[i+1:]
                        result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 1)
                        k += 1
                    elif i > 0 and hand[i] == hand[i-1]:
                        next_board = shrink(board[0:k] + board[k+1:])
                        next_hand = hand[0:i-1] + hand[i+1:]
                        result = min(result, findMinStepHelper(next_board, next_hand, lookup) + 2)
                    j = k+1

            lookup[tuple(board)][tuple(hand)] = result
            return result

        lookup = collections.defaultdict(dict)
        board, hand = list(board), list(hand)
        hand.sort()
        result = findMinStepHelper(board, hand, lookup)
        return -1 if result == float("inf") else result
