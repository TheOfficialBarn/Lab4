#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//Here are function prototypes so that I don't have to create more files
//In C you cannot have a function used before it is declared
double* getUserTempConversion(double* choicesArr);
double convertTemp(double* choicesArr, bool printOutput);
void categorizeTemp(double);
void newLine() {printf("\n");};
int main() { 
	double* choicesArr = (double*)malloc(3 * sizeof(double));

	choicesArr = getUserTempConversion(choicesArr);
	//0 Temperature
	//1 Initial Scale
	//2 Conversion Scale

	convertTemp(choicesArr, true);

	choicesArr[2]=2;
	double celsiusTemp = convertTemp(choicesArr, false);
	categorizeTemp(celsiusTemp);

	free(choicesArr); //We wanna free da memory bc in C
	return(0);
}

double* getUserTempConversion(double* choicesArr)
{
	double userTemp;
	double userChoice;
	double userConvChoice;
	char userStringChoice[20];
	char userStringChoice2[20];

	printf("Enter a temperature: "); scanf("%lf", &userTemp);
	printf("Choose the temperature scale of the input value:\n1) Fahrenheit\n2) Celsius\n3) Kelvin\nScale choice (1-3): ");
	scanf("%lf", &userChoice);
	newLine();

	if(userChoice==1)
	{
		strcpy(userStringChoice, "Fahrenheit");
	} else if (userChoice==2)
	{
		strcpy(userStringChoice, "Celsius"); //String copy is used to modify charArrays and you have to #INCLUDE <STRING.H>
	} else if (userChoice==3)
	{
		strcpy(userStringChoice, "Kelvin");
	}
	
	printf("Would you like to convert %s into:\n1) Fahrenheit\n2) Celsius\n3) Kelvin\nScale choice (1-3): ", userStringChoice);
	scanf("%lf", &userConvChoice);
	newLine();
	newLine();

	if(userConvChoice==1)
	{
		strcpy(userStringChoice2, "Fahrenheit");
	} else if (userConvChoice==2)
	{
		strcpy(userStringChoice2, "Celsius"); //String copy is used to modify charArrays and you have to #INCLUDE <STRING.H>
	} else if (userConvChoice==3)
	{
		strcpy(userStringChoice2, "Kelvin");
	}

	printf("Converting %.2lf degrees %s into %s...\n",userTemp, userStringChoice, userStringChoice2);

	choicesArr[0] = userTemp;
	choicesArr[1] = userChoice;
	choicesArr[2] = userConvChoice;
	return choicesArr;
}

double convertTemp(double* choicesArr, bool printOutput)
{
	double convertedTemp;
	//1 is F
	//2 is C
	//3 is K

	if(choicesArr[2] == 3) //Convert to Kelvin
	{
		if(choicesArr[1] == 3){
			//Do nothing; it is already in Kelvin
			convertedTemp = choicesArr[0];

		} else if(choicesArr[1] ==2){
			//Convert Celius to Kelvin
			//K = C + 273.15
			convertedTemp = choicesArr[0] + 273.15;

		} else{
			//Convert Fahrenheight to Kelvin
			//K = (F-32) x 5.0/9.0 + 273.15
			convertedTemp = (choicesArr[0]-32) * (5.0/9.0) + 273.15;

		}
	} else if(choicesArr[2] == 2) //Convert to Celsius
	{
		if(choicesArr[1] == 2){
			//Do nothing; it is already in Celsius
			convertedTemp = choicesArr[0];

		} else if(choicesArr[1] ==3){
			//C = K-273.15
			convertedTemp = choicesArr[0] - 273.15;

		} else{
			//Convert Fahrenheight to Celsius
			//C = (F-32) x 5.0/9.0
			convertedTemp = (choicesArr[0]-32) * (5.0/9.0);

		}
	} else //Convert to Fahrenheight
	{
		if(choicesArr[1] == 1){
			//Do nothing; it is already in Fahrenheit
			convertedTemp = choicesArr[0];

		} else if(choicesArr[1] == 2){
			//F = C x 9.0/5.0 + 32
			convertedTemp = choicesArr[0] * (9.0/5.0) + 32;

		} else{
			//F = (K-273.15) x 9.0/5.0 + 32
			convertedTemp = (choicesArr[0]-273.15) * (9.0/5.0) + 32;

		}
	}
	if(printOutput == true) printf("Converted temperature: %.2lf\n", convertedTemp);

	return convertedTemp;
}

void categorizeTemp(double temp)
{
	if(temp <= 0){
		printf("It is currently freezing (approx. %.0lf deg.).\nWear your winter coat.", temp);
	} else if(temp <= 10){
		printf("It is currently cold (approx %.0lf deg.).\nWear a jacket.", temp);
	} else if(temp <=25){
		printf("It is currently comfy (approx %.0lf deg.).\nWear whatever and touch grass.", temp);
	} else if(temp <=35){
		printf("It is a lil hot outside (approx %.0lf deg.).\nWear deoderant please and stay hydrated.", temp);
	} else{
		printf("It is extremely hot outside (approx %.0lf deg.).\nYou will evaporate if you go outside. Don't go outside.", temp);
	}
}