#include <stdio.h>
typedef struct LNode
	{
		int data;/*链表数据*/
		struct LNode* next;	/*链表指针*/
	}LNode,*LinkList;
LinkList HeadCreate(LinkList la)
	{
		int num;/*用来装线性链表的数据的*/
		la=(LinkList)malloc(sizeof(LNode));/*建立头结点,但只有头结点，其他的只要用指针指向就行了*/										
		la->next=NULL;/*初始化头结点*/
		printf("请连续输入数据，输入5000即为停止\n");
		scanf("%d",&num);/*输入数据*/
		while(num!=5000)/*输入5000就停止往表里面输入数据*/
		{
			LNode *p=(LinkList)malloc(sizeof(LNode));/*实时指针，作为每一个数据的指针域*/
			p->data=num;/*赋值数据*/
			p->next=la->next;/*赋值指针域*/
			la->next=p;/*移动指针，为下一个指针域做准备*/
			scanf("%d",&num);/*再次输入数据*/
		}
		return la;
	}/*头插法是确定了第一个后在后面进行插入，第一个创建的指针域是NULL，这也就可以用来确定表长*/
void TravelList(LinkList la)/*这是输出函数*/
	{
		LinkList p=la->next;/*这个是第一个数据结点*/
		while(p!=NULL)/*直到最后一个数据域为0，指针域为null，因此是输入的倒序输出*/
		{
			printf("%d->",p->data);
			p=p->next;
		}/*遍历行为*/
		printf("\n");
	}
int LengthList(LinkList la)/*单链表的表长*/
{
	int nLen=0;/*初始化长度*/
	LinkList p=la->next;
	while(p)
	{
		p=p->next;
		nLen++;
	}/*遍历*/
	return nLen;
}
LinkList GetElem(LinkList la,int i)/*单链表的按位查找*/
{
	int j=1;
	LNode* p=la->next;
	if(i<1)
		return NULL;
	while(p && j<i)/*当p非零并且j<i，这个时候才继续循环*//*这个的意思是p和j<i*/
	{
		p=p->next;
		j++;
	}/*条件为位置的按位遍历*/
	return p->data;
}
LinkList LocalElem(LinkList la,int e)/*单链表的按值查找*/
{
	int j=0;
	LNode* p=la->next;
	while(p!=NULL && p->data!=e)
		{
			p=p->next;
			j=j+1;
		}/*条件为值的按位遍历*/
	j=j+1;
	return j;
}
int InsertList(LinkList la,int i,int e)/*单链表插入操作*/
{
	//在la链表中的i位置插入数值e
	int j=1;
	LinkList p=la,s;
	while(p && j<i)
	{
		p=p->next;
		j++;
	}/*条件为位置的按位遍历*/
	if(p==NULL)/*错误条件1*/
		return 0;
	if((s=(LinkList)malloc(sizeof(LNode)))==NULL)/*错误条件2*/
		return 0;
	s->data=e;
	s->next=p->next;
	p->next=s;/*用中间值进行转换*/
	return 1;
}
int DeleteList(LinkList la,int i)/*单链表删除操作*/
{
	int j=1;
	LinkList p=la,q;
	while(p && j<i)	/*p指向第i-1个元素*/
	{
		p=p->next;
		j++;
	}/*条件为位置的按位遍历*/
	if(p==NULL || p->next==NULL)/*错误条件1*//*表示不存在第i-1个和第i的元素*/
		return 0;
	q=p->next;
	p->next=q->next;/*一个来承载值，后一个替代他，因为不是顺序，所以不用循环*/
	free(q);/*释放空间*/
	return 1;
}
int main()
{
	int t,a,b,e,c,d,f;/*t用来确定行为是否成功，a是用来确定表长的，b是用来确定按值查找的那个值所在的位置的，e是用来确定选择结构的,c是用来确定各种位置的，d是用来确定各种值的*/
	LNode la;/*定义头结点*/
	LinkList p;/*定义表结点的*/
	p=HeadCreate(&la);//头插法创建单链表
	while(1)
	{
		printf("请输入你要选择的模式\n");
		printf("1查询模式\n");
		printf("2插入模式\n");
		printf("3删除模式\n");
		printf("4.终止程序\n");
		scanf("%d",&f);/*输入选项*/	
		if(f==4)
			return 0;
		printf("请问是否需要创建结果（输入1是需要，不需要请输入任意除1外数字）\n");
		scanf("%d",&e);
		if(e==1)
		{
			TravelList(p);
		}		
		if(f==1)
		{
			a=LengthList(p);
			printf("需要按位查找请输入1，需要按值查找请输入2：\n");
			scanf("%d",&e);
			if(e==1)
			{
				printf("请输入需要查找的位置：\n");
				scanf("%d",&c);
				printf("这里的数据为%d\n",GetElem(p,a-c+1));//获得第c个结点地址,即为最后一个输入的数据
			}
			if(e==2)
			{
				printf("请输入需要查找的值：\n");
				scanf("%d",&d);
				b=LocalElem(p,d);
				printf("这个值的位置为%d\n",a-b+1);/*获得数值d的位置在哪*/
			}
		}
		if(f==2)
		{
			a=LengthList(p);
			printf("请按序输入需要插入的值的位置和值：\n");
			scanf("%d%d",&c,&d);
			t=InsertList(p,a-c+2,d);/*在链表的倒数第c个位置插入元素d*/
			if(t==0)
			{
				printf("插入失败");
			}
			printf("请问是否需要创建结果（输入1是需要，不需要请输入任意除1外数字）\n");
			scanf("%d",&e);
			if(e==1)
			{
				TravelList(p);
			}		
		}
		if(f==3)
		{
			a=LengthList(p);
			printf("请输入需要删除的值的位置：\n");
			scanf("%d",&c);
			t=DeleteList(p,a-c+1);/*删除链表的第c个元素*/
			if(t==0)
			{
				printf("删除失败");
			}
			printf("请问是否需要创建结果（输入1是需要，不需要请输入任意除1外数字）\n");
			scanf("%d",&e);
			if(e==1)
			{
				TravelList(p);
			}	
		}
	}
	return 0;
}