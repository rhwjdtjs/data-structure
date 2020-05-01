/*
작성자: 20194032 고정선
작성일: 2020년 3월 26일
프로그램명 : 파일입출력을 이용한 최대, 최소값 출력
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i=0;//반복문사용
	int max=0,min=0; //최대값,최소값을 확인할 인덱스번호
	int data[10000];
	int num; //데이터 출력개수를 위한 변수
	int check=0; //최대값,최소값 선언을 위한 변수
	int count=0; //파일안에 숫자갯수확인
	FILE *fp;
	fp=fopen("data.txt","r");

	if(fp==NULL)
	{
		printf("텍스트 파일이 열리지 않았습니다."); //파일이없으면 종료  
		exit(1);
	}
    printf("몇개의 데이터씩 출력할지를 선택해 주세요: ");
	scanf("%d",&num);

	for(i=1; i<=num; i++)
	{
		printf("%4d",i);
	}
	printf("\n");
		printf("===============================================================\n");
	while(!feof(fp))
	{
		fscanf(fp,"%d",&data[count]); //fscanf로 파일안에 숫자 수를 data 배열로 불러옴
		count++;
	}
	max=data[0];
	min=data[0]; // 최대값 최소값 저장을 위해 변수 초기화

	for(i=0; i<count; i++) //배열안에 있는 최대수까지
	{
		if(data[i]>data[max]) //배열안의 수가 현재 최대값 보다 크다면
		{
			max=i; //인덱스의 값을 i에 저장
		}
		if(data[i]<data[min]) //배열안의 수가 현재 최소값 보다 작다면
		{
		    min=i; //인덱스의 값을 i에 저장
		}
	}
	
	for (i = 0; i < count; i++)
	{
		printf("%4d", data[i]); //data[i]안에 있는 모든 숫자 출력

		if ((i + 1) % num == 0 && i != 0) //한줄에 입력한 숫자만큼 출력
		{
			printf("\n");
			

		while(1)
		{
			if(check==max) //check 변수가 max의 인덱스  번호와 같으면
				printf("최대값"); //최대값 출력
			else if(check==min) //check 변수가 mmin의 인덱스  번호와 같으면
				printf("최소값"); //최소값 출력
			else
				printf("    "); //공백출력
			check++;
			if(check % num==0) //한줄에 입력한 수만큼 출력
			{
				printf("\n");
					break;
			}
		}
		}
	}
	fclose(fp);	
}