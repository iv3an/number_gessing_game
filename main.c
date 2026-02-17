#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>



//func prototype | check below 
int random(int min,int max);
void loading(void);

int main(){
  srand(time(NULL));
  int choice;
  int min,max ;
  int random_num,gessed_num,tries;
  printf("*****NUMBER GESSING GAME******\n");
  printf("\nEnter difficulty (1,2): ");
  scanf("%d",&choice);
  switch(choice){
    case 1:
      min=1;
      max=10;
      break;
    case 2:
      min=1;
      max=100;
      break;
  }
  printf("LOADING\n");  
  loading();
  sleep(1);
  printf("\nyou chose LEVEL:%d\n",choice);
  sleep(1);
  printf("\nGess a number between (%d,%d) :) \n",min,max);

  random_num=random(min,max);
  
  tries=1;
  while(scanf("%d",&gessed_num)!=random_num){
    if(gessed_num<random_num){
      printf("TOo Low , try again :)\n");
    }else if(gessed_num>random_num){
      printf("TOo High , try again :)\n");
    }else{break;}
    
    tries++;
  }

  sleep(1);
  printf("\n***CONGRATS YOU GESSED IT RIGHT***\n");
  printf("***  number of tries:%d  ***\n",tries);
   

  return EXIT_SUCCESS;
}







/********************************************************
* this function returns a random number using time(NULL)* 
* as a seed , the number is between min and max .       *         
*                                                       *
* *******************************************************/
int random(int min , int max){
  int random_number=(rand()%(max-min+1))+min;

  return random_number;
}

/******************************************
 *this func prints (*) with a time stop   * 
 * ****************************************/

void loading(void){
  printf("\r[");
 for(int i=0;i<5;i++){
   printf("*");
   fflush(stdout);  //this forces it to print 1 by 1 in screen
   sleep(1); 
 }
  printf("]");
}
