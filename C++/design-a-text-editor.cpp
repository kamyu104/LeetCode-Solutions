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
        return last_characters();
    }
    
    string cursorRight(int k) {
        const int cnt = min(k, static_cast<int>(size(right_)));
        for (int _ = 0; _ < cnt; ++_) {
            left_.push_back(right_.back()); right_.pop_back();
        }
        return last_characters();
    }

private:
    string last_characters() {
        return left_.substr(max(static_cast<int>(size(left_)) - LAST_COUNT, 0), LAST_COUNT);
    }

    static const int LAST_COUNT = 10;
    string left_;
    string right_;
};
