#ifndef DATAHANDLER_H
#define DATAHANDLER_H
void datahandler_init();
void datahandler_addData(char * key, char * value);
char * datahandler_getData(char * key);
#endif