#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#define FIO cin.tie(NULL); ios_base::sync_with_stdio(false);
using namespace std;
vector<int> v;
int parent[4000001];
int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}
int U(int x, int y){
//    cout << x << " " << y << "\n";
    int nx = find(x);
    int ny = find(y);
    if(nx == ny) return parent[nx];
    parent[nx] = ny;
    return nx;
}
int up_bound(int s, int e, int target, vector<int> &v){
//    int result = e;
    while(s<e) {
        int m = (s + e) / 2;
        //찾는값이 더 크다.
        if(v[m] <= target){
            s = m + 1;
        }
        else{
            e = m;
//            result = m;
        }
    }
    return e;
}
int main(){
    FIO;
    int n, m, k;
    cin >> n >> m >> k;
    int num;
    for (int i = 0; i < m; i++) {
        cin >> num;
        parent[i] = i;
        v.push_back(num);
    }

    //upper_bound를 사용하기 위해서 정렬=
    sort(v.begin(), v.end());

    for (int i = 0; i < k; i++) {
        cin >> num;
        int index = up_bound(0, v.size(), num, v);
//        int index = upper_bound(v.begin(), v.end(), num) - v.begin();
        int next_index = find(index);

//        cout << "index : " << next_index << "\n";
        cout << v[U(next_index, next_index + 1)] << "\n";
    }
    return 0;
}
