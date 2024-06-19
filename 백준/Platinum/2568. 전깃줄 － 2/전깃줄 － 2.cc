#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 100001
using namespace std;
vector<pair<int,int>> v;
int dir[MAX_SIZE];
bool check[MAX_SIZE];
int low_bound(int s, int e, int target, vector<int> &vec){
    int result = e;
    while(s<e){
        int m = (s+e)/2;
        if(vec[m] < target){
            s = m + 1;
        }
        else{
            result = m;
            e = m;
        }
    }
    return e;
}
int main(){
    FIO;
    int n;
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    sort(v.begin(), v.end());
    vector<int> result;
    for (int i=0;i<v.size();i++){
        auto tmp = v[i];
        //tmp 보다 큰값이 들어가 있음
        int index = low_bound(0, result.size(), tmp.second, result);
        dir[i] = index + 1;
        if(index != result.size()){
            result[index] = tmp.second;
        }
        //tmp.second가 가장 큰수
        else{
            result.push_back(tmp.second);
        }
    }
    int size = result.size();
    vector<int> ret;
    for (int i = v.size() - 1; 0 <= i; i--) {
        if(dir[i] == size){
            size--;
        }
        else{
            ret.push_back(v[i].first);
        }
    }
    reverse(ret.begin(), ret.end());
    cout << n - result.size() << "\n";
    for(auto tmp : ret){
        cout << tmp << "\n";
    }
    return 0;
}
