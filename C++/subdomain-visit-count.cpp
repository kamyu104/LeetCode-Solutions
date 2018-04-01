// Time:  O(n), is the length of cpdomains (assuming the length of cpdomains[i] is fixed)
// Space: O(n)

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counts;
        for (const auto& cpdomain : cpdomains) {
            int i = cpdomain.find(" ");
            const int count = stoi(cpdomain.substr(0, i));
            const auto& domain = cpdomain.substr(i + 1);
            for (int i = -1; i < static_cast<int>(domain.length()); ++i) {
                if (i != -1 && domain[i] != '.') {
                    continue;
                }
                counts[domain.substr(i + 1)] += count;
            }
        }

        vector<string> result;
        for (const auto& count : counts) {
            result.emplace_back(to_string(count.second));
            result.back() += " ";
            result.back() += count.first;
        }
        return result;
    }
};
