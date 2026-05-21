#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

bool method[10]; //2 ~ 9까지

vector<string> equ;

tuple<string, string, string, string> parse_str(const string& str){
    int idx1, idx2;
    for(int i = 0; i < str.length(); i++){
        auto ch = str[i];
        if(ch == '+' || ch == '-') idx1 = i;
        if(ch == '=') idx2 = i;
    }
    
    string A = str.substr(0, idx1 - 1);
    string B = str.substr(idx1 + 2, idx2 - idx1 - 3);
    string C = str.substr(idx2+ 2);
    string op = str.substr(idx1, 1);
    
    int M = *max_element(A.begin(), A.end()) - '0';
    for(int i = 2; i<=M;i++) method[i] = false;
    
    M = *max_element(B.begin(), B.end()) - '0';
    for(int i = 2; i<=M;i++) method[i] = false;

    if(C != "X"){
        M = *max_element(C.begin(), C.end()) - '0';
        for(int i = 2; i<=M;i++) method[i] = false;
    }

    return {A, B, C, op};
}

int str_to_nth(string str, int n){
    int ret = 0;
    int cur = stoi(str);
    for(auto ch: str){
        ret *= n;
        ret += (ch - '0');
    }
    
    return ret;
}

void test_nth(string A, string B, string C, string op){
    for(int i =9;i>=2;i--){
        if(!method[i]) continue;
    
        
        int a = str_to_nth(A, i), b = str_to_nth(B, i), c = str_to_nth(C, i);
        if(op == "+") method[i] = (a + b == c);
        else method[i] = (a - b == c);
    }
}

vector<string> solution(vector<string> expressions) {
    vector<string> answer;
    
    for(int i = 2; i<= 9;i++) method[i] = true;
    for(auto str: expressions){
        int str_len = str.length();
        if(str[str_len-1] == 'X') {
            equ.push_back(str);
            parse_str(str);
            continue;
        }
        
        auto [A, B, C, op] = parse_str(str);
        test_nth(A, B, C, op);
    }
    
    
    for(auto str: equ){
        bool isPossible = true;
        int ret = -1;
        
        int idx1, idx2;
        for(int i = 0; i < str.length(); i++){
            auto ch = str[i];
            if(ch == '+' || ch == '-') idx1 = i;
            if(ch == '=') idx2 = i;
        }

        string A = str.substr(0, idx1 - 1);
        string B = str.substr(idx1 + 2, idx2 - idx1 - 3);
        string op = str.substr(idx1, 1);
        
        for(int i = 2; i<= 9; i++){
            if(!method[i]) continue;
            
            int tmp;
            int a = str_to_nth(A, i);
            int b = str_to_nth(B, i);
            
            if(op == "+") tmp = a+b;
            else tmp = a-b;
            
            string buf = "";
            while(tmp){
                buf += to_string(tmp % i);
                tmp /= i;
            }
            
            reverse(buf.begin(), buf.end());
            buf = "0" + buf;
            
            if(ret == -1){
                ret = stoi(buf);
                continue;
            }
            
            if(ret != stoi(buf)){
                isPossible = false;
                break;
            }
            
        }
        
        if(!isPossible) answer.push_back(A + " " + op + " " + B + " = " + "?");
        else answer.push_back(A + " " + op + " " + B + " = " + to_string(ret));
    }
    
    
    return answer;
}