#include <stdio.h>
#include <stdlib.h>
#define max 10

struct DSKe
{
	int dinhKe;
	struct DSKe *lienKet;
};
struct DoThi
{
	int soDinh;
	struct DSKe *dsKe[max];
};

int daTham[max], truoc[max];
//Ham them dinh j vao ds ke dinh i:
void them(int i, int j, struct DoThi *g)
{
	struct DSKe *p;
	p = (struct DSKe*)malloc(sizeof(struct DSKe));
	p->dinhKe = j;
	p->lienKet = g->dsKe[i];
	g->dsKe[i] = p;
}
//Ham doc tep du lieu do thi:
void docTep(char *tenTep, struct DoThi *g)
{
	FILE *f; int i,j, tg;
	f = fopen(tenTep,"r");
	fscanf(f,"%d",&g->soDinh);
	for(i=0;i<g->soDinh;i++) 
		g->dsKe[i] = NULL;
	for(i=0;i<g->soDinh;i++)
	{
		for(j=0;j<g->soDinh;j++)
		{
			fscanf(f,"%d",&tg);
			if(tg==1) 
				them(i,j,g);
		}
	}
	fclose(f);
}
//Ham in do thi dang ds ke:
void inDoThi(struct DoThi g)
{
	struct DSKe *p;
	printf("so dinh: %d \n", g.soDinh);
	printf("Cac ds ke:\n");
	for(int i=0;i<g.soDinh; i++)
	{
		printf("Danh sach ke dinh %d: ", i);
		p = g.dsKe[i];
		while (p != NULL)
		{
			printf("%d ", p->dinhKe);
			p = p->lienKet;
		}
		printf("\n");
	}
}
//Ham duyet do thi theo chieu sau tim duong di bang ds ke:
void duyetSau(struct DoThi g, int v)
{
	struct DSKe *p; int w;
	daTham[v]=1;
	p = g.dsKe[v];
	while (p != NULL)
	{
		w = p->dinhKe;
		if(daTham[w]==0)
		{
			truoc[w] = v;
			duyetSau(g,w);
		}
		p=p->lienKet;
	}
}
//Ham tim duong di xuat phat tu dinh s:
int duongDiS(struct DoThi g, int s)
{
	for(int i = 0; i < g.soDinh; i++) 
		daTham[i] = 0;
	duyetSau(g, s);
}
//b.Ham duyet do thi theo chieu rong tim duong di bang ds ke:
void duyetRong(struct DoThi g, int v)
{
	struct DSKe *p;
	int q[max], dau, cuoi, w;
	dau=0; cuoi=0; q[0]=v; daTham[v]=1;
	while(dau<=cuoi)
	{
		v=q[dau]; dau++;
		p=g.dsKe[v];
		while(p!=NULL)
		{
			w=p->dinhKe;
			if(daTham[w]==0)
			{
				truoc[w] = v;
				cuoi++;
				q[cuoi]=w;
				daTham[w]=1;
			}
			p=p->lienKet;
		}
	}
}
//Ham tim duong di xuat phat tu dinh s:
int duongDiR(struct DoThi g, int s)
{
	for(int i = 0; i < g.soDinh; i++) 
		daTham[i] = 0;
	duyetRong(g, s);
}
//Ham in duong di:
void inDD(int s, int d)
{
	int z;
	z = d;
	while (z != s)
	{
		printf("%d <= ", z);
		z = truoc[z];
	}
	printf("%d", s);
}

int main()
{
	struct DoThi g;
	int i = 5;
	docTep("dt1.txt", &g);
	inDoThi(g);
	duyetSau(g, 0);
	duongDiS(g, 0);
	
//	if(daTham[i]==1)
//	{
//		printf("\nDuyet duong di theo chieu sau: ");
//		inDD(0, 1);
//	}
//	else
//		printf("Khong tim thay dinh can duyet.");
		
	//b.
	duyetRong(g, 0);
	duongDiR(g, 0);
	if(daTham[i]==1)
	{
		printf("\nDuyet duong di theo chieu rong: ");
		inDD(0, 2);
	}
	else
		printf("Khong tim thay dinh can duyet.");
}
