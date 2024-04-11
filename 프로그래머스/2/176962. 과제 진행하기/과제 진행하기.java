import java.util.*;

class Solution {
    
    
    static class P{
        private String name;
        private int time;
        private int start;
        public P(String name,int start, int time){
            this.name = name;
            this.start = start;
            this.time = time;
        }
        public P(String name, int time){
            this.name = name;
            this.time = time;
        }
        
    }
    
    
    public List<String> solution(String[][] plans) {
        List<String> answer = new ArrayList<>();
        
        PriorityQueue<P> q = new PriorityQueue<>(
            (o1, o2) -> (o1.start - o2.start)
        );
        
        for(int i=0;i<plans.length;i++){
            String name = plans[i][0];
            int playTime=Integer.parseInt(plans[i][2]);
            String[] str = plans[i][1].split(":");
            int h = Integer.parseInt(str[0]);
            int m = Integer.parseInt(str[1]);
            int time = h*60 + m;
            q.add(new P(name, time, playTime));
        }
        Stack<P> s = new Stack<>();
        while(!q.isEmpty()){
            P task = q.peek(); 
            q.remove();
            String curName = task.name;
            int curStart = task.start;
            int curPlayTime = task.time;
            
            int curTime = curStart;
            //다음 일이 있을때
            if(!q.isEmpty()){
                P nextTask = q.peek();
                //다음 일보다 빨리 끝날때
                if(curTime + curPlayTime < nextTask.start){
                    answer.add(curName);
                    curTime += curPlayTime;
                    while(!s.isEmpty()){
                        P remainTask = s.pop();
                        if(curTime + remainTask.time <= nextTask.start){
                            answer.add(remainTask.name);
                            curTime += remainTask.time;
                        }
                        else{
                            int t = nextTask.start - curTime;
                            s.push(new P(remainTask.name, remainTask.time - t));
                            break;
                        }
                    }
                }
                //끝나고 바로 다음일 시작
                else if(curTime + curPlayTime == nextTask.start){
                    answer.add(curName);
                }
                //끝나지 못함
                else{
                    int t = nextTask.start - curTime;
                    s.push(new P(curName, curPlayTime - t));
                }
            }
            //다음 일이 없을때
            else{
                //멈춰둔 일이 남아있을떄
                if(!s.isEmpty()){
                    answer.add(curName);
                    while(!s.isEmpty()){
                        P rem = s.pop();
                        answer.add(rem.name);
                    }
                }
                //멈춰둔 일도 없을때
                else{
                    answer.add(curName);
                }
            }
        }
        return answer;
    }
}