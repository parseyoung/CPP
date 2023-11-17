// stack & heap
// 스택은 Last in First Out 이고 지역변수들이 저장 됨, 속도는 빠름 단점은 사이즈가 작음 -> 스택오버플로우
// 힙은 사이즈가 큼, 동적메모리 할당 시 사용 단점은 메모리 배치 장소를 알기 어려움
// 만약 ptr을 재사용 하고 싶다면,
#include <iostream>

int main()
{
	int* ptr = nullptr;
	ptr = new int[100000]; // 동적 메모리 할당
	delete[] ptr; // 할당한 메모리 삭제 
	// 메모리 누수 방지를 위해 delete를 꼭 해줘야 함
	// OS에서 메모리 반납은 했지만 OS가 사용하고 있을 수도 있음
	ptr = nullptr; // 재사용 원할 시 nullptr로 초기화 필수로 해야 함.
	
	return 0;
}