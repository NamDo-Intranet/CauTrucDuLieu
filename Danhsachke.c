#include<stdio.h>
#include<stdlib.h>
#define max 10
struct DSKe{
	int dinhke;
	struct DSKe *lienket;
};
struct DoThi{
	int soDinh;
	struct DSKe *dsKe[max];
};
int daTham[max], truoc[max];
//them dinh j vao ds ke dinh i
void them(int i, int j, struct DoThi *g){
	struct DSKe *k = (struct DSKe *)malloc(sizeof (struct DSKe));
	k->dinhke = j;
	k->lienket = g->dsKe[i];
	g->dsKe[i] = k;
}
//Ham doc tep
void doctep(char *tenTep, struct DoThi *g){
	FILE *f;
	int i, j, tg;
	f = fopen(tenTep, "r");
	fscanf(f, "%d", &g->soDinh);
	for(i=0;i<g->soDinh;i++){
		g->dsKe[i] = NULL;
		for(j=0;j<g->soDinh;j++){
			fscanf(f, "%d", &tg);
			if(tg==1)
				them(i, j, g);
		}
	}
	fclose(f);
}
//ham in do thi
void inDoThi(struct DoThi g){
	int i;
	struct DSKe *k;
	k = (struct DSKe *)malloc(sizeof(struct DSKe));
	printf("so dinh: %d\n", g.soDinh);
	printf("cac ds ke:\n");
	for(i=0; i<g.soDinh; i++){
		printf("Danh sach ke thu %d: ", i);
		k = g.dsKe[i];
		while(k!=NULL){
			printf("%d ", k->dinhke);
			k = k->lienket;
		}
		printf("\n");
	}
}
//duyet theo chieu sau
void DFS(struct DoThi g, int v){
	struct DSKe *k;
	int w;
	daTham[v]=1;
	k = g.dsKe[v];
	while(k!=NULL){
		w = k->dinhke;
		if(daTham[w]==0){
			truoc[w] = v;
			DFS(g, w);
		}
		k = k->lienket;
	}
}
//tim duong di
int duongdi(struct DoThi g, int s){
	int i;
	for(i=0; i<g.soDinh;i++){
		daTham[i]=0;
		DFS(g, s);
	}
}
//ham in duong di
void inDD(int s, int d){
	int z;
	z = d;
	while(z!=s){
		printf("%d <=", z);
		z = truoc[z];
	}
	printf("%d", s);
}
int main(){
	struct DoThi g;
//	int s, d;	
//	scanf("%d", &s);
//	scanf("%d", &d);
	doctep("dt1.txt", &g);
	inDoThi(g);
//	DFS(g, 0);
//	printf("\n");
//	duongdi(g, s);
//	inDD(s, d);
	return 0;
}