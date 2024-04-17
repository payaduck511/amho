#include <stdio.h>

typedef unsigned char uchar;

#define BLOCK_SIZE 8
#define ROUND_NUM 3
#define KEY_SIZE 8

uchar F1(uchar in);
uchar F2(uchar in);
uchar Feistel_Enc(uchar in);
uchar Feistel_Dec(uchar in);

uchar F1(uchar in)
{
	uchar tbl[KEY_SIZE] = { 0x05, 0x02, 0x03, 0x06, 0x04, 0x01, 0x07, 0x00 };

	if (in >=0 && in <= KEY_SIZE) return tbl[in];
	return 0;
}

uchar F2(uchar in)
{
	uchar tbl[KEY_SIZE] = { 0x04, 0x00, 0x03, 0x07, 0x06, 0x05, 0x01, 0x02 };

	if (in >= 0 && in <= KEY_SIZE) return tbl[in];
	return 0;
}

uchar Feistel_Enc(uchar in)
{
	uchar temp, left, right, mask = KEY_SIZE - 1;
	int i, half_size = BLOCK_SIZE / 2;

	left = (in >> half_size) & mask;
	right = in & mask;
	for (i = 0; i < ROUND_NUM; i++)
	{
		if (i == 0)
			left = left ^ F1(right);
		else if (i == 1)
			left = left ^ F2(right);

		if (i != ROUND_NUM - 1)
		{
			temp = left;
			left = right;
			right = temp;
		}
	}
	return (left << half_size) | right;
}

uchar Feistel_Dec(uchar in)
{
	uchar temp, left, right, mask = KEY_SIZE - 1;
	int i, half_size = BLOCK_SIZE / 2;

	left = (in >> half_size) & mask;
	right = in & mask;
	for (i = 0; i < ROUND_NUM; i++)
	{
		if (i == 0)
			left = left ^ F2(right);
		else if (i == 1)
			left = left ^ F1(right);

		if (i != ROUND_NUM - 1)
		{
			temp = left;
			left = right;
			right = temp;
		}
	}
	return (left << half_size) | right;
}

void main()
{
	uchar p_bit = 0x2B, c_bit, d_bit;
	int temp = 0, i = 0;

	printf("* 평문 : ");
	for (i = BLOCK_SIZE - 1; i >= 0; i--)
	{
		temp = (p_bit >> i) & 0x01;
		printf("%d ", temp);
	}
	printf("\n");

	c_bit = Feistel_Enc(p_bit);

	printf("* 암호문 : ");
	for (i = BLOCK_SIZE - 1; i >= 0; i--)
	{
		temp = (c_bit >> i) & 0x01;
		printf("%d ", temp);
	}
printf("\n");

d_bit = Feistel_Dec(c_bit);
printf("* 복호문 : ");
for (i = BLOCK_SIZE - 1; i >= 0; i--)
{
	temp = (d_bit >> i) & 0x01;
	printf("%d ", temp);
}
printf("\n ");
}