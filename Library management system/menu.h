
void mainmenu(){
    system("cls");
    design();
    gotoxy(20,3);
    printf("\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xb2\xb2\xb2\xb2\xb1\xb1 MAIN MENU \xb1\xb1\xb2\xb2\xb2\xb2\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb\xdb");
    gotoxy(20,5);
    printf("\xDB\xb2\xB1 1. Add Books");
    gotoxy(20,7);
    printf("\xDB\xb2\xb1 2. Search Books");
    gotoxy(20,9);
    printf("\xDB\xb2\xb1 3. View Book list");
    gotoxy(20,11);
    printf("\xDB\xb2\xb1 4. Issue Books");
    gotoxy(20,13);
    printf("\xDB\xb2\xb1 5. Edit Book's Record");
    gotoxy(20,15);
    printf("\xDB\xb2\xb1 6. Delete books");
    gotoxy(20,17);
    printf("\xdb\xb2\xb1 7. Student corner");
    gotoxy(20,19);
    printf("\xDB\xb2\xb1 8. Close Application");
    gotoxy(20,120);
    printf("------------------------------------------");
    gotoxy(20,21);
    gotoxy(20,22);
    printf("Enter your choice:");
    int c;
    scanf("%d",&c);
    switch (c){
       case 1:
           add_books();
           break;
       case 2:
           search_books();
           break;
       case 3:
           view_book_list();
           break;
       case 4:
           issue_books();
           break;
       case 5:
           edit_books_record();
           break;
       case 6:
           delete_books();
           break;
       case 7:
           student_corner();
           break;
       case 8:
           system("cls");
           gotoxy(20,7);
           printf("\xb1\xdb Thanks for visiting the Library \xdb\xb1\n\n\n\n");
           delay(2000);
           exit(1);
      default:{
          gotoxy(10,23);
          printf("\aWrong Entry!!Please re-entered correct option");
          getch();
          mainmenu();
         }
    }
}


