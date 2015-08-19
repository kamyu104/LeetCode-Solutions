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
            if (heap.top() % 2 == 0) {
                ugly_number = heap.top();
                heap.pop();
                heap.emplace(ugly_number * 2);
            }
            else if (heap.top() % 3 == 0) {
                ugly_number = heap.top();
                heap.pop();
                heap.emplace(ugly_number * 2);
                heap.emplace(ugly_number * 3);
            }
            else {
                ugly_number = heap.top();
                heap.pop();
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
        
        bst.insert(1);
        for (int i = 0; i < n; ++i) {
            if (*bst.cbegin() % 2 == 0) {
                ugly_number = *bst.cbegin();
                bst.erase(bst.cbegin());
                bst.insert(ugly_number * 2);
            }
            else if (*bst.cbegin() % 3 == 0) {
                ugly_number = *bst.cbegin();
                bst.erase(bst.cbegin());
                bst.insert(ugly_number * 2);
                bst.insert(ugly_number * 3);
            }
            else {
                ugly_number = *bst.cbegin();
                bst.erase(bst.cbegin());
                bst.insert(ugly_number * 2);
                bst.insert(ugly_number * 3);
                bst.insert(ugly_number * 5);
            }
        }
        return ugly_number;   
    }
};
