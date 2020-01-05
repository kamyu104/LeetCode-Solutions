// Time:  O(n + vlogv), v is the number of the level videos
// Space: O(w)

class Solution {
public:
    vector<string> watchedVideosByFriends(vector<vector<string>>& watchedVideos, vector<vector<int>>& friends, int id, int level) {
        vector<int> curr_level = {id};
        unordered_set<int> lookup = {id};
        for (int i = 0; i < level; ++i) {
            vector<int> new_level;
            for (const auto& i : curr_level) {
                for (const auto& j : friends[i]) {
                    if (lookup.count(j)) {
                        continue;
                    }
                    lookup.emplace(j);
                    new_level.emplace_back(j);
                }
            }
            curr_level = move(new_level);
        }

        unordered_map<string, int> count;
        for (const auto& i : curr_level) {
            for (const auto& v : watchedVideos[i]) {
                ++count[v];
            }
        }
        vector<string> result;
        transform(count.cbegin(), count.cend(), back_inserter(result),
                  [](const auto& x) {
                      return x.first;
                  });
        sort(result.begin(), result.end(),
             [&count](const auto& a, const auto& b) {
                 return make_pair(count[a], a) < make_pair(count[b], b);
             });
        return result;
    }
};
