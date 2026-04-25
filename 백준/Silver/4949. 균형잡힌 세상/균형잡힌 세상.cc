#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    stack<char> S;
    bool isRight=true;
    while(1){
        isRight=true;
        getline(cin,str);
        if (str ==".")
            return 0;
        for (char c: str){
            if (c == '(' || c =='['){
                S.push(c);
            }
            else if (c == ')' || c==']'){
                if (S.empty()){
                    isRight = false;
                    break;
                }
                if (c ==')'){
                    if(S.top() == '(')
                        S.pop();
                    else{
                        isRight = false;
                        break;
                    }   
                }
                else{
                    if (S.top() == '[')
                        S.pop();
                    else{
                        isRight = false;
                        break;
                    }
                }
            }
        }
        if(isRight && S.empty())
            cout<<"yes"<<'\n';
        else
            cout<<"no"<<'\n';
        while(!S.empty() ) S.pop();
    }
    return 0;
}