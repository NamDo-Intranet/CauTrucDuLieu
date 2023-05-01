#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Nguoi{
	char hoten[20];
	int namSinh;
};
struct cayTQ{
	struct Nguoi dulieu;
	struct cayTQ *con, *em;
};
struct cayTQ *taoNut(struct cayTQ *bcon, struct cayTQ *bem,  struct Nguoi X){
	struct cayTQ *p;
	p = (struct cayTQ *)malloc(sizeof(struct cayTQ));
	p->dulieu = X;
	p->con = bcon;
	p->em = bem;
	return p;
}
struct cayTQ *taoCay(){
	struct Nguoi ng1, ng2, ng3, ng4, ng5, ng6, ng7, ng8;
	struct cayTQ *n1, *n2, *n3, *n4, *n5, *n6, *n7, *n8;
	strcpy(ng1.hoten, "Nguyen F");
	ng1.namSinh = 1965;
	n1 = taoNut(NULL, NULL, ng1);
	strcpy(ng2.hoten, "Nguyen E");
	ng2.namSinh = 1960;
	n2 = taoNut(NULL, n1, ng2);
	strcpy(ng3.hoten, "Nguyen D");
	ng3.namSinh = 1955;
	n3 = taoNut(NULL, n2, ng3);
	
	strcpy(ng4.hoten, "Nguyen H");
	ng4.namSinh = 1970;
	n4 = taoNut(NULL, NULL, ng4);
	strcpy(ng5.hoten, "Nguyen G");
	ng5.namSinh = 1965;
	n5 = taoNut(NULL, n4, ng5);
	
	strcpy(ng6.hoten, "Nguyen C");
	ng6.namSinh = 1935;
	n6 = taoNut(n5, NULL, ng6);
	strcpy(ng7.hoten, "Nguyen B");
	ng7.namSinh = 1930;
	n7 = taoNut(n3, n6, ng7);
	strcpy(ng8.hoten, "Nguyen A");
	ng8.namSinh = 1900;
	n8 = taoNut(n7, NULL, ng8);
	return n8;
}
//In cay gia pha theo thu tu the he (chieu rong)
void inBFS(struct cayTQ *goc){
	struct cayTQ *q[100], *p;
	int dau, cuoi;
	if(goc!=NULL){
		dau = 0;
		cuoi = 0;
		q[0] = goc;
		while(dau<=cuoi){
			p = q[dau];
			printf("\t%s \t %d\n", p->dulieu.hoten, p->dulieu.namSinh);
			dau++;			
			p = p->con;
			while(p!=NULL){
				cuoi++;
				q[cuoi] = p;
				p = p->em;				
			}
		}
	}
}
//Dem so nguoi co trong cay gia pha
int demNguoi(struct cayTQ *goc){
	struct cayTQ *p;
	p = goc;
	int dem = 0, h1=0, h2=0;
	if(p!=NULL){
		h1 = demNguoi(p->con);
		h2 = demNguoi(p->em);
		dem = h1 + h2;
	}else{
		return 0;
	}
	return dem + 1;
}
//Tinh so the he cua cay gia pha
int tinhSTH(struct cayTQ *goc){
	struct cayTQ *p = goc;
	int max= 0, left, right;
	if(p==NULL){
		return 0;
	}else{
		p = goc->con;
		left = tinhSTH(p);
		if(max<left){
			max = left;
		}
		while(p!=NULL){
			p = p->em;
			right = tinhSTH(p);
			if(max < right){
				max = right;
			}
		}
	}
	max++;
	return max;
}
//Tim xem mot nguoi co ho ten X trong cay gia pha khong?
struct cayTQ *timhoTen(struct cayTQ *goc, char *x){
	struct cayTQ *p, *kq;
	p = (struct cayTQ*)(malloc(sizeof(struct cayTQ)));
	if(goc==NULL){
		return NULL;
	}else{
		if(strcmp(goc->dulieu.hoten, x)==0){
			return goc;
		}else{
			p = goc->con;			
			while(p!=NULL){
				kq = timhoTen(p, x);
				if(kq!=NULL){
					return kq;
				}else{
					p = p->em;
				}
			}return NULL;
		}
	}
}
//Kiem tra xem nguoi ten y co phai con cua nguoi ten x trong cay gia pha khong?
int ktConXY(struct cayTQ *goc, char *x, char *y)
{
	struct cayTQ *p, *q, *k;
	p = timhoTen(goc, x);
	if (p==NULL)
		return 0;
	else
	{
		q = p->con;
		while(q!=NULL)
		{
			k = timhoTen(q, y);
			if(k==NULL)
				return 1;
			else
				q=q->em;
		}
		return 0;
	}
}

//7. Them q la con cua x
void themCon(struct cayTQ *goc, char ch[], Nguoi c)
{
	struct cayTQ *r, *p, *q, *t, *p1;
	r = timhoTen(goc, ch);
	if(r==NULL)
		printf("Khong co nguoi %s nen khong the them.", ch);
	else
	{
		q = taoNut(NULL, NULL, c);
		p = r->con;
		if(p==NULL)
			r->con=q;
		else
		{
			if(p->dulieu.namSinh > c.namSinh)
			{
				r->con = q;
				q->em = p;
				return;
			}
			while(p!=NULL)
			{
				if(p->dulieu.namSinh <= c.namSinh)
				{
					p1=p;
					p=p->em;
				}
				else
					break;
			}
			p1->em=q;
			q->em=p;
		}
	}
}
int main(){
	struct cayTQ *goc = NULL;
	char htX[20] = "Nguyen A";
	char htY[20] = "Nguyen C";
	goc = taoCay();
	printf("Cay Gia Pha nha ho Nguyen\n");
	inBFS(goc);
	int demsoNguoi = demNguoi(goc);
	printf("So nguoi co trong cay gia pha la: %d", demsoNguoi);
	printf("\n");
	int sothehecay = tinhSTH(goc);
	printf("So the he cua cay gia pha la: %d", sothehecay);
	printf("\n");
	
	
	struct cayTQ *timht = timhoTen(goc, htX);
	if(timht!=NULL){
		printf("Da tim thay %s trong cay gia pha", htX);
	}else{
		printf("Khong tim thay %s trong cay gia pha!", htX);
	}
	
	printf("\n");
	int kiemtra = ktConXY(goc, htX, htY);
	printf("Y co phai la con cua nguoi ten X khong : %d", kiemtra);
	printf("\n");
	
	printf("Danh sach sau khi them con vao la: \n");
	char ht[] = "Nguyen B";
	struct Nguoi con;
	strcpy(con.hoten, "Nguyen I");
	con.namSinh = 1976;
	themCon(goc, ht, con);
	inBFS(goc);
	
	return 0;
}