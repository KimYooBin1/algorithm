class Solution {
    public int solution(int n, int m, int[] section) {
        int position = 1;
        int answer = 0;
        for(int i=0;i<section.length;i++){
            if(position <= section[i]){
                answer+=1;
                position = section[i] + m;
            }
        }
        
        return answer;
    }
}