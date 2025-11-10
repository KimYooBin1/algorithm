#include<cstring>
#include<iostream>
using namespace std;
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
struct point {
    int x, y;
    int a, b;
};
int main(){
    FIO;
    for (int i = 0; i < 4; i++) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int X, Y, A, B;
        cin >> X >> Y >> A >> B;
        // 점일 때
        if((x == A && y == B) || (x == A && b == Y) || (a == X && b == Y) || (a == X && y == B)){
            cout << 'c' << "\n";
            continue;
        }
        // 만나지 않을 때
        else if (b < Y || a < X || B < y || A < x) {
            cout << 'd' << "\n";
            continue;
        }
        // 선분
        else if(((a == X || x == A) && !(b < Y && B < y)) ||
                (b == Y || y == B) && !(a < X && A < x)){
            cout << 'b' << "\n";
            continue;
        }
        // 직사각형
        else{
            cout << 'a' << "\n";
            continue;
        }
    }
}