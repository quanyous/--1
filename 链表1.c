#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
//  int *p = (int *)malloc(100)  使用完后，p的静态内存消失，动态内存还存在
typedef struct Node
{
	int data;
	struct Node * pNext; 
 } *PNODE,NODE;
 
 void trans(PNODE);
 PNODE  createlist(void);
 bool is_empty(PNODE);
 int length(PNODE);
 void sort(PNODE);
 
 int main()
 {
 	int len=0;
 	PNODE pHead = NULL;
	pHead = createlist();
	trans(pHead);
	if(is_empty(pHead))
		printf("链表为空！");
	else
		printf("链表不空！");
	len = length(pHead);
	printf("共有%d个结点\n",len);
	sort(pHead);
	trans(pHead);
		
	return 0; 
 	
 }
PNODE  createlist(void)
{
	int len;
	int i;
	int val;
	printf("请输入链表的长度：");
	scanf("%d",&len);
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
	{
		printf("分配内存失败\n");
		exit(-1);
	 } 
	PNODE pTail = pHead;
	if (pTail == NULL)
	{
		printf("分配内存失败\n");
		exit(-1);
	 }
	pTail -> pNext = NULL;
	for(i = 0;i<len;i++)
	{
		printf("请输入第%d个值：",i+1);
		scanf("%d",&val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
			if (pTail == NULL)
	{
		printf("分配内存失败\n");
		exit(-1);
	 }
		pNew -> data = val;//新建一个结点，由pNew指向 
		pTail -> pNext = pNew;//把上面结点挂在pTail指向结点的后面 
		pNew -> pNext = NULL;//初始化上结点的指针成员 
		pTail = pNew; //pTail始终指向尾结点 
		
	}
	return pHead;
}
void trans(PNODE pHead)
{
	PNODE p = pHead ->pNext;
	while(p != NULL)
	{
		printf("%d\n",p->data);
		p = p->pNext;
	}
	return 0;
}
bool is_empty(PNODE pHead)
{
	if(pHead ->pNext == NULL)
		return 1;
	else
		return 0;	
}
int length(PNODE pHead)
{
	int len = 0;
	PNODE p = pHead ->pNext;
	while(p!=NULL)
	{
		len++;
		p = p ->pNext;
	}
	return len;
 } 
void sort(PNODE pHead)
{
	int i,j,t;
	int len = length(pHead);
	PNODE p,q;
	for(i=0,p=pHead->pNext; i<len-1; i++,p = p->pNext)
	{
		for(j=1,q=p->pNext; j<len; j++,q=q->pNext)
		{
			if(p->data > q->data)
			{
				t = q->data;
				q->data = p->data;
				p->data = t; 
			}
		}
	}
	return 0;
	
}
void insert(PNODE pHead,int cha)
{
	int i;
	PNODE p = pHead->pNext;
	for(i=1;i<cha;i++)
	{
		p = p->pNext;
		
	}
	
}
