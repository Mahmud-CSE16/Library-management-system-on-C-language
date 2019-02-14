
#define RETURNTIME 5
#define FINE 5


char password1[20]="librarian";

char password[20]="library";

char word[20];

char catagories[][30]={"Math","Physics","Chemistry","Computer","Electrical","Civil","Architecture","Other"};

FILE *fp,*ft,*fs;
typedef struct{
    int dd,mm,yy;
}Date;

struct information{
    int id;
    char name[20];
    char Author[20];
    int quantity;
    int quantity1;
    int quantity2;
    float Price;
    int count;
    int fine;
    int rack_no;
    char cat[30];
    char st_name[20];
    int st_id;
    char st_dprt[50];
    Date issued;
    Date due_date;
    Date back;
};
struct information book,info,issue,issue1;
int s;

void start(){
    design();
    char *arr;
    arr=(char *)malloc(sizeof(char)*50);
    arr="Khulna University of Engineering & Technology";
    gotoxy(20,9);
    printf("\xb2\xb2\xb2\xB2\xB1 %s \xb1\xB2\xb2\xb2\xb2",arr);
    free(arr);
    arr=(char*)calloc(25,sizeof(char));
    arr="Welcome to Library";
    gotoxy(35,11);
    printf("\xb1\xb1\xb1\xb2 %s \xb2\xb1\xb1\xb1",arr);
    free(arr);
    gotoxy(45,18);
    printf("Press any key to continue........");
    getch();
    Password();
}

void design(){
    system("cls");
    gotoxy(1,1);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\xdb\xdb Kuet Library \xdb\xdb@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    gotoxy(1,2);printf("&"); gotoxy(100,2);printf("&");
    int i;
    for(i=3;i<27;i++){
    gotoxy(1,i);printf("\xdb");gotoxy(100,i);printf("\xdb");
    }
    gotoxy(1,27);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    gotoxy(2,26);Time();gotoxy(84,26);date();

}


COORD coord = {0, 0}; // sets coordinates to 0,0
void gotoxy (int x, int y){
        coord.X = x; coord.Y = y; // X and Y coordinates
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void  delay(unsigned int mseconds){
    clock_t goal=mseconds+clock();
    while (goal>clock());
}


int Time(){
    char dest[50];
    time_t t;
    struct tm *tm;
    char pm[3],HH[3],MM[3],SS[3];
    t=time(NULL);
    tm=localtime(&t);

    strftime(dest,50,"%I %M %S %p",tm);
    sscanf(dest,"%s %s %s %s",&HH,&MM,&SS,pm);
    printf("Time: %s:%s:%s %s\n",HH,MM,SS,pm);
}
int date(){
    char dest[50];
    time_t t;
    struct tm *tm;
    int dd,mm,yy;
    t=time(NULL);
    tm=localtime(&t);

    strftime(dest,50,"%d %m %Y",tm);
    sscanf(dest,"%d %d %d",&dd,&mm,&yy);
    printf("Date: %d/%d/%d\n",dd,mm,yy);
}
void Password(){
    system("cls");
    design();
    gotoxy(15,4);
    printf("\xb2\xb2\xb1\xb2\xb2\xb1\xb2\xb2\xb1\xb2\xb2\xb1\xb2\xb2\xb1\xb2\xb2\xb1\xb2\xb2\xb1\xb2\xb2\xb1 Password Protected \xb1\xb2\xb2\xb1\xb2\xb2\xb1\xb2\xb2\xb1\xb2\xb2\xb1\xb2\xb2\xb1\xb2\xb2\xb1\xb2\xb2");
    char ch;
    int i=0;
    gotoxy(15,6);
    printf("\xb2\xb2\xb1 What your position? \xb1\xb2\xb2");
    gotoxy(15,7);
    printf("1. Librarian");
    gotoxy(15,8);
    printf("2. Assistant Librarian");
    gotoxy(15,9);
    printf("3. Student");
    gotoxy(15,10);
    printf("4. Other");
    gotoxy(15,11);
    printf("--------------------------");
    gotoxy(15,12);
    printf("Enter your position:");
    int a;
    scanf("%d",&a);
    if(a==2||a==3||a==4){
    gotoxy(15,14);
    printf("Enter Password:");
    while(ch!=13){
        ch=getch();
        if(ch!=13){
           putch('*');
           word[i++]=ch;
        }
    }
    word[i]='\0';
    if(strcmp(word,password)==0){
        gotoxy(22,17);
        printf("\xdb\xb2\xb2\xb1\xb1\xb1 Password Match \xb1\xb1\xb1\xb2\xb2\xdb");
        gotoxy(35,20);
        printf("Press any key to continue........");
        getch();
        mainmenu();
    }
    else{
        gotoxy(15,17);
        printf("\aWarning!! Incorrect Password\a");
        gotoxy(35,20);
        printf("Press enter key to \"Retry\"");
        getch();
        Password();
    }
    }
    else if(a==1){
        gotoxy(15,14);
    printf("Enter Password:");
    while(ch!=13){
        ch=getch();
        if(ch!=13){
           putch('*');
           word[i++]=ch;
        }
    }
    word[i]='\0';
    if(strcmp(word,password1)==0){
        gotoxy(22,17);
        printf("\xdb\xb2\xb2\xb1\xb1\xb1 Password Match \xb1\xb1\xb1\xb2\xb2\xdb");
        gotoxy(35,20);
        printf("Press any key to continue........");
        getch();
        mainmenu();
    }
    else{
        gotoxy(15,17);
        printf("\aWarning!! Incorrect Password\a");
        gotoxy(35,20);
        printf("Press enter key to \"Retry\"");
        getch();
        Password();
    }
    }
    else{
        gotoxy(15,17);
        printf("\aWarning Enter\a");
        gotoxy(35,20);
        printf("Press any key to \"Retry\"");
        getch();
        Password();
    }
}
int checkid(int t)  //check whether the book is exist in library or not
{
    rewind(fp);
    while(fread(&book,sizeof(book),1,fp)==1){
    if(book.id==t){
       return 0;
    }
    }
    return 1;
}

int check_st_id(int t)
{
    rewind(ft);
    while(fread(&info,sizeof(info),1,ft)==1){
    if(info.st_id==t){
       return 0;
    }
    }
    return 1;
}






