#include <stdio.h>
typedef struct LNode
	{
		int data;/*��������*/
		struct LNode* next;	/*����ָ��*/
	}LNode,*LinkList;
LinkList HeadCreate(LinkList la)
	{
		int num;/*����װ������������ݵ�*/
		la=(LinkList)malloc(sizeof(LNode));/*����ͷ���,��ֻ��ͷ��㣬������ֻҪ��ָ��ָ�������*/										
		la->next=NULL;/*��ʼ��ͷ���*/
		printf("�������������ݣ�����5000��Ϊֹͣ\n");
		scanf("%d",&num);/*��������*/
		while(num!=5000)/*����5000��ֹͣ����������������*/
		{
			LNode *p=(LinkList)malloc(sizeof(LNode));/*ʵʱָ�룬��Ϊÿһ�����ݵ�ָ����*/
			p->data=num;/*��ֵ����*/
			p->next=la->next;/*��ֵָ����*/
			la->next=p;/*�ƶ�ָ�룬Ϊ��һ��ָ������׼��*/
			scanf("%d",&num);/*�ٴ���������*/
		}
		return la;
	}/*ͷ�巨��ȷ���˵�һ�����ں�����в��룬��һ��������ָ������NULL����Ҳ�Ϳ�������ȷ����*/
void TravelList(LinkList la)/*�����������*/
	{
		LinkList p=la->next;/*����ǵ�һ�����ݽ��*/
		while(p!=NULL)/*ֱ�����һ��������Ϊ0��ָ����Ϊnull�����������ĵ������*/
		{
			printf("%d->",p->data);
			p=p->next;
		}/*������Ϊ*/
		printf("\n");
	}
int LengthList(LinkList la)/*������ı�*/
{
	int nLen=0;/*��ʼ������*/
	LinkList p=la->next;
	while(p)
	{
		p=p->next;
		nLen++;
	}/*����*/
	return nLen;
}
LinkList GetElem(LinkList la,int i)/*������İ�λ����*/
{
	int j=1;
	LNode* p=la->next;
	if(i<1)
		return NULL;
	while(p && j<i)/*��p���㲢��j<i�����ʱ��ż���ѭ��*//*�������˼��p��j<i*/
	{
		p=p->next;
		j++;
	}/*����Ϊλ�õİ�λ����*/
	return p->data;
}
LinkList LocalElem(LinkList la,int e)/*������İ�ֵ����*/
{
	int j=0;
	LNode* p=la->next;
	while(p!=NULL && p->data!=e)
		{
			p=p->next;
			j=j+1;
		}/*����Ϊֵ�İ�λ����*/
	j=j+1;
	return j;
}
int InsertList(LinkList la,int i,int e)/*������������*/
{
	//��la�����е�iλ�ò�����ֵe
	int j=1;
	LinkList p=la,s;
	while(p && j<i)
	{
		p=p->next;
		j++;
	}/*����Ϊλ�õİ�λ����*/
	if(p==NULL)/*��������1*/
		return 0;
	if((s=(LinkList)malloc(sizeof(LNode)))==NULL)/*��������2*/
		return 0;
	s->data=e;
	s->next=p->next;
	p->next=s;/*���м�ֵ����ת��*/
	return 1;
}
int DeleteList(LinkList la,int i)/*������ɾ������*/
{
	int j=1;
	LinkList p=la,q;
	while(p && j<i)	/*pָ���i-1��Ԫ��*/
	{
		p=p->next;
		j++;
	}/*����Ϊλ�õİ�λ����*/
	if(p==NULL || p->next==NULL)/*��������1*//*��ʾ�����ڵ�i-1���͵�i��Ԫ��*/
		return 0;
	q=p->next;
	p->next=q->next;/*һ��������ֵ����һ�����������Ϊ����˳�����Բ���ѭ��*/
	free(q);/*�ͷſռ�*/
	return 1;
}
int main()
{
	int t,a,b,e,c,d,f;/*t����ȷ����Ϊ�Ƿ�ɹ���a������ȷ�����ģ�b������ȷ����ֵ���ҵ��Ǹ�ֵ���ڵ�λ�õģ�e������ȷ��ѡ��ṹ��,c������ȷ������λ�õģ�d������ȷ������ֵ��*/
	LNode la;/*����ͷ���*/
	LinkList p;/*��������*/
	p=HeadCreate(&la);//ͷ�巨����������
	while(1)
	{
		printf("��������Ҫѡ���ģʽ\n");
		printf("1��ѯģʽ\n");
		printf("2����ģʽ\n");
		printf("3ɾ��ģʽ\n");
		printf("4.��ֹ����\n");
		scanf("%d",&f);/*����ѡ��*/	
		if(f==4)
			return 0;
		printf("�����Ƿ���Ҫ�������������1����Ҫ������Ҫ�����������1�����֣�\n");
		scanf("%d",&e);
		if(e==1)
		{
			TravelList(p);
		}		
		if(f==1)
		{
			a=LengthList(p);
			printf("��Ҫ��λ����������1����Ҫ��ֵ����������2��\n");
			scanf("%d",&e);
			if(e==1)
			{
				printf("��������Ҫ���ҵ�λ�ã�\n");
				scanf("%d",&c);
				printf("���������Ϊ%d\n",GetElem(p,a-c+1));//��õ�c������ַ,��Ϊ���һ�����������
			}
			if(e==2)
			{
				printf("��������Ҫ���ҵ�ֵ��\n");
				scanf("%d",&d);
				b=LocalElem(p,d);
				printf("���ֵ��λ��Ϊ%d\n",a-b+1);/*�����ֵd��λ������*/
			}
		}
		if(f==2)
		{
			a=LengthList(p);
			printf("�밴��������Ҫ�����ֵ��λ�ú�ֵ��\n");
			scanf("%d%d",&c,&d);
			t=InsertList(p,a-c+2,d);/*������ĵ�����c��λ�ò���Ԫ��d*/
			if(t==0)
			{
				printf("����ʧ��");
			}
			printf("�����Ƿ���Ҫ�������������1����Ҫ������Ҫ�����������1�����֣�\n");
			scanf("%d",&e);
			if(e==1)
			{
				TravelList(p);
			}		
		}
		if(f==3)
		{
			a=LengthList(p);
			printf("��������Ҫɾ����ֵ��λ�ã�\n");
			scanf("%d",&c);
			t=DeleteList(p,a-c+1);/*ɾ������ĵ�c��Ԫ��*/
			if(t==0)
			{
				printf("ɾ��ʧ��");
			}
			printf("�����Ƿ���Ҫ�������������1����Ҫ������Ҫ�����������1�����֣�\n");
			scanf("%d",&e);
			if(e==1)
			{
				TravelList(p);
			}	
		}
	}
	return 0;
}