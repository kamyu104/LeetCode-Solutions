# Time:  O(1)
# Space: O(1)

class Solution(object):
    # @param {integer} A
    # @param {integer} B
    # @param {integer} C
    # @param {integer} D
    # @param {integer} E
    # @param {integer} F
    # @param {integer} G
    # @param {integer} H
    # @return {integer}
    def computeArea(self, A, B, C, D, E, F, G, H):
        return (D - B) * (C - A) + \
               (G - E) * (H - F) - \
               max(0, (min(C, G) - max(A, E))) * \
               max(0, (min(D, H) - max(B, F)))

