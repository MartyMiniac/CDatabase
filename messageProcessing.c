#include <stdio.h>
#include <string.h>
#define db_size 10

static int db[db_size];
static int pos=0;
void stringTokenize(char * msg, char * command, char * value) {
    int offset=0, pos=0;
    char ch=' ';
    
    while((ch=msg[pos])!='\0') {
        if(ch==' '||ch=='\n') {
            command[pos-offset]='\0';
            break;
        }

        command[pos-offset]=msg[pos];
        pos++;
    }

    pos++;
    offset=pos;

    while((ch=msg[pos])!='\0') {
        if(ch==' '||ch=='\n') {
            value[pos-offset]='\0';
            break;
        }

        value[pos-offset]=msg[pos];
        pos++;
    }
}

void performOperation(char * command, char * value, char * message) {
    int val=atoi(value);
    if(strcmp(command, "add")==0) {
        db[pos++%db_size]=val;
        strcpy(message, "data added");
    }
    else if(strcmp(command, "get")==0) {
        if(val>-1 && val<pos) {
            sprintf(message, "%d", db[val]);
        }
        else {
            strcpy(message, "index not available");
        }
    }
    else {
        strcpy(message, "invalid command");
    }
}