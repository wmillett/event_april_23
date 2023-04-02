#include <stdio.h>


void printres(int nb)
{
    if (nb >= 10)
    {
        printres(nb / 10);
        printres(nb % 10);
    }
    else
        printf("%i", nb);
}


int isgoodnb(char c){

    int i = 0;
    char*nb = "23456789";
    while(nb[i])
    {
        if(nb[i] == c)
            return(i + 2);
        i++;
    }
    return(0);
}


int main(int c, char**v){
    int i = 0;
    int count = 0;
    int a = 0;
    int tmp;
    if(c >= 2)
    {
        
        while(v[1][i])
        {
            if (v[1][i] == 'T' || v[1][i] == 'J' || v[1][i] == 'D' || v[1][i] == 'K')
                count += 10;
            else if (v[1][i] == 'A')
                a += 1;
            else if ((tmp = isgoodnb(v[1][i])))
                count += tmp;
            else   
                return(printf("That's not a hand of blackjack >:(\n"));
            ++i;
        }
        if (count == 10 && a == 1 && i == 2)
        {
            printf("Blackjack!\n");
            return(0);
        }
        tmp = a;
        while(tmp > 0)
        {
            count++;
            tmp--;
        }
        tmp = a;
        while (count <= 11 && tmp--)
            count += 10;
        printres(count);
    }
   printf("\n"); 
}