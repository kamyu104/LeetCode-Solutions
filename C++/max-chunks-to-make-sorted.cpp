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
// Space: O(1)
// mono stack solution
class Solution2 {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> increasing_stk;
        for (const auto& num : arr) {
            if (increasing_stk.empty() || increasing_stk.back() <= num) {
                increasing_stk.emplace_back(num);
                continue;
            }
            int max_num = increasing_stk.back();
            while (!increasing_stk.empty() && increasing_stk.back() > num) {
                increasing_stk.pop_back();
            }
            increasing_stk.emplace_back(max_num);
        }
        return size(increasing_stk);
    }
};

