/*
�ۼ��� : 20194032 ������
�ۼ��� : 2020�� 4�� 10��
���α׷���: �ð� ȣ�� �Լ��� �̿��� ���� �ð� ����ϱ�-2��
*/
#include <stdio.h>
#include <time.h>

int main()
{
	int i=0;
	int n;
	int a=5; //������ ���� ����
	int b=1; //������ ���� ����
	clock_t start,stop; //clock_t���� start, stop ���� �ɸ� �ð��� ���ϱ� ���� ����
	double during; // ����ȯ�� ���� ������ �ս��� ���̱����Ͽ� double������ ������ ����
	char word; //switch �������� +,-,/,*�� ���ڸ� �Է¹޾� �˰���<1,2,3> ���� ���
	double sum;  //���� ��� ����

	printf("������ �����ϼ���<+, -, *, /> : ");
	scanf("%c",&word);
	printf("�ݺ� Ƚ���� �Է��ϼ���: ");
	scanf("%d",&n);
	start=clock(); // �˰����� �����ϱ� ���� start�� ���� �ð� ����
	
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
		printf("�߸��� ���� �����Դϴ�.");
		break;
	}
	stop=clock(); // ����� ������ stop�� ���� �ð� ����
	during=(double)(stop-start) /CLOCKS_PER_SEC;// ����� ���� �̿��Ͽ� �ɸ� �ð� ���
	printf("�ɸ� �ð��� %f�Դϴ�.",during);
}