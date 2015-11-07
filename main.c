#include "tram.h"
#include "input_parser.h"


int main()
{
    int n,i;
    Tram* trams[10];
    char *t1;

    n = 10;

    t1 = "adam ewa mary kochana wow";

    parse(t1);

    for (i=0; i<n; i++) {
        t1 = "sdfa";
        trams[i] = new_tram(i, t1, i, t1, t1);
    }

    for (i=0; i<n; i++)
        print_tram_info(trams[i]);

    for (i=0; i<n; i++)
        delete_tram(trams[i]);

    return 0;
}
