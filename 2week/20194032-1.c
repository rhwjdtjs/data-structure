/*
�ۼ��� : 20194032 ������
�ۼ��� : 2020�� 4�� 10��
���α׷���: �ð� ȣ�� �Լ��� �̿��� ���� �ð� ����ϱ�-1��
*/
#include <stdio.h>
#include <time.h>

int main()
{
	int i=0;
	int j=0;
	int n;
	clock_t start,stop; //clock_t���� start, stop ���� �ɸ� �ð��� ���ϱ� ���� ����
	double during; // ����ȯ�� ���� ������ �ս��� ���̱����Ͽ� double������ ������ ����
	int num=0; //switch �������� �˰���<1,2,3> ���� ���
	int sum=0; //���� ��� ����
	printf("�˰����� �����ϼ���<1, 2, 3> : ");
	scanf("%d",&num);
	printf("���ڸ� �Է��ϼ���: ");
	scanf("%d",&n);
	start=clock(); // �˰����� �����ϱ� ���� start�� ���� �ð� ����
	switch(num) // �Է¹��� num�� ���� 1, 2, 3�� �˰����� �����ϱ� ���� switch��
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
		printf("�߸��� ���ڸ� �Է��ϼ̽��ϴ�.");
		break;
	}
	stop=clock(); // ����� ������ stop�� ���� �ð� ����
	during=(double)(stop-start) / CLOCKS_PER_SEC; // ����� ���� �̿��Ͽ� �ɸ� �ð� ���
	printf("�ɸ� �ð��� %f�Դϴ�.",during);
}