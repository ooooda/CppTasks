#include <stdio.h>
#include <string.h>

void strlen2(char input[]){
    int i = 0;
    while (input[i] != '\0'){
        ++i;
    }
    printf("length of your string using function %d", i);
    printf("\n");
}

int main(){
    char input[101] = "";
    int input_length;
    printf("give string\n");
    scanf("%s", input);
    strlen2(input);
    input_length = strlen(input);
    printf("length of your string using function %d", input_length);
    printf("\n");
}

