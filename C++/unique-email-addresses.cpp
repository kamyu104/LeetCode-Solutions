// Time:  O(n * l)
// Space: O(n * l)

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> result;
        for (const auto& email : emails) {
            result.emplace(convert(email));
        }   
        return result.size();
    }

private:
    string convert(const string& email) {
        const auto& at_it = email.find('@');
        const auto& domain = email.substr(at_it);
        auto name = email.substr(0, at_it);
        name = name.substr(0, name.find('+'));
        name.erase(remove(name.begin(), name.end(), '.'), name.end());
        auto new_email = move(name);
        new_email += domain;
        return new_email;
    }
};
