// Time:  O(n)
// Space: O(n)

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> lookup;
        for (const auto& answer : answers) {
            ++lookup[answer];
        }
        int result = 0;
        for (const auto& kvp : lookup) {
            result += ((kvp.first + 1) + kvp.second - 1) / (kvp.first + 1) * (kvp.first + 1);
        }
        return result;
    }
};
