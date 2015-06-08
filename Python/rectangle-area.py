# Time:  O(1)
# Space: O(1)
#
# Find the total area covered by two rectilinear rectangles in a 2D plane.
#
# Each rectangle is defined by its bottom left corner
# and top right corner as shown in the figure.
#
# Rectangle Area
# Assume that the total area is never beyond the maximum
# possible value of int.
#

class Solution:
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
