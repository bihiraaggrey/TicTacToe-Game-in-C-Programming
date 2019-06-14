#include<stdio.h>
struct myDataType{
    int i;
    char ch;
}inputValue();
void main(){
    char startnew[1];
    again:
runboard();
printf("\n\tEnter or press key 1 to start a new game\t Otherwise Press any key to exit\t:");
     scanf("%s",startnew);
    if(*startnew== '1')
        goto again;
    else
        exit(0);

}
 void runboard(){
     int count;
     struct myDataType info;
    char symbol[9]={'1','2','3','4','5','6','7','8','9'};

    displayboard(symbol);

    again:
    info = inputValue(symbol,count);
    symbol[info.i] = info.ch;
    system("cls");//system-clear to enable have all the nodes played on a single board without outputing again!
    displayboard(symbol);
    if(check(symbol, info.ch,count)==1);
    else{
    count++;
    goto again;
    }
 }
 //function for checking similar rows, columns and diagonals
 //takes 3 parameters
 int check(char sym[9], char ch[1], int count){
        //checking for the first row for the winner (matching symbols)
     if(sym[0]==ch&&sym[1]==ch&&sym[2]==ch){
        printf("\n\tCongs!!!!!!The Player %c wins!!\t\n",ch);
         return 1;
     }
       //checking for the first column for the winner (matching symbols)
     if(sym[0]==ch&&sym[3]==ch&&sym[6]==ch){
        printf("\n\tCongs!!!!!!The Player %c wins!!\t\n",ch);
         return 1;
     }
       //checking for the second row for the winner (matching symbols)
     if(sym[3]==ch&&sym[4]==ch&&sym[5]==ch){
        printf("\n\tCongs!!!!!!The Player %c wins!!\t\n",ch);
         return 1;
     }
       //checking for the third row for the winner (matching symbols)
     if(sym[6]==ch&&sym[7]==ch&&sym[8]==ch){
        printf("\n\tCongs!!!!!!The Player %c wins!!\t\n",ch);
         return 1;
     }
       //checking for the second column for the winner (matching symbols)
     if(sym[1]==ch&&sym[4]==ch&&sym[7]==ch){
        printf("\n\tCongs!!!!!!The Player %c wins!!\t\n",ch);
         return 1;
     }
      //checking for the first column for the winner (matching symbols)
     if(sym[0]==ch&&sym[3]==ch&&sym[6]==ch){
        printf("\n\tCongs!!!!!!The Player %c  wins!!\t\n",ch);
        return 1;
     }
       //checking for the third column for the winner (matching symbols)
     if(sym[2]==ch&&sym[5]==ch&&sym[8]==ch){
        printf("\n\tCongs!!!!!!The Player %c  wins!!\t\n",ch);
        return 1;
     }

      //checking for the major diagonal for the winner (matching symbols)
     if(sym[0]==ch&&sym[4]==ch&&sym[8]==ch){
        printf("\n\tCongs!!!!!!The Player %c wins!!\t\n",ch);
         return 1;
     }
      //checking for the minor diagonal for the winner (matching symbols)
     else if(sym[2]==ch&&sym[4]==ch&&sym[6]==ch){
        printf("\n\tCongs!!!!!!The Player %c wins!!\t\n",ch);
        return 1;
     }
     else if(count==8){
        printf("Oooops!!! 0 score-Draw");
     }
     else{
        return 0;
     }

 }
 struct myDataType inputValue(char sym[9], int count){
        char value[1];
        int i;
        struct myDataType info;
        inputAgain:
        if(count%2 ==0){
                //Having the first count for the MAX- player to play first
            printf("Enter the choice for player X: ");
        }
        else{
            //MIN player playing next after MAX has played
            printf("Enter the choice for player 0: ");
        }
        scanf("%s",value);
        for(i=0;i<9;i++){
            if(*value==sym[i]){
                info.i=i;//assigning values to structure variables
                if(count%2==0)
                    info.ch='X';
                else
                    info.ch='O';
                break;
            }
            else{
                info.i=-1;
                info.ch="";
            }
        }
        if(info.i==-1){
            printf("\n Input is not Valid!\n\n");
            goto inputAgain;
        }
        return info;
 }
 void displayboard(char sym[9]){
      printf("\n\t\tTic \tTac \tToe \tGame\tWithout   AI\n\n");
      printf("\n\tPlayer 1 uses symbol: \tX to play\n");
      printf("\n\tPlayer 2 uses symbol: \tO to play\n");
      printf("\n\nPrinting the board\n\n");
      printf("\n\t        |          |     ");
      printf("\n\t    %c   |      %c   |  %c     ",sym[0],sym[1],sym[2] );
      printf("\n\t........|..........|........");
      printf("\n\t    %c   |      %c   |  %c     ",sym[3],sym[4],sym[5] );
      printf("\n\t        |          |     ");
      printf("\n\t........|..........|........");
      printf("\n\t    %c   |      %c   |  %c     ",sym[6],sym[7],sym[8] );
      printf("\n\t        |          |     ");
      printf("\n\n");


 }

