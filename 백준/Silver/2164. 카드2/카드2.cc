#include <bits/stdc++.h>
#define visit VISIT

using namespace std;


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  queue<int> Q;
  int K; cin>>K;
  for (int i = 1; i<=K;i++){
      Q.push(i);
  }
  while(Q.size()!= 1){
      //cout<<Q.size()<<'\n';
      Q.pop();
      int Dat = Q.front();
      Q.push(Dat);
      Q.pop();
  }
  cout<<Q.back();
  return 0;
}