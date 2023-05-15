#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_QUEUE_SIZE 100
typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
}DequeType;

void error(char* message);
void init_deque(DequeType* q);
int is_empty(DequeType* q);
int is_full(DequeType* q);
void deque_print(DequeType* q);

void add_rear(DequeType* q, element item);
element delete_rear(DequeType* q);
element get_rear(DequeType* q);

void add_front(DequeType* q, element val);
element delete_front(DequeType* q);
element get_front(DequeType* q);

int is_pal(char string[]);



int main(void)
{
	char answer = 0;
	while (1)
	{
		if(answer == 78)
		{
			exit(0);
		}
		char myString[MAX_QUEUE_SIZE] = { NULL };
		printf("문자열을 입력하시오 : ");
		gets_s(myString, sizeof(myString));
		if (is_pal(myString) == 1)
		{
			printf("회문입니다.\n");
		}
		else printf("회문이 아닙니다.\n");
		printf("\n");
		printf("계속 하시겠습니까? (Y / N): ");
		scanf("%s", &answer);
		printf("\n");
		getchar();
		
	}
	//gets_s(myString, sizeof(myString));
	/*do
	{
		char myString[MAX_QUEUE_SIZE] = { NULL };
		printf("문자열을 입력하시오 : ");
		gets_s(myString, sizeof(myString));
		if (is_pal(myString) == 1)
		{
			printf("회문입니다.\n");
		}
		else printf("회문이 아닙니다.\n");
		printf("\n");
		printf("계속 하시겠습니까? (Y / N): ");
		scanf("%c", &answer);
		printf("\n");

		gets_s(myString, sizeof(myString));
	} while (answer == 89);
	*/
	return  0;
}

int is_pal(char string[])
{
	DequeType* q;
	init_deque(&q);
	int i = 0;
	while (string[i] != '\0')
	{
		if ('33' <= string[i] && string[i] <= '47')
		{
			continue;
		}
		if ('a' <= string[i] && string[i] <= 'z')
		{
			if (is_full(&q))
			{
				printf("큐가 가득 찼습니다.\n");
				return 0;
			}
			add_front(&q, string[i]);
			
		}
		if ('A' <= string[i] && string[i] <= 'Z')
		{
			if (is_full(&q))
			{
				printf("큐가 가득 찼습니다.\n");
				return 0;
			}
			char x = string[i] + ('a' - 'A');
			add_front(&q, x);
		}
		i++;
	}

	i = 0;
	
	while (!is_empty(&q))
	{

		if (get_front(&q) != get_rear(&q))
		{
			return 0;
		}
		else return 1;
		
	}
	return 1;
}


void error(char* message) //오류함수
{
	fprintf(stderr, "%s\n", message);
	exit(1);
}

void init_deque(DequeType* q) //초기화 함수
{
	q->front = q->rear = 0;
}

int is_empty(DequeType* q)//공백 상태 검출 함수
{
	return (q->front == q->rear);
}

int is_full(DequeType* q)//포화 상태 검출 함수
{
	return((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void deque_print(DequeType* q)//원형큐 출력함수
{
	printf("DEQUE(front=%d rear =%d) = ", q->front, q->rear);
	if (!is_empty(q))
	{
		int i = q->front;
		do
		{
			i = (i + 1) % (MAX_QUEUE_SIZE);
			printf("%d | ", q->data[i]);
			if (i == q->rear)
				break;
		} while (i != q->front);
	}
	printf("\n");
}

void add_rear(DequeType* q, element item) //삽임함수
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element delete_front(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

element get_front(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[(q->front + 1) % MAX_QUEUE_SIZE];
}

void add_front(DequeType* q, element val)
{
	if (is_full(q))
		error("큐가 포화상태입니다.");
	q->data[q->front] = val;
	q->front = (q->front - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}

element delete_rear(DequeType* q)
{
	int prev = q->rear;
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	q->rear = (q->rear - 1 + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
	return q->data[prev];
}

element get_rear(DequeType* q)
{
	if (is_empty(q))
		error("큐가 공백상태입니다.");
	return q->data[q->rear];
}