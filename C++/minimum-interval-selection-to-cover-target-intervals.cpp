// Time:  O(n + m + r)
// Space: O(r)

// line sweep, difference array, greedy
class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        const auto r = max(
            ranges::max(availableIntervals, {}, [](const auto& interval) {
                return interval[1];
            })[1],
            ranges::max(targetIntervals, {}, [](const auto& interval) {
                return interval[1];
            })[1]
        );
        vector<int> diff((2 * r + 1) + 1);
        for (const auto& x : targetIntervals) {
            const auto& l = x[0], &r = x[1];
            ++diff[2 * l];
            --diff[2 * r + 1];
        }
        vector<int> lookup(size(diff));
        for (const auto& x : availableIntervals) {
            const auto& l = x[0], &r = x[1];
            lookup[2 * l] = max(lookup[2 * l], 2 * r);
        }
        int result = 0;
        for (int i = 0, cnt = 0, reachable = 0, mx = 0; i < size(diff); ++i) {
            cnt += diff[i];
            mx = max(mx, lookup[i]);
            if (!cnt || reachable >= i) {
                continue;
            }
            if (mx < i) {
                return -1;
            }
            reachable = mx;
            ++result;
        }
        return result;
    }
};

// Time:  O(nlogn + mlogm)
// Space: O(1)
// sort, greedy
class Solution2 {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        ranges::sort(availableIntervals);
        ranges::sort(targetIntervals);
        int result = 0, reachable = 0, i = 0;
        for (const auto& x : targetIntervals) {
            const auto& l = x[0], &r = x[1];
            while (reachable < r) {
                const auto& need = max(l, reachable);
                int mx = 0;
                for (; i < size(availableIntervals) && availableIntervals[i][0] <= need; ++i) {
                    mx = max(mx, availableIntervals[i][1]);
                }
                if (mx < max(l, reachable + 1)) {
                    return -1;
                }
                reachable = mx;
                ++result;
            }
        }
        return result;
    }
};
