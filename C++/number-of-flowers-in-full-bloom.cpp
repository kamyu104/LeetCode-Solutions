// Time:  O(nlogn + mlogn)
// Space: O(n)

// line sweep, binary search
class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        map<int, int> cnt;
        for (const auto& flower : flowers) {
            ++cnt[flower[0]];
            --cnt[flower[1] + 1];
        }
        vector<int> prefix = {0};
        vector<int> events;
        for (const auto& [k, v] : cnt) {
            events.emplace_back(k);
            prefix.emplace_back(prefix.back() + v);
        }
        vector<int> result;
        for (const auto& t : persons) {
            int i = distance(cbegin(events), upper_bound(cbegin(events), cend(events), t));
            result.emplace_back(prefix[i]);
        }
        return result;
    }
};

// Time:  O(nlogn + mlogn)
// Space: O(n)
// binary search
class Solution2 {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& persons) {
        vector<int> starts, ends;
        for (const auto& flower : flowers) {
            starts.emplace_back(flower[0]);
            ends.emplace_back(flower[1] + 1);
        }
        sort(begin(starts), end(starts));
        sort(begin(ends), end(ends));
        vector<int> result;
        for (const auto& t : persons) {
            result.emplace_back(distance(cbegin(starts), upper_bound(cbegin(starts), cend(starts), t)) - 
                                distance(cbegin(ends), upper_bound(cbegin(ends), cend(ends), t)));
        }
        return result;
    }
};
