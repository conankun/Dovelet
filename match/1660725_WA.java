import java.util.*;

class AA {
	int pos;
	char c;
}
class BB {
	int first,second;
}
public class Main{

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String ss = sc.next();
		AA[] stack = new AA[1000];
		int top = 0;
		BB[] pos = new BB[1000];
		int pos2 = 0;

		int len = ss.length();
		int i;
		for(i=0;i<len;i++) {
			AA a = new AA();
			a.c = ss.charAt(i);
			a.pos = i;
			if(ss.charAt(i) == '(') {
				stack[++top] = a;
			} else if(ss.charAt(i) == ')') {
				BB bbb = new BB();
				bbb.first = stack[top].pos;
				bbb.second = i;
				top--;
				pos[++pos2]=bbb;
			}
		}
	
		if(top == 0) {
			for(i=1;i<=pos2;i++) {
				System.out.printf("%d %d\n",pos[i].first,pos[i].second);
			}
		} else {
			System.out.print("Not match");
		}
	}
}