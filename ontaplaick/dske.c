#include<stdio.h>
#include<stdlib.h>
#define max 150
struct DSKe{
	int dinhKe;
	struct DSKe *lienket;
};
struct DoThi{
	int soDinh;
	struct DSKe *dske[max];
};
void them(int i, int j, struct DoThi *g){
	struct DSKe *k;
	k = (struct DSKe *)malloc(sizeof(struct DSKe));
	k->dinhKe = j;
	k->lienket = g->dske[i];
	g->dske[i] = k;
}
void docTep(char *tenTep, struct DoThi *g){
	FILE *f;
	int i, j, tg;
	f = fopen(tenTep, "r");
	fscanf(f, "%d", &g->soDinh);
	for(i=0;i<g->soDinh;i++){
		g->dske[i]=NULL;
		for(j=0;j<g->soDinh;j++){
			fscanf(f, "%d", &tg);
			if(tg==1){
				them(i, j, g);
			}
		}
	}
	fclose(f);
}
void inDTDSKe(struct DoThi g){
	int i, j;
	struct DSKe *k;
	k = (struct DSKe *)malloc(sizeof(struct DSKe));
	printf("So dinh: %d\n", g.soDinh);
	printf("Cac ds ke: \n");
	for(i=0;i<g.soDinh;i++){
		printf("Danh sach ke thu %d: ", i);
		k = g.dske[i];
		while(k!=NULL){
			printf("%d ", k->dinhKe);
			k = k->lienket;
		}
		printf("\n");
	}
}
int main(){
	struct DoThi g;
	docTep("matrankedothi.txt", &g);
	inDTDSKe(g);
	return 0;
}