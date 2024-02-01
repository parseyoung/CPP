// �÷��̵� �ͼ� �˰��� (Floyd Warshall)
// ��� �������� ��� ���������� �ִ� ��� ���ϱ�
// ��ó���� ������ �������� �˰����� ���� ��
// X -> Y �ּҺ�� VS X���� node 1 + node1���� Y ���
// D[2, 3] vs (D[2,1] + D[1,3])

#include <iostream>
using namespace std;

const int number = 4;
int INF = 100000000;

// �ڷ� �迭 �ʱ�ȭ
int a[4][4] = {
	{0, 5, INF, 8},
	{7, 0, 9, INF},
	{2, INF, 0, 4},
	{INF, INF, 3, 0}
};

void floydWarshall() {
	// ��� �׷��� �ʱ�ȭ 
	int d[number][number];

	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			d[i][j] = a[i][j];
		}
	}

	// K : ���İ��� ���, i : ��� ���, j : ���� ���
	for (int k = 0; k < number; k++) {
		for (int i = 0; i < number; i++) {
			for (int j = 0; j < number; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
				}
			}
		}
	}

	// result print
	for (int i = 0; i < number; i++) {
		for (int j = 0; j < number; j++) {
			cout << d[i][j] << ' ';;
		}
		cout << endl;

	}
}

int main(void) {
	floydWarshall();
	return 0;
}