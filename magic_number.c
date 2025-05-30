#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int reverse_number(int);
int digit_num(int);
void prn_result_message(int);

int main()
{
	while (1)
	{
		int number, result = 1;
		printf("========================");
		printf("\n���ڸ� �Է��ϼ���:");
		scanf("%d", &number);
		printf("������ ����: %d\n", reverse_number(number));
		if (number - reverse_number(number) >= 0)
		{
			int diff = number - reverse_number(number);
			printf("����: %d\n", diff);
			
			result = digit_num(diff);
			if (result > 9)
			{
				while (result > 9)
				{
					printf("�߰����: %d\n", result);
					result = digit_num(result);
				}
				printf("���: %d\n", result);
			}
			else
			{
				printf("���: %d\n", result);
			}

		}
		else
		{
			int diff = reverse_number(number) - number;
			printf("����: %d\n", diff);
			result = digit_num(diff);
			if (result > 9)
			{
				while (result > 9)
				{
					printf("�߰����: %d\n", result);
					result = digit_num(result);
				}
				printf("���: %d\n", result);
			}
			else
			{
				printf("���: %d\n", result);
			}
		}
		prn_result_message(result);

	}

	return 0;
}
int reverse_number(int number)
{
	int count = 0, num = number, multipler = 1, rev = 0;
	while (num > 0)
	{
		num = num / 10;
		count++;
	}
	for (int i = 1; i <= count; i++)
	{
		for (int j = i; j <= count-1; j++)
		{
			multipler = multipler * 10;
		}
		rev = rev + multipler * (number % 10);
		multipler = 1;
		number = number / 10;
	}
	return rev;
}
int digit_num(int diff)
{
	int count = 0, num = diff, multipler = 1, rev = 0;

	while (num > 0)
	{
		num = num / 10;
		count++;
	}

	for (int i = 1; i <= count; i++)
	{
		rev = rev + diff % 10;
		diff = diff / 10;
	}
	return rev;
}
void prn_result_message(int result)
{
	if (result >= 1 && result <= 3)   printf("���� �Ҳ��� �Ǿ�ö����ϴ�.\n");
	if (result >= 4 && result <= 6)   printf("������ ���� �������ϴ�.\n");
	if (result >= 7 && result <= 9)   printf("������ �������� �����մϴ�!\n");
}