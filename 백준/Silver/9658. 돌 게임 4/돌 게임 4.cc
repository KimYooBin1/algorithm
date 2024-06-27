#include<cstring>
#include<iostream>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;
int arr[1001];
int main(){
    FIO;
    int n;
    cin >> n;
    arr[1] = 0;
    arr[2] = 1;
    arr[3] = 0;
    arr[4] = 1;
    for (int i = 5; i <= n; i++) {
        if(!arr[i-1] || !arr[i-3] || !arr[i-4]) arr[i] = 1;
        else arr[i] = 0;
    }
    if(arr[n]){
        cout<<"SK\n";
    }
    else{
        cout<<"CY\n";
    }
    return 0;
}