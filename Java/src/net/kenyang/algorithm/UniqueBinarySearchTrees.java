package net.kenyang.algorithm;

/**
 * Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
 * 
 * For example,
 * Given n = 3, there are a total of 5 unique BST's.
 * @author Ken Yang
 *
 */
public class UniqueBinarySearchTrees {
    
    
    public int numTrees(int n) {
        
        if (n<2) {
            return 1;
        }
        int ans = 0;
        for(int i = 0; i < n; i++) {
            ans += numTrees(i) * numTrees(n-i-1);
        }
        return ans;
        
    }
    
}
