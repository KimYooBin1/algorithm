class Solution {
    public long solution(int cap, int n, int[] deliveries, int[] pickups) {
        long answer = 0;
        int len = deliveries.length;
        int deliv = 0;
        int pick = 0;
        //끝에서 부터 접근해야됨
        for(int i=len - 1;0<=i;i--){
            deliv -= deliveries[i];
            pick -= pickups[i];
            if(deliv < 0 || pick < 0){
                int deliv_cnt = (-deliv - 1)/cap + 1;
                int pick_cnt = (-pick - 1)/cap + 1;
                int cnt = Math.max(deliv_cnt, pick_cnt);
                deliv += cap * cnt;
                pick += cap * cnt;
                answer += cnt * 2 * (i+1);
            }
        }
        return answer;
    }
}