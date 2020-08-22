#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

#define ARGERR printf("ARG_GRESKA");
#define MEMERR printf("MEM_GRESKA");
#define DATERR printf("DAT_GRESKA");



typedef struct elem{
	
char firstname[30];
char lastname[30];
char displayname[30];
char nickname[30];
char primaryemail[30];
char secondaryemail[30];
char screenname[30];
char workphone[30];
char homephone[30];
char faxnumber[30];
char pagernumber[30];
char mobilenumber[30];
char homeadress[30];
char homeadress2[30];
char homecity[30];
char homestate[30];
char homezipcode[30];
char homecountry[30];
char workadress[30];
char workadress2[30];
char workcity[30];
char workstate[30];
char workzipcode[30];
char workcountry[30];
char jobtitle[30];
char department[30];
char organizaton[30];
char webpage1[30];
char webpage2[30];
char birthyear[30];
char birthmonth[30];
char birthday[30];
char notes[100];
struct elem *next, *prev;
	
}*Elem;

typedef struct{
	Elem prvi, poslednji;
}Lista;

Lista readFile(const char ime[]);
Elem readLine(FILE *fp);
void freeList(Lista lista);
void reverse(Lista *lista);
void writeVCF(const char ime[], Lista lista);

