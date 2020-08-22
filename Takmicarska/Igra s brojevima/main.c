#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//min pa max


int main() {
	char *string = NULL;
	int t;
	int k;
	int n,prvi,poslednji, i;
	scanf("%d",&t);
	while(t--){
		fflush(stdin);
		scanf("%d",&n);
		scanf("%d",&k);
		string = malloc(sizeof(char)*(n+1));
		
		prvi = 0;
		poslednji = n-1; 
		fflush(stdin);
		fgets(string,n + 1 , stdin);
		
		while(n!=k){
			i = prvi;
			while((string[i]!='1') && i!=poslednji)i++;
			string[i]='2';
			n--;
			i = prvi;
			
			if(n!=k){
				while(string[i]=='2')i++;
				prvi = i;
				if(string[i]=='0'){
					string[i]='2';
				}else{
					i = poslednji;
					while(string[i]=='2'&&i!=prvi)i--;
					poslednji = i;
					while(string[i]!='0' && i!=prvi)i--;
					string[i]='2';
					
				}
				n--;
			}else{
				break;
			}			
		}
		
		for(i = prvi; i<=poslednji;i++){
			if(string[i]!='2'){
				putchar(string[i]);
			}
		}
		putchar('\n');
		free(string);
		
	}
	return 0;
}

#include<stdio.h>
int main()
{
 int test;
 scanf("%d",&test);
 while(test--)
 {
  int n,k,i;
  scanf("%d%d",&n,&k);
  char str[10000];
  scanf("%s",str);
  int o[n],z[n];
  int l=0,m=0;
  for(i=0;i<n;i++)
  if(str[i]==48)
   z[l++]=i;
  else
   o[m++]=i; 
  int t=n;
  int a=0,j=0;
  int sharry=1,digo=0;
  if(n<=k)
  {
  printf("%s\n",str);
  continue;
  }
  while(1)
  {
   if(sharry)
   {
    if(a<m)
     str[o[a++]]=50;
    else
     str[z[j++]]=50;
     
    sharry=0;
    digo=1;

    t--;
   }
   else if(digo)
   {
    if(j<l)
     str[z[j++]]=50;
    else
     str[o[a++]]=50;
    sharry=1;
    digo=0;
   
    t--;
   }
   if(t==k)
   break;
  }
  for(i=0;i<n;i++)
  if(str[i]!=50)
  printf("%c",str[i]);
  printf("\n");
 }
 return 0;
}


