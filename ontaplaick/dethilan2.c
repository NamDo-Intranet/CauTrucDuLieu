#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 100
struct Nguoi{
	char ten[10];
};
struct CayTQ{
	struct Nguoi dulieu;
	struct CayTQ *con, *em;
};
struct CayTQ *taoNut(struct CayTQ *bcon, struct CayTQ *bem, struct Nguoi X){
	struct CayTQ *k;
	k = (struct CayTQ *)malloc(sizeof(struct CayTQ));
	k->dulieu = X;
	k->con = bcon;
	k->em = bem;
	return k;
}
struct CayTQ *taoCay(){
	struct Nguoi ng1, ng2, ng3, ng4, ng5, ng6, ng7, ng8, ng9, ng10, ng11;
	struct CayTQ *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8, *n9, *n10, *n11;
	strcpy(ng1.ten, "Eha");
	n1 = taoNut(NULL, NULL, ng1);
	strcpy(ng2.ten, "Bob");
	n2 = taoNut(NULL, n1, ng2);
	strcpy(ng3.ten, "Lee");
	n3 = taoNut(NULL, n2, ng3);
	strcpy(ng4.ten, "Bill");
	n4 = taoNut(NULL, NULL, ng4);
	strcpy(ng5.ten, "Sal");
	n5 = taoNut(NULL, NULL, ng5);
	strcpy(ng6.ten, "Tom");
	n6 = taoNut(n4, n5, ng6);
	strcpy(ng7.ten, "Ema");
	n7 = taoNut(n6, NULL, ng7);
	strcpy(ng8.ten, "Bol");
	n8 = taoNut(NULL, n7, ng8);
	strcpy(ng9.ten, "Rohan");
	n9 = taoNut(n8, NULL, ng9);
	strcpy(ng10.ten, "Steve");
	n10 = taoNut(n3, n9, ng10);
	strcpy(ng11.ten, "John");
	n11 = taoNut(n10, NULL, ng11);
	return n11;
}
void incay(struct CayTQ *g){
	struct CayTQ *q[max], *p;
	int dau, cuoi;
	if(g!=NULL){
		dau = 0;
		cuoi = 0;
		q[0] = g;
		while(dau<=cuoi){
			p = q[dau];
			printf("%s\n", p->dulieu.ten);
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
//void incay(struct CayTQ *p){
//	if(p!=NULL){
//		printf("%s\n", p->dulieu.ten);
//		incay(p->con);
//		incay(p->em);
//	}
//}

//Tim ten X co trong cay Ko
struct CayTQ *timTen(struct CayTQ *g, char *X){
	struct CayTQ *p, *kq;
	p = (struct CayTQ *)malloc(sizeof(struct CayTQ));
	if(g==NULL){
		return NULL;
	}else{
		if(strcmp(g->dulieu.ten, X)==0){
			return g;
		}else{
			p = g->con;
			while(p!=NULL){
				kq = timTen(p, X);
				if(kq!=NULL){
					return kq;
				}else{
					p = p->em;
				}
			}return NULL;
		}
	}
}

//Viet ham cho biet y co phai la con chau cua x ko
int ktConChauXY(struct CayTQ *g, char *x, char *y){
	struct CayTQ *q, *p, *k;
	q = timTen(g, x);
	if(q==NULL){
		return 0;
	}else{
		p = q->con;
		while(p!=NULL){
			k = timTen(p, y);
			if(k==NULL){
				return 1;
			}else{
				p = p->em;
			}
		}
		return 0;
	}
}
int main(){
	struct CayTQ *goc = NULL;
	char *x = "Rohan";
	char *y = "Bill";
	char *x1 = "Steve";
	char *y1 = "Sal";
	goc = taoCay();
	incay(goc);
	int KtConChau = ktConChauXY(goc, x, y);
	printf("\n%s co phai la con chau cua %s khong: %d", y, x, KtConChau);
	int KtConChau1 = ktConChauXY(goc, x1, y1);
	printf("\n%s co phai la con chau cua %s khong: %d", y1, x1, KtConChau1);
	return 0;
}