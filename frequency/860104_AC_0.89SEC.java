import java.math.*;
import java.io.*;
public class Main {
	public static void main(String[] ar) throws Exception {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int s1 = Integer.parseInt(br.readLine());
		int i;
		BigInteger counts=new BigInteger("1");
		BigInteger now = new BigInteger("1");
		for(i=1;i<=s1;i++) {
			counts = counts.multiply(now);
			now=now.add(new BigInteger("1"));
		}
		int[] arr= new int[100];
		while(counts.compareTo(new BigInteger("0")) > 0) {
			arr[counts.remainder(new BigInteger("10")).intValue()]++;
			counts=counts.divide(new BigInteger("10"));
		}
		System.out.println(s1+"! --");
		for(i=0;i<10;i++) {
		System.out.printf("   (%d)  %3d ",i,arr[i]);
		if(i==4) System.out.println();
		}
	}
}