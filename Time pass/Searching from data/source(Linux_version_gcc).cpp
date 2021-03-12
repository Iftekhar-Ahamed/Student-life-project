#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <termios.h>
#include <unistd.h>
int getch(void) {
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}


struct data
{
    char name[100];
    char adress[100];
    struct data *next;
};

struct data *read_list()
{
    FILE *read = fopen("list.txt", "r");
    char s[100];
    struct data *head, *last = NULL, *tem;
    int i = 0;
    while (fscanf(read, "%s", s) != EOF)
    {
        tem = (struct data *)malloc(sizeof(struct data));
        strcpy(tem->name, s);
        fscanf(read, "%s", s);
        strcpy(tem->adress, s);
        tem->next = NULL;
        if (head == NULL)
            head = tem;
        else
            last->next = tem;
        last = tem;
    }
    return head;
}
bool nibo(char s[], char s1[])
{
    int count = 0;
    for (int i = 0; s[i] && s1[i]; i++)
    {
        if (s[i] != s1[i])
            return false;
    }
    return true;
}
struct data *show(char s[], struct data *head)
{
    int i = 0;
    struct data *temp = head, *listhead = NULL, *list_temp = NULL, *ob;
    while (temp != NULL)
    {
        if (nibo(s, temp->name))
        {

            list_temp = (struct data *)malloc(sizeof(struct data));
            strcpy(list_temp->name, temp->name);
            strcpy(list_temp->adress, temp->adress);
            list_temp->next = NULL;

            if (listhead == NULL)
            {
                listhead = list_temp;
            }
            else{
                ob->next = list_temp;
            }

            ob = list_temp;
        }
        temp = temp->next;
    }
    ob = listhead;
    while (ob != NULL)
    {
        printf("%s %s\n", ob->name, ob->adress);
        ob = ob->next;
    }
    return head;
}
int main()
{
    char search[100];
    int i = 0, n, ch;
    struct data *ob = read_list();
    search[0]='\0';

    while (1)
    {
        ch = getch();
        if (ch == '\n')
            return 0;
        if (ch == 127){
            if(i>0)--i;
             search[i]='\0',system("clear");
        }
        else
        {
            system("clear");
            search[i] = ch;
            search[++i] = '\0';
        }
        printf("%s\n",search);
        ob = show(search, ob);
    }

    while (ob != NULL)
    {
        printf("%s %s\n", ob->name, ob->adress);
        ob = ob->next;
    }
}
