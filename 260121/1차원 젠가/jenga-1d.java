import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] blocks = new int[n];
        for (int i = 0; i < n; i++) {
            blocks[i] = sc.nextInt();
        }
        int s1 = sc.nextInt();
        int e1 = sc.nextInt();
        int s2 = sc.nextInt();
        int e2 = sc.nextInt();
        // Please write your code here.
        s1--;
        e1--;
        s2--;
        e2--;

        int[] temp = new int[n];
        int tidx = 0;
        for(int i = 0; i < n; i++){
            if(i >= s1 && i <= e1) continue;
            temp[tidx++] = blocks[i];
        }
        // 옮기기
        for(int i = 0; i < n; i++) blocks[i] = temp[i];

        temp = new int[n];
        tidx = 0;
        for(int i = 0; i < n; i++){
            if(i >= s2 && i <= e2) continue;
            temp[tidx++] = blocks[i];
        }
        // 옮기기
        for(int i = 0; i < n; i++) blocks[i] = temp[i];

        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(blocks[i] > 0) cnt++;
        }

        System.out.println(cnt);
        for(int i = 0; i < n; i++){
            if(blocks[i] > 0)
                System.out.println(blocks[i]);
        }
    }
}