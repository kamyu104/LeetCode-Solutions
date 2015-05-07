// Time:  O(|V| + |E|)
// Space: O(|E|)

// Topological sort solution.
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Store courses with in-degree zero.
        queue<int> zeroInDegree;
        
        // in-degree, out-degree
        unordered_map<int, unordered_set<int>> inDegree;
        unordered_map<int, unordered_set<int>> outDegree;
        for (int i = 0; i < prerequisites.size(); ++i) {
            inDegree[prerequisites[i][0]].insert(prerequisites[i][1]);
            outDegree[prerequisites[i][1]].insert(prerequisites[i][0]);
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
            return false;
        }
        
        return true;
    }
};
