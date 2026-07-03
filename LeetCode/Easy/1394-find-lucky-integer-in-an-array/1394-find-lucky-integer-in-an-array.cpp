class Solution {
public:
    int findLucky(vector<int>& arr) {
        int cnt[505] = {0, };

        for(auto& num: arr) cnt[num]++;

        for(int i = 500; i>= 1; i--){
            if(cnt[i] == i) return i;
        }


        return -1;
    }
};