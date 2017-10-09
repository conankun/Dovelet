import java.math.*;
import java.io.*;
public class Main {
	public static void main(String[] ar) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int s1 = Integer.parseInt(br.readLine());
		int i;
		BigInteger counts=new BigInteger("1");
		BigInteger now = new BigInteger("2");
		for(i=1;i<=s1;i++) {
			counts = counts.multiply(now);
		}
		System.out.println(counts);
	}
}