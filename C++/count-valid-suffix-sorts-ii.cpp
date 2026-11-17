// Time:  O(n + m)
// Space: O(n + m)

// freq table, z-function, prefix sum, sliding window
// Template: https://cp-algorithms.com/string/z-function.html
vector<int> z_function(const vector<int>& s) {  // Time: O(n), Space: O(n)
    vector<int> z(size(s));
    for (int i = 1, l = 0, r = 0; i < size(z); ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < size(z) && s[z[i]] == s[i + z[i]]) {
            ++z[i];
        }
        if (i + z[i] - 1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    return z;
}

class Solution {
public:
    vector<int> countSuffix(vector<int>& nums, vector<int>& target) {
        vector<int> s(nums);
        s.reserve(size(nums) + 1 + size(target));
        s.emplace_back(0);
        s.insert(end(s), cbegin(target), cend(target));
        const auto& z = z_function(s);
        vector<int> prefix(size(target));
        for (int i = 0; i + 1 < size(target); ++i) {
            prefix[i + 1] = target[i] >= target[i + 1] ? prefix[i] : i + 1;
        }
        unordered_map<int, int> cnt;
        for (const auto& x : nums) {
            ++cnt[x];
        }
        const auto& update = [&](int x, int d) {
            cnt[x] += d;
            if (cnt[x] == 0) {
                cnt.erase(x);
            }
        };

        vector<int> result;
        result.reserve(size(target) - size(nums) + 1);
        for (int i = 0; i < size(target); ++i) {
            update(target[i], -1);
            if (i < size(nums) - 1) {
                continue;
            }
            result.emplace_back(empty(cnt) ? max(min(z[size(nums) + 1 + (i - size(nums) + 1)], static_cast<int>(size(nums)) - 1) - max(prefix[i] - (i - static_cast<int>(size(nums)) + 1), 0) + 1, 0) : 0);
            update(target[i - size(nums) + 1], +1);
        }
        return result;
    }
};
