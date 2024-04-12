class Solution {
    private int calc(int num, int cnt){
        if(num == 0) return cnt;
        if(num == 1) return cnt + 1;
        int remain = num % 10;
        return Math.min(calc(num/10, cnt+remain), calc(num/10 + 1, cnt+(10-remain)));
    }
    public int solution(int storey) {
        int answer = calc(storey, 0);
        
        return answer;
    }
}