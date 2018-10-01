#include <math.h> 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>





int main (void)
{




/*

 addCustomer()
{

}
 

addPlan()   
{


}

delete plan()
{
	
}


saveInfo() 

{

}

readinfo()
{

}
*/

	float deposit, rate, period;
	
	printf("Enter initial deposit of this investment\n");
    scanf("%f", &deposit);
	printf("Enter the interest rate of this investment\n");
	scanf("%f", &rate);
	printf("Enter the period of this investment\n");
	scanf("%f", &period);
	
	double interestGained = (deposit * rate * period)/100;
	
	printf(" The simple interest gained from this investment = %f", interestGained);
	
	
	



/*
displayInfo() 
{

}

Deleteinfo()
{

} 

Displayplan()
{

}
*/




 return 0;
}
