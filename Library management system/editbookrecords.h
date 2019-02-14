void edit_books_record(){
    system("cls");
    design();
    if(strcmp(word,password1)==0){
    int t=0;
    int d;
    gotoxy(18,4);
    printf("---------------Edit Books Section-------------");
    gotoxy(15,6);
        printf("\xb2\xb1 Enter Book Id to be edited:");
        scanf("%d",&d);
        fp=fopen("Record.dat","r+");
            if(checkid(d)==0){
            B:
            gotoxy(20,7);
            printf("@@ The Book is available");
            gotoxy(20,8);
            printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
            gotoxy(20,9);
            printf("& # ID:%d",book.id);gotoxy(47,9);printf("&");
            gotoxy(20,10);
            printf("\xB2 1. Name:%s",book.name);gotoxy(47,10);printf("\xB2");
            gotoxy(20,11);
            printf("\xB2 2. Author:%s ",book.Author);gotoxy(47,11);printf("\xB2");
            gotoxy(20,12);
            printf("\xB2 3. Quantity:%d ",book.quantity);gotoxy(47,12);printf("\xB2"); gotoxy(47,11);printf("\xB2");
            gotoxy(20,13);
            printf("\xB2 4. Rack No:%d ",book.rack_no);gotoxy(47,14);printf("\xB2");
            gotoxy(20,14);
            printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
            gotoxy(20,15);
            printf("Which record You want to remove:");
            int c;
            scanf("%d",&c);
            switch(c){
            case 1:
                gotoxy(20,17);
                printf("Enter New Name: ");
                scanf(" %[^\n]s",book.name);
                break;
            case 2:
                gotoxy(20,17);
                printf("Enter New Author: ");
                scanf(" %[^\n]s",book.Author);
                break;
            case 3:
                gotoxy(20,17);
                printf("Enter New Quantity: ");
                scanf("%d",book.quantity);
                break;
            case 4:
                gotoxy(20,17);
                printf("Enter the New Rack NO: ");
                scanf("%d",book.rack_no);
            default:
                gotoxy(20,18);
                printf("Wrong Entered:::::.....Reenter:");
                getch();
                goto B;
            }
                gotoxy(15,19);
                printf("\xdb\xdb\xdb\xb1\xb1 The record is modified");
                fseek(fp,ftell(fp)-sizeof(book),0);
                fwrite(&book,sizeof(book),1,fp);
                fclose(fp);
                t=1;
            }
            if(t==0)
            {
                gotoxy(15,9);
                printf("\xdb\xb2\xb1 No record found \xb1\xb2\xdb");
            }

        gotoxy(15,21);
        printf("\xdb\xb1 Modify another Record?(Y/N)");
        if(getch()=='y'){
            edit_books_record();
        }
        else
            mainmenu();
    }
    else{
        gotoxy(15,10);
        printf("Not Available for Everybody..........Back \xdb Main Menu \xdb");
        getch();
        mainmenu();
    }
}


