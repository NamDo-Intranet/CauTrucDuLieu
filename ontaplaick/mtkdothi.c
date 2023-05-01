#include<stdio.h>
#define max 150

struct DoThi{
	int soDinh;
	int mtk[max][max];
};
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
	printf("%d\n", g.soDinh);
	for(i=0;i<g.soDinh;i++){
		for(j=0;j<g.soDinh;j++){
			printf("%d ", g.mtk[i][j]);
		}
		printf("\n");
	}
}
int demSV(struct DoThi *g, int k){
	int i, j, dem=0;
	for(i=0;i<g->soDinh;i++){
		for(j=0;j<g->soDinh;j++){
			if(g->mtk[i][j]==1 && i==k){
				dem++;
			}
		}
	}
	return dem;
}
//Nhung sinh vien trong lop cung tinh voi sinh vien thu k
void dinhkeK(struct DoThi *g, int k){
	int i;
	for(i=0;i<g->soDinh;i++){
		if(g->mtk[k][i]==1){
			printf("%d ", i);
		}
	}
}
int main(){
	struct DoThi g;
	int k = 3;
	docTep("matrankedothi.txt", &g);
	inDoThi(g);
	int demSoSinhvien = demSV(&g, k);
	printf("Sinh vien %d cung tinh %d\n", k, demSoSinhvien);
	printf("Sinh vien cung tinh la: ");
	dinhkeK(&g, k);
	return 0;
}