#include <stdio.h>
#include <string.h>

#define max_spots 10
#define max_plate_len 16

char spots[max_spots][max_plate_len];
int occupied[max_spots];

void init (int n){
    if (n>max_spots){
        n=max_spots;
    }
    for(int i=0; i<n; i++){
        spots[i][0]= '\0';
        occupied [i]= 0;
    }
printf("Initialized spots %d\n", n);
}

void showMenu() {
    int num_option;
    printf("\n--- Parking System ---\n");
    printf("1. Park vehicle\n");
    printf("2. Remove vehicle\n");
    printf("3. List spots\n");
    printf("4. Exit\n");
    printf("Enter choice: ");
    //scanf("%d", &num_option );

   //return num_option;
}

 // check if already parked
void parkVehicle (int n) {
    char plate[max_plate_len];
    printf("Enter vehicle plate number:");
    scanf("%15s", plate);
    printf("\nYour plate number: %s", plate);

    //for parked vehicle
    for (int i = 0; i < n; i++) {
        if (occupied[i] && strcmp(spots[i], plate) == 0) { // strcmp returns 0 if 2 strings are equal
            printf("\nVehicle %s is already parked at spot %d.\n", plate, i+1);
            return;
        }
    }
    // find free spot
    for (int i = 0; i < n; i++) {
        if (!occupied[i]) {
            occupied[i] = 1;
            strncpy(spots[i], plate, max_plate_len-1);
            spots[i][max_plate_len-1] = '\0';
            printf("\nVehicle %s parked at spot %d.\n", plate, i+1);
            return;
        }
    }
    //when two loops are not working
    printf(" Sorry, no free parking spots available.\n");
}

void removeVehicle(int n) {
    char plate[max_plate_len];
    printf("Enter vehicle plate number to remove: ");
    scanf("%15s", plate);

    for (int i = 0; i < n; i++) {
        if (occupied[i] && strcmp(spots[i], plate) == 0) {
            occupied[i] = 0;
            spots[i][0] = '\0';
            printf("Vehicle %s removed from spot %d.\n", plate, i+1);
            return;
        }
    }
     printf("Vehicle %s not found.\n", plate);
}

void listSpots(int n) {
    printf("\nSpot  Status     Plate\n");
    printf("--------------------------\n");
    for (int i = 0; i < n; i++) {
        printf("%4d   %-9s   %s\n",
               i+1,
               (occupied[i] ? "Occupied" : "Free"),
               (occupied[i] ? spots[i] : "-"));
    }
}
/*
int main(){
    int recieved_n, option_n, decision;
    printf("Do you want to initialize? (1. Yes 2. No):");
    scanf("%d", & decision);
    if(decision==1){
        printf("Enter number of spots in the parking system:");
        scanf("%d", & recieved_n);
        init(recieved_n);
    }
    option_n = showMenu();
    //printf("your option is: %d", option_n);

    parkVehicle(max_spots);
    removeVehicle(max_spots);
    listSpots(max_spots);

    return 0;

}*/

int main() {
    int numSpots = 10;  // you can change this to up to MAX_SPOTS
    init(numSpots);

    while (1) {
        showMenu();
        int choice;
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input, try again.\n");
            while (getchar() != '\n'); // flush
            continue;
        }
        switch (choice) {
            case 1:
                parkVehicle(numSpots);
                break;
            case 2:
                removeVehicle(numSpots);
                break;
            case 3:
                listSpots(numSpots);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice, try again.\n");
        }
    }
    return 0;
}
