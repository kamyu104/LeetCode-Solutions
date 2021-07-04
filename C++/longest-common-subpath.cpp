// Time:  O(m * nlogn)
// Space: O(n)

class Solution {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int left = 1, right = size(*min_element(cbegin(paths), cend(paths),
                                                [](const auto& x, const auto& y) {
                                                    return size(x) < size(y);
                                                }));
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (!check(paths, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    template<typename T>
    struct VectorHash {
        size_t operator()(const std::vector<T>& v) const {
            size_t seed = 0;
            for (const auto& i : v) {
                seed ^= std::hash<T>{}(i)  + 0x9e3779b9 + (seed<<6) + (seed>>2);
            }
            return seed;
        }
    };

    bool check(const vector<vector<int>>& paths, int x) {
        unordered_set<vector<int>, VectorHash<int>> intersect = RabinKarp(paths[0], x);
        for (int i = 1; i < size(paths); ++i) {
            intersect = set_intersection<vector<int>, VectorHash<int>>(intersect, RabinKarp(paths[i], x));
            if (empty(intersect)) {
                return false;
            }
        }
        return true;
    }
    
    unordered_set<vector<int>, VectorHash<int>> RabinKarp(const vector<int>& arr, int x) {
        static const int MOD = 1e9 + 7;  // MOD could be the min prime of 7-digit number (1e6+3)
        static const vector<int> P = {113, 109};  // double hashing, P could be {2, 3}
        vector<int> hashes, powers;
        for (const auto& p : P) {
            int64_t h = 0, power = 1;
            for (int i = 0; i < x; ++i) {
                h = (h * p + arr[i]) % MOD;
                power = (power * p) % MOD;
            }
            hashes.emplace_back(h);
            powers.emplace_back(power);
        }
        unordered_set<vector<int>, VectorHash<int>> lookup = {hashes};
        for (int i = x; i < size(arr); ++i) {
            for (int j = 0; j < size(P); ++j) {
                hashes[j] = ((int64_t(hashes[j]) * P[j] - int64_t(arr[i - x]) * powers[j] + arr[i]) % MOD + MOD) % MOD;
            }
            lookup.emplace(hashes);
        }
        return lookup;
    }

    template<typename T, typename H>
    unordered_set<T, H> set_intersection(const unordered_set<T, H>& a,
                                         const unordered_set<T, H>& b) {
        if (a.size() > b.size()) {
            return set_intersection(b, a);
        }
        unordered_set<T, H> result;
        for (const auto& x : a) {
            if (b.count(x)) {
                result.emplace(x);
            }
        }
        return result;
    }
};

// Time:  O(m * nlogn)
// Space: O(n)
class Solution2 {
public:
    int longestCommonSubpath(int n, vector<vector<int>>& paths) {
        int left = 1, right = size(*min_element(cbegin(paths), cend(paths),
                                                [](const auto& x, const auto& y) {
                                                    return size(x) < size(y);
                                                }));
        while (left <= right) {
            const auto& mid = left + (right - left) / 2;
            if (!check(paths, mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return right;
    }

private:
    bool check(const vector<vector<int>>& paths, int x) {
        unordered_set<int64_t> intersect = RabinKarp(paths[0], x);
        for (int i = 1; i < size(paths); ++i) {
            intersect = set_intersection<int64_t>(intersect, RabinKarp(paths[i], x));
            if (empty(intersect)) {
                return false;
            }
        }
        return true;
    }
    
    unordered_set<int64_t> RabinKarp(const vector<int>& arr, int x) {
        static const int64_t MOD = 1e11 + 19;  // MOD is the min prime of 12-digit number
        static const int64_t P = 1e5 + 1;  // max(x for p in paths for x in p)+1
        int64_t h = 0, power = 1;
        for (int i = 0; i < x; ++i) {
            h = (h * P + arr[i]) % MOD;
            power = (power * P) % MOD;
        }
        unordered_set<int64_t> lookup = {h};
        for (int i = x; i < size(arr); ++i) {
            h = ((h * P - arr[i - x] * power + arr[i]) % MOD + MOD) % MOD;
            lookup.emplace(h);
        }
        return lookup;
    }

    template<typename T>
    unordered_set<T> set_intersection(const unordered_set<T>& a,
                                      const unordered_set<T>& b) {
        if (a.size() > b.size()) {
            return set_intersection(b, a);
        }
        unordered_set<T> result;
        for (const auto& x : a) {
            if (b.count(x)) {
                result.emplace(x);
            }
        }
        return result;
    }
};

