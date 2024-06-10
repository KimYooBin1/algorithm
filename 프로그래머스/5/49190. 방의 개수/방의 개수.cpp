#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;
int dx[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
int dy[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int solution(vector<int> arrows) {
    int answer = 0;
    // 해당 {x, y} 좌표를 지난적이 있는지
    map<pair<int, int>, bool> point;
    // 해당 {x1, y1}, {x2, y2}를 연결하는 선을 지난적이 있는지
    map<pair<pair<int, int>, pair<int, int>>, bool> road;
    int size = arrows.size();
    int x = 0;
    int y = 0;
    point[make_pair(x, y)] = true;
    for(int i=0;i<size;i++){
        int dir = arrows[i];
        for(int j=0;j<2;j++){
            // cout<<x<<" "<<y<<"\n";
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            
            //해당 경로를 지난적이 없음
            if(road[make_pair(make_pair(x, y), make_pair(nx, ny))] == false){
                road[make_pair(make_pair(x, y), make_pair(nx, ny))] = true;
                road[make_pair(make_pair(nx, ny), make_pair(x, y))] = true;

                //한번 지난적 있는 점
                if(point[make_pair(nx, ny)]){
                    answer++;    
                }
                point[make_pair(nx, ny)] = true;
            }
            x = nx;
            y = ny;
        }
    }
    
    return answer;
}