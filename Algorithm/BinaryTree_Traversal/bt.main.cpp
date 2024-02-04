// 이진 트리(Binary Tree)의 구현과 순회(Traversal) 방식
// 가장 많이 사용되는 비선형 자료구조, 데이터의 탐색 속도 증진을 위해 자주 사용
// Pointer(포인터)를 사용하여 구현하는 경우 유동적으로 자료구조 활용 가능
// 전위순회(Preorder Traversal) 123
// 중위순회(Inorder Traversal) 213
// 후위순회(Postorder Traversal) 231 -> 컴퓨터가 처리하기 좋은 방식
#include <iostream>
using namespace std;

const int number = 15;
// 포인터 형태로 선언 위해 typedef struct 사용
// 하나의 노드 정보를 선언
typedef struct node* treePointer;
typedef struct node {
	int data;
	treePointer leftChild;
	treePointer rightChild;
} node ;

// 전위 순회
void preorder(treePointer ptr) {
	if (ptr) {
		cout << ptr->data << ' ';
		preorder(ptr->leftChild);
		preorder(ptr->rightChild);
	}
}
// 중위 순회
void inorder(treePointer ptr) {
	if (ptr) {
		inorder(ptr->leftChild);
		cout << ptr->data << ' ';
		inorder(ptr->rightChild);
	}
}
// 후위 순회
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


