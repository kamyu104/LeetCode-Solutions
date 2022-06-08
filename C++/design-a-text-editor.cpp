// Time:  ctor:        O(1)
//        addText:     O(l)
//        deleteText:  O(k)
//        cursorLeft:  O(k)
//        cursorRight: O(k)
// Space: O(n)

// design, stack
class TextEditor {
public:
    TextEditor() {
        
    }
    
    void addText(string text) {
        left_ += text;
    }
    
    int deleteText(int k) {
        const int cnt = min(k, static_cast<int>(size(left_)));
        for (int _ = 0; _ < cnt; ++_) {
            left_.pop_back();
        }
        return cnt;
    }
    
    string cursorLeft(int k) {
        const int cnt = min(k, static_cast<int>(size(left_)));
        for (int _ = 0; _ < cnt; ++_) {
            right_.push_back(left_.back()); left_.pop_back();
        }
        return last_10();
    }
    
    string cursorRight(int k) {
        const int cnt = min(k, static_cast<int>(size(right_)));
        for (int _ = 0; _ < cnt; ++_) {
            left_.push_back(right_.back()); right_.pop_back();
        }
        return last_10();
    }

private:
    string last_10() {
        return left_.substr(max(static_cast<int>(size(left_)) - 10, 0), 10);
    }

    string left_;
    string right_;
};
