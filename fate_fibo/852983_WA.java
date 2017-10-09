import java.math.*;
import java.io.*;
public class Main {
	public static void main(String[] ar) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int s = Integer.parseInt(br.readLine());
		BigInteger n = new BigInteger("1");
		for(int i=1;i<=s;i++) n=n.multiply(new BigInteger("10"));
		BigInteger one = new BigInteger("1");
		BigInteger two = new BigInteger("2");
		int counts=0;
		for(int i=1;i<=10000;i++) {
			BigInteger tmp = one.add(two);
			one=two;
			two=tmp;
			if(two.compareTo(n)>0) {
				counts=i;
				break;
			}
		}
if(s==0) System.out.println("0");
		System.out.println(counts);
	}
}