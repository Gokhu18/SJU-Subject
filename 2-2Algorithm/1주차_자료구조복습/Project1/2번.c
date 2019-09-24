#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define RIGHT 0
#define LEFT 1

typedef struct node nd;
typedef struct tree tr;

struct node { 
	// Node ���� int �� �����͸� ���� �� �ִ� intelem �� char �� �����͸� ���� �� �ִ� charelem �� ������. 
	nd* parent;
	int intelem;
	char charelem;
	nd* leftchild;
	nd* rightchid;
};
struct tree {
	nd rootnode;
};

nd* getNode() { // �� ��带 �Ҵ��ϰ� �ʱ�ȭ�ؼ� ��ȯ���ִ� �Լ�.
	
	//�Ҵ�
	nd* newnode = NULL;
	newnode = (nd*)malloc(sizeof(nd) * 1);
	if (newnode == NULL) return;

	//init them
	newnode->charelem = '0';
	newnode->intelem = 0;
	newnode->parent = NULL;
	newnode->leftchild = NULL;
	newnode->rightchid = NULL;

	return newnode;

}

nd* makeChildNode(nd* node, int left_or_right) { // ��� ����� �ڼճ�带 ����� ��ȯ�ϴ� �Լ�
		
	nd* childnode = NULL;

	//�ڼճ�带 ���� �޸� �Ҵ�
	childnode = getNode();
	childnode->parent = node;


	//���� �ڼ����� �����
	if (left_or_right == LEFT) {
		node->leftchild = childnode;
	}
	//���� �ڼ����� �����
	if (left_or_right == RIGHT) {
		node->rightchid = childnode;
	}

	return childnode;
}
void setElement(nd* node, int intelement) { // ��� ����� element �� setting ���ִ� �Լ�

	node->intelem = intelement;

}

void visitWithId(nd* node, int current_node_number, nd** savingnode) { // ��ȸ�ϴ� ���� id ���� ���� ����� �ּҸ� ������.
	if (current_node_number == node->intelem) {
		*savingnode = node;
	}
}
void preorderAndId(nd* node, int current_node_number, nd** savingnode) { // O(n) �ð��� ������ȸ�ϴ� �˰���

	visitWithId(node, current_node_number, savingnode); // visit
	if (isLeftChildExist(node))
		preorderAndId(node->leftchild, current_node_number, savingnode);
	if (isRightChildExist(node))
		preorderAndId(node->rightchid, current_node_number, savingnode);

}
nd* findNodeById(tr* tree, int current_node_number, nd** savingnode) { // id �� ���� ��带 ã�Ƴ��� �Լ�. ������ȸ �˰����� �̿�
	preorderAndId(&(tree->rootnode), current_node_number, savingnode);
	return *savingnode;
}


int isLeftChildExist(nd* node);
int isRightChildExist(nd* node);

int main() {


	tr tree;

	int i = 0, j = 0;

	int current_node_number;
	int left_node_number;
	int right_node_number;

	int count_of_node;

	scanf("%d", &count_of_node); // ��� ����
	/* 
	
	�帧 ����

	� ��忡 id �� �޾��ְ�
	(1) �� id �� �������� ������ȸ�� ���� ��带 ã��,
	(2) �װ��� ���� �ڼ�, ���� �ڼ��� �޾���
	

	������ �� ������ ������ ��ȿ������
	�ֳ��ϸ�, �ϴ� ó���� count of node �� �� �޴��� �𸣰���.
	������ ������ȸ ������� ��带 �Է¹����ϱ�, Ž�������� ��ġ�� �ʰ� 
	������ ��ġ�� �׳� �ϳ��� ��带 �޾��ְ�, �˾Ƽ� ������ ��带 �ν��ϰ� �ڵ������� ���߰� �Ҽ��� �ְڴٴ� ������ �����.
	�׷��� �������� Node �� ������ �Է¹������ �߱� ������ �ǵ��� �װ��� �ƴ� �� ���ٴ� ������ ��� �̷��� �ڵ�����.
	
	*/

	// �Է� ������
	for (i = 0; i < count_of_node; i++) {
		scanf("%d %d %d", &current_node_number, &left_node_number, &right_node_number);
		if (i == 0) { // �ѹ��� ��带 ���� �� ���� ���
			setElement(&(tree.rootnode), current_node_number);
			setElement(makeChildNode(&(tree.rootnode), LEFT), left_node_number);
			setElement(makeChildNode(&(tree.rootnode), RIGHT), right_node_number);
		}
		else {
			nd* savingnode = NULL;
			setElement(makeChildNode(findNodeById(&(tree), current_node_number, &savingnode), LEFT), left_node_number);
			setElement(makeChildNode(findNodeById(&(tree), current_node_number, &savingnode), RIGHT), right_node_number);
		}
	}



	// Ž�� ������
	int count_of_order;
	char order[101] = { 0 };
	nd* tmpnode;
	scanf("%d", &count_of_order); // Ž�� Ƚ��
	getchar();
	for (i = 0; i < count_of_order; i++) {
		gets(order);
		tmpnode = &(tree.rootnode);
		printf(" %d", tree.rootnode.intelem);
		for (j = 0; j < strlen(order); j++) {
			if (order[j] == 'L') {
				tmpnode = tmpnode->leftchild;
			}
			else { // R
				tmpnode = tmpnode->rightchid;
			}
			printf(" %d", tmpnode->intelem);
		}
		printf("\n");
	}


	return 0;
}


int isLeftChildExist(nd* node) {
	if (node->leftchild == NULL) {
		return 0;
	}
	else {
		return 1;
	}
}
int isRightChildExist(nd* node) {
	if (node->rightchid == NULL) {
		return 0;
	}
	else {
		return 1;
	}
}

