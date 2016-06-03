# Time:  O(s) per move, s is the current length of the snake.
# Space: O(s)

from collections import deque

class SnakeGame(object):

    def __init__(self, width,height,food):
        """
        Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0].
        :type width: int
        :type height: int
        :type food: List[List[int]]
        """
        self.__width = width
        self.__height = height
        self.__score = 0
        self.__food = deque(food)
        self.__snake = deque([(0, 0)])
        self.__direction =  {"U":(-1, 0), "L":(0, -1), "R":(0, 1), "D":(1, 0)};
        

    def move(self, direction):
        """
        Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body.
        :type direction: str
        :rtype: int
        """
        def valid(x, y):
            return 0 <= x < self.__height and \
                   0 <= y < self.__width and \
                   (x, y) not in self.__snake

        d = self.__direction[direction]
        x, y = self.__snake[-1][0] + d[0], self.__snake[-1][1] + d[1]
        tail = self.__snake[-1]
        self.__snake.popleft()
        if not valid(x, y):
            return -1
        elif self.__food and (self.__food[0][0], self.__food[0][1]) == (x, y):
            self.__score += 1
            self.__food.popleft()
            self.__snake.appendleft(tail)
        self.__snake.append((x, y))
        return self.__score


# Your SnakeGame object will be instantiated and called as such:
# obj = SnakeGame(width, height, food)
# param_1 = obj.move(direction)
