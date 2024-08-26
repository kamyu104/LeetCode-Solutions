// Time:  O(n * l^2)
// Space: O(n)

// freq table, combinatorics
class Solution {
public:
    int countPairs(vector<int>& nums) {
        static const int L = 7;
        vector<int> POW10(L);
        POW10[0] = 1;
        for (int i = 0; i + 1 < L; ++i) {
            POW10[i+1] = POW10[i] * 10;
        }
        unordered_map<int, int> cnt1;
        for (const auto& x : nums) {
            ++cnt1[x];
        }
        unordered_map<int, int> cnt2;
        for (const auto& [x, v] : cnt1) {
            for (int i = 0; i < L; ++i) {
                const int a = x / POW10[i] % 10;
                for (int j = i + 1; j < L; ++j) {
                    const int b = x /POW10[j] % 10;
                    if (a == b || !cnt1.count(x - a * (POW10[i] - POW10[j]) + b * (POW10[i] - POW10[j]))) {
                        continue;
                    }
                    cnt2[x - a * (POW10[i] - POW10[j]) + b * (POW10[i] - POW10[j])] += v;
                }
            }
        }
        int result = 0;
        for (const auto& [_, v] : cnt1) {
            result += v * (v - 1) / 2;
        }
        int total = 0;
        for (const auto& [x, v] : cnt1) {
            total += v * cnt2[x];
        }
        return result + total / 2;
    }
};

// Time:  O(n * l^(2 * k)) = O(n * l^2)
// Space: O(n + l^(2 * k)) = O(n + l^2) = O(n)
// freq table, combinatorics, bfs
class Solution2 {
public:
    int countPairs(vector<int>& nums) {
        static const int L = 7;
        static const int K = 1;
        vector<int> POW10(L);
        POW10[0] = 1;
        for (int i = 0; i + 1 < L; ++i) {
            POW10[i+1] = POW10[i] * 10;
        }
        const auto& at_most = [&](int k, int x) {
            unordered_set<int> lookup = {x};
            vector<int> result = {x};
            for (int u = 0; k; --k) {
                for (int v = size(result); u < v; ++u) {
                    const int x = result[u];
                    for (int i = 0; i < L; ++i) {
                        const int a = x / POW10[i] % 10;
                        for (int j = i + 1; j < L; ++j) {
                            const int b = x / POW10[j] % 10;
                            if (a == b) {
                                continue;
                            }
                            const int y = x -a * (POW10[i] - POW10[j]) + b * (POW10[i] - POW10[j]);
                            if (lookup.count(y)) {
                                continue;
                            }
                            lookup.emplace(y);
                            result.emplace_back(y);
                        }
                    }
                }
            }
            return result;
        };

        int result = 0;
        unordered_map<int, int> cnt1;
        for (const auto& x : nums) {
            ++cnt1[x];
        }
        unordered_map<int, int> cnt2;
        for (const auto& [x, v] : cnt1) {
            result += cnt2[x] * v + v * (v - 1) / 2;
            for (const auto& x : at_most(K, x)) {
                if (!cnt1.count(x)) {
                    continue;
                }
                cnt2[x] += v;
            }
        }
        return result;
    }
};
