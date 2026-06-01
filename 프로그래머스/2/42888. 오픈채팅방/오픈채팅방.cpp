#include <bits/stdc++.h>

using namespace std;

vector<string> parse_string(const string& str){
    vector<string> res;
    
    int prev = 0;
    int cur;
    while((cur = str.find(" ", prev)) != string::npos){
        res.push_back(str.substr(prev, cur - prev));
        prev = cur + 1;
    }
    
    res.push_back(str.substr(prev));
    
    return res;
}

vector<string> solution(vector<string> record) {
    vector<string> res;
    unordered_map<string, string> uTOn;
    vector<vector<string>> logs;
    
    for(auto& log: record){
        auto parsed_log = parse_string(log);
        
        string& op = parsed_log[0];
        string& uuid = parsed_log[1];
        
        if(op == "Enter" || op == "Change"){
            string& nickname = parsed_log[2];
            uTOn[uuid] = nickname;
            
            if(op == "Change") continue;
        }
        
        logs.push_back({op, uuid});
    }
    
    for(auto& log: logs){
        string& op = log[0];
        string& uuid = log[1];
        string log_str;
    
        if(op == "Enter"){
            log_str = uTOn[uuid] + "님이 들어왔습니다.";
        } else{
            log_str = uTOn[uuid] + "님이 나갔습니다.";
        }
        
        res.push_back(log_str);
    }
    
    return res;
}