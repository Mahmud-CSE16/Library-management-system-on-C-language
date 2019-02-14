
void issue_books()
{
    system("cls");
    design();
    gotoxy(3,3);
    printf("   ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ Issue Section ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ ");
    gotoxy(10,5);
    printf("\xdb\xdb\xdb\xb1 1.Issue a Book.");
    gotoxy(10,7);
    printf("\xdb\xdb\xdb\xb1 2.View Issued books.");
    gotoxy(10,9);
    printf("\xdb\xdb\xdb\xb1 3.Remove Issued book.");
    gotoxy(10,11);
    printf("\xdb\xdb\xdb\xb1 4.Go back Main Menu");
    gotoxy(10,12);
    printf("-----------------------------------------------------");
    gotoxy(10,13);
    printf("\xdb\xdb\xb1 Enter your choice:");
    int c;
    scanf("%d",&c);
    switch(c)
    {
    case 1:
        system("cls");
        design();
        issue_book();
        break;
    case 2:
        system("cls");
        design();
        view_issued_books();
        break;
    case 3:
        system("cls");
        design();
        remove_issued_book();
        break;
    case 4:
        system("cls");
        design();
        gotoxy(10,10);
        printf("\xdb\xdb\xb1 Press any key to go to main menu........");
        getch();
        mainmenu();
        break;
    default:
    {
        system("cls");
        design();
        gotoxy(10,23);
        printf("\aWrong Entry!!Please re-entered correct option");
        getch();
        issue_book();
    }
    }
    getch();
}
void issue_book()
{
    system("cls");
    design();
    if(strcmp(word,password1)==0)
    {
        int t;
        int c=0;
        char another='y';
        while(another=='y')
        {
            system("cls");
            design();
            c=0;
            gotoxy(13,3);
            printf("*****************************Issue Book section*******************************");
            gotoxy(10,5);
            printf("Enter the Book Id:");
            scanf("%d",&t);
            fp=fopen("Record.dat","r+");
            fs=fopen("Issue.txt","a+");
            ft=fopen("student.txt","r+");
            while((fread(&issue,sizeof(issue),1,fp))==1)
            {
                if(issue.id==t)
                {
                    gotoxy(10,6);
                    printf("\xdb\xdb\xb1The book record is available");
                    gotoxy(10,7);
                    printf("\xdb\xdb\xb1 There are %d unused books in library ",issue.quantity1);
                    gotoxy(20,8);
                    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
                    gotoxy(20,9);
                    printf("& ID:%d",issue.id);
                    gotoxy(60,9);
                    printf("&");
                    gotoxy(20,10);
                    printf("\xB2 Name:%s",issue.name);
                    gotoxy(60,10);
                    printf("\xB2");
                    gotoxy(20,11);
                    printf("\xB2 Author:%s ",issue.Author);
                    gotoxy(60,11);
                    printf("\xB2");
                    gotoxy(20,12);
                    printf("\xB2 Price:%.2f",issue.Price);
                    gotoxy(60,12);
                    printf("\xB2");
                    gotoxy(20,13);
                    printf("\xB2 Rack No:%d ",issue.rack_no);
                    gotoxy(60,13);
                    printf("\xB2");
                    gotoxy(20,14);
                    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
                    gotoxy(10,15);
                    printf("Enter student ID:");
                    scanf("%d",&issue.st_id);
                    if(check_st_id(issue.st_id) == 0)
                    {
                        strcpy(issue.st_name,info.st_name);
                        gotoxy(50,15);
                        printf("Student Name: %s",issue.st_name);
                        char dest[50];
                        time_t t;
                        struct tm *tm;
                        t=time(NULL);
                        tm=localtime(&t);
                        strftime(dest,50,"%d %m %Y",tm);
                        sscanf(dest,"%d %d %d",&issue.issued.dd,&issue.issued.mm,&issue.issued.yy);
                        gotoxy(10,16);
                        printf("Issued Date:%d-%d-%d",issue.issued.dd,issue.issued.mm,issue.issued.yy);
                        gotoxy(10,17);
                        printf("The BOOK of ID %d is issued",issue.id);
                        issue.due_date.dd=issue.issued.dd+RETURNTIME;   //for return date
                        issue.due_date.mm=issue.issued.mm;
                        issue.due_date.yy=issue.issued.yy;
                        if(issue.due_date.dd>30)
                        {
                            issue.due_date.mm+=issue.due_date.dd/30;
                            issue.due_date.dd-=30;

                        }
                        if(issue.due_date.mm>12)
                        {
                            issue.due_date.yy+=issue.due_date.mm/12;
                            issue.due_date.mm-=12;

                        }
                        gotoxy(50,16);
                        printf("Return Date:%d-%d-%d",issue.due_date.dd,issue.due_date.mm,issue.due_date.yy);
                        /*issue.quantity1--;
                        issue.quantity2++;
                        fseek(fp,ftell(fp)-sizeof(issue),0);
                        fwrite(&issue,sizeof(issue),1,fp);*/
                        fwrite(&issue,sizeof(issue),1,fs);
                    }
                    else
                    {
                        gotoxy(13,17);
                        printf("Student ID is not correct.");
                        gotoxy(15,18);
                        printf("\xdb\xb1|-> Try again?(Y / N):");
                        if(getch()=='n')
                            issue_books();
                        else
                            issue_book();
                    }
                    c=1;
                    break;
                }
            }
            fclose(fp);
            fclose(fs);
            fclose(ft);
            if(c==0)
            {
                gotoxy(13,11);
                printf("\xdb\xdb No record found \xdb\xdb");
            }
            gotoxy(20,20);
            printf("\xdb\xdb\xb1 Issue any more(Y/N):");
            if(getch()=='n')
                mainmenu();
            else
                another='y';
        }
    }
    else
    {
        gotoxy(15,10);
        printf("Not Available for Everybody..........Back \xdb Main Menu \xdb");
        getch();
        mainmenu();
    }
}

void view_issued_books()
{
    system("cls");
    gotoxy(2,2);
    printf("@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@ Issued List @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@");
    gotoxy(2,4);
    printf(" SI NO.   Student Name       Student ID     Category    BOOk ID     Book Name       Issued Date     Return Date");
    gotoxy(2,5);
    printf(" ------  ---------------     -----------    --------     -----      ---------       ------------    -----------");
    int j=6;
    int i=0;
    fs=fopen("Issue.txt","r+");
    while(fread(&issue,sizeof(issue),1,fs)==1)
    {
        gotoxy(4,j);
        printf("%d.",++i);
        gotoxy(11,j);
        printf("%s",issue.st_name);
        gotoxy(31,j);
        printf("%d",issue.st_id);
        gotoxy(46,j);
        printf("%s",issue.cat);
        gotoxy (59,j);
        printf("%d",issue.id);
        gotoxy(70,j);
        printf("%s",issue.name);
        gotoxy(87,j);
        printf("%d/%d/%d",issue.issued.dd,issue.issued.mm,issue.issued.yy);
        gotoxy(103,j);
        printf("%d/%d/%d",issue.due_date.dd,issue.due_date.mm,issue.due_date.yy);
        printf("\n\n");
        j++;
    }
    gotoxy(3,j+3);
    printf("Total Issued book =%d",i);
    fclose(fs);
    gotoxy(35,j+3);
    printf("Issue Section....\xb2 ENTER \xb2");
    getch();
    issue_books();
}

void remove_issued_book()
{
    struct information in;
    system("cls");
    design();
    if(strcmp(word,password1)==0)
    {
        int t,find_book,d;
        FILE *f1,*f2,*f3;
        char another='y';
        while(another=='y')
        {
            find_book=0;
            system("cls");
            design();
            gotoxy(10,5);
            printf("\xdb\xdb\xb1 Enter Student Id to remove Issued book:");
            scanf("%d",&t);

            fs=fopen("Issue.txt","r+");
            while(fread(&issue,sizeof(issue),1,fs)==1)
            {
                system("cls");
                design();
                if(issue.st_id==t)
                {
                    d=issue.st_id;
                    in.st_id=issue.st_id;
                    gotoxy(15,7);
                    printf("Student Id: %d",issue.st_id);
                    gotoxy(20,8);
                    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
                    gotoxy(20,9);
                    printf("& Book ID: %d",issue.id);
                    gotoxy(60,9);
                    printf("&");
                    in.id=issue.id;
                    gotoxy(20,10);
                    printf("\xB2 Book Name: %s",issue.name);
                    gotoxy(60,10);
                    printf("\xB2");
                    strcpy(in.name,issue.name);
                    gotoxy(20,11);
                    printf("\xB2 Author name: %s ",issue.Author);
                    gotoxy(60,11);
                    printf("\xB2");
                    strcpy(in.Author,issue.Author);
                    gotoxy(20,12);
                    printf("\xb2 Student Name: %s",issue.st_name);
                    gotoxy(60,12);
                    printf("\xB2");
                    strcpy(in.st_name,issue.st_name);
                    gotoxy(20,13);
                    printf("\xd2 Issued Date: %d-%d-%d",issue.issued.dd,issue.issued.mm,issue.issued.yy);
                    gotoxy(60,13);
                    printf("\xB2");
                    in.issued.dd=issue.issued.dd;
                    in.issued.mm=issue.issued.mm;
                    in.issued.yy=issue.issued.yy;
                    gotoxy(20,14);
                    printf("\xb2 Due Date: %d-%d-%d",issue.due_date.dd,issue.due_date.mm,issue.due_date.yy);
                    gotoxy(60,14);
                    printf("\xB2");
                    in.due_date.dd=issue.due_date.dd;
                    in.due_date.mm=issue.due_date.mm;
                    in.due_date.yy=issue.due_date.yy;

                    gotoxy(20,15);
                    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
                    char dest[50];
                    time_t t;
                    struct tm *tm;
                    t=time(NULL);
                    tm=localtime(&t);
                    strftime(dest,50,"%d %m %Y",tm);
                    sscanf(dest,"%d %d %d",&issue.back.dd,&issue.back.mm,&issue.back.yy);
                    gotoxy(10,17);
                    printf("@@|-> Return Date: %d-%d-%d",issue.back.dd,issue.back.mm,issue.back.yy);
                    in.back.dd=issue.back.dd;
                    in.back.mm=issue.back.mm;
                    in.back.yy=issue.back.yy;
                    int fn=(issue.back.dd+(issue.back.mm*30)+(issue.back.yy*365))-(issue.due_date.dd+(issue.due_date.mm*30)+(issue.due_date.yy*365));
                    if(fn>0)
                    {
                        issue.fine=fn*FINE;
                    }
                    else issue.fine=0;
                    in.fine=issue.fine;
                    gotoxy(10,18);
                    printf("@@|-> Your fine: %d tk.",issue.fine);
                    find_book=1;
                    fclose(fs);
                    break;
                }
            }
            if(find_book==1)
            {

                gotoxy(15,21);
                printf("\xdb\xdb\xb1 Do You Want to Remove it?(Y/N)");
                if(getch()=='y')
                {
A:
                    system("cls");
                    design();
                    int k;
                    gotoxy(13,7);
                    printf("@@|-> Your fine: %d tk.",issue.fine);
                    gotoxy(13,9);
                    printf("@@|->You have to pay Fines.");
                    gotoxy(13,11);
                    printf("@@|->Enter Amount: ");
                    scanf("%d",&k);
                    if(issue.fine==k)
                    {
                        f1=fopen("text1.txt","w+");
                        f3=fopen("Issue.txt","r+");
                        f2=fopen("history.txt","a+");
                        fp=fopen("Record.dat","r+");
                        int s=0;
                        while(fread(&issue,sizeof(issue),1,f3)==1)
                        {
                            if(issue.st_id!=t || s==1)
                            {
                                fwrite(&issue,sizeof(issue),1,f1);
                            }
                            else
                            {
                                /* while(fread(&book,sizeof(book),1,fp)==1){
                                     if(book.id==d){
                                        book.quantity1++;
                                        book.quantity2--;
                                        fseek(fp,ftell(fp)-sizeof(book),0);
                                        fwrite(&book,sizeof(book),1,fp);
                                        fclose(fp);
                                        break;
                                     }
                                 }*/
                                fwrite(&in,sizeof(in),1,f2);
                                fclose(f2);
                                s=1;
                            }
                        }
                        fclose(f1);
                        fclose(f3);
                        remove("Issue.txt");
                        rename("text1.txt","Issue.txt");
                        gotoxy(10,20);
                        printf("\xb2 The Issued book is Removed from Issue List \xb2");
                    }
                    else
                    {
                        gotoxy(15,14);
                        printf("\aYou have not paid correct amount. \xb2 Enter Correct Amount \xb2\a(y/n)");
                        if(getch()=='n')
                        {
                            issue_books();
                        }
                        goto A;
                    }
                }
            }
            if(find_book==0)
            {
                gotoxy(10,15);
                printf("No Record Found");
            }
            gotoxy(15,25);
            printf("Remove any more?(Y/N)");
            if(getch()=='n')
            {
                issue_books();
            }
            else
                another='y';
        }
    }
    else
    {
        gotoxy(15,10);
        printf("Not Available for Everybody..........Back \xdb Main Menu \xdb");
        getch();
        mainmenu();
    }
}


