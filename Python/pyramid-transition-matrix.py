# Time:  O(b^2 * a^(b*(b+1)/2-1)), a is the size of allowed, 
#                                  b is the length of bottom
# Space: O(a + b^2) 

# We are stacking blocks to form a pyramid. Each block has a color which is a one letter string, like `'Z'`.
#
# For every block of color `C` we place not in the bottom row,
# we are placing it on top of a left block of color `A` and right block of color `B`.
# We are allowed to place the block there only if `(A, B, C)` is an allowed triple.
#
# We start with a bottom row of bottom, represented as a single string.
# We also start with a list of allowed triples allowed.
# Each allowed triple is represented as a string of length 3.
#
# Return true if we can build the pyramid all the way to the top, otherwise false.
#
# Example 1:
# Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
# Output: true
# Explanation:
# We can stack the pyramid like this:
#     A
#    / \
#   D   E
#  / \ / \
# X   Y   Z
#
# This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
# Example 1:
# Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
# Output: false
# Explanation:
# We can't stack the pyramid to the top.
# Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
#
# Note:
# bottom will be a string with length in range [2, 100].
# allowed will have length in range [0, 350].
# Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.

# dfs solution
class Solution(object):
    def pyramidTransition(self, bottom, allowed):
        """
        :type bottom: str
        :type allowed: List[str]
        :rtype: bool
        """
        def pyramidTransitionHelper(bottom, edges):
            def dfs(bottom, edges, new_bottom, idx):
                if idx == len(bottom)-1:
                    return pyramidTransitionHelper(new_bottom, edges)
                for i in edges[ord(bottom[idx])-ord('A')][ord(bottom[idx+1])-ord('A')]:
                    new_bottom[idx] = chr(i+ord('A'));
                    if dfs(bottom, edges, new_bottom, idx+1):
                        return True
                return False
            
            if len(bottom) == 1:
                return True
            for i in xrange(len(bottom)-1):
                if not edges[ord(bottom[i])-ord('A')][ord(bottom[i+1])-ord('A')]:
                    return False
            new_bottom = ['A'] * (len(bottom)-1)
            return dfs(bottom, edges, new_bottom, 0)
    
        edges = [[[] for _ in xrange(7)] for _ in xrange(7)]
        for s in allowed:
            edges[ord(s[0])-ord('A')][ord(s[1])-ord('A')].append(ord(s[2])-ord('A'))
        return pyramidTransitionHelper(bottom, edges)
