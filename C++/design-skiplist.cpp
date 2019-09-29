// Time:  O(logn) on average for each operation
// Space: O(n)

// see proof in references:
// 1. https://kunigami.blog/2012/09/25/skip-lists-in-python/
// 2. https://opendatastructures.org/ods-cpp/4_4_Analysis_Skiplists.html
// 3. https://brilliant.org/wiki/skip-lists/
class Skiplist {
private:
    class SkipNode {
    public:
        SkipNode() : SkipNode(0, -1) {
            
        }
    
        SkipNode(int level, int num)
          : num(num)
          , nexts(level) {
            
        }

        int num;
        vector<SkipNode *> nexts;
    };

public:
    Skiplist()
      : gen_((random_device())())
      , len_(0)
      , head_(new SkipNode()) {
        
    }
    
    ~Skiplist() {
        if (head_->nexts.empty()) {
            return;
        }
        auto curr = head_->nexts[0];
        while (curr) {
            auto next = curr->nexts[0];
            delete curr;
            curr = next;
        }
    }
    
    bool search(int target) const {
        return find(target, find_prev_nodes(target)) != nullptr;
    }
    
    void add(int num) {
        auto node = new SkipNode(random_level(), num);
        if (head_->nexts.size() < node->nexts.size()) {
            head_->nexts.resize(node->nexts.size());
        }
        auto prevs = find_prev_nodes(num);
        for (int i = 0; i < node->nexts.size(); ++i) {
            node->nexts[i] = prevs[i]->nexts[i];
            prevs[i]->nexts[i] = node;
        }
        ++len_;
    }
    
    bool erase(int num) {
        auto prevs = find_prev_nodes(num);
        auto curr = find(num, prevs);
        if (!curr) {
            return false;
        }
        --len_;
        for (int i = curr->nexts.size() - 1; i >= 0; --i) {
            prevs[i]->nexts[i] = curr->nexts[i];
            if (!head_->nexts[i]) {
                head_->nexts.pop_back();
            }
        }
        delete curr;
        return true;
    }

    int size() const {
        return len_;
    }
    
private:
    SkipNode *find(int num, const vector<SkipNode *>& prevs) const {
        if (!prevs.empty()) {
            auto candidate = prevs[0]->nexts[0];
            if (candidate && candidate->num == num) {
                return candidate;
            }
        }
        return nullptr;
    }
    
    vector<SkipNode *> find_prev_nodes(int num) const {
        vector<SkipNode *> prevs(head_->nexts.size());
        auto curr = head_;
        for (int i = head_->nexts.size() - 1; i >= 0; --i) {
            while (curr->nexts[i] && curr->nexts[i]->num < num) {
                curr = curr->nexts[i];
            }
            prevs[i] = curr;
        }
        return prevs;
    }
    
    int random_level() {
        static const int P_NUMERATOR = 1;
        static const int P_DENOMINATOR = 2;  // P = 1/4 in redis implementation
        static const int MAX_LEVEL = 32;  // enough for 2^32 elements
        int level = 1;
        while (uniform_int_distribution<int>{1, P_DENOMINATOR}(gen_) <= P_NUMERATOR &&
               level < MAX_LEVEL) {
            ++level;
        }
        return level;
    }
    
    void print_list() const {
        for (int i = head_->nexts.size() - 1; i >= 0; --i) {
            auto curr = head_->nexts[i];
            cout << curr->num;
            curr = curr->nexts[i];
            while (curr) {
                cout << "->" << curr->num;
                curr = curr->nexts[i];
            }
            cout << endl;
        }
    }

    default_random_engine gen_;
    int len_;
    SkipNode *head_;
};

// Time:  O(logn) on average for each operation
// Space: O(n)
// smart pointer version (a little bit slower)
class Skiplist2 {
private:
    class SkipNode {
    public:
        SkipNode() : SkipNode(0, -1) {
            
        }
    
        SkipNode(int level, int num)
          : num(num)
          , nexts(level) {
            
        }

        int num;
        vector<shared_ptr<SkipNode>> nexts;
    };

public:
    Skiplist2()
      : gen_((random_device())())
      , len_(0)
      , head_(make_shared<SkipNode>()) {
        
    }
    
    bool search(int target) const {
        return find(target, find_prev_nodes(target)) != nullptr;
    }
    
    void add(int num) {
        auto node = make_shared<SkipNode>(random_level(), num);
        if (head_->nexts.size() < node->nexts.size()) {
            head_->nexts.resize(node->nexts.size());
        }
        auto prevs = find_prev_nodes(num);
        for (int i = 0; i < node->nexts.size(); ++i) {
            node->nexts[i] = prevs[i]->nexts[i];
            prevs[i]->nexts[i] = node;
        }
        ++len_;
    }
    
    bool erase(int num) {
        auto prevs = find_prev_nodes(num);
        auto curr = find(num, prevs);
        if (!curr) {
            return false;
        }
        --len_;
        for (int i = curr->nexts.size() - 1; i >= 0; --i) {
            prevs[i]->nexts[i] = curr->nexts[i];
            if (!head_->nexts[i]) {
                head_->nexts.pop_back();
            }
        }
        return true;
    }

    int size() const {
        return len_;
    }

private:
    shared_ptr<SkipNode> find(int num, const vector<shared_ptr<SkipNode>>& prevs) const {
        if (!prevs.empty()) {
            auto candidate = prevs[0]->nexts[0];
            if (candidate && candidate->num == num) {
                return candidate;
            }
        }
        return nullptr;
    }
    
    vector<shared_ptr<SkipNode>> find_prev_nodes(int num) const {
        vector<shared_ptr<SkipNode>> prevs(head_->nexts.size());
        auto curr = head_;
        for (int i = head_->nexts.size() - 1; i >= 0; --i) {
            while (curr->nexts[i] && curr->nexts[i]->num < num) {
                curr = curr->nexts[i];
            }
            prevs[i] = curr;
        }
        return prevs;
    }
    
    int random_level() {
        static const int P_NUMERATOR = 1;
        static const int P_DENOMINATOR = 2;  // P = 1/4 in redis implementation
        static const int MAX_LEVEL = 32;  // enough for 2^32 elements
        int level = 1;
        while (uniform_int_distribution<int>{1, P_DENOMINATOR}(gen_) <= P_NUMERATOR &&
               level < MAX_LEVEL) {
            ++level;
        }
        return level;
    }
    
    void print_list() const {
        for (int i = head_->nexts.size() - 1; i >= 0; --i) {
            auto curr = head_->nexts[i];
            cout << curr->num;
            curr = curr->nexts[i];
            while (curr) {
                cout << "->" << curr->num;
                curr = curr->nexts[i];
            }
            cout << endl;
        }
    }

    default_random_engine gen_;
    int len_;
    shared_ptr<SkipNode> head_;
};
