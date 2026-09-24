// File: task2.c
// Author: Mikayla Pelletier
// Creation date: 9/23/2026
// Revision date: 9/24/2026
// Collaborators: None
// Other sources for the code: None
// Description: takes in a temp and scale can converts to different scale and prints a category for that temp
// Inputs: Number for temp (float and int both work). F,C,or K for original scale of temp and desired scale of temp
// Outputs: New temp in desired scale and temp categrory and weather advisory.
// Revisions: Added comments


//inputs not case sensitive


#include <stdio.h>

int main() {
    double temp, converted_temp, temp_in_celsius;
    char unit, want;

    // Get input values
    printf("Enter the temperature value: ");
    if (scanf("%lf", &temp) != 1) { // scanf will be 1(true) if it worked, so will be 0(false) with anything other than a float here
        printf("Invlaid temperature.\n");
        return 1; //ends program with 1 indicating an error happend 
    }

    printf("Enter the original scale (F, C, or K): ");
    scanf(" %c", &unit); //space before %C to get rid of any leading white space

    //Convert input temperature to Celsius
    if (unit == 'C' || unit == 'c') {
        temp_in_celsius = temp;
    } else if (unit == 'F' || unit == 'f') {
        temp_in_celsius = (temp - 32.0) * 5.0 / 9.0;
    } else if (unit == 'K' || unit == 'k') {
        temp_in_celsius = temp - 273.15;
    } else {
        printf("Invalid original scale entered.\n");
        return 1;
    }

    printf("Enter the scale to convert to (F, C, or K): ");
    scanf(" %c", &want);
   
    
    // Convert Celsius to the desired target scale
    if (want == 'C' || want == 'c') {
        converted_temp = temp_in_celsius;
    } else if (want == 'F' || want == 'f') {
        converted_temp = (temp_in_celsius * 9.0 / 5.0) + 32.0;
    } else if (want == 'K' || want == 'k') {
        converted_temp = temp_in_celsius + 273.15;
    } else {
        printf("Invalid target scale entered.\n");
        return 1;
    }

    // Display converted temperature
    printf("Converted temperature: %.2f %c\n", converted_temp, want);

    // Categorize and provide advisory based on Celsius value
    printf("Temperature category: ");
    if (temp_in_celsius < 0) {
        printf("Freezing\n");
        printf("Weather advisory: Bundle up and stay warm!\n");
    } else if (temp_in_celsius >= 0 && temp_in_celsius < 10) {
        printf("Cold\n");
        printf("Weather advisory: Make sure you bring a jacket!.\n");
    } else if (temp_in_celsius >= 10 && temp_in_celsius < 25) {
        printf("Comfortable\n");
        printf("Weather advisory: Enjoy the pleasant weather outside!\n");
    } else if (temp_in_celsius >= 25 && temp_in_celsius < 35) {
        printf("Hot\n");
        printf("Weather advisory: Drink lots of water!\n");
    } else {
        printf("Extreme Heat\n");
        printf("Weather advisory: Stay indoors and avoid direct sunlight!\n");
    }

    return 0;
}
