//#define NUMBER1_1
//#define NUMBER2_1
//#define NUMBER2_2
#define NUMBER3



#ifndef BASIC_HEADER
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#endif // !BASIC_HEADER



#ifndef STRUCTURE
typedef struct element e;
struct element {
	char charelem;
	int intelem;
	char* string;
};

typedef struct node nd;
struct node {
	nd* prev_node;
	e* element;
	nd* next_node;
};
#endif // !STRUCTURE


#ifndef LINKEDLIST
typedef struct linkedlist li;
struct linkedlist {
	int size_of_list;
	nd* header;
	nd* trailer;
	int single_or_double;
	int header_and_trailer;
};
#endif // !LINKEDLIST



//�������� �ϴ� ���ϱ�, ����ü �̸��̶� �Լ� �̸��� ��� ���� �����
//�׷��� �ʵ��� standard �� ���س��� �ؾ߰ڴ� �;���.
//[�ڷᱸ���Ҽ�]_____[�ڷᱸ���� ��ǰ]______[� �ڷᱸ���� �����ߴ���]
#ifndef TREE
#define BINARY 1
typedef struct tree_______bylist			tr____bylist;
typedef struct tree_node__bylist			tr_nd_bylist;
typedef struct tree_binarylist__bylist		tr_bili_bylist;
typedef struct tree_singlelinkedlist_bylist	tr_sili_bylist;
typedef struct tree_queuesize100_byarray	tr_qu100_byarr;	//queue for levelOrder

struct tree_______bylist {
	tr_nd_bylist* rootnode;
};
struct tree_node__bylist {
	tr_nd_bylist* parent;
	e* element;
	tr_bili_bylist* children_list;

	int euler_left;
	int euler_size;

};
struct tree_binarylist__bylist {
	tr_nd_bylist* left;
	tr_nd_bylist* right;
	int treetype_isbinary;
};

struct tree_queuesize100_byarray {
	int front;
	tr_nd_bylist* queue[101];
	int rear;
	int queuemaxsize;
};
#endif // !TREE





//funciton original form
tr_bili_bylist* tr_initBinaryList_byList(int isbinary);
tr_nd_bylist* tr_parent_byList(tr_nd_bylist* node);
void			tr_queue_freeQueue_byArray(tr_qu100_byarr* queue);
void			tr_queue_enQueue_byArray(tr_qu100_byarr* queue, tr_nd_bylist* element);
tr_nd_bylist* tr_queue_deQueue_byArray(tr_qu100_byarr* queue);
tr_qu100_byarr* tr_queue_initQueue_byArray();
tr_nd_bylist* tr_nextNodeByPreorder_byList(tr_nd_bylist* node);
tr_nd_bylist* tr_bi_addNodeRightChild_byList(tr_nd_bylist* node, e* element);
tr_nd_bylist* tr_bi_addNodeLeftChild_byList(tr_nd_bylist* node, e* element);
void			tr_bi_visit_byList(tr_nd_bylist* node, int mode);
extern int cnt;
extern e* tmpelement;

int	int_Max(int a, int b) {
	if (a > b) {
		return a;
	}
	else return b;
}


//��ġ : element �����͸� input ���� �޾ƾ߰���.
//�׷��� ������ element�� free�� �ȵ�ä�� �� ���ƴٴ�.
e* readyElement() {
	e* element;
	element = (e*)malloc(sizeof(e) * 1);
	return element;
}
e				readySetElement(e* elem, int intinput, char charinput) {

	(elem->intelem) = intinput;
	(elem->charelem) = charinput;

	return *elem;
}
e				readySetElement_string(e* elem, char* string) {

	char* cp = string;
	int string_length = 0;
	while (*cp != 0) {
		string_length++;
		cp++;
	}
	elem->string = (char*)malloc(sizeof(char) * string_length + 1);
	strcpy((elem->string), string);
	return *elem;

}


//function reading example : tr_bi_isExternal_byList
//tr_			: Data Structure - Tree ADT
//bi_			: Tree ADT, only for binary tree
//isExternal_	: function name
//byList		: implemented with Linked List
tr_nd_bylist* tr_getNode_bylist(int isbinary) {

	tr_nd_bylist* newnode;
	newnode = (tr_nd_bylist*)malloc(sizeof(tr_nd_bylist) * 1);
	if (newnode == NULL) {
		printf("funciton : tr_getNode_bylist error\n");
		return;
	}

	newnode->children_list = tr_initBinaryList_byList(isbinary);

	newnode->element = readyElement();
	*(newnode->element) = readySetElement(newnode->element, -1, '1');
	newnode->parent = NULL;

	return newnode;

}
tr____bylist* tr_initRoot_byList(int isbinary) {

	tr_nd_bylist* newrootnode;
	tr____bylist* newroot;

	newroot = (tr____bylist*)malloc(sizeof(tr____bylist) * 1);
	if (newroot == NULL) {
		printf("function : tr_initRoot_byList error");
		return;
	}

	newrootnode = tr_getNode_bylist(isbinary);

	//init list first!

	readySetElement(newrootnode->element, 0, '0');
	newroot->rootnode = newrootnode;
	newrootnode->parent == NULL;

	return newroot;
}
tr____bylist* tr_initRootNodeWithElement_byList(int isbinary, e* element) {

	tr____bylist* newroot;
	newroot = tr_initRoot_byList(isbinary);
	newroot->rootnode->element = element;
	return newroot;
}
tr_bili_bylist* tr_initBinaryList_byList(int isbinary) {

	tr_bili_bylist* newlist;
	newlist = (tr_bili_bylist*)malloc(sizeof(tr_bili_bylist) * 1);
	if (newlist == NULL) {
		printf("function : tr_initList_byList error\n");
		return;
	}
	newlist->treetype_isbinary = isbinary;
	newlist->left = NULL;
	newlist->right = NULL;

	return newlist;
}
e				tr_element_byList(tr_nd_bylist* node) {
	return *(node->element);
}
tr_nd_bylist* tr_root_byList(tr_nd_bylist* node) {
	if (tr_parent_byList(node) == NULL) {
		return node;
	}
	else {
		tr_nd_bylist* tmp_parent_node;
		tmp_parent_node = node->parent;
		while (tr_parent_byList(tmp_parent_node) == NULL) {
			tmp_parent_node = tr_parent_byList(tmp_parent_node);
		}
		return tmp_parent_node;
	}
}
tr_nd_bylist* tr_parent_byList(tr_nd_bylist* node) {
	return node->parent;
}
tr_nd_bylist* tr_bi_leftChild_byList(tr_nd_bylist* node) {
	return node->children_list->left;
}
tr_nd_bylist* tr_bi_rightChild_byList(tr_nd_bylist* node) {
	return node->children_list->right;
}
tr_nd_bylist* tr_bi_anotherSibling_byList(tr_nd_bylist* node) {
	tr_nd_bylist* current_node, * tmp_parent_node;
	current_node = node;
	tmp_parent_node = tr_parent_byList(node);

	if (tr_bi_leftChild_byList(tmp_parent_node) == current_node)
		return tr_bi_rightChild_byList(tmp_parent_node);
	else
		return tr_bi_leftChild_byList(tmp_parent_node);

}

tr_nd_bylist* tr_bi_addNodeRightChild_byList(tr_nd_bylist* node, e* element) {
	tr_nd_bylist* newnode;
	newnode = tr_getNode_bylist(BINARY);
	node->children_list->right = newnode;
	newnode->parent = node;
	newnode->element = element;
	return newnode;
}
tr_nd_bylist* tr_bi_addNodeLeftChild_byList(tr_nd_bylist* node, e* element) {
	tr_nd_bylist* newnode;
	newnode = tr_getNode_bylist(BINARY);
	node->children_list->left = newnode;
	newnode->parent = node;
	newnode->element = element;
	return newnode;
}

tr_nd_bylist* tr_bi_binaryPostOrder_byList(tr_nd_bylist* node, int mode) {

	if (tr_bi_isInternal_byList(node)) {	//if node is internal node
		if (tr_bi_isLeftChildExist_byList(node))	tr_bi_binaryPostOrder_byList(tr_bi_leftChild_byList(node), mode);
		if (tr_bi_isRightChildExist_byList(node))	tr_bi_binaryPostOrder_byList(tr_bi_rightChild_byList(node), mode);
	}
	//end condition

	tr_bi_visit_byList(node, mode);
}
tr_nd_bylist* tr_bi_binaryPreOrder_byList(tr_nd_bylist* node, int mode) {

	tr_bi_visit_byList(node, mode);

	if (tr_bi_isInternal_byList(node)) {	//if node is internal node
		if (tr_bi_isLeftChildExist_byList(node))	tr_bi_binaryPreOrder_byList(tr_bi_leftChild_byList(node), mode);
		if (tr_bi_isRightChildExist_byList(node))	tr_bi_binaryPreOrder_byList(tr_bi_rightChild_byList(node), mode);
	}

}
tr_nd_bylist* tr_bi_binaryInOrder_byList(tr_nd_bylist* node, int mode) {

	if (tr_bi_isInternal_byList(node) && tr_bi_isLeftChildExist_byList(node))
		tr_bi_binaryInOrder_byList(tr_bi_leftChild_byList(node), mode);
	tr_bi_visit_byList(node, mode);
	if (tr_bi_isInternal_byList(node) && tr_bi_isRightChildExist_byList(node))
		tr_bi_binaryInOrder_byList(tr_bi_rightChild_byList(node), mode);

}
tr_nd_bylist* tr_bi_levelOrder_byList(tr_nd_bylist* node, int mode) {

	//node number starts at 1
	tr_qu100_byarr* newqueue;
	tr_nd_bylist* tmpnode1, * tmpnode2;
	int cnt = 1;
	newqueue = tr_queue_initQueue_byArray();

	tr_queue_enQueue_byArray(newqueue, node);
	while (!tr_queue_isEmpty_byArray(newqueue)) {
		tmpnode1 = tr_queue_deQueue_byArray(newqueue);
		tr_bi_visit_byList(tmpnode1, mode);
		/*
				if (n != 0) {	//If parameter n is 0, not return any node.
					if (cnt == n) return tmpnode1;
				}
		*/
		tmpnode2 = tr_bi_leftChild_byList(tmpnode1);
		if (tmpnode2 != NULL) tr_queue_enQueue_byArray(newqueue, tmpnode2);
		tmpnode2 = tr_bi_rightChild_byList(tmpnode1);
		if (tmpnode2 != NULL) tr_queue_enQueue_byArray(newqueue, tmpnode2);
		cnt++;
	}


	tr_queue_freeQueue_byArray(newqueue);

}

tr_qu100_byarr* tr_queue_initQueue_byArray() {

	tr_qu100_byarr* newqueue;
	newqueue = (tr_qu100_byarr*)malloc(sizeof(tr_qu100_byarr) * 1);
	if (newqueue == NULL) {
		printf("function : tr_initQueue_byArray error\n");
		return;
	}

	newqueue->front = 0;
	newqueue->rear = 101 - 1;
	newqueue->queuemaxsize = 101;

	return newqueue;
}
tr_nd_bylist* tr_queue_deQueue_byArray(tr_qu100_byarr* queue) {

	tr_nd_bylist* tmp;
	tmp = queue->queue[queue->front];
	queue->front = (queue->front + 1) % queue->queuemaxsize;
	return tmp;

}
void			tr_queue_freeQueue_byArray(tr_qu100_byarr* queue) {
	free(queue);
}
void			tr_queue_enQueue_byArray(tr_qu100_byarr* queue, tr_nd_bylist* element) {

	queue->rear = (queue->rear + 1) % queue->queuemaxsize;
	queue->queue[queue->rear] = element;

}
int				tr_queue_isFull_byArray(tr_qu100_byarr* queue) {
	if ((queue->front + 2) % (queue->queuemaxsize) == queue->rear) {
		return 1;
	}
	else return 0;
}
int				tr_queue_isEmpty_byArray(tr_qu100_byarr* queue) {
	if ((queue->rear + 1) % (queue->queuemaxsize) == queue->front) {
		return 1;
	}
	else return 0;
}
void			qu_fullqueueException_byArray() {
	printf("function : qu_fullqueueException_byArray\n");
}

int tmpcount = 0;
tr_nd_bylist* selected_node;
e* tmpelement;

//This function could be modified freely. This funciton controls what to do at current node
void			tr_bi_visit_byList(tr_nd_bylist* node, int mode) {
	tmpcount = tmpcount + node->element->intelem;
	if (node->element->charelem == tmpelement->charelem) {
		selected_node = node;
	}
	if (mode == 1) {
		printf(" %d", node->element->intelem);
	}

}
//=========================================================================


int				tr_bi_size_byList(tr_nd_bylist* node) {

}
int				tr_dept_byList(tr_nd_bylist* node) {
	if (tr_isRoot_byList(node)) {
		return 0;
	}
	else {
		return 1 + tr_dept_byList(tr_parent_byList(node));
	}
}
int				tr_bi_height_byList(tr_nd_bylist* node) {
	if (tr_bi_isExternal_byList(node)) {
		return 0;
	}
	else {
		tr_nd_bylist* tmp1, * tmp2;
		int height = 0;

		height = int_Max(height, tr_bi_size_byList(tr_bi_leftChild_byList(node))),
			height = int_Max(height, tr_bi_size_byList(tr_bi_rightChild_byList(node)));

		return 1 + height;
	}

}
void			tr_invalidNodeException() {
	printf("invalidNodeException\n");
}

int				tr_bi_isLeftChildExist_byList(tr_nd_bylist* node) {
	if (tr_bi_leftChild_byList(node) == NULL) return 0;
	else return 1;
}
int				tr_bi_isRightChildExist_byList(tr_nd_bylist* node) {
	if (tr_bi_rightChild_byList(node) == NULL) return 0;
	else return 1;
}
int				tr_isRoot_byList(tr_nd_bylist* node) {
	if (tr_root_byList(node) == node) {
		return 1;
	}
	else {
		return 0;
	}
}

//update funciton : isInternal
int				tr_bi_isInternal_byList(tr_nd_bylist* node) {
	if (tr_bi_leftChild_byList(node) != NULL
		||
		tr_bi_rightChild_byList(node) != NULL) {
		return 1;
	}
	return 0;
}
int				tr_bi_isExternal_byList(tr_nd_bylist* node) {
	if (tr_bi_leftChild_byList(node) == NULL
		&&
		tr_bi_rightChild_byList(node) == NULL) {
		return 1;
	}
	return 0;
}
void			tr_readySetElement_byList(tr_nd_bylist* node, e element) {
	*(node->element) = element;
}
void			tr_swapElement_byList(tr_nd_bylist* v, tr_nd_bylist* w) {
	e* tmp;
	tmp = v->element;
	v->element = w->element;
	w->element = tmp;
}



//new code updated -> 14����
int				tr_bi_isRootNode_byList(tr_nd_bylist* node) {

	if (node->parent == NULL) {

		return 1;
	}
	else return 0;

}
//& initroot funciton updated : rootnode->parent = NULL initialize



//���� ��ġ���� ������ȸ ���� ���� ��带 ��ȯ�ϴ� �Լ��� �ۼ��Ѵ�.
tr_nd_bylist* tr_nextNodeByPreorder_byList(tr_nd_bylist* node) {

	if (tr_bi_isInternal_byList(node)) {

		if (tr_bi_isLeftChildExist_byList(node))
			return tr_bi_leftChild_byList(node);
		else return tr_bi_rightChild_byList(node);
	}

	tr_nd_bylist* tmpnode;

	tmpnode = node->parent;
	if (tmpnode == NULL)return;


	while (1) {
		while (node != tr_bi_leftChild_byList(tmpnode)) {

			if (tr_bi_isRootNode_byList(tmpnode)) {
				//�ѹ��� ���� �ٽ� root node �� ���ƿ��� ���̽�.
				return tmpnode;
			}

			node = tmpnode;
			tmpnode = tmpnode->parent;
		}

		if (tr_bi_isRightChildExist_byList(tmpnode))
			return tr_bi_rightChild_byList(tmpnode);

		node = tmpnode;
		tmpnode = tmpnode->parent;
		if (tmpnode == NULL)return;
	}

}



void tr_findNodeByID(tr____bylist* root, int intelement) {

	tr_nd_bylist* node = NULL;
	tr_nd_bylist* p = NULL;
	node = root->rootnode;
	while (tr_nextNodeByPreorder_byList(node) != root->rootnode) {

		if (intelement == node->element->intelem) {

			if (tr_bi_isRootNode_byList(node)) {
				printf("root");
				return;
			}

			p = node->parent;
			if (node == p->children_list->left) {
				printf("left");
			}
			else {
				printf("right");
			}
			return;
		}

		node = tr_nextNodeByPreorder_byList(node);
	}
	printf("nowhere");
	return;

}


//������ȸ ����� : ������ Ʈ���� ����!
tr_nd_bylist* tr_bi_preOrderSucc_byList(tr_nd_bylist* node) {

	tr_nd_bylist* p;

	if (tr_bi_isInternal_byList(node)) {
		if (tr_bi_isLeftChildExist_byList(node)) {
			return tr_bi_leftChild_byList(node);
		}
		else {
			return tr_bi_rightChild_byList(node);
		}
	}
	else {

		p = tr_parent_byList(node);
		while (tr_bi_rightChild_byList(p) == node) {
			if (tr_bi_isRootNode_byList(p)) {
				return p;
			}
			node = p;
			p = tr_parent_byList(node);
		}

		if (tr_bi_isRightChildExist_byList(p)) {
			return tr_bi_rightChild_byList(p);
		}
		return p; //return root node;
	}

}
//������ȸ ����� : ������ Ʈ���� ����!
tr_nd_bylist* tr_bi_nextNodeByPostorder_byList(tr_nd_bylist* node) {

	tr_nd_bylist* p;
	tr_nd_bylist* tmp;

	if (tr_bi_isRootNode_byList(node)) {
		tr_invalidNodeException();
		return;
	}

	p = tr_parent_byList(node);
	if (tr_bi_rightChild_byList(p) == node) {
		return p;
	}
	else { //if left child

		if (tr_bi_isRightChildExist_byList(p)) {
			
			tmp = tr_bi_rightChild_byList(p);

			while (!tr_bi_isExternal_byList(tmp)) {

				if (tr_bi_isLeftChildExist_byList(tmp)) {
					tmp = tr_bi_leftChild_byList(tmp);
				}
				else {
					tmp = tr_bi_rightChild_byList(tmp);
				}

			}
			
			return tmp;
		}
		else {
			return p;
		}
	}
}
//������ȸ ����� : ������ Ʈ���� ����!
tr_nd_bylist* tr_bi_nextNodeByInorder_byList(tr_nd_bylist* node) {

	tr_nd_bylist* p;
	tr_nd_bylist* tmp;
	
	if (tr_bi_isInternal_byList(node)) {

		if (tr_bi_isRightChildExist_byList(node)) { //�������� �۾�
			node = tr_bi_rightChild_byList(node);
			while (tr_bi_isInternal_byList(node)) {
				if (tr_bi_isLeftChildExist_byList(node)) {
					node = tr_bi_leftChild_byList(node);
				}
				else {
					node = tr_bi_rightChild_byList(node);
				}
			}
			return node;
		}
		else { //�ö󰡴� �۾�.
			p = tr_parent_byList(node);
			
			while (tr_bi_rightChild_byList(p) == node) {
				if (tr_bi_isRootNode_byList(p)) {
					return p;
				}
				node = p;
				p = tr_parent_byList(node);
			}
			return p;
		}
	}

	else { //external node , �ö󰡴� �۾�

		p = tr_parent_byList(node);
		if (tr_bi_leftChild_byList(p) == node) {
			return p;
		}
		else {	

			p = tr_parent_byList(node);

			while (tr_bi_rightChild_byList(p) == node) {
				if (tr_bi_isRootNode_byList(p)) {
					return p;
				}
				node = p;
				p = tr_parent_byList(node);
			}

			return p;
		}

	}

}




void tr_bi_changeToArray_byList(tr_nd_bylist* node, int sizeoftree) {

	//proper binary tree
	tr_qu100_byarr* queue;
	tr_nd_bylist* currentnode;
	tr_nd_bylist* nullnode;



	nullnode = tr_getNode_bylist(BINARY);
	nullnode->children_list->left = NULL;
	nullnode->children_list->right = NULL;
	nullnode->element->charelem = '#';
	nullnode->element->intelem = 0;

	queue = tr_queue_initQueue_byArray();
	int sizecount = 0;


	tr_queue_enQueue_byArray(queue, node);
	sizecount = 1;
	printf("  ");

	while (!tr_queue_isEmpty_byArray(queue) && sizecount <= sizeoftree) {

		currentnode = tr_queue_deQueue_byArray(queue);
		if (currentnode == nullnode) {
			printf("# ");
		}
		else {
			printf("%d ", currentnode->element->intelem);
			sizecount++;
		}


		if (tr_bi_isLeftChildExist_byList(currentnode)) {
			tr_queue_enQueue_byArray(queue, currentnode->children_list->left);
		}
		else {
			tr_queue_enQueue_byArray(queue, nullnode);
		}

		if (tr_bi_isRightChildExist_byList(currentnode)) {
			tr_queue_enQueue_byArray(queue, currentnode->children_list->right);
		}
		else {
			tr_queue_enQueue_byArray(queue, nullnode);
		}
	}

	tr_queue_freeQueue_byArray(queue);

}

//tr_nd_bylist* tr_nextNodeByLevelorder_byList(tr_nd_bylist *node) {
//
//	tr_nd_bylist* p;
//
//	if (tr_bi_isInternal_byList(node)) {
//
//		if (tr_bi_isRootNode_byList(node)) {
//			if (tr_bi_isLeftChildExist_byList(node))
//				return node->children_list->left;
//			else if (tr_bi_isRightChildExist_byList(node))
//				return node->children_list->right;
//			else {
//				tr_invalidNodeException();
//				return NULL;
//			}
//		}
//
//		p = node->parent;
//		if (node == p->children_list->left) {
//			if (tr_bi_isRightChildExist_byList(p))
//				return p;
//			else {
//				while () {
//
//				}
//			}
//		}
//		else {
//
//		}
//
//
//
//
//	}
//
//}



int print_tree_volume_submit1(tr____bylist* root, int input) {

	if ((input < 9) && (input >= 1)) {
		tr_nd_bylist* node, * child;
		node = tr_bi_levelOrder_byList(root->rootnode, input);
		printf("%d", node->element->intelem);

		child = tr_bi_leftChild_byList(node);
		if (child != NULL) printf(" %d", child->element->intelem);
		child = tr_bi_rightChild_byList(node);
		if (child != NULL) printf(" %d", child->element->intelem);

	}
	else return -1;
}
int print_tree_volume_submit2(tr____bylist* root, int input, e* element) {

	tmpelement = element;

	if (input == 1) { //pre order
		tr_bi_binaryPreOrder_byList(root->rootnode, 0);
	}
	else if (input == 2) { //post order
		tr_bi_binaryInOrder_byList(root->rootnode, 0);
	}
	else if (input == 3) { //in order
		tr_bi_binaryPostOrder_byList(root->rootnode, 0);
	}
	else {
		printf("-1");
		return;
	}
#ifdef DEBUG
	printf("%c", tmpelement->charelem);
#endif // DEBUG


#ifdef NUMBER2_1
	tmpcount = 0;
	//Order parameter integer 1 means print mode
	if (input == 1) { //pre order
		tr_bi_binaryPreOrder_byList(selected_node, 1);
	}
	else if (input == 2) { //post order
		tr_bi_binaryInOrder_byList(selected_node, 1);
	}
	else if (input == 3) { //in order
		tr_bi_binaryPostOrder_byList(selected_node, 1);
	}
	else {
		printf("-1");
		return;
	}
#endif // NUMBER2_1


#ifdef NUMBER2_2
	tmpcount = 0;
	tr_bi_binaryPostOrder_byList(selected_node, 0);
	printf("%d", tmpcount);
#endif // NUMBER2_2


}





void tr_bi_visitLeft(tr_nd_bylist* node, int* k);
void tr_bi_visitBelow(tr_nd_bylist* node);
int tr_bi_visitRight(tr_nd_bylist* node, int* k);

//About Euler Tour
int tr_bi_findSizeOfSubTree(tr_nd_bylist* node) {
	
	int k = 0;
	return tr_bi_eulerTour_byList(node, &k);
}
int tr_bi_eulerTour_byList(tr_nd_bylist *node, int *k) {


	tr_bi_visitLeft(node, k);
	if (tr_bi_isLeftChildExist_byList(node)) {

		tr_bi_eulerTour_byList(node->children_list->left, k);
	}
	tr_bi_visitBelow(node, k);
	if (tr_bi_isRightChildExist_byList(node)) {

		tr_bi_eulerTour_byList(node->children_list->right, k);
	}
	tr_bi_visitRight(node, k);

	return node->euler_size;
}
void tr_bi_visitLeft(tr_nd_bylist *node, int *k) {
	
	*k = *k + 1;
	node->euler_left = *k;
}
void tr_bi_visitBelow(tr_nd_bylist *node) {

}
int tr_bi_visitRight(tr_nd_bylist *node, int *k) {

	node->euler_size = *k - node->euler_left + 1;
	return node->euler_size;

}






int main() {

	tr____bylist* tree = NULL;
	tr_nd_bylist* currentnode = NULL;
	e* element;




	//---make the tree---//
	//---level0---//
	element = readyElement();
	*element = readySetElement(element, 20, '1');
	tree = tr_initRootNodeWithElement_byList(BINARY, element);


	//---level1---//
	element = readyElement();
	*element = readySetElement(element, 30, '2');
	tr_bi_addNodeLeftChild_byList(tree->rootnode, element);

	element = readyElement();
	*element = readySetElement(element, 50, '3');
	tr_bi_addNodeRightChild_byList(tree->rootnode, element);


	//---level2---//
	element = readyElement();
	*element = readySetElement(element, 70, '4');
	tr_bi_addNodeLeftChild_byList(tree->rootnode->children_list->left, element);

	element = readyElement();
	*element = readySetElement(element, 90, '5');
	tr_bi_addNodeRightChild_byList(tree->rootnode->children_list->left, element);


	element = readyElement();
	*element = readySetElement(element, 120, '6');
	tr_bi_addNodeRightChild_byList(tree->rootnode->children_list->right, element);


	//---level3---//
	element = readyElement();
	*element = readySetElement(element, 130, '7');
	tr_bi_addNodeLeftChild_byList(tree->rootnode->children_list->right->children_list->right, element);


	element = readyElement();
	*element = readySetElement(element, 80, '8');
	tr_bi_addNodeRightChild_byList(tree->rootnode->children_list->right->children_list->right, element);




	printf("%d\n", tr_bi_findSizeOfSubTree(tree->rootnode));


	tr_nd_bylist* tmp;

	tmp = tr_bi_preOrderSucc_byList(tree->rootnode->children_list->right);
	printf("preordersucc : %c\n", tmp->element->charelem);

	tmp = tr_bi_nextNodeByPostorder_byList(tree->rootnode->children_list->right);
	printf("postordersucc : %c\n", tmp->element->charelem);

	tmp = tr_bi_nextNodeByInorder_byList(tree->rootnode->children_list->right);
	printf("inortdersucc : %c\n", tmp->element->charelem);





	return 0;
}