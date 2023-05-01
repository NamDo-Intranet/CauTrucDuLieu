#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct ThueBao{
	char tenTB[30];
	char SDT[10];
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
			themTB(&(*goc)->trai, X);
		}else if(strcmp((*goc)->dulieu.SDT, X.SDT)<0){
			themTB(&(*goc)->phai, X);
		}		
	}
}
void intatca(struct CayTKNP *goc){
	if(goc!=NULL){
		intatca(goc->trai);
		printf("%s  %s\n", goc->dulieu.tenTB, goc->dulieu.SDT);
		intatca(goc->phai);
	}
}
void inDB(struct CayTKNP *goc, char *sdt){
	if(goc!=NULL){
		int kq = strncmp(goc->dulieu.SDT, sdt, strlen(sdt));
		if(kq==0){
			printf("%s  %s\n", goc->dulieu.tenTB, goc->dulieu.SDT);
			inDB(goc->trai, sdt);
			inDB(goc->phai, sdt);
		}else{
			if(kq>0){
				inDB(goc->trai, sdt);
			}else{
				inDB(goc->phai, sdt);
			}
		}
	}
}
int main(){
	struct CayTKNP *goc = NULL;
	struct ThueBao tb1 = {"Nguyen A", "0912432126"};
	struct ThueBao tb2 = {"Nguyen B", "0989132345"};
	struct ThueBao tb3 = {"Nguyen C", "0989234564"};
	struct ThueBao tb4 = {"Nguyen D", "0912243345"};
	struct ThueBao tb5 = {"Nguyen E", "0989655765"};
	themTB(&goc, tb1);
	themTB(&goc, tb2);
	themTB(&goc, tb3);
	themTB(&goc, tb4);
	themTB(&goc, tb5);
//	intatca(goc);
	inDB(goc, "0989");
	return 0;
}