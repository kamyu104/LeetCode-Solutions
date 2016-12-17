// Time:  O(n^2)
// Space: O(n^2)

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        unordered_map<int, int> A_B_sum;
        for (const auto& a : A) {
            for (const auto& b : B) {
                ++A_B_sum[a + b];
            }
        }
        int result = 0;
        for (const auto& c : C) {
            for (const auto& d : D) {
                if (A_B_sum.find(-c - d) != A_B_sum.end()) {
                    result += A_B_sum[-c - d];
                }
            }
        }
        return result;
    }
};
