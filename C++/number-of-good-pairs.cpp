// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int result = 0;
        for (const auto& [n, c] : counter(nums)) {
            result += c * (c - 1) / 2;
        }
        return result;
    }

private:
    unordered_map<int, int> counter(const vector<int>& arr) {
        unordered_map<int, int> result;
        for (const auto& i : arr) {
            ++result[i];
        }
        return result;
    }
};
