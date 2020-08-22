#include <stdio.h>
#include <stdlib.h>

#define MAX 100000
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	int n,i;
	int koordinate[MAX], gold[MAX], energija[MAX];
	scanf("%d", &n);
	
	for(i = 0; i<n; i++){
		scanf("%d %d %d", &koordinate[i], &gold[i], &energija[i]);
		//totalGoldSleva[i] = (i==0)?gold[i]
	}
	int startIndex = 0;
	unsigned long maxGold = 0;
	unsigned long trGold = 0;
	long long totalEnergija = 0;
	int lastPositive = 0;
	unsigned long lastGold=0;
	unsigned long lastEnergy=0;
	i = 0;
	while(lastPositive!=n-1){
		
		for(i=lastPositive; i<n;i++){
			if(totalEnergija > 0){
				lastPositive  = i;
			}
			totalEnergija = (i==0)? totalEnergija + energija[i] : totalEnergija + energija[i] - (koordinate[i]-koordinate[i-1]);
		}
	}
	
	for(i = lastPositive; i<n; i++){
		totalEnergija += energija[i];
		
		if(koordinate[i] - koordinate[startIndex] <= totalEnergija){
			trGold +=gold[i];
		}else{
			if(trGold>maxGold){
				maxGold = trGold;
			}
			
			totalEnergija -=energija[startIndex];
			trGold -= gold[startIndex];
			startIndex+=1;
			while(koordinate[i] - koordinate[startIndex] > totalEnergija){
				totalEnergija -=energija[startIndex];
				trGold -= gold[startIndex];
				startIndex+=1;
			}
			trGold +=gold[i];
		}
	}
	if(trGold>maxGold){
		maxGold = trGold;
	}
	
	printf("%lu",maxGold);		
	return 0;
}
