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

void printval(char* fmt, int val){
    printf(fmt, val);
}

void printptrval(char* fmt, int* val){
    printf(fmt, *val);
}

void printptr(char* fmt, int* val){
    printf(fmt, val);
}


void alligator3(char* str, int* p, int n){
    printf("Here is part of your message: %s\r\n", str);
    printval("Original value: %d", n);
    *p = n + 0x69;
    printptrval("Pointer value: %d\r\n", p);
    printptr("Pointer address: %p\r\n", p);
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
    alligator3("Alligator #3 message", &all2, num);
    return 0x1337;
}
