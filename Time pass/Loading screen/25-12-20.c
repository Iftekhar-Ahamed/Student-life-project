#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include <unistd.h>
using namespace std;
void loding(){
int c=2,t=3;
fflush(stdout);
sleep(3);
while(c--){
    system("clear");
    printf("Loading");
    t=3;
    while(t--){
        printf(".");
        fflush(stdout);
        sleep(1);
    }
}
system("clear");
}


int main(){

printf("Hey Redwan noob coder name is comming...");
loding();
printf("Hehe...I am Iftekhar.\n");
return 0;
}
