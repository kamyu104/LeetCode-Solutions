// Time:  O(n + e)
// Space: O(n + e)

class Solution {    
public:
    vector<int> sortItems(int n, int m, vector<int>& group_id, vector<vector<int>>& beforeItems) {
        for (int i = 0; i < n; ++i) {
            if (group_id[i] == -1) {
                group_id[i] = m++;
            }
        }
        Topo global_group;
        for (int i = 0; i < m; ++i) {
            global_group.addNode(i);
        }
        unordered_map<int, Topo> local_groups;
        for (int i = 0; i < n; ++i) {
            local_groups[group_id[i]].addNode(i);
        }
        for (int i = 0; i < n; ++i) {
            for (const auto& j : beforeItems[i]) {
                if (group_id[i] == group_id[j]) {
                    local_groups[group_id[i]].addEdge(j, i);
                } else {
                    global_group.addEdge(group_id[j], group_id[i]);
                }
            }
        }
        vector<int> result;
        const auto& global_order = global_group.sort();
        if (!global_order) {
            return {};
        }        
        for (const auto& i : *global_order) {
            const auto& local_order = local_groups[i].sort();
            if (!local_order) {
                return {};
            }
            for (const auto& x : *local_order) {
                result.emplace_back(x);
            }
        }
        return result;
    }
    
private:
    class Topo {
    public:
        void addNode(int node) {
            nodes_.emplace(node);
        }
        
        void addEdge(int from, int to) {
            addNode(from), addNode(to);
            in_degree_[to].emplace(from);
            out_degree_[from].emplace(to);
        }
        
        unique_ptr<vector<int>> sort() {
            queue<int> q;
            auto result = make_unique<vector<int>>();
            for (const auto& node : nodes_) {
                if (!in_degree_.count(node)) {
                    q.emplace(node);
                }
            }
            while (!q.empty()) {
                auto node = q.front(); q.pop();
                result->emplace_back(node);
                for (const auto& nei : out_degree_[node]) {
                    in_degree_[nei].erase(node);
                    if (in_degree_[nei].empty()) {
                        in_degree_.erase(nei);
                        q.emplace(nei);
                    }
                }
            }            
            if (result->size() < nodes_.size()) {
                return nullptr;
            }
            return result;
        }

    private:
        unordered_set<int> nodes_;
        unordered_map<int, unordered_set<int>> in_degree_;
        unordered_map<int, unordered_set<int>> out_degree_;
    };
};
