#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
typedef struct Queue
{
	int *pBase;
	int front;
	int rear;
}QUEUE; 

void init(QUEUE *pQ)
{
	pQ->pBase = (int *)malloc(sizeof(int)*6);
	pQ->front = 0;
	pQ->rear = 0;
	
}

bool full_queue(QUEUE *pQ)
{
	if((pQ->rear + 1) % 6 == pQ->front)
	return true;
	else
	return false;
	
}
bool empty_queue(QUEUE *pQ)
{
	if(pQ->front == pQ->rear)
	return true;
	else
	return false; 
}

bool out_queue(QUEUE *pQ,int * pVal)
{
	if(empty_queue(pQ))
	{
		return false;		
	}
	else
	{
		*pVal = pQ->pBase[pQ->front];
		pQ->front =( pQ->front + 1)%6;
		return true;
	}
}

bool en_queue(QUEUE *pQ,int val)
{
	if(full_queue(pQ) )
	{
		return false;
	 } 
	else
	{
		pQ->pBase[pQ->rear]=val;
		pQ->rear = (pQ->rear + 1) % 6;
	}
}
void traverse_queue(QUEUE *pQ)
{
	int i = pQ->front;
	while(i!=pQ->rear )
	{
		printf("%d\n",pQ->pBase[i]);
		i  = (i+1)%6;
	}
	return 0;
 } 
int main()
{
	QUEUE Q;
	int val;
	init(&Q);
	en_queue(&Q,1);
	en_queue(&Q,2);
	en_queue(&Q,3);
	en_queue(&Q,4);
	en_queue(&Q,5);
	en_queue(&Q,6);
	en_queue(&Q,7);
	en_queue(&Q,8);
	full_queue(&Q);
	traverse_queue(&Q);
	//out_queue(&Q,&val);
	//printf("%d\n",val);
	if(out_queue(&Q,&val))
	printf("%d\n",val);
	//traverse_queue(&Q);
//	printf("%d\n",val);
	
	
	return 0;
 } 
