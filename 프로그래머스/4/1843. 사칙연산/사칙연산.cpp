#include <vector>
#include <string>
#include <climits>
#define MAX_SIZE 101
using namespace std;
int max_dist[MAX_SIZE][MAX_SIZE];
int min_dist[MAX_SIZE][MAX_SIZE];

int solution(vector<string> arr)
{
    vector<int> num;
    vector<string> oper;
    for(int i=0;i<arr.size();i+=2){
        num.push_back(stoi(arr[i]));
    }
    for(int i=1;i<arr.size();i+=2){
        oper.push_back(arr[i]);
    }
    int size = num.size();
    
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i == j){
                max_dist[i][i] = num[i];
                min_dist[i][i] = num[i];
            }   
            else{
                max_dist[i][j] = INT_MIN/100;
                min_dist[i][j] = INT_MAX/100;
            }
        }
        
    }

    //어느정도 범위를 계산할건지
    for(int i=1;i<size;i++){
        for(int j=0;j<size-i;j++){
            int z = i+j;
            for(int k=j;k<z;k++){
                if(oper[k] == "+"){
                    max_dist[j][z] = max(max_dist[j][z], max_dist[j][k] + max_dist[k+1][z]);
                    min_dist[j][z] = min(min_dist[j][z], min_dist[j][k] + min_dist[k+1][z]);
                }
                else{
                    max_dist[j][z] = max(max_dist[j][z], max_dist[j][k] - min_dist[k+1][z]);
                    min_dist[j][z] = min(min_dist[j][z], min_dist[j][k] - max_dist[k+1][z]);
                }   
            }
        }
    }
    return max_dist[0][size-1];
    
}