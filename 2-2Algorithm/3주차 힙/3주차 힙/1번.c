#include<stdio.h>
#include<stdlib.h>
// #include<Windows.h>
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
	- charelement : 1���� ����. 
	** element �ڷ����� �̿��Ͽ� ��������� �迭, �׸��� �׷� ������ ����Ʈ��������
	** charelement �� '#' �� �־ NULL ��Ŀ�� �����մϴ�.

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
	- �̰��� ���� ��������� �𸣰�����, Ʈ���� �迭�� ������ ������ �ι��ڷ� �ʱ�ȭ��.

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

typedef struct treenode treenode;
typedef struct doublelinkedlist_tree dublelinkedlist_tree;
typedef struct tree_array tree_array;



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
struct tree_array {
	int maxsize;
	int currentsize;
	element* elementarray;
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


void init_element(element* e) {
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
int isEmpty_doubleLinkedList(doublelinkedlist* list) {

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
void enqueue_doubleLinkedList_prioritiyQueue(doublelinkedlist_priorityqueue* queue, element e) {

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





// binary tree method with array
//��� ���� �߰��Ұ� : ����� ��� �˰���, ��� ��� �˰���

#define UPSMALL 0
#define UPBIG 1

int isRoot_array_tree(int index) {
	if (index == 1) {
		return 1;
	}
	else return 0;
}
element elementInTree_array_tree(element *tree, int index) {
	return tree[index];
}
int parentIndex_array_tree(int index) {
	if (index == 1) {
		return 1;
	}
	else {
		return index / 2;
	}
}
int isParentExist_array_tree(tree_array* tree, int index) {
	if ((tree->elementarray)[parentIndex_array_tree(index)].charelement != '#') {
		return 1;
	}
	else return 0;
}
tree_array* get_array_tree(int arraysize) {

	tree_array* newtree = NULL;
	newtree = (tree_array*)malloc(sizeof(tree_array) * 1);
	if (newtree == NULL) return;

	//init
	newtree->maxsize = arraysize;
	newtree->elementarray = (element*)malloc(sizeof(element) * arraysize);
	if (newtree->elementarray == NULL) return;
	newtree->currentsize = 0;
	
	int i;
	for (i = 1; i < arraysize; i++) {
		//index == 0 �� ��ġ�� �ʱ�ȭ���� ����.
		(newtree->elementarray)[i].charelement = '#';
	}
	
	return newtree;
}
element parentElementInTree_array_tree(element* tree, int index) {
	return tree[parentIndex_array_tree(index)];
}
int lastNodeIndex_array_tree(tree_array* tree) {
	return tree->currentsize;
}
int leftChildIndex_array_tree(int index) {
	return 2 * index;
}
int isLeftChildIndex_array_tree(int index) {
	return (index % 2);
}
int rightChildIndex_array_tree(int index) {
	return 2 * index + 1;
}
int isRightChildIndex_array_tree(int index) {
	return !(index % 2);
}
int isInternalIndex_array_tree(element *tree, int arraysize, int index) {
	return (2 * index < arraysize) && (tree[2 * index].charelement != '#');
}
int isExternalIndex_array_tree(element* tree, int arraysize, int index) {
	return ((2 * index >= arraysize) || (tree[2 * index].charelement == '#'));
}
int isExternalIndex_array_tree_heap(tree_array* tree, int index) {
	if (isExternalIndex_array_tree(tree->elementarray, tree->maxsize, index)) {
		if (tree->currentsize >= index) {
			return 0;
		}
		else return 1;
	}
	else {
		return 0;
	}
}
int isInternalIndex_array_tree_heap(tree_array* tree, int index) {
	if (isExternalIndex_array_tree_heap(tree, index)) {
		return 0;
	}
	else return 1;
}
void setElementWithIndex_array_tree(element *tree, int index, element e) {
	tree[index] = e;
}
void swapElementWithIndex_array_tree(element *tree, int index1, int index2) {
	element tmpelement;
	tmpelement = tree[index1];
	tree[index1] = tree[index2];
	tree[index2] = tmpelement;
}
void printElements_array_tree_heap(tree_array* tree) {
	int i;
	for (i = 1; i <= tree->currentsize; i++) {
		if ((tree->elementarray)[i].charelement == '#') {
			printf("");
		}
		else {
			printf(" %d", (tree->elementarray)[i]);
		}
	}
}
void insertElementWithIndex_array_tree(tree_array* tree, element e, int index) {

	if (tree->currentsize + 1 == tree->maxsize) {
		printf("fullArrayException");
		return;
	}
	
	if (isParentExist_array_tree(tree, index)) {
//		(tree->elementarray)[index].charelement = '1';
		(tree->elementarray)[index] = e;
		(tree->currentsize)++;
	}
	else if (isRoot_array_tree(index)) {
//		(tree->elementarray)[index].charelement = '1';
		(tree->elementarray)[index] = e;
		(tree->currentsize)++;
	}
	else {
		printf("invalidNodeException_ not exist parent");
		return;
	}
}
void downHeap_array_tree_heap(tree_array* tree, int index, int upsmall_or_upbig) {

	if (isExternalIndex_array_tree_heap(tree, leftChildIndex_array_tree(index))
		&& isExternalIndex_array_tree_heap(tree, rightChildIndex_array_tree(index))) {
		return;
	}

	int smallorbigindex = leftChildIndex_array_tree(index);
	element smallorbigelement = elementInTree_array_tree(tree->elementarray, leftChildIndex_array_tree(index));


	if (upsmall_or_upbig == UPSMALL) {
		if (isInternalIndex_array_tree_heap(tree, rightChildIndex_array_tree(index)))	 {
			if (elementInTree_array_tree(tree->elementarray, rightChildIndex_array_tree(index)).intelement < smallorbigelement.intelement) {
				smallorbigindex = rightChildIndex_array_tree(index);
				smallorbigelement = elementInTree_array_tree(tree->elementarray, smallorbigindex);
			}
		}
		if (smallorbigelement.intelement >= elementInTree_array_tree(tree->elementarray, index).intelement) {
			return;
		}
		swapElementWithIndex_array_tree(tree->elementarray, index, smallorbigindex);
	}
	else {//UPBIG
		if (isInternalIndex_array_tree_heap(tree, rightChildIndex_array_tree(index))) {
			if (elementInTree_array_tree(tree->elementarray, rightChildIndex_array_tree(index)).intelement > smallorbigelement.intelement) {
				smallorbigindex = rightChildIndex_array_tree(index);
				smallorbigelement = elementInTree_array_tree(tree->elementarray, smallorbigindex);
			}
		}
		if (smallorbigelement.intelement <= elementInTree_array_tree(tree->elementarray, index).intelement) {
			return;
		}
		swapElementWithIndex_array_tree(tree->elementarray, index, smallorbigindex);
	}

	downHeap_array_tree_heap(tree, smallorbigindex, upsmall_or_upbig);

}
void expandExternal_array_tree_heap(tree_array* tree) {

}
element retreatLast_array_tree_heap(tree_array* tree) {

	element e = elementInTree_array_tree(tree, lastNodeIndex_array_tree(tree));
	(tree->elementarray)[lastNodeIndex_array_tree(tree)].charelement = '#';
	(tree->currentsize)--;

	return e;
}
element removeMinOrMax_array_tree_heap(tree_array* tree, int upsmall_or_upbig) {

	
	element rootelement = (tree->elementarray)[1];
	element lastelement = (tree->elementarray)[lastNodeIndex_array_tree(tree)];
	
	(tree->elementarray)[1] = lastelement;

	retreatLast_array_tree_heap(tree);

	downHeap_array_tree_heap(tree, 1, upsmall_or_upbig);
	
	return rootelement;
}
void upHeap_array_tree_heap(tree_array* tree, int currentindex, int upsmall_or_upbig) {

	if (isRoot_array_tree(tree->elementarray)) {
		return;
	}

	if (upsmall_or_upbig == UPSMALL) {
		if ((tree->elementarray)[currentindex].intelement >= parentElementInTree_array_tree(tree->elementarray, currentindex).intelement) {
			return;
		}
		swapElementWithIndex_array_tree(tree->elementarray, currentindex, parentIndex_array_tree(currentindex));
	}
	else if (upsmall_or_upbig == UPBIG) {
		if ((tree->elementarray)[currentindex].intelement <= parentElementInTree_array_tree(tree->elementarray, currentindex).intelement) {
			return;
		}
		swapElementWithIndex_array_tree(tree->elementarray, currentindex, parentIndex_array_tree(currentindex));
	}
	else {
		printf("parameter error!");
	}

	upHeap_array_tree_heap(tree, parentIndex_array_tree(currentindex), upsmall_or_upbig);
}
void insertElement_array_tree_heap(tree_array* tree, element e) {
	
	expandExternal_array_tree_heap(tree);

	insertElementWithIndex_array_tree(tree, e, (tree->currentsize)+1);

}



int main() {


	tree_array* tree = NULL;
	tree = get_array_tree(101);
//	element tree[101]; //100 �� �ִ��̹Ƿ�, 0�� index ���ٸ� 101 * memory �ʿ�.

	char input;
	int key;
	element tmpelement;
	while (1) {
		scanf("%c", &input);
		if (input == 'i' || input == 'I') {
			scanf("%d", &key);
			
			//set datatype element (init)
			tmpelement.intelement = key;
			tmpelement.charelement = '1';
	
			insertElement_array_tree_heap(tree, tmpelement);
			upHeap_array_tree_heap(tree, tree->currentsize, UPBIG);
			printf("0");
		}

		else if (input == 'd' || input == 'D') {//delete
			printf("%d", removeMinOrMax_array_tree_heap(tree, UPBIG));
		}
		else if (input == 'p' || input == 'P') {//print
			printElements_array_tree_heap(tree);
		}
		else { //input == 'q') : quit!!
			break;
		}
		printf("\n");
		getchar();
	}




	return 0;
}