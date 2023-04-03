// Time:  O(n)
// Space: O(n)

// freq table, constructive algorithms
class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            if (cnt[x] == size(result)) {
                result.emplace_back();
            }
            result[cnt[x]++].emplace_back(x);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
// freq table, constructive algorithms
class Solution2 {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> result;
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        while (!empty(cnt)) {
            unordered_map<int, int> new_cnt;
            result.emplace_back();
            for (const auto& [k, v] : cnt) {
                result.back().emplace_back(k);
                if (v - 1) {
                    new_cnt[k] = v - 1;
                }
            }
            cnt = move(new_cnt);
        }
        return result;
    }
};
