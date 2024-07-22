#include<stdio.h>

int main(){
    char buf[4];
    int num;

    scanf("%x %s", &num, buf);

    // Out-of-bounds read in both directions
    for (int i=-2; i < 8; i++){
        printf(" %02x ", buf[i]);
    }

    printf("\n%x\n", num);

    return 0;
}