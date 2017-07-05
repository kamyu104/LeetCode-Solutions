// Time:  O(nlogn)
// Space: O(k), k is the number of courses you can take

class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[1] < b[1];
             });
        priority_queue<int> max_heap;
        int now = 0;
        for (const auto& course : courses) {
            max_heap.emplace(course[0]);
            now += course[0];
            if (now > course[1]) {
                now -= max_heap.top(), max_heap.pop();
            }
        }
        return heap.size();
    }
};

