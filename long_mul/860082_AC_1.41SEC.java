import java.math.*;
import java.io.*;
public class Main {
	public static void main(String[] ar) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String s1 = br.readLine();
		String s2= br.readLine();
		BigInteger br1 = new BigInteger(s1);
		BigInteger br2 = new BigInteger(s2);
		System.out.println(br1.multiply(br2));
	}
}