// Time:  O(n) on average
// Space: O(1)

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        static const auto& dist = [](const vector<int>& v) {
            return v[0] * v[0] + v[1] * v[1];
        };
        nth_element(points.begin(), points.begin() + K, points.end(),
                    [&](const vector<int>& a, const vector<int>& b) {
                        return dist(a) < dist(b);
                    });
        return {points.cbegin(), points.cbegin() + K};
    }
};

// Time:  O(nlogk)
// Space: O(k)
class Solution2 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        static const auto& dist = [](const vector<int>& v) {
            return v[0] * v[0] + v[1] * v[1];
        };
        
        struct Compare {
            bool operator()(const vector<int>& a, const vector<int>& b) {
                return dist(a) < dist(b);
            }
        };
        priority_queue<vector<int>, vector<vector<int>>, Compare> max_heap;
        for (const auto& point : points) {
            max_heap.emplace(point);
            if (max_heap.size() > K) {
                max_heap.pop();
            }
        }
        vector<vector<int>> result;
        while (!max_heap.empty()) {
            result.emplace_back(max_heap.top()), max_heap.pop();
        }
        return result;
    }
};
