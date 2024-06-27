#include<cstring>
#include<iostream>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 1001
using namespace std;
int main(){
    FIO;
    int n;
    cin >> n;
    //홀수
    if(n%2){
        cout<<"CY\n";
    }
    //짝수
    else{
        cout<<"SK\n";
    }
    return 0;
}