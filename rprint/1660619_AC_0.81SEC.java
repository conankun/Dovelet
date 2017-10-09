import java.util.*;

public class Main {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		/*int x = sc.nextInt(); // Int
		float y = sc.nextFloat();
		double yy = sc.nextDouble(); */
//		String c = sc.next(); // String
		/*
		 * C version
		 * char c[100];
		 * scanf("%s",c);
		 * for(int i=0;i<strlen(c);i++) {
		 * 	c[i]
		 * }
		 */
	/*	int len = c.length();
		for(int i=0;i<len;i++) {
			c.charAt(i);
			
		}
		
		/*
		 * C
		 * 
		 * int array[100]; //선언
		   자료형 이름[사이즈];
		 * array[i]; //참조
		 * 
		 */
	/*	int n=100;
		int[] arr = new int[n];*/
		int n = sc.nextInt();
		int[] arr = new int[n];
		for (int i=0; i<n; i++){
			arr[i]= sc.nextInt();
		}
		for (int i=n-1; i>=0; i--){
			System.out.print(arr[i]+" ");
		}
	}

}
