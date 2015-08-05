// Time:  O(n^2 * 5^(n/2))
// Space: O(n)

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        return findStrobogrammaticRecu(n, n);
    }
    
    vector<string> findStrobogrammaticRecu(const int n, int k) {
        if (k == 0) {
            return {""};
        } else if (k == 1) {
            return {"0", "1", "8"};
        }
    
        vector<string> result;
        for (const auto& num : findStrobogrammaticRecu(n, k - 2)) {
            for (const auto& kvp : lookup) {
                if (n == k && kvp.first == "0") {
                    continue;
                }
                result.emplace_back(kvp.first + num + kvp.second);
            }
        }
        return result;
    }

private:
    const unordered_map<string, string> lookup{{"0", "0"}, {"1", "1"},
                                               {"6", "9"}, {"8", "8"}, 
                                               {"9", "6"}};
};
