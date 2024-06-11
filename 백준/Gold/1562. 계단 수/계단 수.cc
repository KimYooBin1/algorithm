#include <cstring>
#include <iostream>
#include <cmath>
#define FIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define mod 1000000000
typedef long long ll;
using namespace std;
int n;
ll dist[10][101][4];
int calc(int index, int bit, int num){

    if(dist[num][index][bit] != -1) return dist[num][index][bit];
    if(index == n){
        //0~9까지 모든 숫자를 사용했으면 1 return
        if(bit == 3) return 1;
        //아니면 0 return
        return 0;
    }
    int pre_num = num % 10;
    ll result = 0;
    //음수가 들어갈수는 없다
    if(pre_num != 0){
        int next_num2 = pre_num-1;
        result += calc(index + 1, bit | (next_num2 == 0 ? 1 : 0), next_num2);
    }
    //한자리수씩 추가 가능하다
    if(pre_num != 9){
        int next_num1 = pre_num+1;
        result += calc(index + 1, bit | (next_num1 == 9 ? 2 : 0), next_num1);
    }
    return dist[num][index][bit] = result % mod;
}
int main(){
    FIO;
    memset(dist, -1, sizeof(dist));
    cin >> n;
    ll result = 0;
    for(int i=1;i<10;i++){
        result += calc(1, (i == 9) ? 2 : 0, i) % mod;
    }
    cout<<result%mod<<"\n";
}