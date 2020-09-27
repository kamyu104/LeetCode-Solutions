// Time:  ctor:    O(1)
//        birth:   O(1)
//        death:   O(1)
//        inherit: O(n)
// Space: O(n)

class ThroneInheritance {
public:
    ThroneInheritance(string kingName) : king_name_(kingName) {
        
    }
    
    void birth(string parentName, string childName) {
        family_tree_[parentName].emplace_back(childName);
    }
    
    void death(string name) {
        dead_.emplace(name);
    }
    
    vector<string> getInheritanceOrder() {
        vector<string> result;
        vector<string> stk = {king_name_};
        while (!empty(stk)) {  // preorder traversal
            const auto node = move(stk.back()); stk.pop_back();
            if (!dead_.count(node)) {
                result.emplace_back(node);
            }
            if (!family_tree_.count(node)) {
                continue;
            }
            for (int i = size(family_tree_[node]) - 1; i >= 0; --i) {
                stk.emplace_back(family_tree_[node][i]);
            }
        }
        return result;
    }

private:
    string king_name_;
    unordered_map<string, vector<string>> family_tree_;
    unordered_set<string> dead_;
};
