void add_books(){
    system("cls");
    design();
    if(strcmp(word,password1)==0){
    gotoxy(20,3);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2SELECT CATEGOIES");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,5);
    printf("\xDB\xDB\xDB\xB2\xb1 1. Math");
    gotoxy(20,7);
    printf("\xDB\xDB\xDB\xB2\xb1 2. Physics");
    gotoxy(20,9);
    printf("\xDB\xDB\xDB\xB2\xb1 3. Chemistry");
    gotoxy(20,11);
    printf("\xDB\xDB\xDB\xB2\xb1 4. Computer");
    gotoxy(20,13);
    printf("\xDB\xDB\xDB\xB2\xb1 5. Electrical");
    gotoxy(20,15);
    printf("\xDB\xDB\xDB\xB2\xb1 6. Civil");
    gotoxy(20,17);
    printf("\xDB\xDB\xDB\xB2\xb1 7. Architecture");
    gotoxy(20,19);
    printf("\xdb\xdb\xdb\xb2\xb1 8. Other");
    gotoxy(20,21);
    printf("\xdb\xdb\xdb\xb2\xb1 9. Back to Main Menu");
    gotoxy(20,23);
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    printf("\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2\xB2");
    gotoxy(20,25);
    printf("Enter your choice:");
    scanf("%d",&s);
    if(s==9){
        mainmenu();
    }
    system("cls");
    design();
    fp=fopen("Record.dat","a+");
    if(getdata()==1)
    {
    strcpy(book.cat,catagories[s-1]);
    //fseek(fp,0,SEEK_END);
    fwrite(&book,sizeof(book),1,fp);
    fclose(fp);
    gotoxy(21,14);
    printf("\xdb\xdb\xb1 The record is successfully saved \xb1\xdb\xdb");
    gotoxy(21,15);
    printf("\xdb\xb1|-> Save any more?(Y / N):");
    if(getch()=='n')
        mainmenu();
    else
        add_books();
    }
    }
    else{
        gotoxy(15,10);
        printf("Not Available for Everybody..........Back \xdb Main Menu \xdb");
        getch();
        mainmenu();
    }
}

int getdata()
{
    int t;
    gotoxy(20,3);
    printf("\xb1\xb1\xb1\xb1 Enter the Information Below \xb1\xb1\xb1\xb1");
    gotoxy(20,4);
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
    gotoxy(20,5);
    printf("&");gotoxy(60,5);printf("&");
    gotoxy(20,6);
    printf("\xB2");gotoxy(60,6);printf("\xB2");
    gotoxy(20,7);
    printf("\xB2");gotoxy(60,7);printf("\xB2");
    gotoxy(20,8);
    printf("\xB2");gotoxy(60,8);printf("\xB2");
    gotoxy(20,9);
    printf("\xB2");gotoxy(60,9);printf("\xB2");
    gotoxy(20,10);
    printf("\xB2");gotoxy(60,10);printf("\xB2");
    gotoxy(20,11);
    printf("\xB2");gotoxy(60,11);printf("\xB2");
    gotoxy(20,12);
    printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
    gotoxy(21,5);
    printf("Category:");
    gotoxy(33,5);
    printf("%s",catagories[s-1]);
    gotoxy(21,6);
    printf("Book ID:\t");
    gotoxy(33,6);
    scanf("%d",&t);
    if(checkid(t) == 0)
    {
        gotoxy(21,13);
        printf("\aThe book id already exists\a");
        getch();
        mainmenu();
        return 0;
    }
    book.id=t;
    gotoxy(21,7);
    printf("Book Name:");gotoxy(33,7);
    scanf(" %[^\n]s",book.name);
    gotoxy(21,8);
    printf("Author:");gotoxy(33,8);
    scanf(" %[^\n]s",book.Author);
    gotoxy(21,9);
    printf("Quantity:");gotoxy(33,9);
    scanf("%d",&book.quantity);
    book.quantity1=book.quantity;
    book.quantity2=0;
    gotoxy(21,10);
    printf("Rack No:");gotoxy(33,10);
    scanf("%d",&book.rack_no);
    return 1;
}




