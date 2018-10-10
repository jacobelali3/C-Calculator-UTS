#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


#define MAX_NUM_CUSTOMER 10
#define DB_NAME "database"
#define MAX_CUSTOMER_LEN 1000000


typedef struct   
{
    char name[MAX_CUSTOMER_LEN+1];
    int deposit;
    int period;
    int rate;
   
}customer_list_t;
    customer_list_t customer[MAX_NUM_CUSTOMER];
    int num_customer = 0;
void Back (void);
/*int customer (void);
int administrator (void);*/
void customermenu (void);
void adminmenu (void);
void addNew (void);
void displayplan (void);
void displayinfo (void);
void calculateInterest (void);
void saveInfo (void);
void addplan (void);
void savecustomerinfo (void);
void readinfo (void);
void deleteinfo (void);
void deleteplan (void);
void simpleInterest(void);
void compoundInterest(void);

int main (void)  
{
    
    int choice1 = -1;
    
    
    
    printf("You want to run the program as: \n 1.Customer \n 2.admin \n 3.quit\nTYPE HERE>\n");
    scanf("%d", &choice1);

    switch(choice1)
{
          
    case 1:
    
  {
  customermenu();
 
  } 
    case 2:
      
  {
  adminmenu();
  
  }
  case 3:
        printf("goodbye\n");
        break;
   default : printf("Invalid Choice\n");
             main();
             break;
	
}

return 0;
}

void customermenu (void) 
  {
     printf("\n"
    "1. add customer information \n"
    "2. Show the plan list.\n"
    "3. Display the information the customer inputed.\n"
    "4. Calculate the interest.\n"
    "5. save information.\n"
    "6. Back to top level.\n"
    "Enter choice (number between 1-6)> \n");
     int choice2 = -1;
    
    int check = 0;
      scanf("%d", &choice2);
  while ((check = getchar()) != '\n');
            
        switch(choice2)
        {
        case 1:
            addNew();
            break;
        case 2:
            displayplan();
            break;
        case 3:
            displayinfo();
            break;
        case 4:
            calculateInterest();
            break; 
        case 5:
            saveInfo();
            break;
        case 6:
            Back();
            break;     
         default: printf("Invalid choice.\n"); 
                  customermenu();                  
        }  
       
   }


void adminmenu (void)
{
    printf("\n"
        "1.add plan.\n"
        "2.save customer information.\n" 
        "3.read customer information.\n"
        "4.delete customer information.\n"
        "5.delete plan.\n"
        "6. Back to top level.\n"
        "Enter choice (number between 1-6)>\n" );
    int choice3 = -1;
    int check1 = 0;
    scanf("%d", &choice3);
  while ((check1 = getchar()) != '\n');
             
        switch(choice3)
        {
        case 1:
            addplan();
            break;
        case 2:
            savecustomerinfo();
            break;
        case 3:
            readinfo();
            break;
        case 4:
            deleteinfo();
            break; 
        case 5:
            deleteplan();
            break;
        case 6:
            Back();
            break;
             default: printf("Invalid choice.\n");  
                      adminmenu();                    
        }
}

void Back (void)
{
printf("wait to complete\n");
customermenu();
}



void addNew (void)
{
    {


        int check = 0;
        if (num_customer == MAX_NUM_CUSTOMER)
        {
            printf("Cannot add more customer - memory full\n");
            return;
        }
    
  
        printf("Enter customer name>\n");
        
            scanf("%s", customer[num_customer].name);

        

    printf("Enter deposit info for the customer.\n");
 
        printf("Enter deposit amount, period and deposit rate separated by spaces>\n");
        scanf("%d %d %d", 
            &customer[num_customer].deposit,
            &customer[num_customer].period,
            &customer[num_customer].rate);
            
        


    while ((check = getchar()) != '\n');


    num_customer++;
}

    customermenu();
}



void displayplan (void)
{

    customermenu();
}


void displayinfo (void)

{
   {

    int i = 0;
    int find = 0;
    char name[MAX_CUSTOMER_LEN+1] = { 0 };
    printf("Enter customer name or enter * to show all information>\n");
    scanf("%s", name);

    if (num_customer == 0)
    {
        printf("No information\n");
        customermenu();
    }


    if (0 == strcmp(name, "*"))
    {
        printf("%-6s %-15s %-15s %-6s\n", "NAME", "DEPOSIT AMOUNT", "PERIOD", "RATE");
        printf("%-6s %-15s %-15s %-6s\n", "------", "---------------", "---------------", "------");
        for (i = 0; i < num_customer; i++)
        {
            
            printf("%-6s %-15d %-15d %-6d\n", 
                customer[i].name,
                customer[i].deposit,
                customer[i].period,
                customer[i].rate
                );  
        }
    }
    else
    {
        find = 0;
        for (i = 0; i < num_customer; i++)
        {
            if (0 == strcmp(name, customer[i].name))
            {
                find = 1;
                break;
            }

        }

        if (!find)
        {
            printf("No information.\n");
            customermenu();
        }


        printf("%-6s %-15s %-15s %-6s\n", "NAME", "DEPOSIT AMOUNT", "PERIOD", "RATE");
        printf("%-6s %-15s %-15s %-6s\n", "------", "---------------", "---------------", "------");
        for (i = 0; i < num_customer; i++)
        {
            if (0 == strcmp(name, customer[i].name))
            {

                 printf("%-6s %-15d %-15d %-6d\n", 
                customer[i].name,
                customer[i].deposit,
                customer[i].period,
                customer[i].rate
                    );
            }

        }

    }

}
    customermenu();
}

void calculateInterest (void)
{
    int x;
    printf("Please choose an option\n");
    printf("1.Simple interest\n"
           "2.Compound interest\n" 
           "3.Back to previous level\n"
           "Enter your choice here >>>>>\n");
    scanf("%d", &x);
   switch(x)
   {
    case 1:
    
        simpleInterest();
         break;
           
    case 2:
    
        compoundInterest();
        break;
        
    
    case 3:
    
        customermenu();
        break;
    
    default:
    
        printf("invalid option\n");
        calculateInterest();
        break;
    }

}


void simpleInterest(void)
{

    float deposit, rate, period;  /* fix datatypes*/
    
    printf("Simple interest calculator\n");
    printf("Enter initial deposit of this investment\n");
    scanf("%f", &deposit);
    printf("Enter the interest rate of this investment\n");
    scanf("%f", &rate);
    printf("Enter the period of this investment in years\n");
    scanf("%f", &period);
    
    double interestGained = (deposit * rate * period)/100;
    
    printf(" The simple interest gained from this investment = %f\n\n", interestGained);
    calculateInterest();
    
}

void compoundInterest(void)
{
    float deposit, rate, period, interestGained, profit;
    int x;
    
    printf("Compound quarterly interest calculator\n");
    printf("Enter initial deposit of this investment\n");
    scanf("%f", &deposit);
    printf("Enter the interest rate of this investment\n");
    scanf("%f", &rate);
    printf("Enter the period of this investment in years\n");
    scanf("%f", &period);

    for(x = 1; x <= period; x++)
    {
        
        interestGained = deposit* (pow((1 + rate / 100), x));
        profit = interestGained - deposit;
        printf("Year %d\t\t InitialDeposit %f\t\t Finalbalance %f\n \t\t Profit made %f\n\n", x, deposit, interestGained, profit);
    }
    
    calculateInterest();
    
}


void saveInfo (void)
{
    printf("wait to complete\n");
}
void addplan (void)
{
    printf("wait to complete\n");
}
void savecustomerinfo (void)
{
    printf("wait to complete\n");
}
void readinfo (void)
{
    printf("wait to complete\n");
}
void deleteinfo (void)
{
    printf("wait to complete\n");
}
void deleteplan (void)
{
    printf("wait to complete\n");
}

