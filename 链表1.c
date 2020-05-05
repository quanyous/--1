#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>
//  int *p = (int *)malloc(100)  ʹ�����p�ľ�̬�ڴ���ʧ����̬�ڴ滹����
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
		printf("����Ϊ�գ�");
	else
		printf("�����գ�");
	len = length(pHead);
	printf("����%d�����\n",len);
	sort(pHead);
	trans(pHead);
		
	return 0; 
 	
 }
PNODE  createlist(void)
{
	int len;
	int i;
	int val;
	printf("����������ĳ��ȣ�");
	scanf("%d",&len);
	PNODE pHead = (PNODE)malloc(sizeof(NODE));
	if (pHead == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	 } 
	PNODE pTail = pHead;
	if (pTail == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	 }
	pTail -> pNext = NULL;
	for(i = 0;i<len;i++)
	{
		printf("�������%d��ֵ��",i+1);
		scanf("%d",&val);
		PNODE pNew = (PNODE)malloc(sizeof(NODE));
			if (pTail == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);
	 }
		pNew -> data = val;//�½�һ����㣬��pNewָ�� 
		pTail -> pNext = pNew;//�����������pTailָ����ĺ��� 
		pNew -> pNext = NULL;//��ʼ���Ͻ���ָ���Ա 
		pTail = pNew; //pTailʼ��ָ��β��� 
		
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
