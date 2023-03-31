// Time:  O(mlogm + nlogn + (m + n) * logr), r = 2*(max(max(hens), max(grains))-min(min(hens), min(grains))
// Space: O(1)

// binary search, greedy
class Solution {
public:
    int minimumTime(vector<int>& hens, vector<int>& grains) {
        const auto& check = [&](const int x) {
            int i = 0;
            for (const auto& h : hens) {
                int c = x;
                if (h - grains[i] > x) {
                    return false;
                } else if (h - grains[i] > 0) {
                    const int d = h - grains[i];
                    c = max(x - 2 * d, (x - d) / 2);  // # max(go left then right, go right then left)
                }
                for (; i < size(grains) && grains[i] <= h + c; ++i);
                if (i == size(grains)) {
                    return true;
                }
            }
            return false;
        };

        sort(begin(hens), end(hens));
        sort(begin(grains), end(grains));
        int left = 0, right = 2 * (max(hens.back(), grains.back()) - min(hens.front(), grains.front()));
        while (left <= right) {
            const int mid = left + (right - left) / 2;
            if (check(mid)) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};
