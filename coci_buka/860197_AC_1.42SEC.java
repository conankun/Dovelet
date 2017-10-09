import java.math.*;
import java.io.*;
public class Main {
	public static void main(String[] ar) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BigInteger s1 = new BigInteger(br.readLine());
		String s2 = br.readLine();
		BigInteger s3 = new BigInteger(br.readLine());
		if(s2.equals("+")) {
			System.out.println(s1.add(s3));
		} else {
			System.out.println(s1.multiply(s3));
		}
	}
}