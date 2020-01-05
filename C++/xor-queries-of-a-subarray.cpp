// Time:  O(n)
// Space: O(1)

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] ^= arr[i - 1];
        }
        vector<int> result;
        for (const auto& q : queries) {
            const auto& [left, right] = make_pair(q[0], q[1]);
            result.emplace_back(left ? arr[right] ^ arr[left - 1] : arr[right]);
        }
        return result;
    }
};
