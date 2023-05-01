#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//struct ThueBao{
//	char tenTB[25];
//	char SDT[11];	
//};
//struct CayTKNP{
//	struct ThueBao dulieu;
//	struct CayTKNP *trai, *phai;
//};
//void themTB(struct CayTKNP **goc, struct ThueBao X){
//	struct CayTKNP *p;
//	if(*goc==NULL){
//		p = (struct CayTKNP *)malloc(sizeof(struct CayTKNP));
//		p->dulieu = X;
//		p->trai = NULL;
//		p->phai = NULL;
//		*goc = p;	
//	}else{
//		if(strcmp((*goc)->dulieu.SDT, X.SDT)>0){
//			themTB(&(*goc)->trai, X);
//		}else if(strcmp((*goc)->dulieu.SDT, X.SDT)<0){
//			themTB(&(*goc)->phai, X);
//		}
//	}
//}
//void lietKe(struct CayTKNP *goc, char *SDT){
//	if(goc!=NULL){
//		int kq = strncmp(goc->dulieu.SDT, SDT, strlen(SDT));
//		if(kq==0){
//			printf("%s  %s\n", goc->dulieu.tenTB, goc->dulieu.SDT);
//			lietKe(goc->trai, SDT);
//			lietKe(goc->phai, SDT);
//		}else{
//			if(kq>0){
//				lietKe(goc->trai, SDT);
//			}else{
//				lietKe(goc->phai, SDT);
//			}
//		}
//	}
//}
//int main(){
//	struct CayTKNP *goc = NULL;
//	struct ThueBao tb1 = {"Nguyen A", "0912535346"};
//	struct ThueBao tb2 = {"Nguyen B", "0989023523"};
//	struct ThueBao tb3 = {"Nguyen C", "0912534678"};
//	struct ThueBao tb4 = {"Nguyen D", "0989346344"};
//	struct ThueBao tb5 = {"Nguyen E", "0989767956"};
//	themTB(&goc, tb1);
//	themTB(&goc, tb2);
//	themTB(&goc, tb3);
//	themTB(&goc, tb4);
//	themTB(&goc, tb5);
//	lietKe(goc, "0989");
//	return 0;
//}

struct ThueBao{
	char tenTB[20];
	char SDT[11];	
};
struct CayTKNP{
	struct ThueBao dulieu;
	struct CayTKNP *trai, *phai;
};
void themTB(struct CayTKNP **goc, struct ThueBao X){
	struct CayTKNP *p;
	if(*goc==NULL){
		p = (struct CayTKNP *)malloc(sizeof(struct CayTKNP));
		p->dulieu = X;
		p->trai = NULL;
		p->phai = NULL;
		*goc = p;
	}else{
		if(strcmp((*goc)->dulieu.SDT, X.SDT)>0){
			themTB(&(*goc)->phai, X);
		}else if(strcmp((*goc)->dulieu.SDT, X.SDT)<0){
			themTB(&(*goc)->trai, X);
		}
	}
}
void intataca(struct CayTKNP *goc){
	if(goc!=NULL){
		printf("%s  %s\n", goc->dulieu.tenTB, goc->dulieu.SDT);
		intataca(goc->trai);
		intataca(goc->phai);
	}
}
struct CayTKNP *timSDT(struct CayTKNP *goc, char *sdt){
	struct CayTKNP *k;
	k = goc;
	while(k!=NULL){
		if(strcmp(k->dulieu.SDT, sdt)==0){
			return k;
		}
		else{
			if(strcmp(k->dulieu.SDT, sdt)>0){
				k = k->phai;
			}else if(strcmp(k->dulieu.SDT, sdt)<0){
				k = k->trai;
			}
		}
	}return 0;
}
int main(){
	struct CayTKNP *goc = NULL;
	struct ThueBao tb1 = {"Nguyen A", "0957549871"};
	struct ThueBao tb2 = {"Nguyen B", "0997030639"};
	struct ThueBao tb3 = {"Nguyen C", "0246335323"};
	struct ThueBao tb4 = {"Nguyen D", "0235264366"};
	struct ThueBao tb5 = {"Nguyen E", "0363463469"};
	themTB(&goc, tb1);
	themTB(&goc, tb2);
	themTB(&goc, tb3);
	themTB(&goc, tb4);
	themTB(&goc, tb5);
	intataca(goc);
	char sdt[11] = "0997030639";
	struct CayTKNP *timsdt = timSDT(goc, sdt);
	if(timsdt!=0){
		printf("Da tim thay so dien thoai %s co ten thue bao la: %s", timsdt->dulieu.SDT, timsdt->dulieu.tenTB);
	}else{
		printf("Khong tim thay so %s trong thue bao", sdt);
	}
	return 0;
}
