import java.util.*;

public class Main {
    static int n, m;
    static int[] bombs;
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        bombs = new int[n];
        for (int i = 0; i < n; i++) {
            bombs[i] = sc.nextInt();
        }
        // Please write your code here.
        boolean boom = false; // 폭발 여부
        int[] temp = new int[n];
        while(true){
            boom = false;

            for(int i = 0; i < n; i++){
                if(bombs[i] == 0) continue;
                // 숫자가 m개 이상 연속되는 경우?
                int j = getEndIndex(i);

                if(j-i >= m){
                    // 0으로 바꾼다.
                    changeZero(i, j);
                    boom = true;
                }
            }

            // temp에 0을 제외한 숫자들을 저장
            Arrays.fill(temp, 0);
            int ti = 0;
            for(int i = 0; i < n; i++){
                if(bombs[i] == 0) continue;
                temp[ti++] = bombs[i];
            }

            // bombs에 temp 내용을 저장
            copyToBombs(temp);

            if(!boom) break; // 더 이상 폭발 안할 때 탈출
        }

        // 남은 폭탄의 개수 출력
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(bombs[i] == 0) continue;
            cnt++;
        }
        System.out.println(cnt);

        // 남은 폭탄의 숫자 출력
        for(int i = 0; i < cnt; i++){
            System.out.println(bombs[i]);
        }
    }

    static void copyToBombs(int[] temp){
        for(int i = 0; i < n; i++){
            bombs[i] = temp[i];
        }
    }

    static void changeZero(int start, int end){
        for(int i = start; i < end; i++){
            bombs[i] = 0;
        }
    }
     

    static int getEndIndex(int index){
        int end = index + 1;
        for(; end < n; end++){
            if(bombs[end] != bombs[index]) return end;
        }
        return end;
    }

}