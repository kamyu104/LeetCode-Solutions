// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    vector<pair<int, int> > getSkyline(vector<vector<int> >& buildings) {
        unordered_map<int, vector<int>> start_point_to_heights;
        unordered_map<int, vector<int>> end_point_to_heights;
        set<int> points;

        for (int i = 0; i < buildings.size(); ++i) {
            start_point_to_heights[buildings[i][0]].push_back(buildings[i][2]);
            end_point_to_heights[buildings[i][1]].push_back(buildings[i][2]);
            points.emplace(buildings[i][0]);
            points.emplace(buildings[i][1]);
        }

        vector<pair<int, int>> res;
        map<int, int> height_to_count;
        int curr_max = 0;
        // Enumerate each point in increasing order.
        for (auto it = points.begin(); it != points.end(); ++it) {
            vector<int> start_point_heights = start_point_to_heights[*it];
            vector<int> end_point_heights = end_point_to_heights[*it];

            for (int i = 0; i < start_point_heights.size(); ++i) {
                ++height_to_count[start_point_heights[i]];
            }

            for (int i = 0; i < end_point_heights.size(); ++i) {
                --height_to_count[end_point_heights[i]];
                if (height_to_count[end_point_heights[i]] == 0) {
                    height_to_count.erase(end_point_heights[i]);
                }
            }
 
            if (height_to_count.empty()) {
                curr_max = 0;
                res.emplace_back(*it, curr_max);
            } else if (curr_max != height_to_count.rbegin()->first) {
                curr_max = height_to_count.rbegin()->first;
                res.emplace_back(*it, curr_max);
            }
        }
        return res;
    }
};
