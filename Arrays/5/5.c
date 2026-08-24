#include <stdio.h>
#include <string.h>
#define max 100

int main(){
    int b[max];
    int freq[26] = {0};
    char a[13][256] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE","TEN","ELEVEN","TWELVE"};

    int x = 0; //we can use it later for how manu elements are there in a array
    while(1){
        scanf("%d",&b[x]);
        if(b[x] == 999){
            b[x] = '\0';
            break;
        }
        x += 1;
    }

    int l = 0;
    while(l < x){ //for b array that contains the input number
        int num = 0;
        while(a[b[l]][num] != '\0'){ //accessing the string like two,three or something with the help of the input numbers (acts as index number). accessing each character using num (index of each string)
            freq[a[b[l]][num] - 'A'] += 1; //subtracting the actual character ascii value with letter 'A' gives the range of 0 to 25
            num += 1;
        }
        l += 1;
    }

    for(int i = 0; i < 26; i++){ //it gives the index value of each alphabet to access the value of each alphabet in freq[26] 
        for(int j = 0; j < freq[i]; j++){ //accessing the value (count of alphabet) of each alphabet and looping the alphabet until the count become zero. if the count of the alphabet is zero then it will not loop
            printf("%c ",'A' + i); //if we add the first alphabet with the index it will give the alphabet
        }
    }

}