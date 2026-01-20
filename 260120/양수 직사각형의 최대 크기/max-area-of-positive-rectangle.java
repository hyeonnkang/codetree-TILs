import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[][] grid = new int[n][m];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                grid[i][j] = sc.nextInt();

        // Please write your code here.
        int answer = -1;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                
                for(int h = 0; i+h < n; h++){
                    for(int w = 0; j+w < m; w++){
                        
                        boolean isok = true;
                        for(int row = i; row <= i+h && isok; row++){
                            for(int col = j; col <= j+w; col++){
                                if(grid[row][col] <= 0){
                                    isok = false;
                                    break;
                                }
                            }
                        }
                        if(isok) answer = Math.max(answer, (h+1)*(w+1));
                    }
                }
            }
        }
        System.out.println(answer);
    }
}