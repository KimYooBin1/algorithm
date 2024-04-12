class Solution {
    public int solution(int x, int y, int n) {
        int dist[] = new int [y+1];
        for(int i=x;i<=y;i++){
            dist[i] = -1;
        }
        dist[x] = 0;
        for(int i=x;i<=y;i++){
            if(dist[i] == -1) continue;
            if(i+n<=y){
                if(dist[i+n] == -1 || dist[i] + 1 < dist[i+n]){
                    dist[i+n] = dist[i] + 1;
                }
            }
            if(i*2<=y){
                if(dist[i*2] == -1 || dist[i] + 1 < dist[i*2]){
                    dist[i*2] = dist[i] + 1;
                }
            }
            if(i*3<=y){
                if(dist[i*3] == -1 || dist[i] + 1 < dist[i*3]){
                    dist[i*3] = dist[i] + 1;
                }
            }
            
        }
        return dist[y];
    }
}