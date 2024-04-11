class Solution {
    public int solution(String t, String p) {
        int len = p.length();
        int answer = 0;        
        long target = Long.parseLong(p);
        for(int i=0;i<t.length()-len+1;i++){
            Long num = Long.parseLong(t.substring(i, i+len));
            System.out.println(num);
            if(num<=target) answer++;
        }
        return answer;
    }
}