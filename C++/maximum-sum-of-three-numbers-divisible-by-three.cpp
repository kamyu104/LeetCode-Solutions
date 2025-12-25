// Time:  O(n)
// Space: O(1)

// sort, math
class Solution {
public:
    int maximumSum(vector<int>& nums) {
        const auto& add = [](auto& arr, int x) {
            for (int i = 0; i < size(arr); ++i) {
                if (x > arr[i]) {
                    swap(arr[i], x);
                }
            }
            if (size(arr) != 3) {
                arr.emplace_back(x);
            }
        };

        vector<vector<int>> group(3);
        for (const auto& x : nums) {
            add(group[x % 3], x);
        }
        int result = 0;
        for (auto& g : group) {
            if (size(g) == 3) {
                result = max(result, accumulate(cbegin(g), cend(g), 0));
            }
        }
        if (!empty(group[0]) && !empty(group[1]) && !empty(group[2])) {
            result = max(result, group[0][0] + group[1][0] + group[2][0]);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, math
class Solution2 {
public:
    int maximumSum(vector<int>& nums) {
        vector<vector<int>> group(3);
        for (const auto& x : nums) {
            group[x % 3].emplace_back(x);
        }
        int result = 0;
        for (auto& g : group) {
            sort(begin(g), end(g), greater<int>());
            if (size(g) >= 3) {
                result = max(result, accumulate(cbegin(g), cbegin(g) + 3, 0));
            }
        }
        if (!empty(group[0]) && !empty(group[1]) && !empty(group[2])) {
            result = max(result, group[0][0] + group[1][0] + group[2][0]);
        }
        return result;
    }
};
