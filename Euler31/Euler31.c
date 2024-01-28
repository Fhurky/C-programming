#include <stdio.h>

int countWaysToMakeChange(int coins[], int numCoins, int targetAmount){
    int ways[targetAmount + 1];
    int i,j;
    for(i=0; i<=targetAmount; i++){
        ways[i] = 0;
    }
    ways[0] = 1;
    
    for(i=0; i<numCoins; i++){
        for(j=coins[i]; j<=targetAmount; j++){
            ways[j] += ways[j-coins[i]];
        }
    }

    return ways[targetAmount];
}

int main(){
    int coins[] = {1, 2, 5, 10, 20, 50, 100, 200};
    int numCoins = sizeof(coins) / sizeof(coins[0]);
    int targetAmount = 200;

    int ways = countWaysToMakeChange(coins, numCoins, targetAmount);

    printf("Number of ways to make £2: %d\n", ways);

    return 0;
}

