void student_corner(){
    system("cls");
    design();
    gotoxy(10,3);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Student Corner @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    gotoxy(13,5);
    printf("\xdb\xdb\xdb\xb1\xb1 1.Add new student.");
    gotoxy(13,7);
    printf("\xdb\xdb\xdb\xb1\xb1 2.Search student for seeing (his/her) profile.");
    gotoxy(13,9);
    printf("\xdb\xdb\xdb\xb1\xb1 3.View student or member of Library.");
    gotoxy(13,11);
    printf("\xdb\xdb\xdb\xb1\xb1 4.Back to Main Menu.");
    gotoxy(13,12);
    printf("-------------------------------------------------------------");
    gotoxy(10,13);
    printf("\xdb\xdb\xb1 Enter your choice:");
    int k;
    scanf("%d",&k);
    switch(k){
    case 1:
        system("cls");
        design();
        add_student();
        break;
    case 2:
        st_history();
        break;
    case 3:
        view_student_list();
        break;

    case 4:
        system("cls");
        design();
        gotoxy(10,10);
        printf("\xdb\xdb\xb1 Press any key to go to main menu........");
        getch();
        mainmenu();
        break;
    default:{
          gotoxy(10,23);
          printf("\aWrong Entry!!Please re-entered correct option");
          getch();
          student_corner();
         }
    }
    getch();
    ;}

void add_student(){
    if(strcmp(word,password1)==0){
    int t;
    char another='y';
    while(another='y'){
    ft=fopen("student.txt","a+");
    system("cls");
    design();

    gotoxy(20,3);
    printf("\xb1\xb1\xb1\xb1 Enter the Information Below \xb1\xb1\xb1\xb1");
    gotoxy(20,4);
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
    gotoxy(20,5);
    printf("&");gotoxy(70,5);printf("&");
    gotoxy(20,6);
    printf("\xB2");gotoxy(70,6);printf("\xB2");
    gotoxy(20,7);
    printf("\xB2");gotoxy(70,7);printf("\xB2");
    gotoxy(20,8);
    printf("\xB2");gotoxy(70,8);printf("\xB2");
    gotoxy(20,9);
    printf("\xB2");gotoxy(70,9);printf("\xB2");
    gotoxy(20,10);
    printf("\xB2");gotoxy(70,10);printf("\xB2");
    gotoxy(20,11);
    printf("\xB2");gotoxy(70,11);printf("\xB2");
    gotoxy(20,12);
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
    gotoxy(21,6);
    printf("Student ID:\t");
    gotoxy(34,6);
    scanf("%d",&t);
    int d;
    d=(t/100000);
    if((90<d && d<99 )|| (1<d && d<17)){
    if(check_st_id(t) == 0)
    {
        gotoxy(21,13);
        printf("\aThe Student id already exists\a");
        getch();
        student_corner();
    }
    info.st_id=t;
    gotoxy(21,8);
    printf("Student Name:");
    gotoxy(34,8);
    scanf(" %[^\n]s",info.st_name);
    gotoxy(21,10);
    printf("Department:");
    gotoxy(34,10);
    scanf(" %[^\n]s",info.st_dprt);

    fwrite(&info,sizeof(info),1,ft);
    fclose(ft);
    gotoxy(21,14);
    printf("\xdb\xdb\xb1 The record is successfully saved \xb1\xdb\xdb");
    gotoxy(21,15);
    printf("\xdb\xb1|-> Save any more?(Y / N):");
    if(getch()=='n')
        mainmenu();
    else
        another='y';
    }
    else{
    gotoxy(21,14);
    printf("\a The student ID format is not correct.");
    gotoxy(21,15);
    printf("\xdb\xb1|-> Try again?(Y / N):");
    if(getch()=='n')
        student_corner();
    else
        another='y';
    }
    }
    }
    else{
        gotoxy(15,10);
        printf("Not Available for Everybody..........Back \xdb Main Menu \xdb");
        getch();
        mainmenu();
    }
}
void view_student_list(){
    system("cls");
    gotoxy(2,2);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Student List @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    gotoxy(2,4);
    printf(" SI NO.         Name                 Roll                  Department ");
    gotoxy(2,5);
    printf(" ------    ---------------         ----------             -------------");
    int j=6;
    int i=0;
    fclose(ft);
    ft=fopen("student.txt","r+");
    while(fread(&info,sizeof(info),1,ft)==1){
    if(feof(ft)){
        break;
    }
    gotoxy(5,j);
    printf("%d.",++i);
    gotoxy(13,j);
    printf("%s",info.st_name);
    gotoxy(38,j);
    printf("%d",info.st_id);
    gotoxy(63,j);
    printf("%s",info.st_dprt);
    printf("\n\n");
    j++;
    }
    fclose(ft);
    gotoxy(3,j+3);
    printf("Total student =%d",i);
    fclose(fp);
    gotoxy(35,j+3);
    printf("Student Corner....\xb2 ENTER \xb2");
    getch();
    student_corner();
}

void st_history(){
    system("cls");
    FILE *h,*S;

    struct information history,historys;
    int a,m=0;
    gotoxy(10,3);
    printf("Enter Student ID: ");
    scanf("%d",&a);

    ft=fopen("student.txt","r+");
    while((fread(&info,sizeof(info),1,ft))==1){
    if(a==info.st_id){
    gotoxy(10,5);
    printf("@@|-> Student Name: %s",info.st_name);
    gotoxy(10,6);
    printf("@@|-> Department: %s",info.st_dprt);
    gotoxy(2,7);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ History of %s @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@",info.st_name);

    m=1;
    }
    }
    if(m==0){
        gotoxy(10,9);
        printf("Wrong Entered. Please Reenter(Y/n):");
        if(getch()=='y'){
            st_history();
        }
        else{
            student_corner();
        }
    }
    fclose(ft);
    gotoxy(2,8);
    printf(" SI NO.    BOOk ID     Book Name       Issued Date     Due Date     Return date    Fine");
    gotoxy(2,9);
    printf(" ------    -------     ---------       ------------    --------     -----------    ----");
    int j=10;
    int i=0;
    h=fopen("history.txt","r+");
    while(fread(&history,sizeof(history),1,h)==1){
        if(a==history.st_id){
    gotoxy(4,j);
    printf("%d.",++i);
    gotoxy(13,j);
    printf("%d",history.id);
    gotoxy(26,j);
    printf("%s",history.name);
    gotoxy(42,j);
    printf("%d/%d/%d",history.issued.dd,history.issued.mm,history.issued.yy);
    gotoxy(57,j);
    printf("%d/%d/%d",history.due_date.dd,history.due_date.mm,history.due_date.yy);
    gotoxy(73,j);
    printf("%d/%d/%d",history.back.dd,history.back.mm,history.back.yy);
    gotoxy(86,j);
    printf("%d",history.fine);
    printf("\n\n");
    j++;
        }
    }
    gotoxy(2,j);
    printf("Present");
    j++;
    fclose(h);
    S=fopen("Issue.txt","r+");
    i=0;
    while(fread(&historys,sizeof(historys),1,S)==1){
        if(a==historys.st_id){
    gotoxy(4,j);
    printf("%d.",++i);
    gotoxy(13,j);
    printf("%d",historys.id);
    gotoxy(26,j);
    printf("%s",historys.name);
    gotoxy(42,j);
    printf("%d/%d/%d",historys.issued.dd,historys.issued.mm,historys.issued.yy);
    gotoxy(57,j);
    printf("%d/%d/%d",historys.due_date.dd,historys.due_date.mm,historys.due_date.yy);
    gotoxy(73,j);
    printf("%d/%d/%d",historys.back.dd,historys.back.mm,historys.back.yy);
    gotoxy(86,j);
    printf("%d",historys.fine);
    printf("\n\n");
    j++;
        }
    }

    fclose(S);
    gotoxy(35,j+3);
    printf("Student Corner....\xb2 ENTER \xb2");
    getch();
    student_corner();
}
