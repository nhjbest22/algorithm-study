#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main (){
    int num;
    cin>>num;
    int b_num = num / 5;
    int s_num=0;;
    while(b_num != -1){
        while ((b_num*5 + s_num*3) <= num){
            if ((b_num*5 + s_num*3) < num){
                s_num++;
            }
            else{
                cout<<b_num+s_num;
                return 0;
            }
        }
        b_num--; s_num = 0;
    }
    cout<<"-1";
    return 0;
}