#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int h=0, w=0;
    for(int i=0;i<sizes.size();i++){
        if(sizes[i][0] > sizes[i][1]) swap(sizes[i][0], sizes[i][1]);
        if(h < sizes[i][0]) h = sizes[i][0];
        if(w < sizes[i][1]) w = sizes[i][1];
    }
    return h*w;
}