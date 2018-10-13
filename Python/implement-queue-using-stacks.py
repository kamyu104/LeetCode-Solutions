# Time:  O(1), amortized
# Space: O(n)

class Queue(object):
    # initialize your data structure here.
    def __init__(self):
        self.A, self.B = [], []

    # @param x, an integer
    # @return nothing
    def push(self, x):
        self.A.append(x)

    # @return an integer
    def pop(self):
        self.peek()
        return self.B.pop()

    # @return an integer
    def peek(self):
        if not self.B:
            while self.A:
                self.B.append(self.A.pop())
        return self.B[-1]

    # @return an boolean
    def empty(self):
        return not self.A and not self.B

