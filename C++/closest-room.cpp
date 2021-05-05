// Time:  O(nlogn + klogk + klogn)
// Space: O(n + k)

class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        static const auto& by_size_desc = [](const auto& a, const auto& b) { return a[1] > b[1]; };
        sort(begin(rooms), end(rooms), by_size_desc);
        for (int i = 0; i < size(queries); ++i) {
            queries[i].emplace_back(i);
        }
        sort(begin(queries), end(queries), by_size_desc);
        set<int> ids;
        vector<int> result(size(queries), -1);
        int i = 0;
        for (const auto& q : queries) {
            int r = q[0], s = q[1], idx = q[2];
            for (; i < size(rooms) && rooms[i][1] >= s; ++i) {
                ids.emplace(rooms[i][0]);
            }
            result[idx] = find_closest(ids, r);
        }
        return result;
    }

private:
    int find_closest(const set<int>& ids, int r) {
        int result = -1, min_diff = numeric_limits<int>::max();
        auto it = ids.upper_bound(r);
        if (it != begin(ids) && abs(*prev(it) - r) < min_diff) {
            min_diff = abs(*prev(it) - r);
            result = *prev(it);
        }
        if (it != end(ids) && abs(*it - r) < min_diff) {
            min_diff = abs(*it - r);
            result = *it;
        }
        return result;
    }
};

// Time:  O(nlogn + klogk + klogn)
// Space: O(n + k)
class Solution2 {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        static const auto& by_size_asc = [](const auto& a, const auto& b) { return a[1] < b[1]; };
        sort(begin(rooms), end(rooms), by_size_asc);
        for (int i = 0; i < size(queries); ++i) {
            queries[i].emplace_back(i);
        }
        sort(begin(queries), end(queries), by_size_asc);
        set<int> ids;
        for (const auto& room : rooms) {
            ids.emplace(room[0]);
        }
        vector<int> result(size(queries), -1);
        int i = 0;
        for (const auto& q : queries) {
            int r = q[0], s = q[1], idx = q[2];
            for (; i < size(rooms) && rooms[i][1] < s; ++i) {
                ids.erase(rooms[i][0]);
            }
            result[idx] = find_closest(ids, r);
        }
        return result;
    }

private:
    int find_closest(const set<int>& ids, int r) {
        int result = -1, min_diff = numeric_limits<int>::max();
        auto it = ids.upper_bound(r);
        if (it != begin(ids) && abs(*prev(it) - r) < min_diff) {
            min_diff = abs(*prev(it) - r);
            result = *prev(it);
        }
        if (it != end(ids) && abs(*it - r) < min_diff) {
            min_diff = abs(*it - r);
            result = *it;
        }
        return result;
    }
};
