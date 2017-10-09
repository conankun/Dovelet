import java.math.BigInteger;
import java.util.*;
class Main {
public static void main(String[] args) {
	Scanner sc = new Scanner(System.in);
	BigInteger s = new BigInteger(sc.next());
	int[] ar = new int[100];
	int ind=0;;
	while(!s.equals(new BigInteger("0"))) {
		ar[++ind]=Integer.parseInt(s.remainder(new BigInteger("2")).toString());
		s = s.divide(new BigInteger("2"));
	}
	for(int i=ind;i>=1;i--) System.out.print(ar[i]);
}
}