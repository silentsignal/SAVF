#include<stdio.h>

void inner(int i){    
    for (int j=0;j<10;j++){
        int x = i + j;
        printf("Inner loop: %d", x);
    }
}

int main(){
    for (int i=0; i<100; i+=10){
        printf("Outer loop: %d\n",i);
        inner(i);
    }
    return 0x1337;
}