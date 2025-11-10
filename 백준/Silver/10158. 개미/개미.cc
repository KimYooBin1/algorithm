#include<cstring>
#include<iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
int main(){
    FIO;
    int w, h;
    cin >> w >> h;
    int p, q;
    cin >> p >> q;
    int t;
    cin >> t;
    int r_x = -1, r_y = -1;
    if(p + t <= w) r_x = p + t;
    if(q + t <= h) r_y = q + t;
    if(r_x == -1){
        int remain_t = t - (w - p);
        int round = remain_t / w;
        int tmp = remain_t % w;
//        cout << remain_t << p << " " << " " << round << " " << tmp << "\n";
        if(round % 2) r_x = tmp;
        else r_x = w - tmp;
    }
    if(r_y == -1){
        int remain_t = t - (h - q);
        int round = remain_t / h;
        int tmp = remain_t % h;
        if(round % 2) r_y = tmp;
        else r_y = h - tmp;
    }
    cout << r_x << " " << r_y << "\n";
}