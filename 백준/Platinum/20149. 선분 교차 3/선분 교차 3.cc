#include <cstring>
#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pll;

vector<pll> v;

ll CCW(pll A, pll B, pll C){
    ll tmp = A.first * B.second + B.first * C.second + C.first * A.second
           - (B.first * A.second + C.first * B.second + A.first * C.second);

    if(tmp<0) return -1;
    else if(tmp == 0) return 0;
    else return 1;
}
void find_intersection(pll A, pll B, pll C, pll D) // 교점 구하기
{
    double px = (A.first * B.second - A.second * B.first) * (C.first - D.first) - (A.first - B.first) * (C.first * D.second - C.second * D.first);
    double py = (A.first * B.second - A.second * B.first) * (C.second - D.second) - (A.second - B.second) * (C.first * D.second - C.second * D.first);
    double p = (A.first - B.first) * (C.second - D.second) - (A.second - B.second) * (C.first - D.first);

    if (p == 0) // 평행할 때
    {
        // 교점이 하나일 때
        if (B == C && A <= C) cout << B.first << " " << B.second << '\n';
        else if (A == D && C <= A) cout << A.first << " " << A.second << '\n';
    }
    else // 교차할 때
    {
        double x = px / p;
        double y = py / p;

        cout << fixed;
        cout.precision(9);
        cout << x << " " << y;
    }
}

int main(){
    for (int i = 0; i < 4; i++) {
        ll x, y;
        cin>>x>>y;
        v.push_back(make_pair(x, y));
    }
    ll ret1 = CCW(v[0], v[1], v[2]) * CCW(v[0], v[1], v[3]);
    ll ret2 = CCW(v[2], v[3], v[0]) * CCW(v[2], v[3], v[1]);
    if(ret1<=0 && ret2<=0) {
        if(v[1] < v[0]) swap(v[1], v[0]);
        if(v[3] < v[2]) swap(v[3], v[2]);
        if(v[0] <= v[3] && v[2] <= v[1]){
            cout<<1<<"\n";
            find_intersection(v[0], v[1], v[2], v[3]);
        }
        else{
            cout<<0<<"\n";
        }
    }
    else{
        cout<<0<<"\n";
    }
}