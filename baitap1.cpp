#include<conio.h>
#include<stdio.h>
#include<string.h>

struct SinhVien
{
	char MaSV[10];
	char TenSV[30];
	char TenMon[30];
	float Diem;
};

struct Node
{
	SinhVien info;
	Node *pNext;
};
struct List
{
	Node*pHead;
	Node*pTail;
};
void Init(List &l)
{
	l.pHead = l.pTail = NULL;
}
Node* GetNode(SinhVien sv)
{
	Node *n=new Node;
	n->info=sv;
	n->pNext=NULL;
	return n;
}

void AddSV(List &l,SinhVien sv)
{
	Node *p;
	if(l.pHead==NULL)
		l.pHead= GetNode(sv);
	else
	{
		p=l.pHead;
		while(p->pNext!=NULL)
			p=p->pNext;
			p->pNext=GetNode(sv);
	}
}
//them dau 
void AddHead(List &l, SinhVien sv)
{
	Node* p;
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p; 
	}
	else
	{
		p ->pNext = l.pHead; 
		l.pHead = p; 
	}
}
//them cuoi
void AddTail(List &l, Node*p)
{
	if(l.pHead == NULL)
	{
		l.pHead = l.pTail = p;
	}
	else
	{
		l.pTail ->pNext = p; 
		l.pTail = p; 
	}
}
//nhap danh sach
void InPutSV(List &l)
{
	int i,n;
	SinhVien sv;
	Node *p;
	printf(" Nhap so luong sinh vien :");
	scanf("%d",&n);
	fflush(stdin);

	for(i=0;i<n;i++)
	{
		printf(" Nhap ma sinh vien :");
		gets(sv.MaSV);
		printf(" Nhap ten sinh vien :");
		gets(sv.TenSV);
		printf(" Nhap ten mon :");
		scanf("%s",&sv.TenMon);
		fflush(stdin);
		printf(" nhap diem :");
		scanf("%f",&sv.Diem);
		fflush(stdin);
		AddSV(l,sv);
	}	
}
//xuat danh sach
void OutPutSV(List &l)
{
	Node* p;
	p=l.pHead;
	while(p!=NULL)
	{
 		printf(" %s %s %s %f \n",p->info.MaSV,p->info.TenSV,p->info.TenMon,p->info.Diem);
		p=p->pNext;
	}
}
//xuat sv
void OutSV(SinhVien sv)
{
		printf(" %s %s %s %f \n",sv.MaSV,sv.TenSV,sv.TenMon,sv.Diem);
}
//tim sv co diem lon nhat 
void DiemMax (List &l)
{
    Node *p,*max;
    p=l.pHead;
    max=p;
    while (p->pNext !=NULL)
    {
    	p=p->pNext;
        if(p->info.Diem > max->info.Diem) 
		{ 
			max=p; 
		}
		
        
    }
    printf("\nSV co diem cao nhat la: \n");  
	OutSV(max->info);
}
//tim diem min
void DiemMin (List &l)
{
    Node *p,*min;
    p=l.pHead;
    min=p;
    while (p->pNext !=NULL)
    {
    	p=p->pNext;
        if(p->info.Diem < min->info.Diem) 
		{ 
			min=p; 
		}
		
        
    }
    printf("\nSV co diem thap nhat la: \n");  
	OutSV(min->info);
}

//hoan vi
void Waps(SinhVien &sv1,SinhVien &sv2)
{
	SinhVien t=sv1;
	sv1=sv2;
	sv2=t;
}
//thuat toan sap xep
void InchrChangeSort(List &l)
{
	for(Node* p=l.pHead;p;p=p->pNext)
		for(Node*q=p->pNext;q;q=q->pNext)
			if(p->info.Diem > q->info.Diem)
				Waps(p->info,q->info);
}
void selectionsort (List &l)
{
    Node *p,*q,*min;
    p=l.pHead;
    SinhVien sv;
    while (p!=l.pTail)
    {
        min=p;
        q=p->pNext;
        while (q!=NULL)
        {
            if(q->info.Diem<min->info.Diem)  
			min=q;
            q=q->pNext;
        }
        Waps(p->info,min->info);
    }
}
void QuickSort(List &l)
{
	List l1,l2;
	Node*p,*q,*x;
	p=l.pHead;
	q=l.pTail;
	SinhVien sv;
	if(q->info.Diem==q->info.Diem) return;
	Init(l1);Init(l2);
	x=l.pHead;
	l.pHead=l.pHead->pNext;
	x->pNext=NULL;
	while( l.pHead!= NULL )
	{
  		p = l.pHead;
  		l.pHead = l.pHead->pNext;
 		p->pNext = NULL;
 		if(p->info.Diem <= x->info.Diem ) 
		 	AddHead(l1,p->info);
 		else AddHead(l2,p->info);
 }
 QuickSort(l1); 
 if(l1.pHead != NULL )
 { 
  	l.pHead = l1.pHead; 
  	l1.pTail->pNext = x;
 }
 else 
 	{
 	l.pHead = x;
 	x->pNext = l2.pHead;
	}
 if(l2.pHead!= NULL )
  	l.pTail = l2.pTail;
 else l.pTail = x;
}

int main()
{
	List l;
	InPutSV(l);
	printf("danh sach sinh vien vua nhap: \n");
	OutPutSV(l);
	DiemMax(l);
	DiemMin(l);
	InchrChangeSort(l);
	printf("danh sach sinh vien sau khi sap xep\n ");
	OutPutSV(l);
	selectionsort (l);
	QuickSort(l);
	printf("danh sach sinh vien sau khi sap xep\n ");
	OutPutSV(l);
}



