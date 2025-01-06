// Time:  ctor:    O(tlogt)
//        add:     O(logt)
//        edit:    O(logt)
//        rmv:     O(logt)
//        execTop: O(logt)
// Space: O(t)

// bst
class TaskManager {
public:
    TaskManager(vector<vector<int>>& tasks) {
        for (const auto& t : tasks) {
            add(t[0], t[1], t[2]);
        }
    }
    
    void add(int userId, int taskId, int priority) {
        bst_.emplace(priority, taskId, userId);
        lookup_[taskId] = pair(userId, priority);
    }
    
    void edit(int taskId, int newPriority) {
        const auto [userId, _] = lookup_[taskId];
        rmv(taskId);
        add(userId, taskId, newPriority);
    }
    
    void rmv(int taskId) {
        const auto [userId, priority] = lookup_[taskId];
        lookup_.erase(taskId);
        bst_.erase(tuple(priority, taskId, userId));
    }
    
    int execTop() {
        if (empty(bst_)) {
            return -1;
        }
        const auto [_, taskId, userId] = *rbegin(bst_);
        rmv(taskId);
        return userId;
    }

private:
    unordered_map<int, pair<int, int>> lookup_;
    set<tuple<int, int, int>> bst_;
};
