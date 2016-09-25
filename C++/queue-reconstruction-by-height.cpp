// Time:  O(n^2)
// Space: O(n)

class Solution {
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), 
        [](const pair<int, int>& a, pair<int, int>& b) {
            return b.first == a.first ? a.second < b.second : b.first < a.first;
        });
        vector<pair<int, int>> result;
        for (const auto& p : people) {
            result.insert(result.begin() + p.second, p);
        }
        return result;
    }
};
