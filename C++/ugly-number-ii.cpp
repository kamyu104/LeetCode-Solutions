// Time:  O(n)
// Space: O(n)

// DP solution. (12ms)
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> uglies(n);
        uglies[0] = 1;
    
        int f2 = 2, f3 = 3, f5 = 5;
        int idx2 = 0, idx3 = 0, idx5 = 0;
    
        for (int i = 1; i < n; ++i) {
            int min_val = min(min(f2, f3), f5);
            uglies[i] = min_val;
    
            if (min_val == f2) {
                f2 = 2 * uglies[++idx2];
            }
            if (min_val == f3) {
                f3 = 3 * uglies[++idx3];
            }
            if (min_val == f5) {
                f5 = 5 * uglies[++idx5];
            }
        }
    
        return uglies[n - 1];
    }
};

// Time:  O(n)
// Space: O(1)
// Heap solution. (148ms)
class Solution2 {
public:
    int nthUglyNumber(int n) {
        long long ugly_number = 0;
        priority_queue<long long , vector<long long>, greater<long long>> heap;
        
        heap.emplace(1);
        for (int i = 0; i < n; ++i) {
            ugly_number = heap.top();
            heap.pop();
            if (ugly_number % 2 == 0) {
                heap.emplace(ugly_number * 2);
            } else if (ugly_number % 3 == 0) {
                heap.emplace(ugly_number * 2);
                heap.emplace(ugly_number * 3);
            } else {
                heap.emplace(ugly_number * 2);
                heap.emplace(ugly_number * 3);
                heap.emplace(ugly_number * 5);
            }
        }
        return ugly_number;   
    }
};

// BST solution.
class Solution3 {
public:
    int nthUglyNumber(int n) {
        long long ugly_number = 0;
        set<long long> bst;
        
        bst.emplace(1);
        for (int i = 0; i < n; ++i) {
            ugly_number = *bst.cbegin();
            bst.erase(bst.cbegin());
            if (ugly_number % 2 == 0) {
                bst.emplace(ugly_number * 2);
            } else if (ugly_number % 3 == 0) {
                bst.emplace(ugly_number * 2);
                bst.emplace(ugly_number * 3);
            } else {
                bst.emplace(ugly_number * 2);
                bst.emplace(ugly_number * 3);
                bst.emplace(ugly_number * 5);
            }
        }
        return ugly_number;   
    }
};
