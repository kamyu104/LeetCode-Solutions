// Time:  O(nlogn)
// Space: O(n)

// BST solution.
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
 
            if (height_to_count.empty() || curr_max != height_to_count.rbegin()->first) {
                curr_max = height_to_count.empty() ? 0 : height_to_count.rbegin()->first;
                res.emplace_back(*it, curr_max);
            }
        }
        return res;
    }
};

// Time:  O(nlogn)
// Space: O(n)
// Divide and conquer solution.
class Solution2 {
public:
    enum {start, end, height};
    
    vector<pair<int, int>> getSkyline(vector<vector<int>>& buildings) {
        const auto intervals = move(ComputeSkylineInInterval(buildings, 0, buildings.size()));
        
        vector<pair<int, int>> res;
        int last_end = -1;
        for (const auto& interval : intervals) {
            if (last_end != -1 && last_end < interval[start]) {
                res.emplace_back(last_end, 0);
            }
            res.emplace_back(interval[start], interval[height]);
            last_end = interval[end];
        }
        if (last_end != -1) {
            res.emplace_back(last_end, 0);
        }
        return res;
    }
    
    // Divide and Conquer.
    vector<vector<int>> ComputeSkylineInInterval(const vector<vector<int>>& buildings,
                                                 int left_endpoint, int right_endpoint) {
        if (right_endpoint - left_endpoint <= 1) {  // 0 or 1 skyline, just copy it.
            return {buildings.cbegin() + left_endpoint, 
                    buildings.cbegin() + right_endpoint};
        }
        int mid = left_endpoint + ((right_endpoint - left_endpoint) / 2);
        auto left_skyline = move(ComputeSkylineInInterval(buildings, left_endpoint, mid));
        auto right_skyline = move(ComputeSkylineInInterval(buildings, mid, right_endpoint));
        return MergeSkylines(left_skyline, right_skyline);
    }
    
    // Merge Sort
    vector<vector<int>> MergeSkylines(vector<vector<int>>& left_skyline, vector<vector<int>>& right_skyline) {
        int i = 0, j = 0;
        vector<vector<int>> merged;
        
        while (i < left_skyline.size() && j < right_skyline.size()) {
            if (left_skyline[i][end] < right_skyline[j][start]) {
                merged.emplace_back(move(left_skyline[i++]));
            } else if (right_skyline[j][end] < left_skyline[i][start]) {
                merged.emplace_back(move(right_skyline[j++]));
            } else if (left_skyline[i][start] <= right_skyline[j][start]) {
                MergeIntersectSkylines(merged, left_skyline[i], i,
                                       right_skyline[j], j);
            } else {  // left_skyline[i][start] > right_skyline[j][start].
                MergeIntersectSkylines(merged, right_skyline[j], j,
                                       left_skyline[i], i);
            }
        }
        
        // Insert the remaining skylines.
        merged.insert(merged.end(), left_skyline.begin() + i, left_skyline.end());
        merged.insert(merged.end(), right_skyline.begin() + j, right_skyline.end());
        return merged;
    }
    
    // a[start] <= b[start]
    void MergeIntersectSkylines(vector<vector<int>>& merged, vector<int>& a, int& a_idx,
                                vector<int>& b, int& b_idx) {
        if (a[end] <= b[end]) {
            if (a[height] > b[height]) {  // |aaa|
                if (b[end] != a[end]) {   // |abb|b
                    b[start] = a[end];
                    merged.emplace_back(move(a)), ++a_idx;
                } else {        // aaa
                    ++b_idx;    // abb
                }
            } else if (a[height] == b[height]) { // abb
                b[start] = a[start], ++a_idx;    // abb
            } else {  // a[height] < b[height].
                if (a[start] != b[start]) {                                           //    bb
                    merged.emplace_back(move(vector<int>{a[start], b[start], a[height]}));  // |a|bb
                }
                ++a_idx;
            }
        } else {  // a[end] > b[end].
            if (a[height] >= b[height]) {  // aaaa
                ++b_idx;                   // abba
            } else {
                //    |bb|
                // |a||bb|a
                if (a[start] != b[start]) {
                    merged.emplace_back(move(vector<int>{a[start], b[start], a[height]}));
                }
                a[start] = b[end];
                merged.emplace_back(move(b)), ++b_idx;
            }
        }
    }
};
