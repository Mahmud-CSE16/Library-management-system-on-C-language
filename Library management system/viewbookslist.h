
void view_book_list(){
    int i=0,j;
    system("cls");
    gotoxy(1,1);
    printf("  --------------------------------------------Book List--------------------------------------------");
    gotoxy(2,2);
    printf(" CATEGORY      ID     BOOK NAME       AUTHOR      FULL QUANTITY    NOW    ISSUED     RackNo\n ");
    printf("  --------     ----    ---------       ------      -------------    ---    ------     ------");
    j=4;
    fp=fopen("Record.dat","r+");
    while(fread(&book,sizeof(book),1,fp)==1){
    if(feof(fp)){
        break;
    }
    gotoxy(3,j);
    printf("%s",book.cat);
    gotoxy(16,j);
    printf("%d",book.id);
    gotoxy(24,j);
    printf("%s",book.name);
    gotoxy(40,j);
    printf("%s",book.Author);
    gotoxy(58,j);
    printf("%d",book.quantity);
    gotoxy(70,j);
    printf("%d",book.quantity1);
    gotoxy(78,j);
    printf("%d",book.quantity2);
    gotoxy(89,j);
    printf("%d",book.rack_no);
    printf("\n\n");
    j++;
    i=i+book.quantity;
    }
    gotoxy(3,j+3);
    printf("Total Books =%d",i);
    fclose(fp);
    gotoxy(35,j+3);
    printf("Main Menu....\xb2 ENTER \xb2");
    getch();
    mainmenu();
}

