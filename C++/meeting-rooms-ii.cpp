// Time:  O(nlogn)
// Space: O(n)

class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> lookup;
        for (const auto& i : intervals) {
            ++lookup[i[0]];
            --lookup[i[1]];
        }
        int result = 0, curr = 0;
        for (const auto& [time, num] : lookup) {
            result = max(result, curr += num);
        }
        return result;
    }
};

// Time:  O(nlogn)
// Space: O(n)
class Solution2 {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> starts, ends;
        for (const auto& i : intervals) {
            starts.emplace_back(i[0]);
            ends.emplace_back(i[1]);
        }
        
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        
        int min_rooms = 0, cnt_rooms = 0;
        int s = 0, e = 0;
        while (s < starts.size()) {
            if (starts[s] < ends[e]) {
                ++cnt_rooms;  // Acquire a room.
                // Update the min number of rooms.
                min_rooms = max(min_rooms, cnt_rooms);
                ++s;
            } else {
                --cnt_rooms;  // Release a room.
                ++e;
            }
        }
        return min_rooms;
    }
};
