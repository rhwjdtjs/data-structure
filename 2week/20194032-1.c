/*
작성자 : 20194032 고정선
작성일 : 2020년 4월 10일
프로그램명: 시간 호출 함수를 이용한 연산 시간 계산하기-1번
*/
#include <stdio.h>
#include <time.h>

int main()
{
	int i=0;
	int j=0;
	int n;
	clock_t start,stop; //clock_t형의 start, stop 변수 걸린 시간을 구하기 위한 변수
	double during; // 형변환에 의한 데이터 손실을 줄이기위하여 double형으로 변수를 선언
	int num=0; //switch 문에서의 알고리즘<1,2,3> 선택 사용
	int sum=0; //연산 결과 저장
	printf("알고리즘을 선택하세요<1, 2, 3> : ");
	scanf("%d",&num);
	printf("숫자를 입력하세요: ");
	scanf("%d",&n);
	start=clock(); // 알고리즘을 시작하기 전에 start에 시작 시간 저장
	switch(num) // 입력받은 num에 따라 1, 2, 3의 알고리즘을 실행하기 위한 switch문
	{
	case 1: // num==1
		sum=n*n;
		break;
	case 2: //num==2
		for(i=0; i<n; i++)
			sum=sum+n;
		break;
	case 3: //num==3
		for(i=0; i<n; i++)
			for(j=0; j<n; j++)
				sum=sum+1;
		break;
	default: // num != 1 && num != 2 && num != 3
		printf("잘못된 숫자를 입력하셨습니다.");
		break;
	}
	stop=clock(); // 계산이 끝난후 stop에 종료 시간 저장
	during=(double)(stop-start) / CLOCKS_PER_SEC; // 저장된 값을 이용하여 걸린 시간 계산
	printf("걸린 시간은 %f입니다.",during);
}