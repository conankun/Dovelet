import java.util.*;
import java.math.*;
public class Main {

    public static void main(String[] args) {
        int n;
        int[][] arr = new int[111][111];
        BigInteger[][] dp = new BigInteger[111][111];
        Scanner sc = new Scanner(System.in);
        n=sc.nextInt();
        int i,j;
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                arr[i][j] = sc.nextInt();
                dp[i][j] = new BigInteger("0");
            }
        }
        dp[1][1]=dp[1][1].add(BigInteger.ONE);
        for(i=1;i<=n;i++) {
            for(j=1;j<=n;j++) {
                if(arr[i][j]==0) continue;
                if(i+arr[i][j] <= n) dp[i+arr[i][j]][j]=dp[i+arr[i][j]][j].add(dp[i][j]);
                if(j+arr[i][j] <= n) dp[i][j+arr[i][j]]=dp[i][j+arr[i][j]].add(dp[i][j]);
            }

        }
        System.out.print(dp[n][n]);
    }
}
