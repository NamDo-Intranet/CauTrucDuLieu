#include<stdio.h>
#define max 10
struct DoThi{
	int soDinh;
	int mtk[max][max];
};
int DaTham[max], truoc[max];
//ham doc tep
void docTep(char *tenTep, struct DoThi *g){
	FILE *f;
	int i, j;
	f = fopen(tenTep, "r");
	fscanf(f, "%d", &g->soDinh);
	for(i=0;i<g->soDinh;i++){
		for(j=0;j<g->soDinh;j++){
			fscanf(f, "%d ", &g->mtk[i][j]);
		}
	}
	fclose(f);
}
//In do thi
void inDoThi(struct DoThi g){
	int i, j;
	printf("soDinh: %d\n", g.soDinh);
	for(i=0;i<g.soDinh;i++){
		for(j=0;j<g.soDinh;j++){
			printf("%d  ", g.mtk[i][j]);
		}
		printf("\n");
	}
}
//Ham duyet sau
void duyetSau(struct DoThi g, int v){
	int i;
	DaTham[v] = 1;
	for(i=0;i<g.soDinh;i++){
		if(DaTham[i]==0 && g.mtk[v][i]==1){
			duyetSau(g, i);
		}
	}
}
//Ham duyet rong
void duyetRong(struct DoThi g, int v){
	int q[max], dinhDau, dinhCuoi, w;
	dinhDau = 0;
	dinhCuoi =0;
	q[0]=v;
	DaTham[v]=1;
	while(dinhDau<=dinhCuoi){
		v = q[dinhDau];
		dinhDau++;
		printf("%d ", v);
		for(w=0;w<g.soDinh;w++){
			if(g.mtk[v][w]==1 && DaTham[w]==0){
				dinhCuoi++;
				q[dinhCuoi] = w;
				DaTham[w] = 1;
			}
		}
	}
}
//Lien Thong
int lienThong(struct DoThi g){
	int i;
	for(i=0;i<g.soDinh;i++){
		DaTham[i] = 0;
	}
	duyetSau(g, 0);
	for(i=0;i<g.soDinh;i++){
		if(DaTham[i]==0)
			return 0;
	}return 1;
}
int duongDi(struct DoThi g, int x, int y){
	int i;
	for(i=0;i<g.soDinh;i++){
		DaTham[i]=0;
	}
	if(DaTham[y]==1)
		return 1;
	return 0;
}
int main(){
	struct DoThi g;
	int v;
	docTep("dt1.txt", &g);
	inDoThi(g);
//	printf("\nDuyet theo chieu sau la: ");
//	duyetSau(g, 2);
	printf("\nDuyet theo chieu rong la: ");
	duyetRong(g, 4);
//	int LT = lienThong(g);
//	printf("\nDo thi co lien thong hay khong: %d \n", LT);
//	int x = 2, y =5;
//	printf("\nCo duong di hay khong? %d\n", duongDi(g, x, y));
	return 0;
}