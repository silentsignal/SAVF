#include<stdio.h>

void func0(){
    printf("func0\n");
}

int main(){
    int intVar=0x1337;
    char chrVar='A';
    void* openPtr=func0;
    void (*funcPtr)();

    funcPtr=func0;

    printf("intVar pointer:\t%llx %llx\n", &intVar);
    printf("chrVar pointer:\t%llx %llx\n", &chrVar);
    printf("open   pointer:\t%llx %llx\n", openPtr);
    printf("func   pointer:\t%llx %llx\n", funcPtr);
    getchar();

    //openPtr(); // This won't complie...
    //funcPtr=openPtr;
    //funcPtr();

    openPtr=(void*)&chrVar;
    funcPtr=openPtr;
    funcPtr(); // MCH3602:  Pointer type not valid for requested operation.

    return 0x1337;
}

