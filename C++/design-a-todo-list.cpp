// Time:  ctor:           O(1)
//        addTask:        O(l + logn), n is the number of user's tasks, l is the max length of a task
//        getAllTasks:    O(r), r is the length of result
//        getTasksForTag: O(r * c), r is the length of result, c is the length of the tag
//        completeTask:   O(l + logn)
// Space: O(n * l)

// bst
class TodoList {
public:
    TodoList() {
        
    }
    
    int addTask(int userId, string taskDescription, int dueDate, vector<string> tags) {
        tasks_.emplace_back(dueDate, taskDescription, unordered_set<string>(cbegin(tags), cend(tags)));
        user_taskids_[to_string(userId)][dueDate] = size(tasks_);
        return size(tasks_);
    }
    
    vector<string> getAllTasks(int userId) {
        vector<string> result;
        const auto& key = to_string(userId);
        if (user_taskids_.count(key)) {
            for (const auto& [_, i] : user_taskids_[key]) {
                result.emplace_back(std::get<1>(tasks_[i - 1]));
            }
        }
        return result;
    }
    
    vector<string> getTasksForTag(int userId, string tag) {
        vector<string> result;
        const auto& key = to_string(userId);
        if (user_taskids_.count(key)) {
            for (const auto& [_, i] : user_taskids_[key]) {
                if (std::get<2>(tasks_[i - 1]).count(tag)) {
                    result.emplace_back(std::get<1>(tasks_[i - 1]));
                }
            }
        }
        return result;
    }
    
    void completeTask(int userId, int taskId) {
        if (!(taskId - 1 < size(tasks_) && user_taskids_.count(to_string(userId)))) {
            return;
        }
        user_taskids_[to_string(userId)].erase(std::get<0>(tasks_[taskId - 1]));
    }

private:
    vector<tuple<int, string, unordered_set<string>>> tasks_;
    unordered_map<string, map<int, int>> user_taskids_;
};

// Time:  ctor:           O(1)
//        addTask:        O(l + t * logn), n is the number of user's tasks, l is the max length of a task, t is the number of tags
//        getAllTasks:    O(r), r is the length of result
//        getTasksForTag: O(r), r is the length of result
//        completeTask:   O(l + t * logn)
// Space: O(n * (l + t))
// bst
class TodoList2 {
public:
    TodoList2() {
        
    }
    
    int addTask(int userId, string taskDescription, int dueDate, vector<string> tags) {
        tasks_.emplace_back(dueDate, taskDescription, unordered_set<string>(cbegin(tags), cend(tags)));
        user_taskids_[to_string(userId)][dueDate] = size(tasks_);
        for (const auto& tag : std::get<2>(tasks_.back())) {
            user_taskids_[to_string(userId) + '-' + tag][dueDate] = size(tasks_);
        }
        return size(tasks_);
    }
    
    vector<string> getAllTasks(int userId) {
        vector<string> result;
        const auto& key = to_string(userId);
        if (user_taskids_.count(key)) {
            for (const auto& [_, i] : user_taskids_[key]) {
                result.emplace_back(std::get<1>(tasks_[i - 1]));
            }
        }
        return result;
    }
    
    vector<string> getTasksForTag(int userId, string tag) {
        vector<string> result;
        const auto& key = to_string(userId) + '-' + tag;
        if (user_taskids_.count(key)) {
            for (const auto& [_, i] : user_taskids_[key]) {
                result.emplace_back(std::get<1>(tasks_[i - 1]));
            }
        }
        return result;
    }
    
    void completeTask(int userId, int taskId) {
        if (!(taskId - 1 < size(tasks_) && user_taskids_.count(to_string(userId)))) {
            return;
        }
        user_taskids_[to_string(userId)].erase(std::get<0>(tasks_[taskId - 1]));
        for (const auto& tag : std::get<2>(tasks_[taskId - 1])) {
            user_taskids_[to_string(userId) + '-' + tag].erase(std::get<0>(tasks_[taskId - 1]));
        }
    }

private:
    vector<tuple<int, string, unordered_set<string>>> tasks_;
    unordered_map<string, map<int, int>> user_taskids_;
};
