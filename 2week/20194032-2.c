/*
작성자 : 20194032 고정선
작성일 : 2020년 4월 10일
프로그램명: 시간 호출 함수를 이용한 연산 시간 계산하기-2번
*/
#include <stdio.h>
#include <time.h>

int main()
{
	int i=0;
	int n;
	int a=5; //임의의 정수 저장
	int b=1; //임의의 정수 저장
	clock_t start,stop; //clock_t형의 start, stop 변수 걸린 시간을 구하기 위한 변수
	double during; // 형변환에 의한 데이터 손실을 줄이기위하여 double형으로 변수를 선언
	char word; //switch 문에서의 +,-,/,*의 문자를 입력받아 알고리즘<1,2,3> 선택 사용
	double sum;  //연산 결과 저장

	printf("연산을 선택하세요<+, -, *, /> : ");
	scanf("%c",&word);
	printf("반복 횟수를 입력하세요: ");
	scanf("%d",&n);
	start=clock(); // 알고리즘을 시작하기 전에 start에 시작 시간 저장
	
	switch(word)
	{
	case '+': // word=='+'
		for(i=0; i<n; i++)
			sum=a+b;
		break;
	case '-': // word=='-'
		for(i=0; i<n; i++)
			sum=a-b;
		break;
	case '*': // word=='*'
		for(i=0; i<n; i++)
			sum=a*b;
		break;
	case '/': // word=='/'
		for(i=0; i<n; i++)
			sum=a/b;
		break;
	default: // word != '+' && word != '-' && word != '*' && word != '/'
		printf("잘못된 연산 문자입니다.");
		break;
	}
	stop=clock(); // 계산이 끝난후 stop에 종료 시간 저장
	during=(double)(stop-start) /CLOCKS_PER_SEC;// 저장된 값을 이용하여 걸린 시간 계산
	printf("걸린 시간은 %f입니다.",during);
}