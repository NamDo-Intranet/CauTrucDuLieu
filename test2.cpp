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
void inDoThi(struct DoThi g){
	int i, j;
	printf("So dinh la %d\n", g.soDinh);
	for(i=0;i<g.soDinh;i++){
		for(j=0;j<g.soDinh;j++){
			printf("%d  ", g.mtk[i][j]);
		}
		printf("\n");
	}
}
void duyetsau(struct DoThi g, int v){
	int w;
	daTham[v] = 1;
	for(w=0;w<g.soDinh;w++){
		if(g.mtk[v][w]=1 && daTham[w]==0){
			duyetsau(g, w);
		}
	}
}
int lienThong(struct DoThi g){
	int i;
	for(i=0;i<g.soDinh;i++){
		daTham[i] = 0;
	}	
	duyetsau(g, 0);
	for(i=0;i<g.soDinh;i++){
		if(daTham[i]==0){
			return 0;
		}
	}return 1;
}
int main(){
	struct DoThi g;
	docTep("mtk1.txt", &g);
	inDoThi(g);
	int lienthong = lienThong(g);
	printf("Do thi co lien thong hay khong %d", lienthong);
	return 0;
}