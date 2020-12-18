

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct information
{
    long long int id;
    char name[20];
    char grade[3];
    float present,assignment,mid,presention,final,total;
};
int n,i,len_max=0,j=0;

//Functions name:-
void input_data(struct information s_d[]);
void print_data(struct information s_d[]);
void assign_gpa(struct information s_d[]);
void readfile(struct information s_d[]);
void len_name(struct information s_d[]);
void savefile(struct information s_d[]);
void number (char temp[],struct information s_d[]);
void number1 (char temp[],struct information s_d[]);
void number2 (char temp[],struct information s_d[]);
void number3 (char temp[],struct information s_d[]);
void number4 (char temp[],struct information s_d[]);
void name (char temp[],struct information s_d[]);
void
numberid (char temp[],struct information s_d[]);


//Functon start.
int main()
{ 
    int l;
    printf("Asalamualikum User.\nWhat do you want?\n[1]Enters number\n[2]Read from file\nAns:");
    scanf("%d",&l);
    if(l==2)
    {
      printf("How much student you have in file?\nAns:");
      scanf("%d",&n);
      struct information s_d[n];
      readfile(s_d);
      assign_gpa(s_d);
      print_data(s_d);
      savefile(s_d);
    }
    else
    {
      printf("Enter student number:");
      scanf("%d",&n);
      struct information s_d[n];
      input_data(s_d);
      assign_gpa(s_d);
      print_data(s_d);
    }  
    printf("\n\nThank You+_+IFTEKHAR.\n\n\n");
}
void input_data(struct information s_d[])
{
    for(i=0;i<n;i++)
    {
        printf("Serial No: %d\n",i+1);
        printf("Student id:");   scanf("%lld",&s_d[i].id);
        printf("Student name:"); scanf(" %[^\n]%*c",s_d[i].name);
        printf("Prasent:");      scanf(" %f",&s_d[i].present);
        printf("Assignment:");   scanf("%f",&s_d[i].assignment);
        printf("Mid:");          scanf("%f",&s_d[i].mid);
        printf("Presention:");   scanf("%f",&s_d[i].presention);
        printf("Final:");        scanf("%f",&s_d[i].final);
        printf("\n");
    }
}
void print_data(struct information s_d[])
{  
    for(i=0;i<n;i++)
    {
      printf("\nSirial      : %d\nId          : %lld\nName        : %s\nPresent     : %.2f\nAssignment  : %.2f\nMid         : %.2f\nPresentation: %.2f\nFinal       : %.2f\nTotal       : %.2f\nGPA         : %s\n",i+1,s_d[i].id,
                                   s_d[i].name,
                                   s_d[i].present,
                                   s_d[i].assignment,
                                   s_d[i].mid,
                                   s_d[i].presention,
                                   s_d[i].final,
                                   s_d[i].total,
                                   s_d[i].grade); 
    }
}
void assign_gpa(struct information s_d[])
{
    for(i=0;i<n;i++)
    {
        s_d[i].total=s_d[i].present+s_d[i].assignment+s_d[i].mid+s_d[i].presention+s_d[i].final;

        if(s_d[i].total>80)        strcpy(s_d[i].grade,"A+");
        else if (s_d[i].total>=70) strcpy(s_d[i].grade,"A");
        else if(s_d[i].total>= 60) strcpy(s_d[i].grade,"A-");
        else if(s_d[i].total>=50)  strcpy(s_d[i].grade,"B");
        else if(s_d[i].total>=40)  strcpy(s_d[i].grade,"C");
        else if(s_d[i].total>=33)  strcpy(s_d[i].grade,"D");
        else                       strcpy(s_d[i].grade,"F");
    }
}
void readfile(struct information s_d[])
{
  i=1;
   int d,c = 0;
  char temp[2000];
  FILE* fp=fopen("read.txt","r");

   while(temp[c]!=EOF)
  {
    c++;
    
    temp[c] = fgetc(fp);
    
  }
 

for(d=0;d<n;d++)
{
  numberid (temp,s_d);
  name (temp,s_d);
  number (temp,s_d);
  number1 (temp,s_d);
  number2 (temp,s_d);
  number3 (temp,s_d);
  number4 (temp,s_d);
  j++;
}
}
void savefile(struct information s_d[])
{
    FILE *save_info;
    i=0;
    save_info=fopen("save.txt","w");
     if (save_info == NULL)
    {
        printf("Could not open file");
        
    }
    else
    {
        int c=0,b;
        len_name(s_d);
        fprintf(save_info,"                  BUBT SPRING 2020 INTAKE 44 SECTOION 06 TOTAL RESULT\n");
        fprintf(save_info,"                 ******************************************************\n\n");
        fprintf(save_info,"S.No.      ID        NAME");

        for(c=9;c<=len_max;c++)
            {
             fprintf(save_info," ");
            }

        fprintf(save_info,"PRESENT  Assignment  MID  PRESENTATION  FINAL   TOTAL  GPA\n");

        for(i=0;i<n;i++)
        {
            fprintf(save_info,"%d\t"          ,i+1);
            fprintf(save_info," ");
            fprintf(save_info,"%lld "         ,s_d[i].id);
            fprintf(save_info," ");
            fprintf(save_info,"%s"            ,s_d[i].name);
             
            b=strlen(s_d[i].name);
            for(c=b;c<=len_max;c++)
            {
             fprintf(save_info," ");
            }

            fprintf(save_info,"%.2f\t"          ,s_d[i].present);
            fprintf(save_info,"    ");
            fprintf(save_info,"%.2f\t"          ,s_d[i].assignment);
             fprintf(save_info," ");
            fprintf(save_info,"%.2f\t"          ,s_d[i].mid);
            fprintf(save_info,"  ");
            fprintf(save_info,"%.2f\t"          ,s_d[i].presention);
            fprintf(save_info,"     ");
            fprintf(save_info,"%.2f\t"          ,s_d[i].final);
            fprintf(save_info," ");
            fprintf(save_info,"%.2f\t"          ,s_d[i].total);
            fprintf(save_info,"%s\n"            ,s_d[i].grade);
             
        }         
    }
    fclose(save_info);
}
void len_name(struct information s_d[])
{
    for(i=0;i<n;i++)
    {
        if(len_max<strlen(s_d[i].name))len_max=strlen(s_d[i].name);
    }
    len_max=len_max+4;
}














void
number (char temp[],struct information s_d[])
{
    char n3[20];
  int b = 0;
  for (b = 0; b < 20; b++)
    {
      n3[b] = '\0';
    }
  b = 0;
  while (1)
    {
      if ((temp[i] >= '0' && temp[i] <= '9') || (temp[i] == '.'))
	{
	  n3[b] = temp[i];
	  b++;
	}
      else if (temp[i] == ' ')
	{
	  if (temp[i + 1] >= '0' && temp[i + 1] <= '9')
	    {
	      i++;
	      break;
	    }
	}
      else if (temp[i] == '\0'|| temp[i]=='\n' ||(temp[i] >= 65 && temp[i] <= 122))
	{
	  break;
	}

      i++;
    }
  s_d[j].present=atof(n3);

}

void
name (char temp[],struct information s_d[])
{
  int b = 0,x;
  
  char name[20];
  for (b = 0; b < 20; b++)
    {
      name[b] = '\0';
    }
  b = 0;
  while (1)
    {
      if (temp[i] >= 65 && temp[i] <= 122)
	{
	  name[b] = temp[i];
	  b++;
	}
      else if (temp[i] == ' ')
	{
	  if (temp[i + 1] >= 65 && temp[i + 1] <= 122)
	    {
	      name[b] = ' ';
	      b++;
	    }
	}
      else if (temp[i] >= '0' && temp[i] <= '9')
	{
	  break;
	}
      i++;
    }
  strcpy(s_d[j].name,name);
}
void
numberid (char temp[],struct information s_d[])
{
  char n3[20];
  int b = 0;
  for (b = 0; b < 20; b++)
    {
      n3[b] = '\0';
    }
  b = 0;
  while (1)
  {
      if (temp[i] >= '0' && temp[i] <= '9')
	   {
	     n3[b] = temp[i];
	    b++;
	   }
      else if (temp[i] >= 65 && temp[i] <= 122) break;
	    

    i++;
  }
  s_d[j].id=atof(n3);

}
void
number1 (char temp[],struct information s_d[])
{
    char n3[20];
  int b = 0;
  for (b = 0; b < 20; b++)
    {
      n3[b] = '\0';
    }
  b = 0;
  while (1)
    {
      if ((temp[i] >= '0' && temp[i] <= '9') || (temp[i] == '.'))
	{
	  n3[b] = temp[i];
	  b++;
	}
      else if (temp[i] == ' ')
	{
	  if (temp[i + 1] >= '0' && temp[i + 1] <= '9')
	    {
	      i++;
	      break;
	    }
	}
      else if (temp[i] == '\0'|| temp[i]=='\n' ||(temp[i] >= 65 && temp[i] <= 122))
	{
	  break;
	}

      i++;
    }
  s_d[j].assignment=atof(n3);

}
void
number2 (char temp[],struct information s_d[])
{
    char n3[20];
  int b = 0;
  for (b = 0; b < 20; b++)
    {
      n3[b] = '\0';
    }
  b = 0;
  while (1)
    {
      if ((temp[i] >= '0' && temp[i] <= '9') || (temp[i] == '.'))
	{
	  n3[b] = temp[i];
	  b++;
	}
      else if (temp[i] == ' ')
	{
	  if (temp[i + 1] >= '0' && temp[i + 1] <= '9')
	    {
	      i++;
	      break;
	    }
	}
      else if (temp[i] == '\0'|| temp[i]=='\n' ||(temp[i] >= 65 && temp[i] <= 122))
	{
	  break;
	}

      i++;
    }
  s_d[j].mid=atof(n3);

}
void
number3 (char temp[],struct information s_d[])
{
    char n3[20];
  int b = 0;
  for (b = 0; b < 20; b++)
    {
      n3[b] = '\0';
    }
  b = 0;
  while (1)
    {
      if ((temp[i] >= '0' && temp[i] <= '9') || (temp[i] == '.'))
	{
	  n3[b] = temp[i];
	  b++;
	}
      else if (temp[i] == ' ')
	{
	  if (temp[i + 1] >= '0' && temp[i + 1] <= '9')
	    {
	      i++;
	      break;
	    }
	}
      else if (temp[i] == '\0'|| temp[i]=='\n' ||(temp[i] >= 65 && temp[i] <= 122))
	{
	  break;
	}

      i++;
    }
  s_d[j].presention=atof(n3);

}
void
number4 (char temp[],struct information s_d[])
{
    char n3[20];
  int b = 0;
  for (b = 0; b < 20; b++)
    {
      n3[b] = '\0';
    }
  b = 0;
  while (1)
    {
      if ((temp[i] >= '0' && temp[i] <= '9') || (temp[i] == '.'))
	{
	  n3[b] = temp[i];
	  b++;
	}
      else if (temp[i] == ' ')
	{
	  if (temp[i + 1] >= '0' && temp[i + 1] <= '9')
	    {
	      i++;
	      break;
	    }
	}
      else if (temp[i] == '\0'|| temp[i]=='\n' ||(temp[i] >= 65 && temp[i] <= 122))
	{
	  break;
	}

      i++;
    }
  s_d[j].final=atof(n3);

}
