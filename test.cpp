#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Nguoi{
	char hoten[20];
	int namsinh;
};
struct CayTQ{
	struct Nguoi dulieu;
	struct CayTQ *con, *em;
};
struct CayTQ *taoNut(struct CayTQ *bcon, struct CayTQ *bem, struct Nguoi X){
	struct CayTQ *goc;
	goc = (struct CayTQ *)(malloc(sizeof(struct CayTQ)));
	goc->con = bcon;
	goc->em = bem;
	goc->dulieu = X;
	return goc;
}
struct CayTQ *taoCay(){
	struct Nguoi ng1, ng2, ng3, ng4, ng5, ng6, ng7, ng8;
	struct CayTQ *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
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
void inCayTQ(struct CayTQ *goc){
	struct CayTQ *q[100], *p;
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
//dem so nguoi co trong cay gia pha
int demNguoi(struct CayTQ *goc){
	int dem, d1, d2;
	dem = 0;
	struct CayTQ *p;
	p = goc;
	if(p!=NULL){
		d1 = demNguoi(p->con);
		d2 = demNguoi(p->em);
		dem = d1 + d2;
	}else{
		return 0;
	}
	return dem + 1;
}
//tinh so the he cua cay gia pha
int tinhSTH(struct CayTQ *goc){
	struct CayTQ *p = goc;
	int left, right, max = 0;
	if(p == NULL){
		return 0;
	}else{
		p = goc->con;
		left = tinhSTH(p);
		if(max < left){
			max = left;
		}
		while(p!=NULL){
			p = p->em;
			right = tinhSTH(p);
			if(max < right){
				max = right;
			}
		}
	}
	max++;
	return max;
}
int main(){
	struct CayTQ *goc;
	goc = taoCay();
	inCayTQ(goc);
	int demsonguoi = demNguoi(goc);
	printf("\nTat ca co %d nguoi trong cay gia pha", demsonguoi);
	int tinhsthcay = tinhSTH(goc);
	printf("\nSo the he cay la %d", tinhsthcay);
	return 0;
}