#include<cstring>
#include<iostream>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
int main(){
    FIO;
    int cnt;
    cin>>cnt;
    while(cnt--){
        int h, w, n;
        cin >> h >> w >> n;
        n--;

        int wid = n%h;
        int num = n/h+1;
        string tmp1 = to_string(num);
        string result = "";
        if(tmp1.length() == 1) result += '0';
        cout<<wid+1<<result<<num<<"\n";
    }
}