#include<cstring>
#include<iostream>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define MAX_SIZE 1001
using namespace std;
int arr[MAX_SIZE][2];
int n;
bool calc(int x, int turn){
    if(x == n){
        if(turn){
            cout<<"SK\n";
        }else{
            cout<<"CY\n";
        }
        return true;
    } else if (n < x) {
        return false;
    }
    if(calc(x+1, 1-turn)) return true;
    if(calc(x+3, 1-turn)) return true;
    return false;
}
int main(){
    FIO;
    cin >> n;
    calc(0, 0);
    return 0;
}