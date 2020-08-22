#include <stdio.h>
#define MIN1 -2147483648

int maxx(int a, int b){
	if(a>b){
		return a;
	}else{
		return b;
	}
}
int abs(int a){
	if(a>0){
		return a;
	}else{
		return -a;
	}
}
int main(){
    int n,i,j,k;
    scanf("%d",&n);
    int arr[n];
    for(i=0;i<n;i++) scanf("%d",&arr[i]);
    int lis[n];
    for(i = 0; i<n; i++) lis[i] = 1;
    for(i = 1; i < n; i++){
        int sign;
        if(arr[i] > 0)
            sign = 1;
        else
            sign = -1;
        for(j = 0;j < i; j++){
            int sign2;
            if(arr[j] < 0)
                sign2 = -1;
            else
                sign2 = 1;
            if(abs(arr[j]) < abs(arr[i]) && sign2*sign == -1){
                
				k = maxx(lis[i], (1+lis[j]));
				lis[i] = k;
            } 
        }
    }
    int maxxx = MIN1;
    for(i = 0;i < n; i++){
        maxxx = maxx(maxxx, lis[i]);
    }
    printf("%d", maxxx);
    return 0;
}
