#include <bits/stdc++.h>

using namespace std;

vector<int> answer;

vector<string> parse_str(string s){
    vector<string> res;
    string parsed_str;
    
    // , 기준으로 먼저 자르기
    
    int prev = 1, cur;
    while((cur = s.find('}', prev)) != string::npos){
        parsed_str = s.substr(prev, cur - prev + 1);
        res.push_back(parsed_str);
        
        prev = cur + 2;
    }
    
    return res;
}

vector<int> solution(string s) {
    vector<int> res;
    unordered_set<int> us;
    
    vector<string> parsed_str = parse_str(s);
    
    sort(parsed_str.begin(), parsed_str.end(), [&](const string& a, const string& b){
        if(a.size() != b.size()) return a.size() < b.size();
    });
    
    for(auto& str: parsed_str){
        int cur, prev = 1, num;
        bool isFind = false;
        
        while((cur = str.find(',', prev)) != string::npos){
            num = stoi(str.substr(prev, cur - prev));
            
            if(us.find(num) == us.end()){
                us.insert(num);
                res.push_back(num);
                isFind = true;
                break;
            }
            
            prev = cur + 1;
        }
        
        if(isFind) continue;
        
        num = stoi(str.substr(prev, str.size() - prev - 1));
        us.insert(num);
        res.push_back(num);
    }

    return res;
    
}