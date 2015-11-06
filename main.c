#include <stdio.h>
#include "tram.h"


int main()
{
    int n,i;
    Tram* trams[10];
    char *t1, *t2;

    n = 10;

    for (i=0; i<n; i++) {
        t1 = "sdfa";
        trams[i] = new_tram(i, t1, i, t1);
    }

    for (i=0; i<n; i++)
        printf("%d %s %d %s\n", trams[i]->line_no, trams[i]->tram_type, trams[i]->side_no, trams[i]->motorman_name);

    for (i=0; i<n; i++)
        delete_tram(trams[i]);

    return 0;
}
