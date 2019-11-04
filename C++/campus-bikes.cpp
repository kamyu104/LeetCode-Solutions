// Time:  O((w * b) * log(w * b))
// Space: O(w * b)

class Solution {
public:
    vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
        using P = vector<int>;
        vector<vector<P>> distances(workers.size());
        for (int i = 0; i < workers.size(); ++i) {
            for (int j = 0; j < bikes.size(); ++j) {
                distances[i].push_back({manhattan(workers[i], bikes[j]), i, j});
            }
            sort(distances[i].begin(), distances[i].end(), greater<P>());
        }
        
        vector<int> result(workers.size());
        unordered_set<int> lookup;
        priority_queue<P, vector<P>, greater<P>> min_heap;
        for (int i = 0; i < workers.size(); ++i) {
            min_heap.emplace(distances[i].back());
            distances[i].pop_back();
        }
        while (lookup.size() < workers.size()) {
            const auto worker = min_heap.top()[1];
            const auto bike = min_heap.top()[2];
            min_heap.pop();
            if (!lookup.count(bike)) {
                result[worker] = bike;
                lookup.emplace(bike);
            } else {
                min_heap.emplace(distances[worker].back());
                distances[worker].pop_back();
            }
        }
        return result;
    }
    
private:
    int manhattan(const vector<int>& p1, const vector<int>& p2) {
        return abs(p1[0] - p2[0]) + abs(p1[1] - p2[1]);
    }
};
