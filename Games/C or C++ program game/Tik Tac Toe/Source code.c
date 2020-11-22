/*I have only use c language and only using stdio.h and conio.h
Game is supportable linux and Windows 
Follow instruction.*\
#include<stdio.h>
#if windows
#include<conio.h>
#endif // windows
#define clrscr() printf("\e[1;1H\e[2J")
char player[3][3];
int flag=0,trace=0;

void refresh_board(){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            player[i][j]=' ';
        }
    }
}
void print_head(){
    printf("  --- Tik Tac Toe Board ---\n");
}
void print_mid(){
    printf("    -------------------    \n");
}
void print_board(){
int i,j;
print_head();
for(i=0;i<3;i++){

        printf("\t %c | %c | %c \n",player[i][0],player[i][1],player[i][2]);

        if(i!=2)print_mid();
}
printf("\n");
}
int compare(char *s){
int i;
char con[]={"quite"};
for(i=0;i<5;i++){
    if(s[i]>='A'&&s[i]<='Z'){
        s[i]+=32;
    }
    if(s[i]=='\0')
    {
        break;
    }
}
int c=0;
for(i=0;i<5;i++){
    if(s[i]==con[i]){
        c++;
    }else if(s[i]=='\0')
    {
        break;
    }

}
if(c==5){
    return 1;
}else
{
    return 0;
}
return 0;
}
int player_entry(int x,char *name){
    int i,j,f=1;
    char data[5];
    char c;
    printf("Player %d (%s), please enter your move: ",x,name);
    scanf("%s",&data);
    clrscr();
    if(compare(data)){
       return 1;
    }
    else{
        i=data[0]-'0';
        j=data[2]-'0';
         printf("\n");
        if(player[i-1][j-1]!=' '||i>3||j>3){
             printf("INVALID MOVE. PLEASE TRY AGIN.\n");
             return player_entry(x,name);

        }else{
             if(x==1){
             player[i-1][j-1]='X';
            }else
            {
               player[i-1][j-1]='O';
            }
            trace++;
         print_board();
        }
         return 0;
    }
}
void row(){
    if((player[0][0]==player[0][1]&&player[0][1]==player[0][2])&&player[0][0]!=' '){
            flag=1;
    }
    if((player[1][0]==player[1][1]&&player[1][1]==player[1][2])&&player[1][0]!=' '){
            flag=1;
    }
    if((player[2][0]==player[2][1]&&player[2][1]==player[2][2])&&player[2][0]!=' '){
            flag=1;
    }
}
void oto(){
    if((player[0][0]==player[1][1]&&player[1][1]==player[2][2])&&player[0][0]!=' '){
            flag=1;
    }
    if((player[0][2]==player[1][1]&&player[1][1]==player[2][0])&&player[2][0]!=' '){
            flag=1;
    }
}
void coloumn(){
    if((player[0][0]==player[1][0]&&player[0][0]==player[2][0])&&player[0][0]!=' '){
            flag=1;
    }
    if((player[0][1]==player[1][1]&&player[0][1]==player[2][1])&&player[0][1]!=' '){
            flag=1;
    }
    if((player[0][2]==player[1][2]&&player[0][2]==player[2][2])&&player[2][2]!=' '){
            flag=1;
    }
}
void calculate(){
    row();
    oto();
    coloumn();

}
int main(){
flag=trace=0;
char player1[50];
char player2[50];
clrscr();
printf("Please enter the name of player 1 (X):" );
scanf("%s",&player1);
printf("\nPlease enter the name of player 2 (O):" );
scanf("%s",&player2);
printf("\n");
clrscr();
refresh_board();
print_board();
int i=0,c;
int d;
while(1){
if(player_entry(1,player1))break;
calculate();
if(flag){
    printf("CONGRATS Player 1(%s)!!! YOU ARE THE WINNER.\n",player1);
    printf("Do YOU WANNA PLAY AGIN?\n[1].YES.\n[2].NO\n");
    scanf("%d",&d);
    if(d==1){
         return main();
    }else{
     break;
    }
}
if(trace>=9){
    printf("MATCH DRAW!!!\n");
    printf("Do YOU WANNA PLAY AGIN?\n[1].YES.\n[2].NO\n");
    scanf("%d",&d);
    if(d==1){
         return main();
    }else{
     break;
    }
}

if(player_entry(2,player2))break;
calculate();
if(flag){
    printf("CONGRATS Player 2(%s)!!! YOU ARE THE WINNER.\n",player2);
    printf("Do YOU WANNA PLAY AGIN?\n[1].YES.\n[2].NO\n");

    scanf("%d",&d);
    if(d==1){
         return main();
    }else{
     break;
    }

}
if(trace>=9){
    printf("MATCH DRAW!!!\n");
    printf("Do YOU WANNA PLAY AGIN?\n[1].YES.\n[2].NO\n");
    scanf("%d",&d);
    if(d==1){
         return main();
    }else{
     break;
    }
}

}
printf("---GAME END---\nMade by ^IFTEKHAR AHAMED SIDDIQUEE^\n");
    return 0;
}
