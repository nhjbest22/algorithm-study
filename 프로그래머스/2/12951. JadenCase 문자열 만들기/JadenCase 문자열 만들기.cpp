#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    int prev = 0;
    int pos;
    
    vector<string> str;
    
    while((pos = s.find(" ", prev)) != string::npos){
        str.push_back(s.substr(prev, pos - prev));
        prev = pos + 1;
    }
    
    str.push_back(s.substr(prev));
    
    for(auto& s: str){
        if(s[0] >= 'a' && s[0] <= 'z'){
            s[0] += ('Z' - 'z');
        }
        
        for(int i = 1; i < s.size(); i++){
            if(s[i] <= 'Z' && s[i] >= 'A') s[i] += ('z' - 'Z');
        }
    }
    
    string output = str[0];
    for(int i = 1; i < str.size(); i++){
        output += ' ';
        output += str[i];
    }
    
    return output;
    // return answer;
}