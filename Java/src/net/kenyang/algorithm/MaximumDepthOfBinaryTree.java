package net.kenyang.algorithm;

/**
 * Given a binary tree, find its maximum depth. </br>
 * The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * @author Ken Yang
 *
 */
public class MaximumDepthOfBinaryTree {
    public class TreeNode {
        int val;
        TreeNode left;
        TreeNode right;
        TreeNode(int x) {
            val = x;
        }
    }

    public int maxDepth(TreeNode root) {

        if (root == null) {
            return 0;
        }

        int iRightDepth = maxDepth(root.right);
        int iLefttDepth = maxDepth(root.left);
        return (iRightDepth > iLefttDepth) ? iRightDepth + 1 : iLefttDepth + 1;
    }
}
