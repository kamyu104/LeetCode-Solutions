// Time:  ctor:                O(1)
//        upload:              O(logn+l)
//        remove:              O(logn)
//        like:                O(1)
//        dislike:             O(1)
//        view:                O(l)
//        getLikesAndDislikes: O(1)
//        getViews:            O(1)
// Space: O(n * l), n = len(videos), l = max(len(v) for v in videos) 

// design, heap
class VideoSharingPlatform {
public:
    VideoSharingPlatform() {
        
    }
    
    int upload(string video) {
        int i;
        if (!empty(avails_)) {
            i = avails_.top(); avails_.pop();
        } else {
            i = size(videos_);
            videos_.emplace_back();
            likes_.emplace_back();
            dislikes_.emplace_back();
            views_.emplace_back();
        }
        videos_[i] = video;
        return i;
    }
    
    void remove(int videoId) {
        if (videoId >= size(videos_) || views_[videoId] == -1) {
            return;
        }
        avails_.emplace(videoId);
        videos_[videoId].clear();
        likes_[videoId] = dislikes_[videoId] = views_[videoId] = 0;
    }
    
    string watch(int videoId, int startMinute, int endMinute) {
        if (videoId >= size(videos_) || empty(videos_[videoId])) {
            return "-1";
        }
        ++views_[videoId];
        return videos_[videoId].substr(startMinute, endMinute - startMinute + 1);
    }
    
    void like(int videoId) {
        if (videoId >= size(videos_) || empty(videos_[videoId])) {
            return;
        }
        ++likes_[videoId];
    }
    
    void dislike(int videoId) {
        if (videoId >= size(videos_) || empty(videos_[videoId])) {
            return;
        }
        ++dislikes_[videoId];
    }
    
    vector<int> getLikesAndDislikes(int videoId) {
        if (videoId >= size(videos_) || empty(videos_[videoId])) {
            return {-1};
        }
        return {likes_[videoId], dislikes_[videoId]};
    }
    
    int getViews(int videoId) {
        if (videoId >= size(videos_) || empty(videos_[videoId])) {
            return -1;
        }
        return views_[videoId];
    }

private:
    priority_queue<int, vector<int>, greater<int>> avails_;
    vector<string> videos_;
    vector<int> likes_;
    vector<int> dislikes_;
    vector<int> views_;
};
