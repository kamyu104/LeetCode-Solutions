// Time:  O(n)
// Space: O(n)

class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> count;
        for (const auto& s : arr) {
            ++count[s];
        }
        for (const auto& s : arr) {
            if (count[s] == 1 && --k == 0) {
                return s;
            }
        }
        return "";
    }
};
