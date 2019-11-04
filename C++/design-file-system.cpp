// Time:  create: O(n)
//        get:    O(n)
// Space: O(n)

class FileSystem {
public:
    FileSystem() : lookup_({{"", -1}}) {
        
    }
    
    bool create(string path, int value) {
        if (!lookup_.count(path.substr(0, path.find_last_of('/')))) {
            return false;
        }
        lookup_[path] = value;
        return true;
    }
    
    int get(string path) {
        if (!lookup_.count(path)) {
            return -1;
        }
        return lookup_[path];
    }
    
private:
    unordered_map<string, int> lookup_;
};
