// Time:  O(nlogn)
// Space: O(1)

// binary search, greedy
class Solution {
public:
    int minLength(string s, int numOps) {
        const auto& binary_search = [](int left, int right, const auto& check) {
            while (left <= right) {
                const int mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        const auto& check = [&](int x) {
            if (x == 1) {
                int cnt = 0;
                for (int i = 0; i < size(s); ++i) {
                    if (s[i] - '0' != i % 2) {
                        ++cnt;
                    }
                }
                return min(cnt, static_cast<int>(size(s)) - cnt) <= numOps;
            }
            int total = 0;
            for (int i = 0, cnt = 0; i < size(s); ++i) {
                ++cnt;
                if (i + 1 == size(s) || s[i + 1] != s[i]) {
                    total += cnt / (x + 1);
                    cnt = 0;
                }
            }
            return total <= numOps;
        };
        
        return binary_search(1, size(s), check);
    }
};

// Time:  O(nlogn)
// Space: O(n)
// binary search, greedy
class Solution2 {
public:
    int minLength(string s, int numOps) {
        const auto& binary_search = [](int left, int right, const auto& check) {
            while (left <= right) {
                const int mid = left + (right - left) / 2;
                if (check(mid)) {
                    right = mid - 1;
                } else {
                    left = mid + 1;
                }
            }
            return left;
        };

        vector<int> arr;
        const auto& check = [&](int x) {
            if (x == 1) {
                int cnt = 0;
                for (int i = 0; i < size(s); ++i) {
                    if (s[i] - '0' != i % 2) {
                        ++cnt;
                    }
                }
                return min(cnt, static_cast<int>(size(s)) - cnt) <= numOps;
            }
            int cnt = 0;
            for (const auto& l : arr) {
                cnt += l / (x + 1);
            }
            return cnt <= numOps;
        };

        for (int i = 0, cnt = 0; i < size(s); ++i) {
            ++cnt;
            if (i + 1 == size(s) || s[i + 1] != s[i]) {
                arr.emplace_back(cnt);
                cnt = 0;
            }
        }
        return binary_search(1, size(s), check);
    }
};
