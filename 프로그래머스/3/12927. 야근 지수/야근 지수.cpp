#include <string>
#include <vector>
#include <map>
#include <queue>

#define MAX_SIZE 50001
using namespace std;
priority_queue <int> q;
map <int, long long> m;
bool check[MAX_SIZE];
long long solution(int n, vector<int> works) {
    long long answer = 0;
    for(auto a : works){
        q.push(a);
        m[a]++;
        answer += a;
    }
    if(answer <= n){
        return 0;
    }
    while(true){
        int max = q.top();
        int r_cnt = m[max];
        printf("max : %d, cnt : %d \n", max, r_cnt);
        if(r_cnt <= n){
            n-=r_cnt;
            m[max]=0;
            m[max-1] += r_cnt;
            q.pop();
            if(q.top() != max-1){
                q.push(max-1);
            }
            if(!n) break;
        }
        else{
            int remain = r_cnt - n;
            m[max] -= n;
            m[max-1] += n;
            if(q.top() != max-1){
                q.push(max-1);
            }
            q.push(max);
            break;
        }
    }
    long long sum = 0;
    while(!q.empty()){
        long long index = q.top(); q.pop();
        if(check[index]) continue;
        check[index] = true;
        printf("index : %d, cnt : %d \n",index,  m[index]);
        sum += m[index] * index * index;
    }
    return sum;
}