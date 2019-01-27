// Time:  O(n^3)
// Space: O(n^2)

class Solution {
public:
    int countTriplets(vector<int>& A) {
        unordered_map<int, int> count;
        for (int i = 0 ;i < A.size(); ++i) {
            for (int j = 0; j < A.size(); ++j) {
                ++count[A[i] & A[j]];
            }
        }
        int result = 0;
        for (int k = 0; k < A.size(); ++k) {
            for (const auto& kvp : count) {
                if ((A[k] & kvp.first) == 0) {
                    result += kvp.second;
                }
            }
        }
        return result;
    }
};
