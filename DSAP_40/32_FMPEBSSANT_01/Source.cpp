// Find maximum profit earned by buying
// and selling shares any number of times

//Stock Prices : {1, 5, 2, 3, 7, 6, 4, 5}
//
//Total profit earned is 10
//
// day = index + 1
//Buy on day 1 and sell on day 2
//Buy on day 3 and sell on day 5
//Buy on day 7 and sell on day 8
//
//Stock Prices : {10, 8, 6, 5, 4, 2}
//
//Total profit earned is 0

#include <stdio.h>

int findMaxProfit(int priceArr[], int lenPriceArr)
{
	int sumProfit = 0;
	int j = 0;
	for (int i = 1; i < lenPriceArr; i++)
	{
		if (priceArr[i - 1] > priceArr[i])
		{
			j = i;
		}

		if (priceArr[i - 1] <= priceArr[i] 
			&& (i == lenPriceArr - 1 || priceArr[i] > priceArr[i + 1]))
		{
			sumProfit += priceArr[i] - priceArr[j];
			printf("Buy on day %d and sell on day %d",
				j + 1, i + 1);
			printf("\n");
		}
	}
	return sumProfit;
}
int main()
{
	int priceArr[] = { 1, 5, 2, 3, 7, 6, 4, 5 };
	int lenPriceArr = sizeof(priceArr) / sizeof(priceArr[0]);

	printf("Total profit earned is %d", findMaxProfit(priceArr, lenPriceArr));
}