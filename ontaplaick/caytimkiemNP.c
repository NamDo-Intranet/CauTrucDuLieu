#include<stdio.h>
#include<stdlib.h>
struct CayNP{
	int songuyen;
	struct CayNP *trai, *phai;
};
void them(struct CayNP **goc, int X){
	struct CayNP *p;
	if(*goc==NULL){
		p = (struct CayNP *)malloc(sizeof(struct CayNP));
		p->songuyen = X;
		p->trai = NULL;
		p->phai = NULL;
		*goc = p;
	}
	else{
		if((*goc)->songuyen>X)
			them(&(*goc)->trai, X);
		else if((*goc)->songuyen<X)
			them(&(*goc)->phai, X);
	}
}
void incay(struct CayNP *goc){
	if(goc!=NULL){
		incay(goc->trai);
		printf("%d  ", goc->songuyen);
		incay(goc->phai);
	}
}
int timSoX(struct CayNP *goc, int X){
	if(goc==NULL){
		return 0;
	}
	else{
		if(goc->songuyen==X)
			return 1;
		else{
			if(goc->songuyen>X)
				return timSoX(goc->trai, X);
			else
				return timSoX(goc->phai, X);
		}
	}
}
int main(){
	struct CayNP *goc = NULL;
	them(&goc, 5);
	them(&goc, 9);
	them(&goc, 8);
	them(&goc, 7);
	them(&goc, 10);
	them(&goc, 15);
	them(&goc, 13);
	them(&goc, 20);
	them(&goc, 27);
	them(&goc, 19);
	incay(goc);
	int timso = timSoX(goc, 21);
	printf("So can tim co hay khong: %d", timso);
	return 0;
}