# Time:  O(1)
# Space: O(1)

class Vector2D:
    x, x_len = 0, 0
    y, y_len = 0, 0
    vec = None

    # Initialize your data structure here.
    # @param {integer[][]} vec2d
    def __init__(self, vec2d):
        self.vec = vec2d
        self.x = 0
        self.x_len = len(self.vec)
        if self.x != self.x_len:
            self.y = 0
            self.y_len = len(self.vec[self.x])
            self.adjustNextIter()

    # @return {integer}
    def next(self):
        ret = self.vec[self.x][self.y]
        self.y += 1
        self.adjustNextIter()
        return ret

    # @return {boolean}
    def hasNext(self):
        return self.x != self.x_len and self.y != self.y_len

    def adjustNextIter(self):
        while self.x != self.x_len and self.y == self.y_len: 
            self.x += 1
            if self.x != self.x_len:
                self.y = 0
                self.y_len = len(self.vec[self.x])
