#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
#define MAX_SIZE 100001
using namespace std;
vector<pair<int,int>> v;
int dir[MAX_SIZE];
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
    return result;
}
int main(){
    FIO;
    int n;
    cin >> n;
    int a, b;
    //전기줄 입력
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }
    //정렬을 통해 b만 확인해도 교차하는지 아닌지 판단하기 위해
    sort(v.begin(), v.end());
    vector<int> result;
    //
    for (int i=0;i<v.size();i++){
        auto tmp = v[i];
        //tmp 보다 크거나 같은 숫자의 index 출력
        int index = low_bound(0, result.size(), tmp.second, result);
        //해당 위치가 가장 긴 순열에서 어느 index에 위치하는지
        dir[i] = index + 1;
        // index가 가장 긴 부분순열 중간에 위치하면 해당 위치를 교체
        if(index != result.size()){
            result[index] = tmp.second;
        }
        // 현재 b가 가장 큰 숫자, 그냥 push
        else{
            result.push_back(tmp.second);
        }
    }
    int size = result.size();
    vector<int> ret;
    // 가장 긴 순열에서 가장 마지막 index부터 ret에 추가해야 올바른 집합이 나온다
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
