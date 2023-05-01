#include <stdio.h>
#define max 50
struct canh{
	int dinhDau, dinhCuoi;
};
struct DoThi{
	int soDinh, soCanh;
	struct canh dsCanh[max];
};
int DaTham[max];
void docTep(char *tenTep, struct DoThi *k){
	FILE *f;
	int i, j, tg;
	f = fopen(tenTep, "r");
	fscanf(f, "%d", &k->soDinh);
	k->soCanh = 0;
	for(i=0;i<k->soDinh;i++){
		for(j=0;j<k->soDinh;k++){
			fscanf(f, "%d", &tg);
			if(tg==1){
				k->dsCanh[k->soCanh].dinhDau = i;
				k->dsCanh[k->soCanh].dinhCuoi = j;
				k->soCanh++;
			}
		}
	}
	fclose(f);
}
void inDoThi(struct DoThi k){
	int i;
	printf("So Dinh %d So Canh %d\n", k.soDinh, k.soCanh);
	for(i=0;i<k.soCanh;i++){
		printf("%d %d\n", k.dsCanh[i].dinhDau, k.dsCanh[i].dinhCuoi);
	}
}
void duyetsau(struct DoThi k, int v, struct DoThi *h){
	int i, w;
	DaTham[v] = 1;
	for(i=0;i<k.soCanh;i++){
		if(k.dsCanh[i].dinhDau==v){
			w = k.dsCanh[i].dinhCuoi;
		}else{
			if(k.dsCanh[i].dinhCuoi==v){
				w = k.dsCanh[i].dinhDau;
			}else{
				w = -1;
			}
		}
		if(w!=-1 && DaTham[w]==0){
			h->dsCanh[h->soCanh] = k.dsCanh[i];
			h->soCanh++;
			duyetsau(k, w, h);
		}
	}
}
struct DoThi CayKhung(struct DoThi k){
	struct DoThi h;
	int i;
	h.soDinh = k.soDinh;
	h.soCanh = 0;
	for(i=0;i<k.soDinh;i++){
		DaTham[i] = 0;
	}
	duyetsau(k, 0, &h);
	return h;
}
int main(){
	struct DoThi k, h;
	docTep("caykhung.txt", &k);
	inDoThi(k);
	h = CayKhung(k);
	inDoThi(h);
	return 0;
}