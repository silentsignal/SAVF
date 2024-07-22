#include<stdio.h>

int alligator1(int n){
    printf("First alligator is here!");
    fflush(stdout);
    return n;
}

void alligator2(int n, int* out){
    printf("Second alligator is here!");
    fflush(stdout);
    *out = n*2;
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
    all1=alligator1(num);
    printf("Alligator #1 returned: %d\n", all1);
    fflush(stdout);
    alligator2(all1, &all2);
    printf("Alligator #2 returned: %d\n", all2);
    fflush(stdout);
    return 0x1337;
}
