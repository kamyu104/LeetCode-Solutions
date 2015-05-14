// Time:  O(|V| + |E||)
// Space: O(1)

// Topological sort.
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<int> res;
        // Store courses with in-degree zero.
        queue<int> zeroInDegree;
        
        // in-degree, out-degree
        unordered_map<int, unordered_set<int>> inDegree;
        unordered_map<int, unordered_set<int>> outDegree;
        for (int i = 0; i < prerequisites.size(); ++i) {
            inDegree[prerequisites[i].first].insert(prerequisites[i].second);
            outDegree[prerequisites[i].second].insert(prerequisites[i].first);
        }
        
        // Put all the courses with in-degree zero into queue.
        for(int i = 0; i < numCourses; ++i) {
            if(inDegree.find(i) == inDegree.end()) {
                zeroInDegree.push(i);
            }
        }
        
        // V+E
        while(!zeroInDegree.empty()) {
            // Take the course which prerequisites are all taken.
            int prerequisite = zeroInDegree.front();
            res.emplace_back(prerequisite);
            zeroInDegree.pop();
            for (const auto & course: outDegree[prerequisite]) {
                // Update info of all the courses with the taken prerequisite.
                inDegree[course].erase(prerequisite);
                // If all the prerequisites are taken, add the course to the queue.
                if (inDegree[course].empty()) {
                    zeroInDegree.push(course);
                }
            }
            // Mark the course as taken.
            outDegree.erase(prerequisite);
        }
        
        // All of the courses have been taken.
        if (!outDegree.empty()) {
            return {};
        }
        
        return res;
    }
};
