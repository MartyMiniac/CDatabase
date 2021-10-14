#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#include "datahandler.h"

void stringTokenize(char * msg, char ** inputs) {
    bool quoteOpen=false;
    int index=0, pos=0;
    char * buf = malloc(sizeof(char)*100);
    strcpy(buf, "");

    for(int i=0; msg[i]!='\n'; i++) {
        if(!quoteOpen && (msg[i]==' ' || msg[i]=='\n')) {
            inputs[index]=buf;
            buf=malloc(sizeof(char)*100);
            strcpy(buf, "");
            index++;
            continue;
        }
        
        if(msg[i]=='"') {
            quoteOpen=!quoteOpen;
            continue;
        }
        
        strncat(buf, &msg[i], 1);
        pos++;
    }

    inputs[2]=buf;    
}

void performOperation(char ** inputs, char * message) {
    if(strcmp(inputs[0], "add")==0) {
        datahandler_addData(inputs[1], inputs[2]);
        strcpy(message, "data added");
    }
    else if(strcmp(inputs[0], "get")==0) {
        char * val=datahandler_getData(inputs[1]);
        if(val!=NULL) {
            sprintf(message, "%s", val);
        }
        else {
            strcpy(message, "key not found");
        }
    }
    else {
        strcpy(message, "invalid command");
    }
}