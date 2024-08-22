#include <stdio.h>
#include <stdlib.h>
void verify(int x1,int x2, int x3, int x4);
int main()
{
    char* ip=NULL;
    int x1;
    int x2;
    int x3;
    int x4;
    ip=getenv("QUERY_STRING");
    sscanf(ip,"ip=%d.%d.%d.%d",&x1,&x2,&x3,&x4);
    verify(x1,x2,x3,x4);
}
void verify(int x1,int x2, int x3, int x4)
{
    printf("Content-Type:Text/html\n\n");
    printf("<HTML><HEAD><META charset=utf-8></HEAD>\n");
    printf("<BODY>\n");
    printf("<p>%d.%d.%d.%d</p>",x1,x2,x3,x4);
    if(x1<255 && x2<255 && x3<255 && x4<255)
    {
        printf("<p>IP valid!</p>");
        if(x1>=0 && x1<=127)
        {
            printf("<p>IP de type A</p>");
        }
        else if(x1>=128 && x1<=191)
        {
            printf("<p>IP de type B</p>");

        }
        else if(x1>=192 && x1<=223)
        {
                printf("<p>IP de type C</p>");

        }
        else if(x1>=224 && x1<=239)
        {
            printf("<p>IP de type D</p>");

        }
        else if(x1>=240 && x1<=255)
        {
            printf("<p>IP de type E</p>");

        }
    }
    else
    {
         printf("<p>IP invalid!</p>");
    }
    printf("</BODY>");
    printf("</HTML>");
}