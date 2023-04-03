#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<windows.h>

void Timeslot(),Price(int x,int y),Details(),Ticketstatus(); //Function Prototypes

typedef struct {
    char mobile[15];
} BOOKING;

BOOKING list1[50],list2[50];// list1 stores bookings on based of mobile numbers and list2 is just for function details when user wants to check ticket status
int i=1,j=0;

void main(){
    FILE*cp;
    int choice,moviecode,persons,payc,back1,back2,back3;

        system("cls");
       
        system("color e5");
        
        do{
            for(int i=0;i<68;i++){
               printf("*");
            }printf("\n\t\t");
        printf("Welcome to Cinema"); printf("\n\t\t");
        printf("\n\n\t");  printf("Select your choice from 1 to 4");
        printf("\n\t");    printf("1.Prebooking");
        printf("\n\t");    printf("2.Timeslot");
        printf("\n\t");    printf("3.MyTickets");
        printf("\n\t");    printf("4.Exit");
        printf("\n\n\t\t");printf("Enter your choice: ");scanf("%d",&choice); 

        system("cls");
        
        switch(choice){
            case 1: 
                printf("GREAT,LET'S SEE A MOVIE!"); printf("\n");
                printf("\n\t");     printf("Select your movie choice and enter the code as follows~~");
                printf("\n\t");     printf("movie1->1 or movie2->2 , for 1st digit of code");
                printf("\n\t");     printf("Select screen1->1 or Screen2->2 for 2nd digit of code");
                printf("\n\t");     printf("Choice Morning->1 or Evening->2 for 3rd digit of code");
                printf("\n\t");     printf("**If You want to watch movie1 at morning in screen2,enter code:112**");
                printf("\n\t");     printf("**If You want to watch movie2 at evening in screen1,enter code:221**");
                printf("\n\n\t");   printf("Enter the moviecode: "); scanf("%d",&moviecode);
                
                    
                cp=fopen("Record.txt","a");
                fprintf(cp,"\n\t\t\tCINEMA RECORDS\n\n");
                fprintf(cp,"\tPREBOOKING:\n");
                fprintf(cp,"\t\tMovieCode = %d\n",moviecode);
                fclose(cp);

                printf("\n\t"); printf("Enter the number of persons: "); scanf("%d",&persons);

                Price(moviecode,persons);
                
                printf("\n\t"); printf("Let's have Confirmation. ");
                printf("\n\t"); printf("Enter->1 to confirm Ticket or Enter->0 to go Home : "); scanf("%d",&payc); printf("\n");
                
                if(payc==0){
                    break;
                }

                printf("\n\tRemember your booking number is %d",i);
                printf("\n\n\t"); printf("Enter your mobile number and ticket gets confirmed: "); 
                scanf("%s",list1[i-1].mobile); printf("\n");   i++;

                cp = fopen("Record.txt","a");
                fprintf(cp,"\n\tDETAILS:\n");
                fprintf(cp,"\t\tBooking number = %d\n",i-1);
                fprintf(cp,"\t\tMobile Number = %s\n",list1[i-2].mobile);
                fclose(cp);
 
                printf("\n\n\tEnter->0 to go Back Home. ->");   scanf("%d",&back1); printf("\n");
                if(back1==0){break;}
                
            case 2:
                Timeslot();
                printf("\n\n\tEnter->0 to go Back Home. ->");   scanf("%d",&back2); printf("\n");
                if(back2==0){break;}

            case 3:
                Ticketstatus();
                printf("\n\n\tEnter->0 to go Back Home. ->");   scanf("%d",&back3); printf("\n");
                if(back3==0){break;}
                
        }
       } while(choice!=4); 
}

void Price(int x,int y){
    int final_price,price;
    FILE *cv;
    if(x==111){
        price=200;       
    }
    else if(x==112){
        price=210;
    }
    else if(x==121){
        price=210;
    }
    else if(x==122){
        price=200;
    }
    else if(x==211){
        price=150;
    }
    else if(x==212){
        price=160;
    }
    else if(x==221){
        price=160;
    }
    else if(x==222){
        price=150;
    }

    final_price = price*y;
    
    printf("\n\tMovie price is = %d/-",price);
    printf("\n\tTotal cost is = %d/- Only",final_price);   printf("\n");

    cv=fopen("Record.txt","a");
    fprintf(cv,"\n\tPRICE DETAILS:");
    fprintf(cv,"\n\t\tPersons = %d",y);
    fprintf(cv,"\n\t\tPrice = %d ",final_price); fprintf(cv,"\n");
    fclose(cv);
}


void Timeslot(){
    char movie[15];
    printf("\n\n\tEnter the movie name: ");
    scanf("%s",movie);
    
    if(strcmp(movie,"movie1")==0){
        printf("\n\t");       printf("Morning slot at screen1 : 7-9(am) "); 
        printf("\n\t");       printf("Evening slot at screen1 : 4-6(pm) ");
        printf("\n\t");       printf("Morning slot at screen2 : 4-6(pm) ");
        printf("\n\t");       printf("Evening slot at screen2 : 7-9(pm) ");
    }
    else if(strcmp(movie,"movie2")==0){
        printf("\n\t");       printf("Morning slot at screen1 : 7-9(am) ");
        printf("\n\t");       printf("Evening slot at screen1 : 4-6(pm) ");
        printf("\n\t");       printf("Morning slot at screen2 : 4-6(pm) ");
        printf("\n\t");       printf("Evening slot at screen2 : 7-9(pm) ");
    } 
    else{
        printf("\n\t");       printf("OOPS! No such movie going on. ");
    }   
}

void Details(){
    printf("\n\n\t");  printf("Enter Your Registered Mobile Number: ");
    scanf("%s",list2[j].mobile); j++;

}

void Ticketstatus(){
    Details();
    int num; printf("\n\tEnter your booking number: "); scanf("%d",&num);
    FILE *mt;
    
    if(strcmp(list1[num-1].mobile,list2[j-1].mobile)==0){
        printf("\n\t\t"); printf("*Your Ticket is Confirmed*");
        mt = fopen("Record.txt","a");
        fprintf(mt,"\n\tTicket Status : Confirmed \n\n");
        fclose(mt);
    }
    else{
        printf("\n\t"); printf("No Tickets Registered On this Mobile Number!");
    }
}



