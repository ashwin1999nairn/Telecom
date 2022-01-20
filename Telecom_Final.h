typedef struct user
{char name[50],type[10];
long long int phno;
float amt;
struct user *next;}user;

bool Is_Empty(user **);
void gotoxy(short ,short );
void initiate(user **);
void terminate(user **);
user *searchbyphno(user **);
void search_display(user **);
void addrecord(user **);
void deleterecord(user **);
void deletedatabase(user **);
void modifyrecord(user **);
void listrecords(user *);
void bill(user **);
void services(user **);
void passwordcheck();
