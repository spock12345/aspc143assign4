//inculde the math.h and the stdio.h libraries
#include <stdio.h>
#include <math.h>

int main() {
    //first we can delcare our varibles at the start
    float costI , annuity , intrest , i  , PV;
    int lifespan;
    //now we can get the user input for the problem.
    //first the input for the initial cost of the project and store it in a varible
    printf ("\nEnter the initial cost of the project: $");
    scanf ("%f" , &costI);
    //same with the annuity of the project
    printf("Enter the annuity of the project: $");
    scanf("%f" , &annuity);
    //now the interest
    printf("Enter the interest rate in %: ");
    scanf("%f" , &intrest);
    //you get the drill by now, last one is life span
    printf("Enter the lifespan of the project in years: ");
    scanf("%d" , &lifespan);

    //now that we have our functions stored whe can now find the present value of the project
    //now we have to find the present worth of the project
    //this part of the code is to format the user input variables that the user gave us.
    i = 1.0 + (intrest / 100.0);
    costI *= -1;
    //now i will declare a new varible equail to the intal cost becuse in the PV calc costI is changed
    float costI2 = costI;
    //now we can calculate the value of the PV. it will be the intial cost plus
    //the out put of the equation giving in the instuctions, done for every
    //value of the lifespan
    while (lifespan > 0){
        PV = annuity / ( pow(i , lifespan));
        costI += PV;
        lifespan --;
    }
    //now we can print the present value to the console
    //now a simple if else statement to print whether the project is worth pursuing
    if (costI > 0)
        printf ("Present worth of the project = $%0.2f\nThe project is economically feasible." , fabs(costI));
    else
        printf ("Present worth of the project = -$%0.2f\nThe project is not economically feasible.", fabs(costI));
    //now we can calculate the payback period
    float n = 0;
    while (costI2 <= 0){
        float Payback = annuity / ( pow(i , n));
        costI2 += Payback;
        n ++;
    }
    // now ceil the n
    ceil (n);
    printf ("\nThe payback period for this project is %.0f years.\n" , n);
    return 0;
}
