//Cài đặt Kruskal cây khung lớn nhất
#include <stdio.h>
#define max 50

struct Canh{
	int dinhDau, dinhCuoi;
	int trongSo;
};
struct DoThi{
	int soDinh, soCanh;
	struct Canh dscanh[max];
};
int DaTham[max];
//Hàm đọc tệp dữ liệu
void docTep(char *tenTep, struct DoThi *k){
	FILE *f;
	int i, j, trong_so;
	f = fopen(tenTep, "r");
	fscanf(f, "%d", &k->soDinh);
	k->soCanh = 0;
	for(i=0;i<k->soDinh;i++){
		for(j=0;j<k->soDinh;j++){
			fscanf(f,"%d", &trong_so);
			if(trong_so!=0){
				k->dscanh[k->soCanh].dinhDau = i;
				k->dscanh[k->soCanh].dinhCuoi = j;
				k->dscanh[k->soCanh].trongSo = trong_so;
				k->soCanh++;
			}
		}
	}
	fclose(f);
}
//Hàm in
void inDoThi(struct DoThi k){
	int i;
	printf("So Dinh: %d va So Canh: %d\n", k.soDinh, k.soCanh);
	for(i=0;i<k.soCanh;i++){
		printf("(%d %d)->%d\n", k.dscanh[i].dinhDau, k.dscanh[i].dinhCuoi, k.dscanh[i].trongSo);
	}
}
//Hàm sort
void sort(struct DoThi *k){
	int i, j;
	struct Canh temp;
	for(i=0;i<k->soCanh;i++){
		for(j=i+1;j<k->soCanh;j++){
			if(k->dscanh[i].trongSo > k->dscanh[j].trongSo){
				temp = k->dscanh[i];
				k->dscanh[i] = k->dscanh[j];
				k->dscanh[j] = temp;
			}
		}
	}
}
//ghép thành phần liên thông
void ghepTPLT(int a, int b, int tp[], int n){
	int i;
	for(i=0;i<n;i++){
		if(tp[i]==b){
			tp[i] = a;
		}
	}
}
struct DoThi Kruskal(struct DoThi k){
	struct DoThi h;
	int l=0, i, dd, dc;
	int tp[k.soDinh];
	h.soDinh = k.soDinh;
	h.soCanh = 0;
	for(i=0;i<k.soDinh;i++){
		tp[i] = i;
	}
	sort(&k);
	while(h.soCanh < h.soDinh-1){
		dd = k.dscanh[l].dinhDau;
		dc = k.dscanh[l].dinhCuoi;
		if(tp[dd]!=tp[dc]){
			h.dscanh[h.soCanh] = k.dscanh[l];
			h.soCanh++;
			ghepTPLT(tp[dd], tp[dc], tp, k.soDinh);
		}l++;
	}
	return h;
}
int main(){
	struct DoThi g, h;
	docTep("kruskal.txt", &g);
	inDoThi(g);
	h = Kruskal(g);
	sort(&g);
	printf("cay khung sau khi duoc sap xep va cay khung co trong so ngan nhat la:\n");
	inDoThi(h);
	return 0;
}