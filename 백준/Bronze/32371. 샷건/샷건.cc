#include <iostream>
#include <map>
#include <tuple>
#include <vector>
using namespace std;
int main()
{
    vector<vector<char>> v(4, vector<char>(10));
    map<char, pair<int,int>> m;
    string str;
    for(int i=0;i<4;i++){
        cin>>str;
        for(int j=0;j<10;j++){
            m[str[j]] = {i, j};
            v[i][j] = str[j];
        }
    }
    cin>>str;
    int sx = -1, sy = -1, ex = -1, ey = -1;
    int x, y;
    for(int i=0;i<9;i++){
        tie(x,y) = m[str[i]];
        if(sx == -1){
            sx = x;
            ex = x;
        }
        else if(x < sx) sx = x;
        else if(ex < x) ex = x;
        if(sy == -1){
            sy = y;
            ey = y;
        }else if(y < sy) sy = y;
        else if(ey < y) ey = y;
    
    }
    cout<<v[(sx + ex)/2][(sy+ey)/2]<<"\n";
    return 0;
}