/*
- 컴파일러의 설정을 변경하지 않았다면 
프로세스 안에서 지역 변수가 저장되는 기본 스택 메모리 크기는 1Mbyte이다. 
따라서 함수를 호출할 때 지역 변수가 할당되는 메모리 공간은 최대 1Mbyte를 넘을 수 없다.

	(max - min + 1) 제곱 ㄴㄴ 수가 아닌 수
- new 연산자가 메모리 할당에 실패했을 경우, 
	C++ 스탠다드에 따라 std::bad_alloc Exception을 throw한다
- exception이 throw되었기 때문에 넘겨받은 포인터가 
	NULL인지 체크하는 부분까지 진행되지도 않고 프로그램이 종료

출처: https://jangpd007.tistory.com/228 [참 놀라운 세상:티스토리]
https://foameraserblue.tistory.com/190


처음에는 내가 동적할당에서 무언가 한 값을 범위를 잘못 했다고 생각했는데,,,너무 무식한 방법이었다.
min과 max의 범위가 1조에 육박하므로 특정 환경의 pc에서 동적할당 할 경우 범위를 초과한다
32bit 기반 운영체제 pc에서 컴파일 할 경우 사용 가능한 최대 크기는 
2^32*byte = 4 * GIGA * 1Byte, 4GB이다. 이중 2GB를 주소로 사용할 수 있으므로
2^32 값을 초과할 경우 인식할 수 없다.
ex)
		메모리 한 칸은 8bit(1Byte)로 구성된다.
		32bit 운영체제의 경우.. 
		2^32*1Byte = 4.294.967.296 Byte = 4,194,304 KB = 4,096 MB = 4GB
		
		64bit 운영체제의 경우
		2^64*1Byte
		
		
		long long 형의 경우 한 데이터가 차지하는 메모리 용량은 8Byte이다.
		1조 개의 데이터가 들어갔을 떄...8조 바이트를 차지한다(OMG)
		즉 자료형에 따라 수용 가능한 최대 용량은 정해져 있다.
		각 자료형이 표현할 수 있는 크기와 범위를 생각하자
			* int - 4Byte(32 bit) - abs(2,147,483,647) - 1GB 
			* short - 2Byte(16 bit) - abs(32,767) - 2GB
			* char - 1Byte(8 bit) - abs(256) - 4GB
			* long long
			
		int 형은 4byte이므로 
		

	1Byte = 8Bit(256)
	1KB   = 2^10Byte = 1024Byte
	1MB   = 2^20Byte = 1024KB
	1GB   = 2^30Byte = 1024MB
*/

#include<iostream>

using namespace std;
int main() {
	long long arr[1000001] = {0,};
	long long min;
	long long max;
	long long result;
	cin >> min >> max;
	result = max - min + 1;
	for(long long i = 2; i * i <= max; i++) {
		long long value = min / (i*i);
		if(value * (i * i) < min)
			value ++;
		while(value * (i*i) <= max) {
			if(arr[value*(i*i) - min] == 0){
				arr[value*(i*i) - min] = 1;
				result --;
			}
			value ++;
		}
	}
	cout<<result;
}
	