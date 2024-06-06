#include<cstring>
#include<iostream>
using namespace std;

int main(){
	cin.tie(NULL); //입출력 묶음 해제
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    int arr[n+1][n+1] = {0,};
    int sum[n+1][n+1] = {0,};
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            int tmp;
            cin>>tmp;
            arr[i][j] = tmp;
        }
    }
    int ret = arr[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            sum[i][j] = max(sum[i-1][j-1], sum[i-1][j]) + arr[i][j];
            ret = max(ret, sum[i][j]);
        }
    }
    cout<<ret<<"\n";
}