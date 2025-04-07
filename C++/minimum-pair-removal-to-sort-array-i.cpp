// Time:  O(nlogn)
// Space: O(n)

// simulation, doubly linked list, bst
class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        vector<int64_t> arr(cbegin(nums), cend(nums));
        vector<int> left(size(arr) + 1);
        iota(begin(left), end(left), -1);
        vector<int> right(size(arr));
        iota(begin(right), end(right), 1);
        int cnt = 0;
        set<pair<int64_t, int>> bst;
        const auto& add = [&](int i) {
            if (0 <= i && i < right[i] && right[i] < size(arr)) {
                bst.emplace(arr[i] + arr[right[i]], i);
                if (arr[i] > arr[right[i]]) {
                    ++cnt;
                }
            }
        };

        const auto& remove = [&](int i) {
            if (0 <= i && i < right[i] && right[i] < size(arr)) {
                bst.erase({arr[i] + arr[right[i]], i});
                if (arr[i] > arr[right[i]]) {
                    --cnt;
                }
            }
        };

        for (int i = 0; i + 1 < size(arr); ++i) {
            bst.emplace(arr[i] + arr[i + 1], i);
            if (arr[i] > arr[i + 1]) {
                ++cnt;
            }
        }
        int result = 0;
        for (; cnt; ++result) {
            const auto [_, i] = *cbegin(bst);
            remove(left[i]);
            remove(i);
            remove(right[i]);
            arr[i] += arr[right[i]];
            left[right[right[i]]] = i;
            right[i] = right[right[i]];
            add(left[i]);
            add(i);
        }
        return result;
    }
};
