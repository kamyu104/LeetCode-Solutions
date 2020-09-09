// Time:  O(n * 5^(n/2))
// Space: O(n)

class Solution {
public:
    vector<string> findStrobogrammatic(int n) {
        static const unordered_map<string, string> lookup{{"0", "0"}, {"1", "1"},
                                                          {"6", "9"}, {"8", "8"}, 
                                                          {"9", "6"}};
        vector<string> result = {""};
        if (n % 2) {
            result = {"0", "1", "8"};
        }
        for (int i = n % 2; i < n; i += 2) {
            vector<string> new_result;
            for (const auto& num : result) {
                for (const auto& [a, b] : lookup) {
                    if (i != n - 2 || a != "0") {
                        new_result.emplace_back(a + num + b);
                    }
                }
            }
            result = move(new_result);
        }
        return result;
    }
};

// Time:  O(n * 5^(n/2))
// Space: O(n)
class Solution2 {
public:
    vector<string> findStrobogrammatic(int n) {
        return findStrobogrammaticRecu(n, n);
    }

private:
    vector<string> findStrobogrammaticRecu(const int n, int k) {
        static const unordered_map<string, string> lookup{{"0", "0"}, {"1", "1"},
                                                          {"6", "9"}, {"8", "8"}, 
                                                          {"9", "6"}};
        if (k == 0) {
            return {""};
        } else if (k == 1) {
            return {"0", "1", "8"};
        }
        vector<string> result;
        for (const auto& num : findStrobogrammaticRecu(n, k - 2)) {
            for (const auto& kvp : lookup) {
                if (n != k || kvp.first != "0") {
                    result.emplace_back(kvp.first + num + kvp.second);
                }
            }
        }
        return result;
    }
};
