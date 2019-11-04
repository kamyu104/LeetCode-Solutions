// Time:  O(m * 2^n), n is the number of skills
//                    m is the number of people
// Space: O(2^n)

class Solution {
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        unordered_map<string, int> lookup;
        for (int i = 0; i < req_skills.size(); ++i) {
            lookup[req_skills[i]] = i;
        }
        unordered_map<int, vector<int>> dp;
        dp[0];
        for (int i = 0; i < people.size(); ++ i) {
            int his_skill_set = 0;
            for (const auto& skill : people[i]) {
                if (lookup.count(skill)) {
                    his_skill_set |= 1 << lookup[skill];
                }
            }
            auto tmp(dp);
            for (const auto& [skill_set, people] : tmp) {
                const auto with_him_set = skill_set | his_skill_set;
                if (with_him_set == skill_set) {
                    continue;
                }
                if (!dp.count(with_him_set) || 
                    dp[with_him_set].size() > people.size() + 1) {
                    dp[with_him_set] = move(people);
                    dp[with_him_set].emplace_back(i);
                }
            }
        }
        return dp[(1 << req_skills.size()) - 1];
    }
};
