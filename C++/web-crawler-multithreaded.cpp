// Time:  O(|V| + |E|)
// Space: O(|V|)

/**
 * // This is the HtmlParser's API interface.
 * // You should not implement it, or speculate about its implementation
 * class HtmlParser {
 *   public:
 *     vector<string> getUrls(string url);
 * };
 */
class Solution {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        q_.emplace(startUrl);
        unordered_set<string> lookup = {startUrl};
        vector<thread> workers;
        const auto& worker = [this](HtmlParser *htmlParser, unordered_set<string> *lookup) {
            while (true) {
                string from_url;
                {
                    unique_lock<mutex> lock{m_};
                    cv_.wait(lock, [this]() { return !q_.empty(); });
                    from_url = q_.front(); q_.pop();
                    if (from_url.empty()) {
                        break;
                    }
                    ++working_count_;
                }
                const auto& name = hostname(from_url);
                for (const auto& to_url: htmlParser->getUrls(from_url)) {
                    if (name != hostname(to_url)) {
                        continue;
                    }
                    unique_lock<mutex> lock{m_};
                    if (!lookup->count(to_url)) {
                        lookup->emplace(to_url);
                        q_.emplace(to_url);
                        cv_.notify_all();
                    }
                }
                {
                    unique_lock<mutex> lock{m_};
                    --working_count_;
                    if (q_.empty() && !working_count_) {
                        cv_.notify_all();
                    }
                }
            }
        };
        for (int i = 0; i < NUMBER_OF_WORKERS; ++i) {
            workers.emplace_back(worker, &htmlParser, &lookup);
        }
        {
            unique_lock<mutex> lock{m_};
            cv_.wait(lock, [this]() { return q_.empty() && !working_count_; });
            for (const auto& t : workers) {
                q_.emplace();
            }
            cv_.notify_all();
        }
        for (auto& t : workers) {
            t.join();
        }
        return vector<string>(lookup.cbegin(), lookup.cend());
    }

private:
    string hostname(const string& url) {
        static const string scheme = "http://";
        return url.substr(0, url.find('/', scheme.length()));
    }

    static const int NUMBER_OF_WORKERS = 4;
    queue<string> q_;
    int working_count_ = 0;
    mutex m_;
    condition_variable cv_;
};

// Time:  O(|V| + |E|)
// Space: O(|V|)
class Solution2 {
public:
    vector<string> crawl(string startUrl, HtmlParser htmlParser) {
        q_.emplace(startUrl);
        unordered_set<string> lookup = {startUrl};
        vector<thread> workers;
        for (int i = 0; i < NUMBER_OF_WORKERS; ++i) {
            workers.emplace_back(bind(&Solution2::worker, this, &htmlParser, &lookup));
        }
        {
            unique_lock<mutex> lock{m_};
            cv_.wait(lock, [this]() { return q_.empty() && !working_count_; });
            for (const auto& t : workers) {
                q_.emplace();
            }
            cv_.notify_all();
        }
        for (auto& t : workers) {
            t.join();
        }
        return vector<string>(lookup.cbegin(), lookup.cend());
    }

private:
    void worker(HtmlParser *htmlParser, unordered_set<string> *lookup) {
        while (true) {
            string from_url;
            {
                unique_lock<mutex> lock{m_};
                cv_.wait(lock, [this]() { return !q_.empty(); });
                from_url = q_.front(); q_.pop();
                if (from_url.empty()) {
                    break;
                }
                ++working_count_;
            }
            const auto& name = hostname(from_url);
            for (const auto& to_url: htmlParser->getUrls(from_url)) {
                if (name != hostname(to_url)) {
                    continue;
                }
                unique_lock<mutex> lock{m_};
                if (!lookup->count(to_url)) {
                    lookup->emplace(to_url);
                    q_.emplace(to_url);
                    cv_.notify_all();
                }
            }
            {
                unique_lock<mutex> lock{m_};
                --working_count_;
                if (q_.empty() && !working_count_) {
                    cv_.notify_all();
                }
            }
        }
    }
    
    string hostname(const string& url) {
        static const string scheme = "http://";
        return url.substr(0, url.find('/', scheme.length()));
    }

    static const int NUMBER_OF_WORKERS = 4;
    queue<string> q_;
    int working_count_ = 0;
    mutex m_;
    condition_variable cv_;
};
