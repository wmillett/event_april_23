#include <stdio.h>
#include <ctype.h>
int findlongest(int argc, char**v)
{
    int i = 1;
    int j = 0;
    int count = 0;
    int biggest = 0;

    while(i < argc)
    {
        j = 0;
        while(v[i][j])
        {
            count = 0;
            while(isalpha(v[i][j]) == 0)
                j++;
            while(isalpha(v[i][j]))
            {
                count++;
                j++;
            }
            if (count > biggest)
                biggest = count;
        }
        i++;
    }
    return(biggest);
}

void eachwordprint(int argc,char**v, int longest)
{
    int i = 1;
    int j = 0;
    int count = 0;
    int biggest = 0;
    int tmp;

     while(i < argc)
    {
        j = 0;
        while(v[i][j])
        {
            count = 0;
            printf("* ");
            while(isalpha(v[i][j]) == 0 && v[i][j])
                j++;
            while(isalpha(v[i][j]))
            {
                printf("%c", v[i][j]);
                count++;
                j++;
            }
            while(isalpha(v[i][j]) == 0 && v[i][j])
                j++;
            tmp = longest;
            if (count < tmp--)
            {
                while(count++ < tmp)
                    printf(" ");
            }
            printf(" *\n");
        }
        i++;
    }
}

int main(int argc, char**argv){
    int longest;
    int tmp;
    if (argc >= 2)
    {
        longest = findlongest(argc,argv);
        if (longest == 0)
        {
            printf("Ain't no word in here >:(");
            return(0);
        }
        tmp = longest + 4;
        while(tmp--)
            printf("*");
        printf("\n");
        eachwordprint(argc, argv, longest);
        tmp = longest + 4;
         while(tmp--)
            printf("*");
        printf("\n");
    }
}