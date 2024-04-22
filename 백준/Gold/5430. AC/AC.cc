#include<cstring>
#include<iostream>
#include<deque>
#include<algorithm>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;


int main(){
    FIO;
    int t;
    cin>>t;
    while(t--) {
        string p, arr;
        int n;
        cin >> p >> n >> arr;
        deque<int> d;
        string tmp = "";
        for (int i = 1; i < arr.length(); i++) {
            if(arr[i] != '[' && arr[i] != ']' && arr[i] != ',') {
                tmp += arr[i];
                continue;
            }
            if(tmp == "") continue;
            d.push_back(stoi(tmp));
            tmp = "";
        }

        int len = p.length();
        bool check = true;
        bool r = true;
        for (int i = 0; i < len; i++) {
            if(p[i] == 'R'){
                r = !r;
            }
            else{
                if(d.empty()){
                    cout << "error\n";
                    check = false;
                    break;
                }
                if(r){
                    d.pop_front();
                }
                else{
                    d.pop_back();
                }
            }
        }
        if(!check) continue;
        cout<<'[';
        while (!d.empty()) {
            if(r){
                cout<<d.front();
                d.pop_front();
            }
            else{
                cout << d.back();
                d.pop_back();
            }
            if(d.empty()) break;
            cout<<',';
        }
        cout<<"]\n";

    }
}