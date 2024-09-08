// Time:  O(h)
// Space: O(h)

// line sweep, difference array
class Solution {
public:
    long long maxArea(int height, vector<int>& positions, string directions) {
        vector<int> events(2 * height + 1);
        for (int i = 0; i < size(positions); ++i) {
            if (directions[i] == 'U') {
                --events[height - positions[i]];
                ++events[(height - positions[i]) + height];
            } else {
                ++events[positions[i]];
                --events[positions[i] + height];
            }
        }
        int64_t total = accumulate(cbegin(positions), cend(positions), 0ll);
        int64_t result = total;
        int cnt = count(cbegin(directions), cend(directions), 'U');
        for (int t = 1; t < size(events); ++t) {
            total += (-(static_cast<int32_t>(size(directions)) - cnt) + cnt);
            result = max(result, total);
            cnt += events[t];
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
        map<int, int> events;
        for (int i = 0; i < size(positions); ++i) {
            if (directions[i] == 'U') {
                --events[height - positions[i]];
                ++events[(height - positions[i]) + height];
            } else {
                ++events[positions[i]];
                --events[positions[i] + height];
            }
        }
        int64_t total = accumulate(cbegin(positions), cend(positions), 0ll);
        int64_t result = total;
        int cnt = count(cbegin(directions), cend(directions), 'U');
        int prev = 0;
        for (const auto& [t, diff] : events) {
            total += static_cast<int64_t>(t - prev) * (-(static_cast<int32_t>(size(directions)) - cnt) + cnt);
            result = max(result, total);
            cnt += diff;
            prev = t;
        }
        return result;
    }
};
