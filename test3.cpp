#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct DoThi{
	char kytu[10];
};
struct CayTQ{
	struct DoThi dulieu;
	struct CayTQ *con, *em;
};
struct CayTQ *taoNut(struct CayTQ *bcon, struct CayTQ *bem, struct DoThi X){
	struct CayTQ *goc;
	goc = (struct CayTQ *)(malloc(sizeof(struct CayTQ)));
	goc->con = bcon;
	goc->em = bem;
	goc->dulieu = X;
	return goc;
}
struct CayTQ *taoCay(){
	struct DoThi kt1, kt2, kt3, kt4, kt5, kt6, kt7, kt8, kt9, kt10, kt11, kt12, kt13, kt14, kt15, kt16;
	struct CayTQ *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *n10, *n11, *n12, *n13, *n14, *n15, *n16;
	strcpy(kt1.kytu, "M");
	n1 = taoNut(NULL, NULL, kt1);
	strcpy(kt2.kytu, "L");
	n2 = taoNut(NULL, n1, kt2);
	strcpy(kt3.kytu, "D");
	n3 = taoNut(n2, NULL, kt3);	
	
	strcpy(kt4.kytu, "G");
	n4 = taoNut(NULL, NULL, kt4);
	strcpy(kt5.kytu, "F");
	n5 = taoNut(NULL, n4, kt5);
	strcpy(kt6.kytu, "E");
	n6 = taoNut(NULL, n5, kt6);	
	
	strcpy(kt7.kytu, "K");
	n7 = taoNut(NULL, NULL, kt7);
	strcpy(kt8.kytu, "J");
	n8 = taoNut(NULL, n7, kt8);
	strcpy(kt9.kytu, "I");
	n9 = taoNut(NULL, n8, kt9);
	strcpy(kt10.kytu, "H");
	n10 = taoNut(NULL, n9, kt10);
	
	strcpy(kt11.kytu, "C");
	n11 = taoNut(n10, NULL, kt11);
		
	strcpy(kt12.kytu, "B");
	n12 = taoNut(n6, NULL, kt12);
	strcpy(kt13.kytu, "A");
	n13 = taoNut(n3, n12, kt13);	
	strcpy(kt14.kytu, "R");
	n14 = taoNut(n11, NULL, kt14);
	strcpy(kt15.kytu, "Q");
	n15 = taoNut(n13, n14, kt15);
	strcpy(kt16.kytu, "P");
	n16 = taoNut(n15, NULL, kt16);
	return n16;	
}
void indothiBFS(struct CayTQ *goc){
	struct CayTQ *q[100], *p;
	int dau, cuoi;
	if(goc!=NULL){
		dau = 0;
		cuoi = 0;
		q[0] = goc;
		while(dau<=cuoi){
			p = q[dau];
			printf("%s\n", p->dulieu.kytu);
			dau++;
			p = p->con;
			while(p!=NULL){
				cuoi++;
				q[cuoi] = p;
				p = p->em;
			}
		}
	}
}
void indothiDFS(struct CayTQ *goc){
	struct CayTQ *p;
	if(goc!=NULL){
		p = goc;
		printf("%s\n", goc->dulieu.kytu);
		indothiDFS(p->con);
		indothiDFS(p->em);
	}
}
int main(){
	struct CayTQ *goc;
	goc = taoCay();
//	indothiBFS(goc);
	indothiDFS(goc);
	return 0;
}