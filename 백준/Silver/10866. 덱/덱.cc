#include <bits/stdc++.h>
#define visit VISIT

using namespace std;


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  deque<int> D;
  string str;
  int K; cin>>K;
  while(K--){
      cin>>str;
      if (str == "push_back"){
          int Dat; cin>>Dat;
          D.push_back(Dat);
      }
      else if (str == "push_front"){
          int Dat; cin>>Dat;
          D.push_front(Dat);
      }
      else if (str == "pop_front"){
          if (D.empty())
            cout<<-1<<'\n';
          else{
              cout<<D.front()<<'\n'; D.pop_front();
          }
      }
      else if(str == "pop_back"){
        if (D.empty())
            cout<<-1<<'\n';
        else{
            cout<<D.back()<<'\n'; D.pop_back();
          }
      }
      else if (str == "size")
        cout<<D.size()<<'\n';
      else if (str == "empty")
        cout<<(D.empty()?1:0)<<'\n';
      else if (str == "front")
        cout<<(D.empty()?-1:D.front())<<'\n';
      else if (str =="back")
        cout<<(D.empty()?-1:D.back())<<'\n';
  }
  return 0;
}