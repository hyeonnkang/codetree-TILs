import java.util.*;

public class Main {
    static int n, m, q;
    static int[][] a;

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        m = sc.nextInt();
        q = sc.nextInt();
        a = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                a[i][j] = sc.nextInt();

        boolean[] visited ;
        for (int i = 0; i < q; i++) {
            int r = sc.nextInt();
            char d = sc.next().charAt(0);

            visited = new boolean[n];
            r--;

            // r행을 d방향으로 이동
            Queue<int[]> q = new ArrayDeque<>();
            q.add(new int[]{r, (int)d});
            visited[r] = true;
            while(!q.isEmpty()){
                int[] cur = q.poll();

                move(cur[0], (char)cur[1]);

                // r-1, r+1 확인
                for(int row : new int[]{cur[0]-1, cur[0]+1}){
                    if(row < 0 || row >= n) continue;
                    if(visited[row]) continue;

                    visited[row] = true;

                    if(isThereSame(cur[0], row)){
                        if((char)cur[1] == 'L') q.add(new int[]{row, (int)'R'});
                        else q.add(new int[]{row, (int)'L'});
                    }
                }
            }
            
        }

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                System.out.print(a[i][j] + " ");
            }System.out.println();
        }
    }

    static boolean isThereSame(int r1, int r2){
        for(int i = 0; i < m; i++){
            if(a[r1][i] == a[r2][i]) return true;
        }
        return false;
    }

    static void move(int row, char dir){
        if(dir == 'R'){
            int tmp = a[row][0];
            for(int i = 0; i < m-1; i++) a[row][i] = a[row][i+1];
            a[row][m-1] = tmp;
        }else{
            int tmp = a[row][m-1];
            for(int i = m-1; i > 0; i--) a[row][i] = a[row][i-1];
            a[row][0] = tmp;
        }
    }
}