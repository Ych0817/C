#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//배열의 필요성 1. 일괄처리 2. 유연성
//문자열안의 숫자 개수 계산
#if 0
int main(void) 
{
	int i;
	char *data = "178034129712637";
	int count[10] = {0};
	for(i = 0; i < strlen(data); i++) 
	//strlen보다 sizeof - 1 이 더 좋음 sizeof는 컴파일타임때 계산 
	//strlen은 런타임때 계산 for문안에서 계속해서 안 좋음
	//반복문 조건식에 동일한 결과를 가져오는 함수 호출 필요시 그전에 변수에 값을 저장해 사용할 것
	{
		count[*(data + i) - '0']++;
	}
	for(i=0; i<=9; i++){
	printf("%d : %d개 \n",i, count[i]);}
	return 0;
}
#endif