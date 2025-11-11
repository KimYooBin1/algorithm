#include<cstring>
#include<iostream>
#include<vector>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);

int calc(int n){
    if(n < 0) n += 8;
    if(8 <= n) n -= 8;
    return n;
}

int main(){
    FIO;
    vector<string> v(5);
    vector<int> cnt(5, 0);
    for (int i = 1; i <= 4; i++) {
        cin >> v[i];
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int index, dir;
        cin >> index >> dir;
        int tmp_index = index;
        int next_dir = dir;
        cnt[tmp_index] = calc(cnt[tmp_index] - next_dir);
        while(tmp_index < 4){
            int next_index = tmp_index + 1;
            if(v[tmp_index][calc(cnt[tmp_index] + 2 + next_dir)] == v[next_index][calc(cnt[next_index] + 6)]) break;
            cnt[next_index] = calc(cnt[next_index] + next_dir);
            tmp_index = next_index;
            next_dir = 0 - next_dir;
        }
//        cout << calc(cnt[1]) << " " << calc(cnt[2]) << " " << calc(cnt[3]) << " " << calc(cnt[4]) << "\n";
        tmp_index = index;
        if (tmp_index == 1)
            continue;
        next_dir = dir;
//        cnt[tmp_index] += next_dir;
        while(1 <= tmp_index){
            int next_index = tmp_index - 1;
            if(v[tmp_index][calc(cnt[tmp_index] + 6 + next_dir)] == v[next_index][calc(cnt[next_index] + 2)]) break;
            cnt[next_index] = calc(cnt[next_index] + next_dir);
            tmp_index = next_index;
            next_dir = 0 - next_dir;
        }
//        cout << calc(cnt[1]) << " " << calc(cnt[2]) << " " << calc(cnt[3]) << " " << calc(cnt[4]) << "\n";
    }
//    cout << v[1][cnt[1]] << "\n" << v[2][cnt[2]] << "\n" << v[3][cnt[3]] << "\n" << v[4][cnt[4]] << "\n";
    cout << (v[1][cnt[1]] - '0') + (v[2][cnt[2]] - '0') * 2 + (v[3][cnt[3]] - '0') * 4 + (v[4][cnt[4]] - '0') * 8 << "\n";
}