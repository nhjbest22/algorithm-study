#include <bits/stdc++.h>
using namespace std;

int main (){
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    int num; cin>>num;
    while(num--){
        list <char>li;
        list<char>::iterator it;
        it = li.end();
        cin>>str;
        for (auto ch : str){
            if (ch == '<'){
                if (it != li.begin())
                    it--;
            }
            else if (ch == '>'){
                if (it != li.end())
                    it++;
            }
            else if (ch == '-'){
                if (it != li.begin()){
                    it--;
                    it = li.erase(it);
                }
            }
            else{
                li.insert(it,ch);
            }

        }
        for (auto ch : li)
            cout<<ch;
        cout<<'\n';
    }
    return 0;
}