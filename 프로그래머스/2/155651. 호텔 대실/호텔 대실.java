import java.util.*;

class Solution {
    
    static class Reg{
        private int start;
        private int end;
        public Reg(int start, int end){
            this.start = start;
            this.end = end;
        }
    }
    
    static private int calc(String str){
        String time[] = str.split(":");
        return Integer.parseInt(time[0])*60 + Integer.parseInt(time[1]);
    }
    
    public int solution(String[][] book_time) {
        int answer = 0;
        int[][] bookTime = new int[book_time.length][2];
        for(int i=0;i<book_time.length;i++){
            bookTime[i][0] = calc(book_time[i][0]);
            bookTime[i][1] = calc(book_time[i][1]) + 10;
        }
        Arrays.sort(bookTime, (o1, o2) -> o1[0] - o2[0]);
        PriorityQueue<Reg> list = new PriorityQueue<>(
            (o1, o2) -> o1.end - o2.end
        );
        for(int i=0;i<book_time.length;i++){
            int from = bookTime[i][0];
            int to = bookTime[i][1];
            System.out.println(from);
            System.out.println(to);
            
            if(list.isEmpty()){
                list.add(new Reg(from, to));    
            }
            else{
                Reg tmp = list.peek();
                System.out.println(tmp.end+".");
                if(tmp.end <= from){
                    list.remove();
                }
                list.add(new Reg(from, to));
            }
        }
        return list.size();
    }
}