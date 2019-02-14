void search_books(){
    system("cls");
    design();
    int d;
    int find_book;
    gotoxy(15,5);
    printf("*****************************Search Books*********************************");
    gotoxy(20,10);
    printf("\xDB\xDB\xDB|-> 1. Search By ID");
    gotoxy(20,14);
    printf("\xDB\xDB\xDB|-> 2. Search By Name");
    gotoxy( 15,20);
    printf("\xdb\xb1 Enter Your Choice: ");
    fp=fopen("Record.dat","r+");
    rewind(fp);
    switch(getch())
    {
      case '1':
    {
        find_book=0;
        system("cls");
        design();
        gotoxy(25,4);
        printf("----------Search Books By Id----------");
        gotoxy(20,5);
        printf("Enter the book id:");
        scanf("%d",&d);
        gotoxy(20,7);
        printf("Searching........");
        while(fread(&book,sizeof(book),1,fp)==1){
        if(feof(fp)){
            break;
        }
        if(book.id==d)
        {
            gotoxy(20,6);
            printf("\xdb\xdb\xdb\xb1\xb1 The Book is available");
            gotoxy(20,8);
            printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
            gotoxy(20,9);
            printf("& ID:%d",book.id);gotoxy(47,9);printf("&");
            gotoxy(20,10);
            printf("\xB2 Name:%s",book.name);gotoxy(47,10);printf("\xB2");
            gotoxy(20,11);
            printf("\xB2 Author:%s ",book.Author);gotoxy(47,11);printf("\xB2");
            gotoxy(20,12);
            printf("\xB2 Qantity:%d ",book.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
            gotoxy(20,13);
            printf("\xB2 Rack No:%d ",book.rack_no);gotoxy(47,13);printf("\xB2");
            gotoxy(20,14);
            printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
            find_book=1;
        }

        }
        if(find_book==0)
        {
        gotoxy(20,8);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
        gotoxy(20,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(22,9);printf("\a\xdb\xb2\xb1 No Record Found \xb1\xb2\xdb");
        }
        gotoxy(20,17);
        printf("\xdb\xb2\xb1 Try another search?(Y/N)");
        if(getch()=='y')
        search_books();
        else
        mainmenu();
        break;
    }
    case '2':
    {
        find_book=0;
        char s[15];
        system("cls");
        design();
        gotoxy(25,4);
        printf("-----------Search Books By Name----------");
        gotoxy(20,5);
        printf("Enter Book Name:");
        scanf("%s",s);
        gotoxy(20,7);
        printf("\xdb\xdb\xdb\xb1 Full name of books below:");
        int n=0;
        while(fread(&book,sizeof(book),1,fp)==1){
        if(feof(fp)){
            break;
        }
        int i,s1=0;
        for(i=0;s[i]!='\0';i++){
            if(book.name[i]!=s[i]){
               s1=1;
               break;
            }
        }
        if(s1==0){
            gotoxy(23,n+9);
            printf("%d. %s",++n,book.name);
        }
        }
        if(n>0){
        gotoxy(20,24);
        printf("Enter full Book Name:");
        scanf("%s",s);
        system("cls");
        design();
        rewind(fp);
        while(fread(&book,sizeof(book),1,fp)==1){
        if(feof(fp)){
            break;
        }
        if(strcmp(book.name,(s))==0) //checks whether book.name is equal to s or not
        {
            system("cls");
            design();
            gotoxy(20,7);
            printf("\xdb\xdb\xdb\xb1\xb1 The Book is available");
            gotoxy(20,8);
            printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
            gotoxy(20,9);
            printf("& ID:%d",book.id);gotoxy(47,9);printf("&");
            gotoxy(20,10);
            printf("\xB2 Name:%s",book.name);gotoxy(47,10);printf("\xB2");
            gotoxy(20,11);
            printf("\xB2 Author:%s",book.Author);gotoxy(47,11);printf("\xB2");
            gotoxy(20,12);
            printf("\xB2 Qantity:%d",book.quantity);gotoxy(47,12);printf("\xB2");
            gotoxy(20,13);
            printf("\xB2 Rack No:%d ",book.rack_no);gotoxy(47,13);printf("\xB2");
            gotoxy(20,14);
            printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
            find_book=1;
        }
        }

        }
        if(find_book==0)
        {
        gotoxy(20,8);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(20,9);printf("\xB2");  gotoxy(38,9);printf("\xB2");
        gotoxy(20,10);
        printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
        gotoxy(22,9);printf("\aNo Record Found");
        }
        gotoxy(20,17);
        printf("\xdb\xdb\xb1 Try another search?(Y/N)");
        if(getch()=='y')
        search_books();
        else
        mainmenu();
        break;
    }
    default :
    getch();
    search_books();
    }
    fclose(fp);
}


