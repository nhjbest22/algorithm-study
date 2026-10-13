class TimeMap {
private:
    unordered_map<string, vector<pair<int, string>>> um;
public:
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        um[key].push_back({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        if(um.find(key) == um.end()) return "";

        auto& v = um[key];
        auto it = lower_bound(v.begin(), v.end(), make_pair(timestamp, ""));

        if(it != v.end() && it->first == timestamp) return it->second;
        if(it == v.begin()) return "";

        return (it-1)->second;
    }
};
