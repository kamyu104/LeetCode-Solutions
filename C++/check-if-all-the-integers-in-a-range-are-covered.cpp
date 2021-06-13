// Time:  O(n + r)
// Space: O(r)

// if r is small, this is better
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        static const int RANGE_SIZE = 50;

        vector<int> interval(RANGE_SIZE + 1);
        for (const auto& r : ranges) {
            ++interval[r[0] - 1];
            --interval[(r[1] - 1) + 1];
        }
        for (int i = 0, cnt = 0; i <= right - 1; ++i) {
            cnt += interval[i];
            if (i >= left - 1 && !cnt) {
                return false;
            }
        }
        return true;
    }
};

// Time:  O(nlogn)
// Space: O(1)
// if r is big, this is better
class Solution2 {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(begin(ranges), end(ranges));
        for (const auto& r : ranges) {
            if (r[0] <= left && left <= r[1]) {
                left = r[1] + 1;
            }
        }
        return left > right;
    }
};

// Time:  O(n * r)
// Space: O(1)
class Solution3 {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        for (int i = left; i <= right; ++i) {
            bool found = false;
            for (const auto& r : ranges) {
                if (r[0] <= i && i <= r[1]) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                return false;
            }
        }
        return true;
    }
};
