#include "Workshop3.h"

int main() {
    struct Customer customer = inputCustomerInfo();

    printf("\n");
    printf("You entered:\n");
    printf("%s %s\n", customer.firstName, customer.lastName);
    printf("%s,\n", customer.address);
    printf("%s, ", customer.city);
    printf("%s,\n", customer.province);
    printf("%s\n", customer.postalCode);
    printf("\n");

    return 0;
}

//Function to check if the input is valid
void checkInput(char* prompt, char* input, size_t length) {
    int validInput = 0;

    while (!validInput) {
        printf("%s", prompt);

        if (fgets(input, length, stdin)) {
            // Remove the newline character if present
            size_t strLength = strlen(input);
            if (strLength > 0 && input[strLength - 1] == '\n') {
                input[strLength - 1] = '\0';
            }

            // Check if the input is not empty
            if (strlen(input) > 0) {
                validInput = 1;
            }
            else {
                printf("Input cannot be empty. Please enter a valid input.\n");
            }
            for (int i = 0; i < strLength-1; i++)
            {
                if (!isalpha(input[i]))
                {
                    printf("Your input should only have letters\n");
                    validInput = 0;
                    break;
                }
            }
            
        }
        else {
            printf("Error reading input. Please try again.\n");
        }
    }
}

//function to check the address
int checkAddress(char* input) 
{
    int validInput = 0;

    while (!validInput) {

        if (fgets(input, MAX_STRING_LEN, stdin)) {
            // Remove the newline character if present
            size_t strLength = strlen(input);
            if (strLength > 0 && input[strLength - 1] == '\n') {
                input[strLength - 1] = '\0';
            }

            // Check if the input is not empty
            if (strlen(input) > 0) {
                validInput = 1;
            }
            else {
                printf("Input cannot be empty. Please enter a valid input.\n");
            }

        }
        else {
            printf("Error reading input. Please try again.\n");
        }
    }

    return validInput;
}

//function to check if postal code is valid
int checkPostalCode (char* input)
{
    int validInput = 0;

    while (!validInput) {

        if (fgets(input, MAX_STRING_LEN, stdin)) {
            // Remove the newline character if present
            size_t strLength = strlen(input);
            if (strLength > 0 && input[strLength - 1] == '\n') {
                input[strLength - 1] = '\0';
            }

            // Check if the input is not empty
            if (strlen(input) > 0) {
                validInput = 1;
            }
            else {
                printf("Input cannot be empty. Please enter a valid input.\n");
                validInput = 0;
            }
            
            //check if the postal code is formatted
            if (isalpha(input[0]) && isalpha(input[2]) && isalpha(input[5]) && isdigit(input[1]) && isdigit(input[4]) && isdigit(input[6]))
            {
                validInput = 1;
            }
            else
            {
                printf("Your postal code should be: A0A 0A0\n");
                printf("Enter your Postal Code: ");
                validInput = 0;
            }
        }
        else 
        {
            printf("Error reading input. Please try again.\n");
            printf("Enter your Postal Code: ");
            validInput = 0;
        }
    }
    return validInput;

}

//Function to get the customer informations
struct Customer inputCustomerInfo() {
    struct Customer customer;
    int ok1 = 0, ok2 = 0;
    
    checkInput("Enter your first name: ", customer.firstName, MAX_STRING_LEN);
    checkInput("Enter your last name: ", customer.lastName, MAX_STRING_LEN);

    while (!ok1)
    {
        ok1 = 0;
        printf("Enter your address: ");
        ok1 = checkAddress(customer.address);
    }

    checkInput("Enter your city: ", customer.city, MAX_STRING_LEN);
    checkInput("Enter your province: ", customer.province, MAX_PROV_LEN);
    
    while(!ok2)
    {   
        ok2 = 0;
        printf("Enter your Postal Code: ");
        ok2 = checkPostalCode(customer.postalCode);
    }
    

    return customer;
}
