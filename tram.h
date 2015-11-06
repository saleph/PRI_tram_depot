#ifndef TRAM_H_INCLUDED
#define TRAM_H_INCLUDED

/* TODO: in list's structure - add field RECORD_NO */
typedef struct {
    int line_no;
    char *tram_type;
    int side_no;
    char *motorman_name;
} Tram;

extern Tram* new_tram(int, char*, int, char*);
extern char* new_string(char*);

#endif /* TRAM_H_INCLUDED */
