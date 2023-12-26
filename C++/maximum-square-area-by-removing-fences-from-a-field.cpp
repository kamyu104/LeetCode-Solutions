// Time:  O(h^2 + v^2)
// Space: O(min(h, v)^2)

// hash table
class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        static const int MOD = 1e9 + 7;

        int64_t result = -1;
        unordered_set<int64_t> lookup;
        const auto& diff = [&](auto& arr, int x, bool check) {
            arr.emplace_back(1);
            arr.emplace_back(x);
            for (int i = 0; i < size(arr); ++i) {
                for (int j = i + 1; j < size(arr); ++j) {
                    if (!check) {
                        lookup.insert(abs(arr[i] - arr[j]));  // use insert rather than emplace to speed up
                        continue;
                    }
                    if (lookup.count(abs(arr[i] - arr[j]))) {
                        result = max(result, static_cast<int64_t>(arr[i] - arr[j]) * (arr[i] - arr[j]));
                    }
                }
            }
        };

        if (size(hFences) > size(vFences)) {
            swap(hFences, vFences);
            swap(m, n);
        }
        diff(hFences, m, false);
        diff(vFences, n, true);
        return result % MOD;
    }
};

// Time:  O(h^2 + v^2)
// Space: O(h^2 + v^2)
// hash table
class Solution2 {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hFences, vector<int>& vFences) {
        static const int MOD = 1e9 + 7;

        const auto& diff = [](auto& arr, int x) {
            unordered_set<int64_t> lookup;
            arr.emplace_back(1);
            arr.emplace_back(x);
            for (int i = 0; i < size(arr); ++i) {
                for (int j = i + 1; j < size(arr); ++j) {
                    lookup.insert(abs(arr[i] - arr[j]));  // use insert rather than emplace to speed up
                }
            }
            return lookup;
        };

        const auto& lookup = diff(hFences, m);
        int64_t result = -1;
        for (const auto& x : diff(vFences, n)) {
            if (lookup.count(x)) {
                result = max(result, x * x);
            }
        }
        return result % MOD;
    }
};
