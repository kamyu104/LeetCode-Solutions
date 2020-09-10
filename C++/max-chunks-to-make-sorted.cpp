// Time:  O(n)
// Space: O(1)

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int result = 0;
        for (int i = 0, max_i = 0; i < arr.size(); ++i) {
            max_i = max(max_i, arr[i]);
            if (max_i == i) ++result;
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// mono stack solution
class Solution2 {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> increasing_stk;
        for (const auto& num : arr) {
            int max_num = empty(increasing_stk) ? num : max(increasing_stk.back(), num);
            while (!empty(increasing_stk) && increasing_stk.back() > num) {
                increasing_stk.pop_back();
            }
            increasing_stk.emplace_back(max_num);
        }
        return size(increasing_stk);
    }
};

