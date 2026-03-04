// Time:  O(n * l)
// Space: O(n * l)

// string, hash table
class Solution {
public:
    int uniqueEmailGroups(vector<string>& emails) {
        const auto& lower = [](const auto& s) {
            string result(s);
            for (auto& x : result) {
                x = tolower(x);
            }
            return result;
        };

        unordered_set<string> result;
        for (auto& email : emails) {
            email = lower(email);
            auto local = email.substr(0, email.find_first_of("+@"));
            local.erase(remove(begin(local), end(local), '.'), end(local));
            const auto& domain = email.substr(email.find('@') + 1);
            result.emplace(local + '@' + domain);
        }
        return size(result);
    }
};
