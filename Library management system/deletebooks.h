
void delete_books(){
    int d;
    int t=0;
    system("cls");
    design();
    if(strcmp(word,password1)==0){
    gotoxy(20,4);
    fp=fopen("Record.dat","r+");
    printf("\xdb\xb2\xb1 Enter the Book ID to delete:");
    scanf("%d",&d);
    rewind(fp);
    while(fread(&book,sizeof(book),1,fp)==1){
        if(book.id==d){
            gotoxy(20,7);
            printf("The Book is available");
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
            printf("\xB2 Rack No:%d ",book.rack_no);gotoxy(47,14);printf("\xB2");
            gotoxy(20,14);
            printf("&&&&&&&&&&&&&&&&&&&&&&&&&&&&");
            t=1;
        }
    }
        if(t==0){
            gotoxy(20,17);
            printf("No Record is found, Modify the search:");
            getch();
            mainmenu();
        }
        else{
            gotoxy(20,17);
            printf("Do you want to delete these books(y/n):");
            if(getch()=='y'){
              ft=fopen("test.dat","w+");  //temporary file for delete
              rewind(fp);
              while(fread(&book,sizeof(book),1,fp)==1){
                if(book.id!=d){
                   //fseek(ft,0,SEEK_CUR);
                  fwrite(&book,sizeof(book),1,ft); //write all in tempory file except that
               }                              //we want to delete
             }
             fclose(fp);
             fclose(ft);
             remove("Record.dat");
             rename("test.dat","Record.dat");
             gotoxy(20,20);
             printf("The Record is successfully deleted");
             gotoxy(20,22);
             printf("Delete another books(y/n):");
             if(getch()=='n')
                mainmenu();
             else
                delete_books();
          }
          else
             mainmenu();
    }
    }
    else{
        gotoxy(15,10);
        printf("Not Available for Everybody..........Back \xdb Main Menu \xdb");
        getch();
        mainmenu();
    }
}
