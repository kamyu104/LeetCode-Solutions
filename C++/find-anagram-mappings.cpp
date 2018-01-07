// Time:  O(n)
// Space: O(n)

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, queue<int>> lookup;
        for (int i = 0; i < B.size(); ++i) {
            lookup[B[i]].emplace(i);
        }
        vector<int> result;
        for (const auto& el : A) {
            result.emplace_back(lookup[el].back());
            lookup[el].pop();
        }
        return result;
    }
};
