// Time:  O(n)
// Space: O(h)

/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        return dfs(employees, id);
    }

private:
    int dfs(const vector<Employee*>& employees, const int id) {
        if (!employees[id - 1]) {
            return 0;
        }
        auto result = employees[id - 1]->importance;
        for (const auto& id : employees[id - 1]->subordinates) {
            result += getImportance(employees, id);
        }
        return result;
    }
};

// Time:  O(n)
// Space: O(w), w is the max number of nodes in the levels of the tree
class Solution2 {
public:
    int getImportance(vector<Employee*> employees, int id) {
        auto result = 0;
        queue<int> q;
        q.emplace(id);
        while (!q.empty()) {
            const auto curr = q.front(); q.pop();
            const auto& employee = employees[curr - 1];
            result += employee->importance;
            for (const auto& id : employee->subordinates) {
                q.emplace(id);
            }
        }
        return result;
    }
};
