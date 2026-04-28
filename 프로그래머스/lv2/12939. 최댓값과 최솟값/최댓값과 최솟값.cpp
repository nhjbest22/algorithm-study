#include <bits/stdc++.h>

using namespace std;

vector<int>& parseString(string& s, vector<int>& v){
    string token;
    stringstream ss(s);
    while(getline(ss, token, ' ')){
        v.push_back(stoi(token));
    }
    
    return v;
}

string solution(string s) {
    vector<int> v;
    parseString(s, v);
    sort(v.begin(), v.end());
    
    string answer = to_string(v.front()) + " " + to_string(v.back());
    return answer;
}