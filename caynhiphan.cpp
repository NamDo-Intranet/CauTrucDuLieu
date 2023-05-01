#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Nguoi{
	char hoTen[20];
	int namSinh;
};
struct CayGPNP{
	struct Nguoi dulieu;
	struct CayGPNP *trai, *phai;
};
struct CayGPNP *taoNut(struct CayGPNP *btrai, struct CayGPNP *bphai, struct Nguoi X){
	struct CayGPNP *k;
	k = (struct CayGPNP *)(malloc(sizeof(struct CayGPNP)));
	k->dulieu = X;
	k->trai = btrai;
	k->phai = bphai;
	return k;
}
struct CayGPNP *taoCay(){
	struct Nguoi ng1, ng2, ng3, ng4, ng5, ng6;
	struct CayGPNP *n1, *n2, *n3, *n4, *n5, *n6;
	strcpy(ng1.hoTen, "Nguyen D");
	ng1.namSinh = 1960;
	n1 = taoNut(NULL, NULL, ng1);
	strcpy(ng2.hoTen, "Nguyen B");
	ng2.namSinh = 1930;
	n2 = taoNut(NULL, n1, ng2);
	strcpy(ng3.hoTen, "Nguyen E");
	ng3.namSinh = 1965;
	n3 = taoNut(NULL, NULL, ng3);
	strcpy(ng4.hoTen, "Nguyen F");
	ng4.namSinh = 1970;
	n4 = taoNut(NULL, NULL, ng4);
	strcpy(ng5.hoTen, "Nguyen C");
	ng5.namSinh = 1935;
	n5 = taoNut(n3, n4, ng5);
	strcpy(ng6.hoTen, "Nguyen A");
	ng6.namSinh = 1900;
	n6 = taoNut(n2, n5, ng6);
	return n6;
}
void inTruoc(struct CayGPNP *p){
	if(p!=NULL){
		printf("\t%s\t%d\n", p->dulieu.hoTen, p->dulieu.namSinh);
		inTruoc(p->trai);
		inTruoc(p->phai);
	}
}
//Dem so nguoi trong cay
int demSN(struct CayGPNP *d){
	struct CayGPNP *k;
	k = d;
	int d1 = 0, d2 =0, dem = 0;
	while(k!=NULL){
		if(k->trai!=NULL){
			d1++;
		}
		k = k->phai;
		d2++;
	}
	dem = (d1+d2)+1;
	return dem;
}
//Tinh so the he cua cay
int sothehecay(struct CayGPNP *goc){
	struct CayGPNP *k = goc;
	int left,right;
	int max = 0;
	if(k==NULL){
		return 0;
	}
	if(k->trai!=NULL){
		left = sothehecay(k->trai);
		if(max<left){
			max = left;
		}
	}	
	if(k->phai!=NULL){
		right = sothehecay(k->phai);
		if(max<right){
			max = right;
		}
	}
		max++;
	return max;
}
//Dem so nguoi sinh truoc nam X
int demNSlonhonX(struct CayGPNP *goc, int X){
	struct CayGPNP *k = goc;
	int dem = 0, dem1 = 0, dem2 = 0;
	if(k==NULL){
		return 0;
	}else{
		
		if(k->dulieu.namSinh<X){
			dem1 = demNSlonhonX(k->trai, X);
			dem2 = demNSlonhonX(k->phai, X);
			return dem = (dem1+dem2)+1;
		}
	}return 0;
}
//Tim 1 nguoi trong cay khi biet ho ten
struct CayGPNP *timhoten(struct CayGPNP *goc, char ht[]){
	struct CayGPNP *k;
	if(goc==NULL){
		return NULL;
	}else{
		if(strcmp(goc->dulieu.hoTen, ht)==0){
			return goc;
		}else{
			k = timhoten(goc->trai, ht);
			if(k!=NULL){
				return k;
			}
			k = timhoten(goc->phai, ht);
			return k;
		}
	}
}
//Cho biet nguoi ten X thuoc the he thu may trong cay

//Kiem tra nguoi ten Y co phai la con cua nguoi ten X hay khong
//int ktcon(struct CayGPNP *goc, char Y[], char X[]){
//	struct CayGPNP *p;
//	p = timhoten(goc, X);
//	if(p==NULL){
//		return 0;
//	}else{
//		if((p->trai!=NULL&&strcmp(p->dulieu.hoTen, Y)==0) || (p->phai!=NULL&&strcmp(p->dulieu.hoTen, Y)==0)){
//			return 1;
//		}else{
//			return 0;
//		}
//	}
//}
//Liet ke tat ca con chau cua nguoi ten X
void lietkeConchau(struct CayGPNP *goc, char X[]){
	struct CayGPNP *p;
	p = timhoten(goc, X);
	if(p!=NULL){
		if(p->trai!=NULL || p->phai!=NULL){
			inTruoc(p->trai);
			inTruoc(p->phai);
		}
		if(p->trai==NULL && p->phai==NULL){
			printf("ko tim thay con chau cua nguoi ten %s", p->dulieu.hoTen);
		}
	}
}
int main(){
	struct CayGPNP *goc;
	char ht[20] = "Nguyen E";
	char Y[20] = "Nguyen C";
	int X = 1901;
	goc = taoCay();
	printf("Cay Gia Pha nha ho Nguyen\n");
	inTruoc(goc);
//	int demSNtrongcayGP = demSN(goc);
//	printf("\n\nSo nguoi trong cay gia pha la %d nguoi ", demSNtrongcayGP);
//	int thehecay = sothehecay(goc);
//	printf("\n\nso the he cay la: %d", thehecay);
//	int demNS = demNSlonhonX(goc, X);
//	printf("\n\nSo nguoi sinh truoc nam X la: %d", demNS);
//	struct CayGPNP *timht = timhoten(goc, ht);
//	if(timht!=0){
//		printf("\n\nDa tim thay thong tin %s voi Nam sinh la %d trong cay gia pha", timht->dulieu.hoTen, timht->dulieu.namSinh);
//	}else{
//		printf("\n\nKhong tim thay thong tin %s", ht);
//	}

//	int KiemtraCon = ktcon(goc, Y, ht);
//	printf("\n\nNguoi ten Y co phai la con cua nguoi ten X hay ko (1 or 0): %d", KiemtraCon);
	printf("\n\nTat ca con chau cua nguoi ten X la: \n");
	lietkeConchau(goc, Y);
	return 0;
}