#include <bits/stdc++.h>
using namespace std;
int arr[26];

int main(void) {
    ios::sync_with_stdio(0); cin.tie(0);
    int num,temp;
    bool flag = false;
    string str1, str2;
    cin>>num;
    while(num--){
        flag = false;
        cin>>str1>>str2;
        for (int i = 0; i < str1.size();i++){
            arr[str1[i] -'a']++;
            arr[str2[i] - 'a']--;
        }
        for (int c : arr){
            if (c)
                flag = true;
        }
        if (flag)
            cout<<"Impossible"<<'\n';
        else
            cout<<"Possible"<<'\n';
        fill(arr,arr+26,0);
    }
    return 0;
}