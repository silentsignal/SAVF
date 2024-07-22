#include<stdio.h>

int alligator1(int n, int m){
    printf("First alligator is here!\r\n");
    fflush(stdout);
    return n+m;
}

void alligator2(int n, int* out){
    printf("Second alligator is here!\r\n");
    fflush(stdout);
    *out = n+0x42;
}

void alligator3(char* str, int n){
    printf("Here is part of your message:\r\n");
    for (int i = 0; i<n; i++){
        putchar(str[i]);
    }
    printf("\r\n");
    fflush(stdout);
}

int main(){
    int num;
    int all1;
    int all2;

    printf("What's your number?\n");
    fflush(stdout);
    scanf("%d", &num);
    printf("Calling all Alligators!\n\n");
    fflush(stdout);
    all1=alligator1(num, num+0x41);
    printf("Alligator #1 returned: %d\n", all1);
    fflush(stdout);
    alligator2(all1, &all2);
    printf("Alligator #2 returned: %d\n", all2);
    fflush(stdout);
    alligator3("Alligator #3 message", num);
    return 0x1337;
}
