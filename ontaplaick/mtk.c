#include<stdio.h>
#define max 10
struct DoThi{
	int soDinh;
	int mtk[max][max];
};
int daTham[max];
void docTep(char *tenTep, struct DoThi *g){
	FILE *f;
	int i, j;
	f = fopen(tenTep, "r");	
	fscanf(f, "%d", &g->soDinh);
	for(i=0;i<g->soDinh;i++){
		for(j=0;j<g->soDinh;j++){
			fscanf(f, "%d", &g->mtk[i][j]);
		}
	}
	fclose(f);
}
void indothi(struct DoThi g){
	int i, j;
	printf("%d\n", g.soDinh);
	for(i=0;i<g.soDinh;i++){
		for(j=0;j<g.soDinh;j++){
			printf("%d ", g.mtk[i][j]);
		}
		printf("\n");
	}
}
void duyetsau(struct DoThi g, int v){
	int w;
	printf("%d->", v);
	daTham[v] = 1;
	for(w=0;w<g.soDinh;w++){
		if(g.mtk[v][w]==1 && daTham[w]==0){
			duyetsau(g, w);
		}
	}
}
void duyetRong(struct DoThi g, int v){
	int dau, cuoi, q[max], w;
	dau = 0, cuoi = 0, q[0]=v;
	daTham[v] = 1;
	while(dau<=cuoi){
		v = q[dau];
		dau++;
		printf("%d->", v);
		for(w=0;w<g.soDinh;w++){
			if(g.mtk[v][w]==1 && daTham[w]==0){
				cuoi++;
				q[cuoi] = w;
				daTham[w] = 1;
			}
		}
	}
}
int main(){
	struct DoThi g;
	docTep("dt1.txt", &g);
	indothi(g);
//	printf("Ham duyetsau la:");
//	duyetsau(g, 3);
	printf("\nHam duyet rong la:");
	duyetRong(g, 5);
	return 0;
}