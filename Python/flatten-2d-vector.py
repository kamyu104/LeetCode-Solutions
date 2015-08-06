# Time:  O(1)
# Space: O(1)

class Vector2D:
    x, y = 0, 0
    vec = None

    # Initialize your data structure here.
    # @param {integer[][]} vec2d
    def __init__(self, vec2d):
        self.vec = vec2d
        self.x = 0
        if self.x != len(self.vec):
            self.y = 0
            self.adjustNextIter()

    # @return {integer}
    def next(self):
        ret = self.vec[self.x][self.y]
        self.y += 1
        self.adjustNextIter()
        return ret

    # @return {boolean}
    def hasNext(self):
        return self.x != len(self.vec) and self.y != len(self.vec[self.x])

    def adjustNextIter(self):
        while self.x != len(self.vec) and self.y == len(self.vec[self.x]): 
            self.x += 1
            if self.x != len(self.vec):
                self.y = 0
