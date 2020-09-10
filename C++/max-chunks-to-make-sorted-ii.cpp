// Time:  O(n)
// Space: O(n)

// mono stack solution
class Solution {
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

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    int maxChunksToSorted(vector<int>& arr) {
        vector<int> idxs(arr.size());
        iota(idxs.begin(), idxs.end(), 0);
        sort(idxs.begin(), idxs.end(),
             [&](int i1, int i2) {
                 return arr[i1] != arr[i2] ? arr[i1] < arr[i2] : i1 < i2;
             });

        int result = 0;
        for (auto i = 0, max_i = 0; i < idxs.size(); ++i) {
            max_i = max(max_i, idxs[i]);
            if (max_i == i) ++result;
        }
        return result;
    }
};
