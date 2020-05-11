// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, pair<int, int>> count_sum;
        count_sum[0] = {1, 0};
        int result = 0;
        for (int i = 0, prefix = 0; i < arr.size(); ++i) {
            prefix ^= arr[i];
            auto& [c, t] = count_sum[prefix];
            result += c * i - t;
            ++c, t += i + 1;
        }
        return result;
    }
};
