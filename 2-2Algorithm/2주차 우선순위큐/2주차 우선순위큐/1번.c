#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#include<time.h>


//�ڵ� �����

/*

<!> typedef �� "struct" �� �ۼ����� �ʱ� ���� ����մϴ�.

<!> ADT(�߻��ڷᱸ��) �� A_B_C... �� ���� ���·� �̷�����ϴ�.
	- ���� �̸��� A_B_C ��� ���� ������ ADT�� C�̰�, A�� B�� �̿��� �����Ǿ��� ���Դϴ�.

<!> ADT Function (�߻��ڷᱸ�� �Լ�) �� A_B_C... �� ���� ���·� �̷�����ϴ�.
	- ���� �̸��� A_B_C ���, ����� A �̰�, B�� C�� �̿��� �����Ǿ��� ���Դϴ�.

<!> element ����ü�� ���Ͽ�
	- ���� : element ����ü�� (���Ǳ��ȿ� �ִ� �ǻ��ڵ带 ����) ������ �ڵ� ������ ���� �����߽��ϴ�.
	- ���� : int ��, char ��, string ���� ��� ��� �ֽ��ϴ�. float ��, custom ����ü�� �ʿ��ϸ� �Լ��� �߰��ؼ� ����ϸ� �˴ϴ�.
	- ��� : ������ �� �ڷ����� �Լ� ���ڷ� �Ѱ��ָ� �ڵ� ��ü�� �׿� �°� ���ư��ϴ�.

	- intelement : 1���� ����
	- charelement : 1���� ����
	- stringelement* : ���� �Ҵ��� �ؼ� ����ϴ� �����Դϴ�.

	- �ڷ��� �Լ� �ۼ��� :

<!> doublelinkedlist ����ü�� ���Ͽ�
	- header�� ������� �ʴ� �ڷ��������� firstnode �� �̿��Ͽ� ����Ʈ�� �����մϴ�.

<!> swapElements_doubleLinkedList_priorityQueue �Լ��� ���Ͽ�
	<-------�߿� ����------>
	- element �� �����͸� ��ü�ϴ� ���� ������ ���ٴ� ������ ������ϴ�.
	- ������, element ��ü�� ������(element *e) �� �������� �ʰ�, �׳� value (element e) �� �����߱⿡, ���� �ٲٴ� ������ �����մϴ�.
	- ���� ������ �ּ�ó���մϴ�.
	-- swapElement �� ������ element �� ��ȯ�ϴ� ������, ����Ʈ ��ü�� ��߸��� �ȵȴٰ� �����մϴ�.
	-- ����Ʈ ��ü�� ������ ���, �ش� �ڷᱸ���� �̿��ϴ� queue ��� front �� rear �� ������ ���׹��� �Ǵ� ���� �������� ���� ��.

		<----���� ����--->
			- �� �Լ���, element �� ��ü�ϴ� ����� �ƴ϶�, �ش� ��� ��ü�� ��ġ�� �ٲٴ� ���·� �����մϴ�.
			- element �� �����Ͱ� �ƴϱ� ������, element ���븸 ��ȯ�ϴ� ���� element �� Ŀ�� �� ��ȿ�����̱� �����Դϴ�.



	<--- ���� --->
	- 2019 09 10 ����ä�����Բ� ����
	- "ť" ��� �Ϳ� �ǹ̰� �ִ� ���� �ƴϰ�, �׳� �ƿ� ���� ����� �ٸ� ������ �ν�.
	- ����Ʈ�� ��� input �� �ް� (Ȥ�� ������� �ް�) �������İ� ���������� �����ϸ� �� �˰������� ��ü�� ���ĵǴ� ������� ����.


<!> ����
	- �Ϲ� node �� treenode �� ���������� �ٸ��ϴ�. tree �� ������ ������ treenode �� ����ؾ� �մϴ�.
	- �ݵ�� linked list �� �� �� ����� prevnode, �� �� ����� nextnode �� NULL �� �ʱ�ȭ�Ǿ��־�� �մϴ�.

<!> �ۼ�
	- 2019/09

*/

#define SELECTION 0
#define INSERTION 1

#define MIN 2
#define MAX 3

#define SORT_AND_DEQUEUE 0
#define JUST_SORT 1
#define JUST_DEQUEUE 2

typedef struct element element;
typedef struct node node;
typedef struct doublelinkedlist doublelinkedlist;
typedef struct doublelinkedlist_queue doublelinkedlist_queue;
typedef struct doublelinkedlist_priorityqueue doublelinkedlist_priorityqueue;

// typedef struct treenode treenode;
// typedef struct doublelinkedlist_tree dublelinkedlist_tree;


struct element {
	int intelement;
	char charelement;
	char* stringelement;
	/* Here! */
};
struct node {
	node* prevnode;
	node* nextnode;
	element e;
};
struct doublelinkedlist {
	node* header;
	node* trailer;
	node* firstnode;
};
struct doublelinkedlist_priorityqueue {
	node* front;
	doublelinkedlist* doublelinkedlist;
	node* rear;
	int selection_or_insertion;
};


void emptyListException() {
	printf("empteyListException");
}
void emptyQueueException() {
	printf("emptyQueueException");
}
void fullQueueException() {
	printf("fullQueueException");
}


void init_element(element *e) {
	e->charelement = '0';
	e->intelement = 0;
	e->stringelement = NULL;
}
node* get_node() {

	node* newnode = NULL;
	newnode = (node*)malloc(sizeof(node) * 1);
	if (newnode == NULL) return;

	init_element(&(newnode->e));
	newnode->nextnode = NULL;
	newnode->prevnode = NULL;

	return newnode;
}
element remove_node(node* currentnode) {

	element e;
	e = currentnode->e;
	free(currentnode);
	return e;
}
doublelinkedlist* get_doubleLinkedList() {

	doublelinkedlist* newlist = NULL;
	newlist = (doublelinkedlist*)malloc(sizeof(doublelinkedlist) * 1);
	if (newlist == NULL) return;

	//with header and trailer
	newlist->header = get_node();
	newlist->trailer = get_node();
	
	//init
	newlist->header->nextnode = newlist->trailer;
	newlist->trailer->prevnode = newlist->header;
	newlist->firstnode = NULL;

	return newlist;
}
int isEmpty_doubleLinkedList(doublelinkedlist *list) {

	if (list->header != NULL) {
		if (list->trailer != NULL) { // header, trailer exist
			if (list->header->nextnode == list->trailer) {
				return 1;
			}
			else {
				return 0;
			}
		}
		else { // header exist, trailer does not exist
			if (list->header->nextnode == NULL) {
				return 1;
			}
			else {
				return 0;
			}
		}
	}
	else { // header does not exist
		if (list->firstnode == NULL) {
			return 1;
		}
		else {
			return 0;
		}
	}

}
doublelinkedlist_priorityqueue* get_doubleLinkedList_prioritiyQueue(int selection_or_insertion) {

	doublelinkedlist* newlist = NULL;
	newlist = get_doubleLinkedList();

	doublelinkedlist_priorityqueue* newqueue = NULL;
	newqueue = (doublelinkedlist_priorityqueue*)malloc(sizeof(doublelinkedlist_priorityqueue) * 1);
	if (newqueue == NULL) return;


	//remove header and trailer
	remove_node(newlist->header);
	remove_node(newlist->trailer);
	newlist->header = NULL;
	newlist->trailer = NULL;

	//init
	newqueue->doublelinkedlist = newlist;
	newqueue->front = NULL;
	newqueue->rear = NULL;
	newqueue->selection_or_insertion = selection_or_insertion;

	return newqueue;
}
void enqueue_doubleLinkedList_prioritiyQueue(doublelinkedlist_priorityqueue *queue, element e) {

	node* newnode = NULL;
	newnode = get_node();
	newnode->e = e;


	if (isEmpty_doubleLinkedList(queue->doublelinkedlist)) {
		queue->front = newnode;
		queue->rear = newnode;
		queue->doublelinkedlist->firstnode = newnode;
	}
	else {
		newnode->prevnode = queue->rear;
		queue->rear->nextnode = newnode;
		queue->rear = newnode;
	}

}
void swapElements_doubleLinkedList_priorityQueue(doublelinkedlist* list, node* frontnode, node* backnode) {


	element tmpelement;
	tmpelement = frontnode->e;
	frontnode->e = backnode->e;
	backnode->e = tmpelement;

	/*
	node* fronttmpnode = NULL;
	node* backtmpnode = NULL;
	fronttmpnode = frontnode;
	backtmpnode = backnode;

	if		((frontnode->prevnode == NULL) && (backnode->nextnode == NULL)) {
		frontnode->prevnode = backtmpnode->prevnode;
		frontnode->nextnode = NULL;
		backnode->prevnode = NULL;
		backnode->nextnode = fronttmpnode->nextnode;
	}
	else if ((frontnode->prevnode == NULL) && (backnode->nextnode != NULL)) {
		frontnode->prevnode = backtmpnode->prevnode;
		frontnode->nextnode = backtmpnode->nextnode;
		backnode->prevnode = NULL;
		backnode->nextnode = fronttmpnode->nextnode;
	}
	else if ((frontnode->prevnode != NULL) && (backnode->nextnode == NULL)) {
		frontnode->prevnode = backtmpnode->prevnode;
		frontnode->nextnode = NULL;
		backnode->prevnode = fronttmpnode->prevnode;
		backnode->nextnode = fronttmpnode->nextnode;
	}
	else if ((frontnode->prevnode != NULL) && (backnode->nextnode != NULL)) {
		frontnode->prevnode = backtmpnode->prevnode;
		frontnode->nextnode = backtmpnode->nextnode;
		backnode->prevnode = fronttmpnode->prevnode;
		backnode->nextnode = fronttmpnode->nextnode;
	}
	else {
		printf("nothing");
	}
	*/

}
void sortElementsSelection_doubleLinkedList_priorityQueue(doublelinkedlist_priorityqueue* queue, int min_or_max) {

	//�� �ݺ����� ���� ũ�ų� ���� ���� ã��, ���ʺ��� ä��� ������� �۵�. ���� 2���� ���� ������.
	node* tmpnode_i = NULL;
	node* tmpnode_j = NULL;
	node* min_or_max_loc = NULL;

	// ���� ť�� ����� ������ ������ 1���� ���, ������ �߻��� �� �ֽ��ϴ�.
	for (tmpnode_i = queue->front; tmpnode_i != queue->rear; tmpnode_i = tmpnode_i->nextnode) {
		min_or_max_loc = tmpnode_i;
		for (tmpnode_j = tmpnode_i->nextnode; tmpnode_j != NULL; tmpnode_j = tmpnode_j->nextnode) {
			if (min_or_max == MIN) {
				if (tmpnode_j->e.intelement < min_or_max_loc->e.intelement)
					min_or_max_loc = tmpnode_j;
			}
			else {
				if (tmpnode_j->e.intelement > min_or_max_loc->e.intelement)
					min_or_max_loc = tmpnode_j;
			}
		}
		swapElements_doubleLinkedList_priorityQueue(queue->doublelinkedlist, tmpnode_i, min_or_max_loc);
	}

}
void sortElementsReverseSelection_doubleLinkedList_priorityQueue(doublelinkedlist_priorityqueue* queue, int min_or_max) {

	//�� �ݺ����� ���� ũ�ų� ���� ���� ã��, �����ʺ��� ä��� ������� �۵�. ���� 1���� ���� ������.
	node* tmpnode_i = NULL;
	node* tmpnode_j = NULL;
	node* min_or_max_loc = NULL;

	// ���� ť�� ����� ������ ������ 1���� ���, ������ �߻��� �� �ֽ��ϴ�.
	for (tmpnode_i = queue->rear; tmpnode_i != queue->front; tmpnode_i = tmpnode_i->prevnode) {
		min_or_max_loc = tmpnode_i;
		for (tmpnode_j = tmpnode_i->prevnode; tmpnode_j != NULL; tmpnode_j = tmpnode_j->prevnode) {
			if (min_or_max == MIN) {
				if (tmpnode_j->e.intelement < min_or_max_loc->e.intelement)
					min_or_max_loc = tmpnode_j;
			}
			else {
				if (tmpnode_j->e.intelement > min_or_max_loc->e.intelement)
					min_or_max_loc = tmpnode_j;
			}
		}
		swapElements_doubleLinkedList_priorityQueue(queue->doublelinkedlist, tmpnode_i, min_or_max_loc);
	}

}
void sortElementsInsertion_doubleLinkedList_priorityQueue(doublelinkedlist_priorityqueue* queue, int min_or_max) {

	node* tmpnode_i = NULL;
	node* tmpnode_j = NULL;
	element e;


	for (tmpnode_i = queue->doublelinkedlist->firstnode->nextnode; tmpnode_i != NULL; tmpnode_i = tmpnode_i->nextnode) {
		
		e = tmpnode_i->e;
		tmpnode_j = tmpnode_i->prevnode;
		if (min_or_max == MIN) {
			//���� ������� ����
			while ((tmpnode_j != NULL) && (tmpnode_j->e.intelement > e.intelement)) {
				tmpnode_j->nextnode->e = tmpnode_j->e;
				tmpnode_j = tmpnode_j->prevnode;
			}
		}
		else {
			//ū ������� ����
			while ((tmpnode_j != NULL) && (tmpnode_j->e.intelement < e.intelement)) {
				tmpnode_j->nextnode->e = tmpnode_j->e;
				tmpnode_j = tmpnode_j->prevnode;
			}
		}
		if (tmpnode_j == NULL)
			queue->doublelinkedlist->firstnode->e = e;
		//null �� �Ǿ������ ������ ������ ���ؼ�.
		else tmpnode_j->nextnode->e = e;
	}

}



element dequeue_doubleLinkdedList_priorityQueue(doublelinkedlist_priorityqueue* queue, int min_or_max, int sort_or_dequeue) {

	if (isEmpty_doubleLinkedList(queue->doublelinkedlist)) {
		emptyQueueException();
		return;
	}

	if (sort_or_dequeue == SORT_AND_DEQUEUE || sort_or_dequeue == JUST_SORT) {
		if (queue->selection_or_insertion == SELECTION) {
			/* ���� Ǯ��. */
			// 1 ��
			if (min_or_max == MAX) sortElementsReverseSelection_doubleLinkedList_priorityQueue(queue, MAX);
			// 2 ��
			if (min_or_max == MIN) sortElementsSelection_doubleLinkedList_priorityQueue(queue, MIN);
		}
		else {
			if (min_or_max == MIN) sortElementsInsertion_doubleLinkedList_priorityQueue(queue, MIN);
			if (min_or_max == MAX) sortElementsInsertion_doubleLinkedList_priorityQueue(queue, MAX);
		}
	}
	if (sort_or_dequeue == SORT_AND_DEQUEUE || sort_or_dequeue == JUST_DEQUEUE) {
		//front �� ������ �ְ�, ������ �˾Ƽ� ������ ��.
		element e;
		node* removingnode = NULL;
		removingnode = queue->front;
		e = removingnode->e;

		if (queue->doublelinkedlist->firstnode != NULL) {
			//���� �����ϰ��� �ϴ� ��尡 �� �տ� �ִ� �����
			if (queue->doublelinkedlist->firstnode == queue->front) {
				queue->doublelinkedlist->firstnode = queue->doublelinkedlist->firstnode->nextnode;
			}
		}

		queue->front = queue->front->nextnode;
		remove_node(removingnode);
		return e;
	}
	return;
}

int main() {

	int n, i;

	scanf("%d", &n);
	element* tmparray = NULL;
	tmparray = (element*)malloc(sizeof(element) * n);
	int index = 0;

	srand(time(NULL));
	LARGE_INTEGER tickspersec;
	LARGE_INTEGER start, diff, end;



	int kindof = 0;
	int random_sorted_reverse = 0;
	doublelinkedlist_priorityqueue* queue[2];
	element currentelement;


	printf("\n-------------------------------------\n");
	for (random_sorted_reverse = 0; random_sorted_reverse < 3; random_sorted_reverse++) {
		for (kindof = 0; kindof < 2; kindof++) {
			//kindof == 0 : selection sort
			//kindof == 1 : insertion sort
			if (kindof == 0) {
				printf("selection sort - ���� ����\n");
			}
			else {
				printf("insertion sort - ���� ����\n");
			}



			if (random_sorted_reverse == 0) { // ����
				printf("type A - ���� ");
				queue[kindof] = get_doubleLinkedList_prioritiyQueue(kindof);
				for (i = 0; i < n; i++) { // ����
					currentelement.intelement = rand() % n;
					enqueue_doubleLinkedList_prioritiyQueue(queue[kindof], currentelement);
				}

				QueryPerformanceFrequency(&tickspersec);
				QueryPerformanceCounter(&start);
				/* --- code here --- */
				dequeue_doubleLinkdedList_priorityQueue(queue[kindof], MIN, JUST_SORT); // ����
				/* --- code end --- */
				QueryPerformanceCounter(&end);
				diff.QuadPart = end.QuadPart - start.QuadPart;
				printf("time : %.12f sec\n\n", (((double)diff.QuadPart) / ((double)tickspersec.QuadPart)));

				index = 0;
				while (!isEmpty_doubleLinkedList(queue[kindof]->doublelinkedlist)) {
					// printf(" %d", dequeue_doubleLinkdedList_priorityQueue(queue[kindof], MIN, JUST_DEQUEUE)); // ����ϸ� ��ť
					tmparray[index] = dequeue_doubleLinkdedList_priorityQueue(queue[kindof], MIN, JUST_DEQUEUE); // ���ĵȰ� ��ť
					index++;
				}
			}
			else if (random_sorted_reverse == 1) { // ���ĵ� ����
				printf("type B - ������ ");
				for (i = 0; i < n; i++) { // ����
					enqueue_doubleLinkedList_prioritiyQueue(queue[kindof], tmparray[i]);
				}

				QueryPerformanceFrequency(&tickspersec);
				QueryPerformanceCounter(&start);
				/* --- code here --- */
				dequeue_doubleLinkdedList_priorityQueue(queue[kindof], MIN, JUST_SORT); // ����
				/* --- code end --- */
				QueryPerformanceCounter(&end);
				diff.QuadPart = end.QuadPart - start.QuadPart;
				printf("time : %.12f sec\n\n", (((double)diff.QuadPart) / ((double)tickspersec.QuadPart)));

				index = 0;
				while (!isEmpty_doubleLinkedList(queue[kindof]->doublelinkedlist)) {
					// printf(" %d", dequeue_doubleLinkdedList_priorityQueue(queue[kindof], MIN, JUST_DEQUEUE)); // ����ϸ� ��ť
					tmparray[index] = dequeue_doubleLinkdedList_priorityQueue(queue[kindof], MIN, JUST_DEQUEUE); // ���ĵȰ� ��ť
					index++;
				}

			}
			else { // ������ ����
				printf("type C - ������ ");
				for (i = 0; i < n; i++) { // ����
					enqueue_doubleLinkedList_prioritiyQueue(queue[kindof], tmparray[i]);
				}

				QueryPerformanceFrequency(&tickspersec);
				QueryPerformanceCounter(&start);
				/* --- code here --- */
				dequeue_doubleLinkdedList_priorityQueue(queue[kindof], MAX, JUST_SORT); // ����
				/* --- code end --- */
				QueryPerformanceCounter(&end);
				diff.QuadPart = end.QuadPart - start.QuadPart;
				printf("time : %.12f sec\n\n", (((double)diff.QuadPart) / ((double)tickspersec.QuadPart)));

				index = 0;
				while (!isEmpty_doubleLinkedList(queue[kindof]->doublelinkedlist)) {
					// printf(" %d", dequeue_doubleLinkdedList_priorityQueue(queue[kindof], MIN, JUST_DEQUEUE)); // ����ϸ� ��ť
					tmparray[index] = dequeue_doubleLinkdedList_priorityQueue(queue[kindof], MAX, JUST_DEQUEUE); // ���ĵȰ� ��ť
					index++;
				}
			}
		}
		printf("-------------------------------------\n");
	}
	
	
	return 0;


}