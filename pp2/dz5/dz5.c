#include "dz5.h"


int main(int argc, char *argv[]){
	if(argc<3 ||argc>4){
		ARGERR
		return 0;
	}else{
		unsigned int flag = 1 ? argc==4 : 0;
		if(flag){
			if(!strcmp(argv[3],"-reverse\n")){
				ARGERR
				
			}
		}
		Lista lista;
		lista = readFile(argv[1]);
		if(flag){
			reverse(&lista);
		}
		writeVCF(argv[2],lista);
		freeList(lista);
	}
	return 0;
}
