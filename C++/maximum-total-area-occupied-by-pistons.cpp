// Time:  O(h)
// Space: O(h)

// line sweep, difference array
class Solution {
public:
    long long maxArea(int height, vector<int>& positions, string directions) {
        vector<int> diff(2 * height + 1);
        for (int i = 0; i < size(positions); ++i) {
            if (directions[i] == 'U') {
                --diff[height - positions[i]];
                ++diff[(height - positions[i]) + height];
            } else {
                ++diff[positions[i]];
                --diff[positions[i] + height];
            }
        }
        int64_t total = accumulate(cbegin(positions), cend(positions), 0ll);
        int64_t result = total;
        int cnt = count(cbegin(directions), cend(directions), 'U');
        for (int t = 1; t < size(diff); ++t) {
            total += -(static_cast<int32_t>(size(directions)) - cnt) + cnt;
            result = max(result, total);
            cnt += diff[t];
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, line sweep, difference array
class Solution2 {
public:
    long long maxArea(int height, vector<int>& positions, string directions) {
        unordered_map<int, int> diff;
        for (int i = 0; i < size(positions); ++i) {
            if (directions[i] == 'U') {
                --diff[height - positions[i]];
                ++diff[(height - positions[i]) + height];
            } else {
                ++diff[positions[i]];
                --diff[positions[i] + height];
            }
        }
        int64_t total = accumulate(cbegin(positions), cend(positions), 0ll);
        int64_t result = total;
        int cnt = count(cbegin(directions), cend(directions), 'U');
        int prev = 0;
        vector<pair<int, int>> sorted_diff(cbegin(diff), cend(diff));
        sort(begin(sorted_diff), end(sorted_diff));
        for (const auto& [t, d] : sorted_diff) {
            total += static_cast<int64_t>(t - prev) * (-(static_cast<int32_t>(size(directions)) - cnt) + cnt);
            result = max(result, total);
            cnt += d;
            prev = t;
        }
        return result;
    }
};
