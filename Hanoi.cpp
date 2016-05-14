#include<stdio.h>

//��
const int S = 1;
const int M = 2;
const int L = 3;

//���̍����̍ő�l
const int height = 3;

int A[height] = { L,M,S };
int B[height] = { 0,0,0 };
int C[height] = { 0,0,0 };

//-------------------------------------
//�n�m�C�̓��S�̕`��

void Print()
{
	for (int i = height - 1; i >= 0; i--)
	{
		printf("A:[%d]:%d", i, A[i]);
		printf(" B:[%d]:%d", i, B[i]);
		printf(" C:[%d]:%d\n", i, C[i]);
	}

	printf("******************************\n");
}

//-------------------------------------
//�����Ƃ��ēn���ꂽ���̎���
//(�΂̐�)��߂�l�Ƃ��ĕԂ�

int Count(int _array[])
{
	int counter = 0;

	for (int i = 0; i < height; i++)
	{
		if (0 != _array[i])
		{
			counter++;
		}
	}

	return counter;
}

void Move(int _from[],int _to[],int _work[],int n)
{
	if (0 == n)
	{
		return;
	}
	else if (n == 1)
	{
		int tmp = 0;
		tmp = _to[Count(_to)];
		_to[Count(_to)] = _from[Count(_from) - 1];
		_from[Count(_from) - 1] = tmp;

		Print();
	}
	else if(n >= 2)
	{
		Move(_from, _work, _to, n - 1);

		int tmp = 0;
		tmp = _to[Count(_to)];
		_to[Count(_to)] = _from[Count(_from) - 1];
		_from[Count(_from) - 1] = tmp;

		Print();

		Move(_work, _to, _from, n - 1);
	}

}

void main()
{	
	Print();

	Move(A, C, B, height);
	
	getchar();
}