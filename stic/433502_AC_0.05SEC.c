int log(n,i) {
	for(;n>1;){
		n/=2;
		i++;
	}
	return i;
}
main(i){for(i=1;i<=200000;i++) printf("%d\n",log(i,0));}