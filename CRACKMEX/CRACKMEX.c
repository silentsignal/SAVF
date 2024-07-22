#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

typedef struct CommandStruct{
    void (*exec)(char*);
    char* name;
} Command;


void my_system(char* cmd){
    printf("my_system(%s) running \n", cmd);
    system(cmd);
    printf("my_system ended \n");
    fflush(stdout);
}

void lower(char* str){
    for (int i=0;i<strlen(str);i++){
        if (isalnum(str[i])){
            str[i]=(char)tolower(str[i]);
        }
    }
    printf("lower '%s'\n", str);
    fflush(stdout);
}

void upper(char* str){
        for (int i=0;i<strlen(str);i++){
        if (isalnum(str[i])){
            str[i]=(char)toupper(str[i]);
        }
    }
    printf("UPPER '%s'\n", str);
    fflush(stdout);
}

void menu(void){
    printf("0) UPPERCASE \n");
    printf("1) lowercase \n");
    printf("99) Exit \n");
    fflush(stdout);
}

int main(){
    void (*adminCmd)(char*);
    Command commands[2];
    char param[256]; 
    int cmd = 0; 

    commands[1].name="lower";
    commands[1].exec=lower;
    commands[0].name="upper";
    commands[0].exec=upper;
    
    adminCmd = my_system;
    
    printf("adminCmd: %llx %llx \n", &adminCmd);
    printf("commands: %llx %llx \n", &commands);
    fflush(stdout);
    adminCmd("SNDPGMMSG MSG(CRACKMEX) MSGTYPE(*INFO)");
    
    while(cmd != 99){
        menu();
        scanf("%d", &cmd);
        if (cmd == 99) break;

        printf("Parameter: ");
        fflush(stdout);
        
        /* stdin handling workaround */
        param[0]=0;
        getchar();

        /* We need spaces in params*/
        fgets(param, 256, stdin);

        /* stdin handling workaround */
        if (strlen(param) < 2) break;
        param[strlen(param)-1] = 0;
        
        Command *tmpCmd = &(commands[cmd]);
        printf("%llx %llx %llx %llx\n", *tmpCmd);
        printf("Invoking %s(%s)\n", tmpCmd->name, param);
        tmpCmd->exec(param);
        
    }
    return 0x1337;
}
