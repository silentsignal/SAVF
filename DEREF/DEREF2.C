#include<stdio.h>

void derefChar(char* buf){
    printf("Deref char: %c\n", buf[0]);
    fflush(stdout);
}

void derefCastedChar(void* ptr){
    printf("Ptr: %llx %llx\n", ptr);
    char* buf=(char*)ptr;
    printf("Deref casted char: %c\n", buf[1]);
    fflush(stdout);
}

void derefFuncPtr(void* ptr){
    char *dummy="xxxx";
    printf("Func Ptr: %llx %llx\n", ptr);
    void (*fp)(char*) = ptr;
    printf("Calling funcptr...\n");
    fflush(stdout);
    fp(dummy);
}

int main(){
    char buf[16];
    void* fp=derefChar;
    printf("Buf: ");
    fflush(stdout);
    scanf("%s", buf);

    derefChar(buf);
    
    derefFuncPtr(derefChar);
    
    derefCastedChar((void*)buf);

    derefCastedChar(derefChar);

    return 0x1337;
}