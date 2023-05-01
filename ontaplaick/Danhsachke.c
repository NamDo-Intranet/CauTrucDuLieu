#include<stdio.h>
#include<stdlib.h>
#define max 100
struct DSKe{
	int dinhKe;
	struct DSKe *lienket;
};
struct DoThi{
	int soDinh;
	struct DSKe *dsKe[max];
};
void them(int i, int j, struct DoThi *g){
	struct DSKe *k;
	k = (struct DSKe *)malloc(sizeof(struct DSKe));
	k->dinhKe = j;
	k->lienket = g->dsKe[i];
	g->dsKe[i] = k;
}
void docTep(char *tenTep, struct DoThi *g){
	FILE *f;
	int i, j, tg;
	f = fopen(tenTep, "r");
	fscanf(f, "%d", &g->soDinh);
	for(i=0;i<g->soDinh;i++){
		g->dsKe[i]= NULL;
		for(j=0;j<g->soDinh;j++){
			fscanf(f, "%d", &tg);
			if(tg==1){
				them(i, j, g);
			}
		}
	}
	fclose(f);
}
void inDoThi(struct DoThi g){
	int i;
	struct DSKe *k;
	printf("So Dinh: %d\n", g.soDinh);
	printf("Danh Sach Ke:\n");
	for(i=0;i<g.soDinh;i++){
		printf("Danh sach ke thu %d: ", i);
		k = g.dsKe[i];
		while(k!=NULL){
			printf("%d ", k->dinhKe);
			k = k->lienket;
		}printf("\n");
	}
}
//Cho biet sinh vien X và y co cung tinh khong?
int KTCungTinhXY(struct DoThi *g, int x, int y){
	int i;
	struct DSKe *k;
	for(i=0;i<g->soDinh;i++){
		x == i;
		k = g->dsKe[x];
		if(k->dinhKe==y)
			return 1;
	}return 0;
}
int main(){
	struct DoThi g;
	int x = 0, y = 8;
	docTep("dske.txt", &g);
	inDoThi(g);
	int KTcungtinh = KTCungTinhXY(&g, x, y);
	printf("\nSinh vien %d voi sinh vien %d co cung tinh khong %d", x, y, KTcungtinh);
	return 0;
}