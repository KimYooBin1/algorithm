class Solution {
    public int solution(String s) {
        char target = 'A';
        int cnt1 = 0;
        int cnt2 = 0;
        int answer = 0;
        for(int i=0;i<s.length();i++){
            if(target == 'A'){
                target = s.charAt(i);
                cnt1 = 1;
                continue;
            }
            if(s.charAt(i) == target){
                cnt1++;
            }
            else{
                cnt2++;
            }
            if(cnt1 == cnt2){
                target = 'A';
                cnt1 = 0;
                cnt2 = 0;
                answer+=1;
            }
        }
        if(target != 'A') answer++;
        return answer;
    }
}