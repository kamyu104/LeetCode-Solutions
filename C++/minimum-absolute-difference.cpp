// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        vector<vector<int>> result;
        int min_diff = numeric_limits<int>::max();
        sort(arr.begin(),arr.end());
        for (int i = 0; i < arr.size() - 1; ++i) {
            const auto diff = arr[i + 1] - arr[i];
            if (diff < min_diff) {
                min_diff = diff;
                result = {{arr[i], arr[i + 1]}};
            } else if (diff == min_diff) {
                result.push_back({arr[i], arr[i + 1]});
            }
        }
        return result;
    }
};
