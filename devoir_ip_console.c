int main()
{
    char* ip=NULL;
    getdata(&ip);
    verification(ip);
    return 0;
}
void getdata(char** ip)
{
    int d=255;
    *ip=(char*)malloc(d*sizeof(char));
    printf("entrer l'ip : ");
    scanf("%s", *ip);
}
void verification(char* ip)
{
    int i=0;
    int val[4];
    char *t = NULL;
    int point = 0;
    int j;
    for (j = 0; j < strlen(ip); j++)
    {
        if (ip[j] == '.')
        {
            point++;
        }
    }
    if (!strchr(ip, '.') || point != 3)
    {
        printf("ip non valid\n");
        main();
    }
    else
    {
        t = strtok(ip, ".");
        while (t != NULL)
        {
            if (atoi(t) > 255 || atoi(t) < 0 || strcmp(t, "\[0-9]+?") == 0)
            {
                printf("ip non valid\n");
                main();
                break;
            }
            else if (atoi(t) == 0 && (!strchr(t, '0') && strlen(t) != 0))
            {
                printf("ip non valid\n");
                main();
                break;
            }    
            val[i]=atoi(t);
            i++;
            t = strtok(NULL, ".");
        }
    }
        printf("ip valid\n");
        for(i=0; i<4;i++)
        {
            printf("%d\n",val[i]);
        }
        if(val[0]>=0 && val[0]<=127)
        {
            printf("ip de classe A\n");
        }
        if(val[0]>=128&& val[0]<=191)
        {
            printf("ip de classe B\n");
        }
        if(val[0]>=192&& val[0]<=223)
        {
            printf("ip de classe C\n");
        }
        if(val[0]>=224&& val[0]<=239)
        {
            printf("ip de classe D\n");
        }
        if(val[0]>=240&& val[0]<=255)
        {
            printf("ip de classe E\n");
        }
}
