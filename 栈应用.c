#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node
{
	int data;
	struct Node * pNext;
 } NODE,*PNODE;

typedef struct Stack
{
	PNODE pTop;
	PNODE pBottom;
 } STACK,*PSTACK;
 
 void init(PSTACK pS)
 {
 	pS->pTop = (PNODE)malloc(sizeof(NODE));
 	if(NULL==pS->pTop)
 	{
		 	printf("��̬�ڴ����ʧ��\n");
			exit(-1); 
 }
	 else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext=NULL;
		}	
 	//return 0;
 }
 void push(PSTACK pS,int val)
 {
 	PNODE pNew = (PNODE)malloc(sizeof(NODE)); //�����½���ָ�룬�͵��������½�� 
 	if(NULL==pNew)
 	{
		 	printf("��̬�ڴ����ʧ��\n");
			exit(-1);
	}
	 pNew->data = val;  //�½�㸳ֵ 
	 pNew->pNext = pS->pTop;//���ܸĳ�pS->pB ��ʹ�½���ָ����ָ��top��� 
	 pS->pTop = pNew;       //ʹpTopָ���½�� 
 	//return 0;
 }
 
 void trans(PSTACK pS)
 {
 	PNODE p = pS->pTop;
 	while(p != pS->pBottom)
 	{
 		printf("%d ",p->data);
 		p = p->pNext;
	 }
	 printf("\n");
	 return ;
  } 
bool empty(PSTACK pS)
  {
  	if(pS->pTop == pS ->pBottom)
  		return true;
  	else
	  return false;	
   } 
bool pop(PSTACK pS,int* pVal)
{
	if(empty(pS))
		return false;
	else
	{
		PNODE r = pS ->pTop;
		*pVal = r->data;
		pS->pTop = r->pNext;
		free(r);
		r=NULL;
		return true;
		}	
  }  
  
void clear(PSTACK pS)
{
	if(empty(pS))
	{
		return;
	}
	else
	{
		PNODE p = pS->pTop;
		PNODE q = NULL;
		while(p!=pS->pBottom)
		{
			q = p->pNext;
			free(p);
			p = q;
		}
		pS->pTop=pS->pBottom;
	}
  }  
  
 int main()
 {
 	STACK S;
 	int val;
 	
 	init(&S);
 	push(&S,1);
 	push(&S,2);
 	push(&S,3);
 	push(&S,5);
 	push(&S,9);
 	push(&S,4);
 	push(&S,7);
 	push(&S,20);
 	trans(&S);
 //	clear(&S);
 //	trans(&S);
 //	pop(&S,&val);
 
if(pop(&S,&val))
	 printf("��ջ�ɹ�������%d",val);
	 else
	 printf("youmaob");  
 	clear(&S);
 	trans(&S);	  
 	return 0;
 }
