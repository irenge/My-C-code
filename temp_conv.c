#include<stdio.h>
int temp_conv(int n);
main(){
	int i,z;
	for(i=0;i<=15;i++){
	z=20*i;
	printf("%d %d\n", z,temp_conv(z));
	}
}
int temp_conv(int n){
	int x;
	x = 5*(n-32) / 9;
	return x;
}
