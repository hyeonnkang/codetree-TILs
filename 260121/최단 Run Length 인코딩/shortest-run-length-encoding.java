import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String A = sc.next();
        // Please write your code here.
        char[] c = A.toCharArray();
        int n = A.length();

        int answer = Integer.MAX_VALUE;
        for(int shift = 0; shift < n; shift++){
            // 인코딩 길이 구하기
            StringBuilder sb = new StringBuilder();
            char pre = c[0];
            int cnt = 1;
            for(int i = 1; i < n; i++){
                if(c[i] != pre){
                    sb.append(pre).append(cnt);
                    pre = c[i];
                    cnt = 1;
                }else cnt++;
            }
            String encoding = sb.append(pre).append(cnt).toString();
            answer = Math.min(answer, encoding.length());

            // 오른쪽으로 한칸 쉬프트
            char temp = c[n-1];
            for(int i = n-1; i > 0; i--) c[i] = c[i-1];
            c[0] = temp;
        }
        System.out.println(answer);
    }
}