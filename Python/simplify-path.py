# Time:  O(n)
# Space: O(n)

class Solution(object):
    # @param path, a string
    # @return a string
    def simplifyPath(self, path):
        stack, tokens = [], path.split("/")
        for token in tokens:
            if token == ".." and stack:
                stack.pop()
            elif token != ".." and token != "." and token:
                stack.append(token)
        return "/" + "/".join(stack)

