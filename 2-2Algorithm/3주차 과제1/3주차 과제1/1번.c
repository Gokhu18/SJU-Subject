#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct Node {
	char elem;
	struct Node* prev;
	struct Node* next;
}Node; // ��� ����


typedef struct List {
	struct Node* header;
	struct Node* trailer;
}List; // ����Ʈ ����


void init_list(List* list) {

	//����� Ʈ���Ϸ� �Ҵ�
	list->header = (Node*)malloc(sizeof(Node) * 1);
	list->trailer = (Node*)malloc(sizeof(Node) * 1);

	//����� Ʈ���Ϸ� �ʱ�ȭ
	list->header->next = list->trailer;
	list->trailer->prev = list->header;
	list->header->prev = NULL;
	list->trailer->next = NULL;
}


Node* getNode() {

	Node* newnode = NULL; // ���ο� ��� ������ ����
	newnode = (Node*)malloc(sizeof(Node) * 1);
	if (newnode == NULL)return;

	newnode->elem = '0';
	newnode->next = NULL;
	newnode->prev = NULL;


	return newnode; // ���� �޸𸮸� �Ҵ���� ��� ��ȯ
}
void linkNode(Node *prevnode, Node* newnode, Node* nextnode) { // add �Լ����� ȣ��Ǵ� �Լ�
	prevnode->next = newnode;
	newnode->next = nextnode;
	newnode->prev = prevnode;
	nextnode->prev = newnode;
}
void unlinkNode(Node* prevnode, Node* currentnode, Node* nextnode) { // delete �Լ����� ȣ��Ǵ� �Լ�
	prevnode->next = nextnode;
	nextnode->prev = prevnode;
}


#define SELECT 0
#define INSERT 1
int isInvalidRankException(List list, int select_or_insert, int position) { // input �� position �� invalid ���� �˾ƺ��� �Լ�

	Node* np = list.header;
	int cnt = 0;
	while (np->next != list.trailer) { // �ִ� ������ count �մϴ�. Trailer �� ��Ÿ�������� ������ ���� position �� ���ϱ� ����
		np = np->next;
		cnt++;
	}

	if (select_or_insert == INSERT) { // ����, ��� ���� �� invalid �� �˻��ϴٸ� INSERT ���� ����
		if (cnt + 1 < position || position < 0) {
			printf("invalid position\n");
			return 1;
		}
		else return 0;
	}
	else { // ����, ��带 �����ؼ� ó���ؾ� �ϴ� ��Ȳ invalid �� �˻��Ѵٸ� SELECT ���� ����
		if (cnt < position || position <= 0) {
			printf("invalid position\n");
			return 1;
		}
	}
	return 0;
}

void add(List list, int position, char item) {

	if (isInvalidRankException(list, INSERT, position)) return;
	
	Node* prevnode = list.header;
	Node* nextnode = list.header->next;

	Node* newnode = NULL; // ���� �Ҵ���� ��� �޸�
	newnode = getNode();
	newnode->elem = item;

	int i; // ��ġ ã�ư��� for loop
	for (i = 1; i < position; i++, 
		prevnode = prevnode->next,
		nextnode = nextnode->next) {
	}
	// ���� �߰��� ��ġ�� ��, �ĸ� ���.

	linkNode(prevnode, newnode, nextnode); // ���� ���, ���� ���, ���� ��带 �������ִ� �Լ�
}

int delete(List list, int position) {

	if (isInvalidRankException(list, SELECT, position)) return;

	Node* currentnode = list.header;
	Node* nextnode = list.header->next;

	int i; // ��ġ ã�ư��� for loop
	for (i = 0; i < position; i++,
		currentnode = currentnode->next,
		nextnode = nextnode->next) {
	}
	// ���� ������ ����� ���� ��带 ���.
	
	unlinkNode(currentnode->prev, currentnode, nextnode); // ���� ���, ���� ���, ���� ��带 �����ִ� �Լ�
	int e = currentnode->elem;
	free(currentnode);
	return e;
}

int get_entry(List list, int position) { 

	if (isInvalidRankException(list, SELECT, position)) return;



	Node* currentnode = list.header;
	Node* nextnode = list.header->next;

	int i; // ��ġ ã�ư��� for loop
	for (i = 0; i < position; i++,
		currentnode = currentnode->next,
		nextnode = nextnode->next) {
	}
	// ���� ���� ����� ���� ��带 ���.

	char e = currentnode->elem;
	printf("%c\n", e);
	return e;
}

void print(List list) {

	Node* np = list.header;
	np = np->next;

	while (np != list.trailer) {
		printf("%c", np->elem);
		np = np->next;
	}
	printf("\n");

}

void free_list(List list) {


	Node* currentnode = list.header->next; // ���� ����ִ� ��� : currentnode
	Node* nextnode = list.header->next->next; // ���� ����ִ� ���� ��� : currentnode->next

	while (currentnode != list.trailer) {

		unlinkNode(currentnode->prev, currentnode, nextnode); // ��ũ ����
		free(currentnode); // Ÿ�� ��� ����

		currentnode = nextnode;
		nextnode = currentnode->next;

	}

	free(list.header);
	free(list.trailer);
}


int main(void) {

	List list;			// ����Ʈ ����
	char op, item;		// �Է� ������ ����, ������
	int position;		// �Է� ��ġ
	int num_op;			// ������ ����
	

	init_list(&list);		// ����Ʈ �ʱ�ȭ (���, Ʈ���Ϸ� ��� �Ҵ� �� �ʱ�ȭ)
	scanf("%d", &num_op);	// ���� ���� �Է�
	

	
	for (int i = 0; i < num_op; ++i) {
		getchar();			// ���� �Ǵ� ���๮�� �б�
		scanf("%c", &op);	// ���� ����
		switch (op) {

		case 'A': // ����
			scanf("%d %c", &position, &item);
			add(list, position, item);
			break;

		case 'D': // ����
			scanf("%d", &position);
			delete(list, position);
			break;

		case 'G': // ����
			scanf("%d", &position);
			get_entry(list, position);
			break;

		case 'P': // ���
			print(list);
			break;
		}
	}


	free_list(list); // ����Ʈ�� ��� ����


	return 0;
}