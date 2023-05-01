#include<stdio.h>
#include<stdlib.h>
#define max 50
struct Canh{
	int dinhDau, dinhCuoi;
};
struct DoThi{
	int soDinh, soCanh;
	struct Canh dsCanh[50];
};
void docTep(char *tenTep, struct DoThi *g){
	FILE *f;
	int i, j, tg;
	f = fopen(tenTep, "r");
	fscanf(f, "%d", &g->soDinh);
	g->soCanh = 0;
	for(i=0;i<g->soDinh;i++){
		for(j=0;j<g->soDinh;j++){
			fscanf(f, "%d", &tg);
			if(tg==1){
				g->dsCanh[g->soCanh].dinhDau = i;
				g->dsCanh[g->soCanh].dinhCuoi = j;
				g->soCanh++;
			}
}
	}
	fclose(f);
}
void inDoThi(struct DoThi g){
	int i;
	printf("So Dinh: %d , So Canh: %d\n", g.soDinh, g.soCanh);
	for(i=0;i<g.soCanh;i++){
		printf("%d  %d\n", g.dsCanh[i].dinhDau, g.dsCanh[i].dinhCuoi);
	}
}
//Cho biet sinh vien thu k biet nha bao nhieu ban trong lop
int demSoSV(struct DoThi *g, int k){
	int i, j, dem=0;
	if(g!=NULL){
		for(i=0;i<g->soCanh;i++){
			if(g->dsCanh[i].dinhDau==k){
				dem = dem + 1;
			}
		}
	}
	return dem;
}
int main(){
	struct DoThi g;
	int k = 4;
	docTep("sinhvien.txt", &g);
	inDoThi(g);
	int demSoSinhvien = demSoSV(&g, k);
	printf("Sinh vien %d biet nha %d nguoi", k, demSoSinhvien);
	return 0;
}