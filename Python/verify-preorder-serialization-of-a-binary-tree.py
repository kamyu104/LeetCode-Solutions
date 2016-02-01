# Time:  O(n)
# Space: O(1)

# One way to serialize a binary tree is to use pre-oder traversal.
# When we encounter a non-null node, we record the node's value. 
# If it is a null node, we record using a sentinel value such as #.
#
#      _9_
#     /   \
#   3     2
#   / \   / \
#  4   1  #  6
# / \ / \   / \
# # # # #   # #
# For example, the above binary tree can be serialized to the string
# "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.
#
# Given a string of comma separated values, verify whether it is a 
# correct preorder traversal serialization of a binary tree. 
# Find an algorithm without reconstructing the tree.
#
# Each comma separated value in the string must be either an integer
# or a character '#' representing null pointer.
#
# You may assume that the input format is always valid, for example
# it could never contain two consecutive commas such as "1,,3".
#
# Example 1:
# "9,3,4,#,#,1,#,#,2,#,6,#,#"
# Return true
#
# Example 2:
# "1,#"
# Return false
#
# Example 3:
# "9,#,#,1"
# Return false

class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        def split_iter(s, tok):
            start = 0
            for i in xrange(len(s)):
                if s[i] == tok:
                    yield s[start:i]
                    start = i + 1
            yield s[start:]

        if not preorder:
            return False

        depth, cnt = 0, preorder.count(',') + 1
        for tok in split_iter(preorder, ','):
            cnt -= 1
            if tok == "#":
                depth -= 1;
                if depth < 0:
                    break
            else:
                depth += 1
        return cnt == 0 and depth < 0
