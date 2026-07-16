class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        for(int hour = 0; hour < 12; hour++){
            for(int min = 0; min < 60; min++){
                if(__builtin_popcount(hour) + __builtin_popcount(min) != turnedOn) continue;

                string str = to_string(hour) + ":";
                
                if(min < 10) str += "0";
                str += to_string(min);

                ans.push_back(str);
            }
        }
        return ans;
    }
};