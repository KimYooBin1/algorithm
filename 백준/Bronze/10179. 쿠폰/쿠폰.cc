#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
int main(){
    int n;
    cin>>n;
    while(n--){
        double num;
        cin>>num;
        cout<<"$";
        cout<<fixed;
        cout.precision(2);
        cout<<num * 0.8<<"\n";
    }
}