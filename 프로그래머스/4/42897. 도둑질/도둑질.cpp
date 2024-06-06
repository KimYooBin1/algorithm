#include <string>
#include <vector>
#include <iostream>
#define MAX_SIZE 1000001
using namespace std;
int dist[MAX_SIZE][2];
int solution(vector<int> money) {
    int answer = 0;
    int size = money.size();
    dist[0][1] = money[0];
    dist[1][1] = money[0];
    
    dist[1][0] = money[1];
    for(int i=2;i<size-1;i++){
        dist[i][0] = max(dist[i-1][0], dist[i-2][0] + money[i]);    
        dist[i][1] = max(dist[i-1][1],dist[i-2][1] + money[i]);    
    }
    dist[size-1][0] = max(dist[size-2][0], dist[size-3][0] + money[size-1]);  
    dist[size-1][1] = dist[size-2][1];  
    answer = max(dist[size-1][0], dist[size-1][1]);
    return answer;
}