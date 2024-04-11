class Solution {
    static private int cnt1;
    static private int cnt2;
    static private String[] map;
    
    static private int check_row(char target){
        int result = 0;
        for(int index = 0;index<3;index++){
            if(map[index].charAt(0) == target && target == map[index].charAt(1) && target == map[index].charAt(2)) result++;
            if(map[0].charAt(index) == target && target == map[1].charAt(index) && target == map[2].charAt(index)) result++;    
        }
        return result;
    }
    static private int check_cross(char target){
        int result = 0;
        if(map[0].charAt(0) == target && target == map[1].charAt(1) && target == map[2].charAt(2)) result++;
        if(map[2].charAt(0) == target && target == map[1].charAt(1) && target == map[0].charAt(2)) result++;
        return result;
    }
    
    static private boolean check(){
        int val1 = check_row('O');
        int val2 = check_cross('O');
        int val3 = check_row('X');
        int val4 = check_cross('X');
        
        if(val1 + val2>0 && val3 + val4>0) return false;
        
        if(val1+val2>0){
            if(cnt1 == cnt2) return false;
            return true;
        }
        if(val3+val4>0){
            if(cnt1==cnt2+1) return false;
            return true;
        }
        return true;
    }
    public int solution(String[] board) {
        map = board;
        int answer = -1;
        cnt1 = 0;
        cnt2 = 0;
        for(int i=0;i<board.length;i++){
            for(int j=0;j<board[i].length();j++){
                if(board[i].charAt(j) == 'O'){
                    cnt1++;
                }
                if(board[i].charAt(j) == 'X'){
                    cnt2++;
                }
            }
        }
        if(cnt1<cnt2) return 0;
        if(cnt1-cnt2 != 0 && cnt1-cnt2 != 1) return 0;
        if(check()) return 1;
        return 0;
        
    }
}