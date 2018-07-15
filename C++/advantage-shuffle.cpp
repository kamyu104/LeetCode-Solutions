// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<int> advantageCount(vector<int>& A, vector<int>& B) {
        vector<int> sortedA(A.cbegin(), A.cend());
        sort(sortedA.begin(), sortedA.end());
        vector<int> sortedB(B.cbegin(), B.cend());
        sort(sortedB.begin(), sortedB.end());

        unordered_map<int, vector<int>> candidates;
        vector<int> others;
        int j = 0;
        for (const auto& a : sortedA) {
            if (a > sortedB[j]) {
                candidates[sortedB[j]].emplace_back(a);
                ++j;
            } else {
                others.emplace_back(a);
            }
        }
        vector<int> result;
        for (const auto& b : B) {
            if (!candidates[b].empty()) {
                result.emplace_back(candidates[b].back());
                candidates[b].pop_back();
            } else {
                result.emplace_back(others.back());
                others.pop_back();
            }
        }
        return result;
    }
};
