class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int a = 0, b = 0, l = 0;
        int n = 0, o = 0;

        vector<int> v (5,0); // a, b, n, l, o;
        vector<char> v_ch = {'a', 'b', 'n', 'l', 'o'};

        for(auto& ch: text){
            for(int i = 0; i < 5; i++)
                if(v_ch[i] == ch) v[i]++;
        }

        return min({v[0], v[1], v[2], v[3]/2, v[4]/2});
    }
};