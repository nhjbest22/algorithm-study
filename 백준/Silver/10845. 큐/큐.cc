#include <bits/stdc++.h>
#define visit VISIT

using namespace std;

int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<int> Q;
  string str;
  int K; cin>>K;
  while(K--){
      cin>>str;
      if (str=="push"){
          int Dat; cin>>Dat;
          Q.push(Dat);
      }
      else if (str=="pop"){
          if(!Q.empty()){
            cout<<Q.front()<<'\n'; Q.pop();
          }
          else 
            cout<<-1<<'\n';
      }
      else if (str == "size")
        cout<<Q.size()<<'\n';
      else if (str == "empty"){
          if (Q.empty())
            cout<<1<<'\n';
          else
            cout<<0<<'\n';
      }
      else if (str == "front"){
          if(Q.empty()){
              cout<<-1<<'\n';
          }
          else
            cout<<Q.front()<<'\n';
      }
      else
          if(Q.empty()){
              cout<<-1<<'\n';
          }
          else
            cout<<Q.back()<<'\n';
  }  
}