# Time:  O(n)
# Space: O(1)

class MinStack(object):
    def __init__(self):
        self.min = None
        self.stack = []

    # @param x, an integer
    # @return an integer
    def push(self, x):
        if not self.stack:
            self.stack.append(0)
            self.min = x
        else:
            self.stack.append(x - self.min)
            if x < self.min:
                self.min = x

    # @return nothing
    def pop(self):
        x = self.stack.pop()
        if x < 0:
            self.min = self.min - x

    # @return an integer
    def top(self):
        x = self.stack[-1]
        if x > 0:
            return x + self.min
        else:
            return self.min

    # @return an integer
    def getMin(self):
        return self.min

# Time:  O(n)
# Space: O(n)
class MinStack2(object):
    def __init__(self):
        self.stack, self.minStack = [], []
    # @param x, an integer
    # @return an integer
    def push(self, x):
        self.stack.append(x)
        if len(self.minStack):
            if x < self.minStack[-1][0]:
                self.minStack.append([x, 1])
            elif x == self.minStack[-1][0]:
                self.minStack[-1][1] += 1
        else:
            self.minStack.append([x, 1])

    # @return nothing
    def pop(self):
        x = self.stack.pop()
        if x == self.minStack[-1][0]:
            self.minStack[-1][1] -= 1
            if self.minStack[-1][1] == 0:
                self.minStack.pop()

    # @return an integer
    def top(self):
        return self.stack[-1]

    # @return an integer
    def getMin(self):
        return self.minStack[-1][0]

# time: O(1)
# space: O(n)

class MinStack3(object):

    def __init__(self):
        self.stack = []

    def push(self, x):
        if self.stack:
            current_min = min(x, self.stack[-1][0])
            self.stack.append((current_min, x))
        else:
            self.stack.append((x, x))

    def pop(self):
        return self.stack.pop()[1]

    def top(self):
        return self.stack[-1][1]

    def getMin(self):
        return self.stack[-1][0]
