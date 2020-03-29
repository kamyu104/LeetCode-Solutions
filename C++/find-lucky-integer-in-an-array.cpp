// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int findLucky(vector<int>& arr) {
        const auto& count = counter(arr);
        int result = -1;
        for (const auto& [k, v] : count) {
            if (k == v) {
                result = max(result, k);
            }
        }
        return result;
    }

private:
    unordered_map<int, int> counter(const vector<int>& arr) {
        unordered_map<int, int> count;
        for (const auto& i : arr) {
            ++count[i];
        }
        return count;
    }
};
