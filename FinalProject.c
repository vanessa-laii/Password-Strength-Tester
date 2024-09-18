#include <stdio.h>
#include <string.h>
#include <ctype.h>

int hasLowercase(char x[]){
    int i;
    for (i=0; x[i]!='\0'; i++){
        if (x[i]>= 'a' && x[i]<= 'z'){
            return 1;
        }
    }
    return 0;
}

int hasUppercase(char x[]){
    int i;
    for (i=0; x[i]!='\0'; i++){
        if (x[i]>= 'A' && x[i]<= 'Z'){
            return 1;
        }
    }
    return 0;
}

int hasDigit(char x[]){
    int i;
    for (i=0; x[i]!='\0'; i++){
        if (x[i]>= '0' && x[i]<= '9'){
            return 1;
        }
    } 
    return 0;
}

int hasSpecialChar(char x[]){
    int i;
    for (i=0; x[i]!='\0'; i++){    
        if (!isdigit(x[i]) && !isalpha(x[i])){
            return 1;
        }
    }
    return 0;
}

int evaluateStrength(char x[]){
    int count;
    int length;
    length = strlen(x);
    count = hasLowercase(x) + hasUppercase(x)+ hasDigit(x) + hasSpecialChar(x);
    if (length > 12){
	count++;
    }  
    return count;
}

int main(){
    int exit;
    exit = 0;
    int lastStrength;
    lastStrength = 10;
    while (exit == 0){
        printf("Password Resilience Analyzer\n");
        printf("1. Test a new password\n");
        printf("2. view strength of the last tested password\n");
        printf("3. Exit\n");
        printf("Enter you choice: ");
        int choice;
        scanf("%d", &choice);
        char password[100];
        int strength;
        if (choice == 1){
            printf("Enter the password: ");
            scanf("%s", password);
            int len;
            len = strlen(password);
            if (len<8){
                printf("Error: Password should be at least 8 characters long.\n");
        
	    }
            else{
                strength = evaluateStrength(password);
		printf("Password Strength: ");

    		if (strength>=0 && strength <=2){
       		    printf("Weak\n");
    		}
    		else if (strength>= 3 && strength <= 4){
        	    printf("Moderate\n");
    		}
    		else if (strength == 5){
                    printf("Strong\n");
    		}

                lastStrength = strength;
		
            }
        }
        else if (choice == 2){
            printf("Last tested password strength: ");

            if (lastStrength>=0 && lastStrength <=2){
                printf("Weak\n");
                }
                else if (lastStrength>= 3 && lastStrength <= 4){
                    printf("Moderate\n");
                }
                else if (lastStrength == 5){
                printf("Strong\n");
                }
                else if (lastStrength ==10){
                printf("No Previous Password\n");
                }
            }
        else if (choice == 3){
            printf("Exiting...\n");
            exit=1;
        }
	printf("\n");
    }
    return 0;
}






