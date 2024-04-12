class Solution {
    static int amount;
    static int[] dc = {10, 20, 30, 40};
    static int[][] userList;
    static int[] discounts = new int[7];
    static int result_cnt = -1;
    static int result_price = -1;
    static void calcResult(int index, int[] emoticons){
        //할인률을 정해서 계산시작
        if(index == amount){
            int tmp_cnt = 0;
            int tmp_price = 0;
            for(int i=0;i<userList.length;i++){
                int wishDc = userList[i][0];
                int limit = userList[i][1];
                int sum = 0;
                for(int j=0;j<amount;j++){
                    if(discounts[j] < wishDc) continue;
                    sum += emoticons[j] / 100 * (100-discounts[j]); 
                }
                // System.out.println("user : " + i + " , sum : "+ sum);
                //플러스 구매
                if(limit<=sum){
                    tmp_cnt++;
                }
                //쌩돈 구매
                else{
                    tmp_price += sum;
                }
            }
            // System.out.println(tmp_cnt+" "+tmp_price);
            if(result_cnt < tmp_cnt){
                result_cnt = tmp_cnt;
                result_price = tmp_price;    
            }
            else if(result_cnt == tmp_cnt){
                if(result_price<tmp_price){
                    result_cnt = tmp_cnt;
                    result_price = tmp_price;    
                    
                }
            }
            return;
        }
        for(int i=0;i<4;i++){
            discounts[index] = dc[i];
            calcResult(index+1, emoticons);
        }
    }
    
    public int[] solution(int[][] users, int[] emoticons) {
        amount = emoticons.length;
        userList = users;
        calcResult(0, emoticons);
        int[] answer = {result_cnt, result_price};
        return answer;
    }
}