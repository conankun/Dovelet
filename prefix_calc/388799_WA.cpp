#include<iostream>
#include<string.h>
#include<deque>
using namespace std;
char calc[10000];
struct A {
	char oper;
	int value;
};
deque<A> st;
int main() {
	scanf("%s",calc);
	int size = strlen(calc);
	int i;
	for(i=0;i<size;i++) {
		A a;
		a.oper = calc[i];
		a.value = -100; // oper
		if(calc[i] >= '0' && calc[i] <= '9') {
			a.value = calc[i]-'0';
		}
		st.push_back(a);
		while(1) {
		if(st.size() < 3) break;
		if(st[st.size()-1].value > -100 && st[st.size()-2].value > -100 && st[st.size()-3].value == -100) {
			switch(st[st.size()-3].oper) {
			case '+': {
						a.value = st[st.size()-1].value+st[st.size()-2].value;
						st.pop_back();
						st.pop_back();
						st.pop_back();
						st.push_back(a);
						break;
					  }
			case '-': {
						a.value = st[st.size()-2].value-st[st.size()-1].value;
						st.pop_back();
						st.pop_back();
						st.pop_back();
						st.push_back(a);
						break;
					  }
			case '*': {
						a.value = st[st.size()-1].value*st[st.size()-2].value;
						st.pop_back();
						st.pop_back();
						st.pop_back();
						st.push_back(a);
						break;
					  }
			case '/': {
						if(st[st.size()-1].value == 0) {
							cout<<"Divide by zero";
							return 0;
						}
						
						st.pop_back();
						st.pop_back();
						st.pop_back();
						a.value = st[st.size()-2].value/st[st.size()-1].value;
						st.push_back(a);
						break;
					  }
			}
		} else break;
		}
	}
	cout<<st.back().value;
}