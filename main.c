#include <stdio.h>
#include "tram.h"


int main()
{
    int n,i;
    Tram* trams[10];

    n = 10;

    for (i=0; i<n; i++)
        trams[i] = new_tram(i, "123N", 1231, "Imie Nazwisko");

    return 0;
}
