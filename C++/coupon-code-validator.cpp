// Time:  O(l * nlogn)
// Space: O(n * l)

// hash table, sort
class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        static const unordered_map<string, int> LOOKUP = {{"electronics", 0}, {"grocery", 1}, {"pharmacy", 2}, {"restaurant", 3}};

        vector<pair<int, string>> sorted_codes;
        for (int i = 0; i < size(code); ++i) {
            if (isActive[i] && !empty(code[i]) && LOOKUP.count(businessLine[i]) && all_of(cbegin(code[i]), cend(code[i]), [](const auto& x) {
                return isalnum(x) || x == '_';
            })) {
                sorted_codes.emplace_back(LOOKUP.at(businessLine[i]), code[i]);
            }
        }
        sort(begin(sorted_codes), end(sorted_codes));
        vector<string> result;
        result.reserve(size(sorted_codes));
        for (const auto& [_, c] : sorted_codes) {
            result.emplace_back(c);
        }
        return result;
    }
};
