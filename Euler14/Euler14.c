#include <stdio.h>

long long int collatz_sequence_length(long long int n){
	
    long long int length = 1;   
    while(n != 1){
        if(n % 2 == 0){
            n = n/2;
        }else{
            n = 3*n + 1;
        }
        length++;
    }
    return length;
}

int main(){
    long long int max_starting_number = 0;
    long long int max_chain_length = 0;
    long long int i;
    
    for(i=1; i<1000000; i++){
        long long int current_chain_length = collatz_sequence_length(i);

        if(current_chain_length > max_chain_length){
            max_chain_length = current_chain_length;
            max_starting_number = i;
        }
    }

    printf("Starting number under one million that produces the longest chain: %lld\n", max_starting_number);
    printf("Length of the chain: %lld\n", max_chain_length);

    return 0;
}

