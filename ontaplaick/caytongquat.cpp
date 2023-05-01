#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Nguoi{
	char hoten[25];
	int namsinh;
};
struct cayTQ{
	struct Nguoi dulieu;
	struct cayTQ *con, *em;
};
struct cayTQ *taoNut(struct cayTQ *bcon, struct cayTQ *bem, struct Nguoi X){
	struct cayTQ *k;
	k = (struct cayTQ *)malloc(sizeof(struct cayTQ));
	k->dulieu = X;
	k->con = bcon;
	k->em = bem;
	return k;
}
struct cayTQ *taoCay(){
	struct Nguoi ng1, ng2, ng3, ng4, ng5, ng6, ng7, ng8;
	struct cayTQ *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
	strcpy(ng1.hoten, "Nguyen F");
	ng1.namsinh = 1965;
	n1 = taoNut(NULL, NULL, ng1);
	strcpy(ng2.hoten, "Nguyen E");
	ng2.namsinh = 1960;
	n2 = taoNut(NULL, n1, ng2);
	strcpy(ng3.hoten, "Nguyen D");
	ng3.namsinh = 1955;
	n3 = taoNut(NULL, n2, ng3);
	strcpy(ng4.hoten, "Nguyen H");
	ng4.namsinh = 1970;
	n4 = taoNut(NULL, NULL, ng4);
	strcpy(ng5.hoten, "Nguyen G");
	ng5.namsinh = 1965;
	n5 = taoNut(NULL, n4, ng5);
	strcpy(ng6.hoten, "Nguyen C");
	ng6.namsinh = 1935;
	n6 = taoNut(n5, NULL, ng6);
	strcpy(ng7.hoten, "Nguyen B");
	ng7.namsinh = 1930;
	n7 = taoNut(n3, n6, ng7);
	strcpy(ng8.hoten, "Nguyen A");
	ng8.namsinh = 1900;
	n8 = taoNut(n7, NULL, ng8);
	return n8;
}
//in cay gia pha BFS
void inBFS(struct cayTQ *goc){
	struct cayTQ *q[100], *p;
	int dau, cuoi;
	if(goc!=NULL){
		dau = 0;
		cuoi = 0;
		q[0] = goc;
		while(dau<=cuoi){
			p = q[dau];
			printf("%s\t%d\n", p->dulieu.hoten, p->dulieu.namsinh);
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
//Dem so nguoi co trong cay gia pha
int demNguoi(struct cayTQ *goc){
	struct cayTQ *k;
	k = goc;
	int d1=0, d2=0, dem =0;
	if(k!=NULL){
		d1 = demNguoi(k->con);
		d2 = demNguoi(k->em);
		dem = d1 + d2;
	}else{
		return 0;
	}
	return dem + 1;
}
//tinh so the he trong cay gia pha
int tinhsthcay(struct cayTQ *k){
	struct cayTQ *g;
	g = k;
	int max = 0, left, right;
	if(g==NULL){
		return 0;
	}else{
		g = g->con;
		left = tinhsthcay(g);
		if(max<left){
			max = left;
		}
		while(g!=NULL){
			g = g->em;
			right = tinhsthcay(g);
			if(max<right){
				max = right;
			}
		}
	}
	max++;
	return max;
}
int main(){
	struct cayTQ *goc;
	goc = taoCay();
	inBFS(goc);
	int demsoNguoi = demNguoi(goc);
	printf("Cay gia pha co %d nguoi", demsoNguoi);
	int tinhsth = tinhsthcay(goc);
	printf("\nSo the he cua cay la %d", tinhsth);
	return 0;
}