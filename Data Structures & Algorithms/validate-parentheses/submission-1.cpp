class Solution {
public:
    bool isValid(string str) {
        unordered_map<char, char> um;
        um[')'] = '('; um['}'] = '{'; um[']'] = '[';
        stack<char> s;

        for(auto& ch: str){
            if(ch == '(' || ch == '{' || ch == '['){
                s.push(ch);
                continue;
            }

            if(s.empty()) return false;
            if(s.top() != um[ch]) return false;

            s.pop();
        }

        if(!s.empty()) return false;

        return true;
    }
};
