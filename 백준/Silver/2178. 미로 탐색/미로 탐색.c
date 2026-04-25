#include <stdio.h>
#include <stdlib.h>
#define TRUE   1
#define FALSE   0

typedef struct{
    int xpos, ypos;
}Point;

typedef struct{
    Point Pos;
    int numofMove;
}POINT;

typedef POINT Data;

typedef struct _node
{
	Data data;
	struct _node * next;
} Node;

typedef struct _lQueue
{
	Node * front;
	Node * rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

int dx[] = {-1,0,1,0};
int dy[] = {0, 1, 0, -1};

char maze[104][104];
int visit[104][104];

int Iflag = FALSE;
int Fflag = FALSE;


int main (){
    int x,y;
    int nextx, nexty;
    for (int i=0;i<104;i++){
        for(int j=0;j<104;j++){
            maze[i][j] = '2';
        }
    }
    scanf("%d %d", &x, &y);
    for (int i = 0; i<x;i++){
        scanf("%s",&maze[i+1][1]);
        getchar();
    }
    POINT pos;
    pos.numofMove = 1;
    pos.Pos.xpos = 1; pos.Pos.ypos = 1;
    visit[1][1] = 1;
    Queue queue;
    QueueInit(&queue);
    POINT temp;
    temp = pos;
    Enqueue(&queue,pos);
    while(1){
        //printf("123\n");
        pos = Dequeue(&queue);
        if (pos.Pos.xpos == x && pos.Pos.ypos == y)
            break;
        for(int i=0;i<4;i++){
            //printf("123\n");
            temp = pos;
            nextx = temp.Pos.xpos + dx[i]; nexty = temp.Pos.ypos+dy[i];
            if((maze[nextx][nexty] == '1' && visit[nextx][nexty] == 0)){
                temp.Pos.xpos+=dx[i]; temp.Pos.ypos +=dy[i];
                temp.numofMove++;
                visit[temp.Pos.xpos][temp.Pos.ypos] = 1;
                Enqueue(&queue,temp);
            }
        }
    }
    printf("%d",pos.numofMove);
    return 0;
}



void QueueInit(Queue * pq)
{
	pq->front = NULL;
	pq->rear = NULL;
}

int QIsEmpty(Queue * pq)
{
	if(pq->front == NULL)
		return TRUE;
	else
		return FALSE;
}

void Enqueue(Queue * pq, Data data)
{
	Node * newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->data = data;

	if(QIsEmpty(pq))
	{
		pq->front = newNode;
		pq->rear = newNode;
	}
	else
	{
		pq->rear->next = newNode;
		pq->rear = newNode;
	}
}

Data Dequeue(Queue * pq)
{
	Node * delNode;
	Data retData;

	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	delNode = pq->front;
	retData = delNode->data;
	pq->front = pq->front->next;

	free(delNode);
	return retData;
}

Data QPeek(Queue * pq)
{
	if(QIsEmpty(pq))
	{
		printf("Queue Memory Error!");
		exit(-1);
	}

	return pq->front->data;
}
