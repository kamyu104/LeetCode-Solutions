// Time:  O(nlogk + n * sqrt(k))
// Space: O(n + sqrt(k)), number of factors of k is at most sqrt(k)

// math, number theory
class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> idxs;
        for (int i = 0; i < size(nums); ++i) {
            idxs[nums[i]].emplace_back(i);
        }
        int result = 0;
        for (const auto& [_, idx] : idxs) {
            unordered_map<int, int> gcds;
            for (const auto& i : idx) {
                const int gcd_i = gcd(i, k);
                for (const auto& [gcd_j, cnt] : gcds) {
                    if (gcd_i * gcd_j % k == 0) {
                        result += cnt;
                    }
                }
                ++gcds[gcd_i];
            }
        }
        return result;
    }
};

// Time:  O(nlogk + n * sqrt(k)^2) = O(n * k)
// Space: O(n * sqrt(k)), number of factors of k is at most sqrt(k)
// math, number theory
class Solution2 {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, unordered_map<int, int>> cnts;
        for (int i = 0; i < size(nums); ++i) {
            ++cnts[nums[i]][gcd(i, k)];
        }
        int result = 0;
        for (const auto& [_, cnt] : cnts) {
            for (const auto& [x, c1] : cnt) {
                for (const auto& [y, c2] : cnt) {
                    if (x > y || x * y % k) {
                        continue;
                    }
                    result += (x != y) ? c1 * c2 : c1 * (c1 - 1) / 2;
                }
            }
        }
        return result;
    }
};

// Time:  O(n^2)
// Space: O(n)
// brute force
class Solution3 {
public:
    int countPairs(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> idxs;
        for (int i = 0; i < size(nums); ++i) {
            idxs[nums[i]].emplace_back(i);
        }
        int result = 0;
        for (const auto& [_, idx] : idxs) {
            for (int i = 0; i < size(idx); ++i) {
                for (int j = i + 1; j < size(idx); ++j) {
                    if (idx[i] * idx[j] % k == 0) {
                        ++result;
                    }
                }
            }
        }
        return result;
    }
};
