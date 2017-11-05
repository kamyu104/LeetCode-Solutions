// Time:  O(nlogn), n is the number of total emails, and the max length of email is 320, p.s. {64}@{255}
// Space: O(n)

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        UnionFind union_find;
        unordered_map<string, string> email_to_name;
        unordered_map<string, int> email_to_id;
        for (const auto& account : accounts) {
            const auto& name = account[0];
            for (int i = 1; i < account.size(); ++i) {
                if (!email_to_id.count(account[i])) {
                    email_to_name[account[i]] = name;
                    email_to_id[account[i]] = union_find.get_id();
                }
                union_find.union_set(email_to_id[account[1]], email_to_id[account[i]]);
            }
        }

        unordered_map<int, set<string>> lookup; 
        for (const auto& kvp : email_to_name) {
            const auto& email = kvp.first;
            lookup[union_find.find_set(email_to_id[email])].emplace(email);
        }
        vector<vector<string>> result;
        for (const auto& kvp : lookup) {
            const auto& emails = kvp.second;
            vector<string> tmp{email_to_name[*emails.begin()]};
            for (const auto& email : emails) {
                tmp.emplace_back(email);
            }
            result.emplace_back(move(tmp));
        }
        return result;
    }

private:
    class UnionFind {
        public:
            int get_id() {
                set_.emplace_back(set_.size());
                return set_.size() - 1;
            }

            int find_set(const int x) {
               if (set_[x] != x) {
                   set_[x] = find_set(set_[x]);  // Path compression.
               }
               return set_[x];
            }

            void union_set(const int x, const int y) {
                int x_root = find_set(x), y_root = find_set(y);
                if (x_root != y_root) {
                    set_[min(x_root, y_root)] = max(x_root, y_root);
                }
            }

        private:
            vector<int> set_;
    };
};
