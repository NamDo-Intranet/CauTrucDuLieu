#include<stdio.h>
#define max 50

struct Canh{
	int dinhDau, dinhCuoi;
	float trongSo;
};
struct DoThi{
	int soDinh, soCanh;
	struct Canh dsCanh[max];
};
int DaTham[max];
//Hàm đọc tệp dữ liệu đồ thị
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
//Hàm in đồ thị biểu diễn bằng ds cạnh
void inDoThi(struct DoThi g){
	int i;
	printf("So Dinh: %d, So Canh: %d\n", g.soDinh, g.soCanh);
	for(i=0;i<g.soCanh;i++){
		printf("%d %d \n", g.dsCanh[i].dinhDau, g.dsCanh[i].dinhCuoi);
	}
}
//Hàm Duyệt sâu cây khung
void duyetSauCK(struct DoThi g, int v, struct DoThi *h){
	DaTham[v] = 1;
	int w, i;
	for(i=0;i<g.soCanh;i++){
		if(g.dsCanh[i].dinhDau==v){
			w = g.dsCanh[i].dinhCuoi;
		}else{
			if(g.dsCanh[i].dinhCuoi==v){
				w = g.dsCanh[i].dinhDau;
			}else{
				w = -1;
			}
		}
		if(w!=-1 && DaTham[w]==0){
			h->dsCanh[h->soCanh] = g.dsCanh[i];
			h->soCanh++;
			duyetSauCK(g, w, h);
		}
	}
}
//Cây khung đồ thị
struct DoThi caykhung(struct DoThi g)
{
	struct DoThi h;
	int i;
	h.soDinh = g.soDinh;
	h.soCanh = 0;
	for(i=0;i<g.soDinh;i++){
		DaTham[i] = 0;
		duyetSauCK(g, 0, &h);
	}
	return h;
}
//hàm main
int main(){
	struct DoThi g, h;
	docTep("caykhung.txt", &g);
	h = caykhung(g);
	inDoThi(h);
}
