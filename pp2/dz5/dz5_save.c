#include "dz5.h"
#define M printf("marker\n");
#define SC fprintf(fp,";");
#define PRT(X) if((X[0]))fprintf(fp,"%s",(X));
#define NL fprintf(fp,"\n");

void writeContact(FILE *fp, Elem cur){
	//beginvcard
	fprintf(fp,"begin:vcard\n");
	fprintf(fp,"fn:%s\n",cur->displayname);
	fprintf(fp,"n:%s;%s\n",cur->lastname,cur->firstname);
	if(cur->organizaton[0]||cur->department[0]){
		fprintf(fp,"org:%s",cur->organizaton);
		if(cur->department[0]){
			fprintf(fp,";%s",cur->department);
		}
		fprintf(fp,"\n");
	}
	if(cur->workadress[0]||cur->workcity[0]||cur->workcountry[0]||cur->workstate[0]||cur->workzipcode[0]){
		fprintf(fp,"adr:");
		PRT(cur->workadress2)
		SC
		SC
		if(cur->workadress)fprintf(fp,"%s",cur->workadress);
		SC
		PRT(cur->workcity)
		SC
		PRT(cur->workstate)
		SC
		PRT(cur->workzipcode)
		if(cur->workcountry[0])SC
		PRT(cur->workcountry)
		NL
		
		
	}
//		if(cur->homeadress[0]||cur->homecity[0]||cur->homecountry[0]||cur->homestate[0]||cur->homezipcode[0]){
//		fprintf(fp,"adr;work:;;");
//		if(cur->homeadress)fprintf(fp,"%s",cur->homeadress);
//		SC
//		PRT(cur->homecity)
//		SC
//		PRT(cur->homestate)
//		SC
//		PRT(cur->homezipcode)
//		SC
//		PRT(cur->homecountry)
//		NL
//		
//		
//	}
	
	if(cur->primaryemail[0]||cur->secondaryemail[0]){
		fprintf(fp,"email;internet:");
		PRT(cur->primaryemail)
		NL
	}
	if(cur->jobtitle[0]) fprintf(fp,"title:%s\n",cur->jobtitle);
	if(cur->workphone[0])fprintf(fp,"tel;work:%s\n",cur->workphone);
	if(cur->faxnumber[0])fprintf(fp,"tel;fax:%s\n",cur->faxnumber);
	if(cur->pagernumber[0])fprintf(fp,"tel;pager:%s\n",cur->pagernumber);
	if(cur->homephone[0])fprintf(fp,"tel;home:%s\n",cur->homephone);
	if(cur->mobilenumber[0])fprintf(fp,"tel;cell:%s\n",cur->mobilenumber);
	if(cur->notes[0])fprintf(fp,"note:%s\n",cur->notes);
	if(cur->webpage1[0])fprintf(fp,"url:%s\n",cur->webpage1);
	
	fprintf(fp,"version:2.1\n");
	fprintf(fp,"end:vcard\n");
}

void writeVCF(const char ime[], Lista lista){
	FILE *fp;
	Elem cur;
	
	fp = fopen(ime,"w");
	if(!fp){
		DATERR
	}
	cur = lista.prvi;

	while(cur){
		writeContact(fp,cur);
		cur = cur->next;
		if(cur)fprintf(fp,"\n");
	}
	
	fclose(fp);
}


