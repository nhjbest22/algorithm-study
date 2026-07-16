class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;

        vector<int> t = {8, 4, 2, 1, 32, 16, 8, 4, 2, 1};
        bool state[10];

        for(int i = 0; i < 10; i++) state[i] = i < turnedOn ? 0 : 1;

        do{
            int hour = 0, min = 0;
            for(int i = 0; i < 10; i++){
                if(state[i]) continue;

                if(i < 4) hour += t[i];
                else min += t[i];
            }

            if(hour > 11 || min > 59) continue;
            
            string str = to_string(hour) + ":";
            str += (min < 10 ? "0" + to_string(min) : to_string(min));

            ans.push_back(str);
        }while(next_permutation(state, state + 10));

        return ans;
    }
};