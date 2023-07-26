#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "../../lib/vrs_str.h"

const char resource_location[17] = "/usr/vrs/concert/";
const char user_location[19] = "~/.vreiras/concert/";

int main(int argc, char** argv){
    FILE* conf = fopen("/usr/vrs/concert/concert.conf","r");
    char buffer[1024];
    char src[1020];
    char terminalCommand[1025];
    char target[128];
    char pyfile[128];
    for(int i = 0; i < 17; i++){
        src[i] = resource_location[i];
        pyfile[i] = resource_location[i];
    }
    for(int i = 0; i < 19; i++){
        target[i] = user_location[i];
    }
    while(fgets(buffer,1024,conf)){
        if(substreq(buffer,"src=",4)){
            for(int i = 0; i < 1020 && buffer[i+4] != '\n'; i++){
                src[i] = buffer[i+4];
            }
        }
        if(substreq(buffer,"tgt=",4)){
            for(int i = 0; i < 108 && buffer[i+4] != '\n'; i++){
                target[i+19] = buffer[i+4];
            }
        }
        if(substreq(buffer,"pyfile=",7)){
            for(int i = 0; i < 111 && buffer[i+7] != '\n'; i++){
                pyfile[i+17] = buffer[i+7];
            }
        }
    }
    system("mkdir -p ~/.vreiras");
    system("mkdir -p ~/.vreiras/concert");
    sprintf(terminalCommand,"curl %s > %s",src,target);
    system(terminalCommand);
    //FILE* json = fopen(target,"r");
    //fgets(buffer,1024,json);
    sprintf(terminalCommand,"python %s %s",pyfile,target);
    system(terminalCommand);
}
