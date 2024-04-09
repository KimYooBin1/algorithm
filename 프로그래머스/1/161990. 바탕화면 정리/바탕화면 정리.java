class Solution {
    public int[] solution(String[] wallpaper) {
        int n = wallpaper.length;
        int m = wallpaper[0].length();
        int x1,x2,y1,y2;
        x1 = -1; x2 = -1; y1 = -1; y2 = -1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(wallpaper[i].charAt(j) != '#') continue;
                if(x1 == -1 || i<x1) x1 = i;
                if(x2 == -1 || x2<i) x2 = i;
                if(y1 == -1 || j<y1) y1 = j;
                if(y2 == -1 || y2<j) y2 = j;
                
            }
        }
        int[] answer = {x1,y1,x2+1,y2+1};
        return answer;
    }
}