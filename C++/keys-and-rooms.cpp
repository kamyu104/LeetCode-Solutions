// Time:  O(n!)
// Space: O(n)

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int> lookup = {0};
        vector<int> stack = {0};
        while (!stack.empty()) {
            auto node = stack.back(); stack.pop_back();
            for (const auto& nei : rooms[node]) {
                if (!lookup.count(nei)) {
                    lookup.emplace(nei);
                    if (lookup.size() == rooms.size()) {
                        return true;
                    }
                    stack.emplace_back(nei);
                }
            }
        }
        return lookup.size() == rooms.size();
    }
};
