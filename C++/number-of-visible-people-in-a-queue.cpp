// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> result(size(heights));
        vector<int> stk;
        for (int i = 0; i < size(heights); ++i) {
            while (!empty(stk) && heights[stk.back()] <= heights[i]) {
                ++result[stk.back()]; stk.pop_back();
            }
            if (!empty(stk)) {
                ++result[stk.back()];
            }
            stk.emplace_back(i);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(n)
class Solution2 {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        vector<int> result(size(heights));
        vector<int> stk;
        for (int i = size(heights) - 1; i >= 0; --i) {
            int cnt;
            for (cnt = 0; !empty(stk) && heights[stk.back()] < heights[i]; ++cnt) {
                stk.pop_back();
            }
            result[i] = !empty(stk) ? cnt + 1 : cnt;
            stk.emplace_back(i);
        }
        return result;
    }
};
