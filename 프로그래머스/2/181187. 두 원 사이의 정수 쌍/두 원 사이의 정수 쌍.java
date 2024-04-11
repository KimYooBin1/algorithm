import java.util.*;

class Solution {
    public long solution(int r1, int r2) {
        long answer = 0;
        long repli = r2-r1+1;
        for(int i=0;i<=r2;i++){
            double powr1 = Math.pow(r1, 2);
            if(r1<i) powr1 = 0;
            double y1 = 0;
            if(powr1!=0){
                double powx1 = Math.pow(i, 2);
                y1 = Math.sqrt(powr1 - powx1);    
                y1 = Math.ceil(y1);
            }
            
            double powr2 = Math.pow(r2, 2);
            double powx2 = Math.pow(i, 2);
            double y2 = Math.sqrt(powr2-powx2);
            y2 = Math.floor(y2);
            // System.out.println(y1+" "+y2);
            long sum = (int)y2-(int)y1+1;
            
            answer += sum;
            
            
        }
        return answer * 4 - repli*4;
    }
}