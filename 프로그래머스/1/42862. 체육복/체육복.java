import java.util.*;

class Solution {
    public boolean contain(int n, int[] reserve){
        for(int i=0;i<reserve.length;i++){
            if(reserve[i] == n) return true;
        }
        return false;
    }
    public int solution(int n, int[] lost, int[] reserve) {
        int answer = 0;
        boolean check[] = new boolean[n+1];
        Arrays.fill(check, false);
        int cnt = 0;
        Arrays.sort(lost);
        Arrays.sort(reserve);
        for(int i=0;i<lost.length;i++){
            if(contain(lost[i], reserve)){
                check[lost[i]] = true;
                cnt++;
                lost[i] = -1;
            }
            
        }
        for(int i=0;i<lost.length;i++){
            if(lost[i] == -1) continue;
            int px = lost[i] - 1;
            if(0<px){
                //앞자리가 여분있을때
                if(contain(px, reserve) && check[px] == false){
                    check[px] = true;
                    cnt++;
                    continue;
                }
            }


            int nx = lost[i] + 1;
            if(nx<=n){
                //뒷자리가 여분있을때
                if(contain(nx, reserve) && check[nx] == false){
                    check[nx] = true;
                    cnt++;
                }
            }
            
        }
        return n-lost.length+cnt;
    }
}