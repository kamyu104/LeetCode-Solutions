// Time:  O(n)
// Space: O(1)

// Heap solution.
class Solution {
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
class Solution2 {
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
