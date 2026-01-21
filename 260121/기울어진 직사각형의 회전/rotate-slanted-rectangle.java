import java.util.Scanner;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] grid = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                grid[i][j] = sc.nextInt();
        int r = sc.nextInt();
        int c = sc.nextInt();
        int m1 = sc.nextInt();
        int m2 = sc.nextInt();
        int m3 = sc.nextInt();
        int m4 = sc.nextInt();
        int dir = sc.nextInt(); // 0이면 반시계, 1이면 시계방향
        // Please write your code here.

        int[] dr = {-1, -1, 1, 1};
        int[] dc = {1, -1, -1, 1};

        r--;
        c--;

        if(dir == 0){
            // 반시계 회전
            int temp1 = grid[r+m1*dr[0]][c+m1*dc[0]];
            for(int i = m1; i > 0; i--){
                grid[r+i*dr[0]][c+i*dc[0]] = grid[r+(i-1)*dr[0]][c+(i-1)*dc[0]];
            }
            int temp2 = grid[r+m1*dr[0]+m2*dr[1]][c+m1*dc[0]+m2*dc[1]];
            for(int i = m2; i > 0; i--){
                grid[r+i*dr[1]+m1*dr[0]][c+i*dc[1]+m1*dc[0]] = grid[r+(i-1)*dr[1]+m1*dr[0]][c+(i-1)*dc[1]+m1*dc[0]];
            }
            grid[r+m1*dr[0]+dr[1]][c+m1*dc[0]+dc[1]] = temp1;
            temp1 = grid[r+m1*dr[0]+m2*dr[1]+m3*dr[2]][c+m1*dc[0]+m2*dc[1]+m3*dc[2]];
            for(int i = m3; i > 0; i--){
                grid[r+m1*dr[0]+m2*dr[1]+i*dr[2]][c+m1*dc[0]+m2*dc[1]+i*dc[2]]
                = grid[r+m1*dr[0]+m2*dr[1]+(i-1)*dr[2]][c+m1*dc[0]+m2*dc[1]+(i-1)*dc[2]];
            }
            grid[r+m1*dr[0]+m2*dr[1]+dr[2]][c+m1*dc[0]+m2*dc[1]+dc[2]] = temp2;
            temp2 = grid[r+m1*dr[0]+m2*dr[1]+m3*dr[2]+m4*dr[3]][c+m1*dc[0]+m2*dc[1]+m3*dc[2]+m4*dc[3]];
            for(int i = m4; i > 0; i--){
                grid[r+m1*dr[0]+m2*dr[1]+m3*dr[2]+i*dr[3]][c+m1*dc[0]+m2*dc[1]+m3*dc[2]+i*dc[3]]
                = grid[r+m1*dr[0]+m2*dr[1]+m3*dr[2]+(i-1)*dr[3]][c+m1*dc[0]+m2*dc[1]+m3*dc[2]+(i-1)*dc[3]];
            }
            grid[r+m1*dr[0]+m2*dr[1]+m3*dr[2]+dr[3]][c+m1*dc[0]+m2*dc[1]+m3*dc[2]+dc[3]] = temp1;
            grid[r+dr[0]][c+dc[0]] = temp2;
        }else{
            // 시계 회전
            int temp1 = grid[r+m1*dr[0]+m2*dr[1]+m3*dr[2]+dr[3]][c+m1*dc[0]+m2*dc[1]+m3*dc[2]+dr[3]];
            int temp2 = grid[r][c];
            for(int i = 0; i < m1; i++){
                grid[r+i*dr[0]][c+i*dc[0]] = grid[r+(i+1)*dr[0]][c+(i+1)*dc[0]];
            }

            grid[r+m1*dr[0]][c+m1*dc[0]] = grid[r+m1*dr[0]+dr[1]][c+m1*dc[0]+dc[1]];
            for(int i = 0; i < m2; i++){
                grid[r+i*dr[1]+m1*dr[0]][c+i*dc[1]+m1*dc[0]] = grid[r+(i+1)*dr[1]+m1*dr[0]][c+(i+1)*dc[1]+m1*dc[0]];
            }
            grid[r+m1*dr[0]+m2*dr[1]][c+m1*dc[0]+m2*dc[1]] = grid[r+m1*dr[0]+m2*dr[1]+dr[2]][c+m1*dc[0]+m2*dc[1]+dc[2]];
            
            for(int i = 0; i < m3; i++){
                grid[r+m1*dr[0]+m2*dr[1]+i*dr[2]][c+m1*dc[0]+m2*dc[1]+i*dc[2]]
                = grid[r+m1*dr[0]+m2*dr[1]+(i+1)*dr[2]][c+m1*dc[0]+m2*dc[1]+(i+1)*dc[2]];
            }
            grid[r+m1*dr[0]+m2*dr[1]+m3*dr[2]][c+m1*dc[0]+m2*dc[1]+m3*dc[2]]= temp1;

            for(int i = 1; i < m4; i++){
                grid[r+m1*dr[0]+m2*dr[1]+m3*dr[2]+i*dr[3]][c+m1*dc[0]+m2*dc[1]+m3*dc[2]+i*dc[3]]
                = grid[r+m1*dr[0]+m2*dr[1]+m3*dr[2]+(i+1)*dr[3]][c+m1*dc[0]+m2*dc[1]+m3*dc[2]+(i+1)*dc[3]];
            }
            if(m4 > 1){
                grid[r+m1*dr[0]+m2*dr[1]+m3*dr[2]+(m4-1)*dr[3]][c+m1*dc[0]+m2*dc[1]+m3*dc[2]+(m4-1)*dc[3]]
                = temp2;
            }
        }
        
        

        // 출력
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                System.out.print(grid[i][j] + " ");
            }System.out.println();
        }
    }
}