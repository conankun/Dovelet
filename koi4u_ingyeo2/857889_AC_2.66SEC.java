import java.io.*;
import java.math.*;
public class Main {
	public static void main(String[] ar) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int xx=0;
		int[] ar1=new int[100];
		xx=Integer.parseInt(br.readLine());
		BigInteger bi=new BigInteger("0");
		int i,j;
		for(i=1;i<=xx;i++) {
			BigInteger tmp = new BigInteger("1");
			for(j=1;j<=i;j++) {
				tmp=tmp.multiply(new BigInteger(Integer.toString(i)));
			}
			bi=bi.add(tmp);
		}
		for(;;) {
			if(bi.equals(new BigInteger("0"))) {
				break;
			}
			BigInteger bs=bi.remainder(new BigInteger("10"));
			ar1[bs.intValue()]++;
			bi=bi.divide(new BigInteger("10"));
		}
		for(i=0;i<10;i++) System.out.print(ar1[i]+" ");
	}
}
