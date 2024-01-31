// ���� Ʈ��(Binary Tree)�� ������ ��ȸ(Traversal) ���
// ���� ���� ���Ǵ� ���� �ڷᱸ��, �������� Ž�� �ӵ� ������ ���� ���� ���
// Pointer(������)�� ����Ͽ� �����ϴ� ��� ���������� �ڷᱸ�� Ȱ�� ����
// ������ȸ(Preorder Traversal) 123
// ������ȸ(Inorder Traversal) 213
// ������ȸ(Postorder Traversal) 231 -> ��ǻ�Ͱ� ó���ϱ� ���� ���
#include <iostream>
using namespace std;

const int number = 15;
// ������ ���·� ���� ���� typedef struct ���
// �ϳ��� ��� ������ ����
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild;
	treePointer rightChild;
} node ;

// ���� ��ȸ
void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
// ���� ��ȸ
void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}
// ���� ��ȸ
void postorder(treePointer ptr) {
	if (ptr) {
		postorder(ptr->leftChild);
		postorder(ptr->rightChild);
		cout << ptr->data << ' ';
	}
}
int main(void) {

	node nodes[number + 1];
	for (int i = 1; i <= number; i++) {
		nodes[i].data = i;
		nodes[i].leftChild = NULL;
		nodes[i].rightChild = NULL;
	}

	for (int i = 1; i <= number; i++) {
		if (i % 2 == 0) {
			nodes[i / 2].leftChild = &nodes[i];
		}
		else {
			nodes[i / 2].rightChild = &nodes[i];
		}
	}
	cout << "Preorder Traversal: ";
	preorder(&nodes[1]);
	cout << endl;

	cout << "Inorder Traversal: ";
	inorder(&nodes[1]);
	cout << endl;

	cout << "Postorder Traversal: ";
	postorder(&nodes[1]);
	cout << endl;

	return 0;
}


