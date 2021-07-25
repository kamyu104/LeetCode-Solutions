// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result;
        for (int i = 0; i < size(heights); ++i) {
            while (!empty(result) && heights[result.back()] <= heights[i]) {
                result.pop_back();
            }
            result.emplace_back(i);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(1)
class Solution2 {
public:
    vector<int> findBuildings(vector<int>& heights) {
        vector<int> result;
        for (int i = size(heights) - 1; i >= 0; --i) {
            if (empty(result) || heights[i] > heights[result.back()]) {
                result.emplace_back(i);
            }
        }
        return {rbegin(result), rend(result)};
    }
};
