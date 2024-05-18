#include <stdio.h>
#include <string.h>

// Main function to add a new entry to the phonebook
int main(int argc, char *argv[]) {
    // Check if the correct number of arguments is provided
    if (argc < 3) {
        // If not, print usage information and return an error code
        printf("Usage: %s <name> <phone_number>\n", argv[0]);
        return 1;
    }

    // Concatenate name parts into a single string
    char name[256] = ""; // Initialize an empty string to store the name
    for (int i = 1; i < argc - 1; i++) {
        strcat(name, argv[i]); // Append each part of the name to the string
        if (i < argc - 2) {
            strcat(name, " "); // Add a space between name parts
        }
    }

    // Validate the name
    for (int i = 0; name[i] != '\0'; i++) {
        // Check if each character in the name is a letter or a space
        if (!((name[i] >= 'a' && name[i] <= 'z') || (name[i] >= 'A' && name[i] <= 'Z') || name[i] == ' ')) {
            printf("Invalid input: Name contains invalid characters\n");
            return 1;
        }
    }

    // Validate the phone number
    char *phone_number = argv[argc - 1]; // The phone number is the last argument
    int hyphen_count = 0; // Counter for hyphens in the phone number
    for (int i = 0; phone_number[i] != '\0'; i++) {
        if (phone_number[i] == '-') {
            hyphen_count++; // Increment hyphen count
            // Check if there is more than one hyphen
            if (hyphen_count > 1) {
                printf("Invalid input: Phone number contains multiple hyphens\n");
                return 1;
            }
        } else if (phone_number[i] < '0' || phone_number[i] > '9') {
            // Check if each character in the phone number is a digit
            printf("Invalid input: Phone number contains non-numeric characters\n");
            return 1;
        }
    }

    // Write the new entry to the phonebook file
    FILE *f = fopen("phonebook.txt", "a"); // Open the phonebook file in append mode
    if (f == NULL) {
        // If the file cannot be opened, print an error message
        printf("Error opening file!\n");
        return 1;
    }
    // Write the name and phone number to the file
    fprintf(f, "%s,%s\n", name, phone_number);
    // Close the file
    fclose(f);

    return 0; // Return success
}
