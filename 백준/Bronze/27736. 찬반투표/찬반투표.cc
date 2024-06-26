#include<cstring>
#include<iostream>
#include<map>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int main(){
    FIO;
    map<int, int> m;
    int n;
    cin>>n;
    int num;
    for (int i = 0; i < n; i++) {
        cin>>num;
        m[num]++;
    }
    //홀수
    if(n%2){
        if((n/2) + 1 <= m[0]){
            cout<<"INVALID\n";
            return 0;
        }
    }
    //짝수
    else{
        if(n/2 <= m[0]){
            cout<<"INVALID\n";
            return 0;
        }
    }
    if(m[1] <= m[-1]){
        cout<<"REJECTED\n";
    }
    else{
        cout<<"APPROVED\n";
    }
    return 0;
}