/*
�ۼ���: 20194032 ������
�ۼ���: 2020�� 3�� 26��
���α׷��� : ����������� �̿��� �ִ�, �ּҰ� ���
*/
#include <stdio.h>
#include <stdlib.h>
int main()
{
	int i=0;//�ݺ������
	int max=0,min=0; //�ִ밪,�ּҰ��� Ȯ���� �ε�����ȣ
	int data[10000];
	int num; //������ ��°����� ���� ����
	int check=0; //�ִ밪,�ּҰ� ������ ���� ����
	int count=0; //���Ͼȿ� ���ڰ���Ȯ��
	FILE *fp;
	fp=fopen("data.txt","r");

	if(fp==NULL)
	{
		printf("�ؽ�Ʈ ������ ������ �ʾҽ��ϴ�."); //�����̾����� ����  
		exit(1);
	}
    printf("��� �����;� ��������� ������ �ּ���: ");
	scanf("%d",&num);

	for(i=1; i<=num; i++)
	{
		printf("%4d",i);
	}
	printf("\n");
		printf("===============================================================\n");
	while(!feof(fp))
	{
		fscanf(fp,"%d",&data[count]); //fscanf�� ���Ͼȿ� ���� ���� data �迭�� �ҷ���
		count++;
	}
	max=data[0];
	min=data[0]; // �ִ밪 �ּҰ� ������ ���� ���� �ʱ�ȭ

	for(i=0; i<count; i++) //�迭�ȿ� �ִ� �ִ������
	{
		if(data[i]>data[max]) //�迭���� ���� ���� �ִ밪 ���� ũ�ٸ�
		{
			max=i; //�ε����� ���� i�� ����
		}
		if(data[i]<data[min]) //�迭���� ���� ���� �ּҰ� ���� �۴ٸ�
		{
		    min=i; //�ε����� ���� i�� ����
		}
	}
	
	for (i = 0; i < count; i++)
	{
		printf("%4d", data[i]); //data[i]�ȿ� �ִ� ��� ���� ���

		if ((i + 1) % num == 0 && i != 0) //���ٿ� �Է��� ���ڸ�ŭ ���
		{
			printf("\n");
			

		while(1)
		{
			if(check==max) //check ������ max�� �ε���  ��ȣ�� ������
				printf("�ִ밪"); //�ִ밪 ���
			else if(check==min) //check ������ mmin�� �ε���  ��ȣ�� ������
				printf("�ּҰ�"); //�ּҰ� ���
			else
				printf("    "); //�������
			check++;
			if(check % num==0) //���ٿ� �Է��� ����ŭ ���
			{
				printf("\n");
					break;
			}
		}
		}
	}
	fclose(fp);	
}