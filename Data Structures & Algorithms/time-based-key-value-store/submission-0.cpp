class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {}

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {

        if (!mp.contains(key))
            return "";

        auto& vec = mp[key];

        int left = 0, mid, right = vec.size() - 1;
        string result = "";

        while (left <= right) {

            mid = left + (right - left) / 2;
            if (vec[mid].first == timestamp)
                return mp[key][mid].second;
            if (vec[mid].first > timestamp)
                right = mid - 1;
            if (vec[mid].first < timestamp) {
                left = mid + 1;
                result = vec[mid].second;
            }
        }

        return result;
    }
};
