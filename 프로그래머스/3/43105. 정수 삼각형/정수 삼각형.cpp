#include <string>
#include <vector>
#define MAX_SIZE 501
using namespace std;
int dist[MAX_SIZE][MAX_SIZE];

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int n = triangle.size();
    dist[0][0] = triangle[0][0];
    for(int i=1;i<n;i++){
        for(int j=0;j<=i;j++){
            dist[i][j] = triangle[i][j] + max(dist[i-1][j], dist[i-1][j-1]);
            answer = max(answer, dist[i][j]);
        }
    }
    return answer;
}