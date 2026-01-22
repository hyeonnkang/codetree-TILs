import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] bombs = new int[n];
        for (int i = 0; i < n; i++) {
            bombs[i] = sc.nextInt();
        }

        int[] temp = new int[n];
        // Please write your code here.
        while(true){
            boolean flag = false; // 폭탄이 터질 지 여부
            int left = 0;
            int right = 1;
            while(left <= right && right < n){

                if(bombs[left] == bombs[right]){ // 같을때
                    right++;
                }else{ // 다를때
                    int cnt = right - left;
                    if(cnt >= m){
                        for(int i = left; i < right; i++) bombs[i] = 0;
                        flag = true;
                        left = right;
                        right++;
                    }else{
                        left++;
                        right++;
                    }
                }
            }
            

            Arrays.fill(temp, 0);
            int ti = 0;
            for(int i = 0; i < n; i++){
                if(bombs[i] == 0) continue;
                temp[ti++] = bombs[i];
            }
            for(int i = 0; i < n; i++){
                bombs[i] = temp[i];
            }

            // 폭탄 터질게 없으면 탈출하기
            if(!flag) break;
        }

        int cnt = 0;
        for(int i = 0; i < n; i++) if(bombs[i] > 0) cnt++;
        System.out.println(cnt);
        for(int i = 0; i < cnt; i++){
            if(bombs[i] == 0) break;
            System.out.println(bombs[i]);
        }
    }
}