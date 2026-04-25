#include <bits/stdc++.h>
#define visit VISIT

using namespace std;


int main(void) {
  ios::sync_with_stdio(0);
  cin.tie(0);
  deque<int> D;
  string str;
  bool isL(0), isR(0);
  int count(0);
  int K, N; cin>>K>>N;
  for (int i= 1; i <=K;i++)
    D.push_back(i);
  while(N--){
      int Num; cin >>Num;
      int left, right;
      for (int i = 0; i<D.size();i++){
          if(D[i] == Num){
              left = i; isL = 1; break;
          }
          else if (D[D.size()-i-1] == Num){
              right = i; isR = 1; break;
          }
      }
      if (isL){
          while(left--){
              int back = D.front();
              D.pop_front(); D.push_back(back);
              count++;
          }
          D.pop_front(); isL = 0;
      }
      else{
          while(right--){
              int back = D.back();
              D.pop_back(); D.push_front(back);
              count++;
          }
          D.pop_back();
          count++;
      }

  }
  cout<<count;
  return 0;
}