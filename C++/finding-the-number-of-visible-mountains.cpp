// Time:  O(nlogn)
// Space: O(1)

// math, sort
class Solution {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        sort(begin(peaks), end(peaks), [](const auto& a, const auto& b) {
             const int x1 = a[0], y1 = a[1];
             const int x2 = b[0], y2 = b[1];
             return x1 - y1 != x2 - y2 ? x1 - y1 < x2 - y2 : x1 + y1 > x2 + y2;  // rotate points by 45 degrees and we only care the largest new y in the same new x
        });
        
        int result = 0;
        for (int i = 0, mx = 0; i < size(peaks); ++i) {
            if (peaks[i][0] + peaks[i][1] <= mx) {
                continue;
            }
            mx = peaks[i][0] + peaks[i][1];
            if (i + 1 == size(peaks) || peaks[i + 1] != peaks[i]) {
                ++result;
            }
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// sort, mono stack
class Solution2 {
public:
    int visibleMountains(vector<vector<int>>& peaks) {
        const auto& is_covered = [](const auto& a, const auto& b) {
             const int x1 = a[0], y1 = a[1];
             const int x2 = b[0], y2 = b[1];
             return x2 - y2 <= x1 - y1  && x1 + y1 <= x2 + y2; 
        };

        sort(begin(peaks), end(peaks));
        vector<int> stk;
        for (int i = 0; i < size(peaks); ++i) {
            while (!empty(stk) && is_covered(peaks[stk.back()], peaks[i])) {
                stk.pop_back();
            }
            if ((i - 1 == -1 || peaks[i - 1] != peaks[i]) && 
                (empty(stk) || !is_covered(peaks[i], peaks[stk.back()]))) {  // not duplicted and not covered
                stk.emplace_back(i);
            }
        }
        return size(stk);
    }
};
