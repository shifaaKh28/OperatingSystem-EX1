#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Validate the input format
    if (argc != 2 || argv[1][0] == ',' || argv[1][0] == '\0') {
        printf("Usage: %s \"<name>,<phone_number>\"\n", argv[0]);
        return 1;
    }
    
    // Validate name and phone number
    int i = 0;
    int hyphen_count = 0;
    int name_valid = 0;
    int phone_valid = 0;
    
    // Loop through the input string
    while (argv[1][i] != '\0') {
        // Check for name validity
        if ((argv[1][i] >= 'a' && argv[1][i] <= 'z') || (argv[1][i] >= 'A' && argv[1][i] <= 'Z') || argv[1][i] == ' ') {
            name_valid = 1;
        } else if (argv[1][i] == ',') {
            // Check if the comma is followed by a valid phone number
            if (argv[1][i + 1] != '\0' && argv[1][i + 1] >= '0' && argv[1][i + 1] <= '9') {
                phone_valid = 1;
            }
        } else if (argv[1][i] == '-') {
            // Count hyphens to validate phone number format
            hyphen_count++;
            if (hyphen_count > 1) {
                phone_valid = 0;
            }
        } else if (argv[1][i] < '0' || argv[1][i] > '9') {
            phone_valid = 0;
        }
        i++;
    }
    
    // Check overall validity
    if (!name_valid || !phone_valid) {
        printf("Invalid input\n");
        return 1;
    }
    
    // Open the file
    FILE *f = fopen("phonebook.txt", "a");
    if (f == NULL) {
        printf("Error opening file!\n");
        return 1;
    }
    
    // Write to file: name,phone_number
    fprintf(f, "%s\n", argv[1]);
    fclose(f);
    
    return 0;
}
