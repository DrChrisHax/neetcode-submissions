class TimeMap {
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        keys_[key].emplace_back(timestamp, value);        
    }
    
    string get(string key, int timestamp) {
        std::string res = "";
        auto& values = keys_[key];
        int l = 0, r = values.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            auto& [time, value] = values[mid];

            if (time <= timestamp) {
                res = value;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return res;
    }

private:
    std::unordered_map<std::string, std::vector<std::pair<int, std::string>>> keys_;
};
