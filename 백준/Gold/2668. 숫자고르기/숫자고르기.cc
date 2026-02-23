#include<cstring>
#include<iostream>
#include<set>
#include<vector>
using namespace std;
set<int> result;

bool calc(int first, int num, vector<int> &v, vector<bool> &c){
//    cout << first << " " << num << "\n";
    if(first == num){
        result.insert(num);
        return true;
    }
    if(c[v[num]]) return false;
    c[v[num]] = true;
    if(calc(first, v[num], v, c)){
        result.insert(num);
        return true;
    }
    return false;
}

int main(){
    int n;
    cin>>n;
    vector<int> v(n + 1);
    for (int i = 1; i <= n; i++) {
        cin>>v[i];
    }
    for (int i = 1; i <= n; i++) {
        vector<bool> check(n + 1, false);
//        check[i] = true;
        calc(i, v[i], v, check);
    }
    cout<<result.size()<<"\n";
    for(auto &a: result){
        cout << a << "\n";
    }
}