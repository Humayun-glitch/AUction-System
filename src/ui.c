// ui.c
#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "auction.h"

extern Auction auctions[2];  // Assuming auctions is a global array in auction.c

void display_main_menu(void) {
    printf("\n=== AUCTION SYSTEM ===\n");
    printf("1. Browse Auctions\n");
    printf("2. Place Bid\n");
    printf("3. Initiate Auction\n");
    printf("4. Monitor Bidding History\n");
    printf("5. View Won Items\n");
    printf("6. Exit\n");
    printf("7. Creation Options\n");
    printf("Choose an option (1-7): ");
}

void browse_auctions(Auction *auctions) {
    printf("Browsing available auctions...\n");

    // TODO: Retrieve and display a list of available auctions
    // Example: Print auction details such as item name, starting price, and status
    // For demonstration purposes, let's assume there are two auctions.

    for (int i = 0; i < MAX_AUCTIONS; ++i) {
        if (auctions[i].is_open) {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Open\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        } else {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Closed\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        }
    }
}

void place_bid(void) {
    printf("Placing a bid...\n");

    // Display available auctions
    printf("Available Auctions:\n");
    for (int i = 0; i < 2; ++i) {
        if (auctions[i].is_open) {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Open\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        } else {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Closed\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        }
    }

    // Prompt user for the name of the item
    char item_name[50];
    printf("Enter the name of the item you want to bid on: ");
    scanf("%s", item_name);

    // Find the auction with the given item name
    int auction_id = -1;
    for (int i = 0; i < 2; ++i) {
        if (strcmp(auctions[i].item_name, item_name) == 0 && auctions[i].is_open) {
            auction_id = auctions[i].id;
            break;
        }
    }

    // Validate auction ID
    if (auction_id == -1) {
        printf("Invalid item name or the auction is closed. Please try again.\n");
        return;
    }

    // Prompt user for bid amount
    double bid_amount;
    printf("Enter your bid amount: $");
    scanf("%lf", &bid_amount);

    // Validate bid amount
    if (bid_amount <= auctions[auction_id - 1].current_highest_bid) {
        printf("Your bid amount must be higher than the current highest bid.\n");
        return;
    }

    // TODO: Update bid history and auction status
    // Example: Update bid history for the user and update the auction's current highest bid

    printf("Bid placed successfully!\n");
}

void initiate_auction(void) {
    // TODO: Implement the logic to initiate a new auction
    // For demonstration purposes, let's assume the user wants to initiate a new auction.

    char item_name[50];
    double starting_price;

    printf("Enter the name of the item: ");
    scanf("%s", item_name);

    printf("Enter the starting price: ");
    scanf("%lf", &starting_price);

    // TODO: Create a new auction and add it to the list of available auctions
    printf("Auction for %s initiated with a starting price of %.2f\n", item_name, starting_price);
}

void monitor_bidding_history(void) {
    // TODO: Implement the logic to display bidding history
    // For demonstration purposes, let's assume there is a bid history for the user.

    // Assume the user has bid on auction ID 1.
    printf("Bidding history for user:\n");
    printf("Auction ID: 1, Bid Amount: $150.00\n");
}

void view_won_items(void) {
    // TODO: Implement the logic to display won items
    // For demonstration purposes, let's assume the user has won an item in auction ID 2.

    printf("Viewing won items...\n");

    // Assume the user won an item in auction ID 2.
    printf("You won an item in auction ID 2!\n");
}

void exit_auction_system(void) {
    // TODO: Implement any necessary cleanup or finalization
    // Example: Save user data, close connections, etc.

    printf("Exiting the auction system...\n");
}
// ui.c
#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "auction.h"

extern Auction auctions[2];  // Assuming auctions is a global array in auction.c

void display_main_menu(void) {
    printf("\n=== AUCTION SYSTEM ===\n");
    printf("1. Browse Auctions\n");
    printf("2. Place Bid\n");
    printf("3. Initiate Auction\n");
    printf("4. Monitor Bidding History\n");
    printf("5. View Won Items\n");
    printf("6. Exit\n");
    printf("7. Creation Options\n");
    printf("Choose an option (1-7): ");
}

void browse_auctions(Auction *auctions) {
    printf("Browsing available auctions...\n");

    // TODO: Retrieve and display a list of available auctions
    // Example: Print auction details such as item name, starting price, and status
    // For demonstration purposes, let's assume there are two auctions.

    for (int i = 0; i < MAX_AUCTIONS; ++i) {
        if (auctions[i].is_open) {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Open\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        } else {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Closed\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        }
    }
}

void place_bid(void) {
    printf("Placing a bid...\n");

    // Display available auctions
    printf("Available Auctions:\n");
    for (int i = 0; i < 2; ++i) {
        if (auctions[i].is_open) {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Open\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        } else {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Closed\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        }
    }

    // Prompt user for the name of the item
    char item_name[50];
    printf("Enter the name of the item you want to bid on: ");
    scanf("%s", item_name);

    // Find the auction with the given item name
    int auction_id = -1;
    for (int i = 0; i < 2; ++i) {
        if (strcmp(auctions[i].item_name, item_name) == 0 && auctions[i].is_open) {
            auction_id = auctions[i].id;
            break;
        }
    }

    // Validate auction ID
    if (auction_id == -1) {
        printf("Invalid item name or the auction is closed. Please try again.\n");
        return;
    }

    // Prompt user for bid amount
    double bid_amount;
    printf("Enter your bid amount: $");
    scanf("%lf", &bid_amount);

    // Validate bid amount
    if (bid_amount <= auctions[auction_id - 1].current_highest_bid) {
        printf("Your bid amount must be higher than the current highest bid.\n");
        return;
    }

    // TODO: Update bid history and auction status
    // Example: Update bid history for the user and update the auction's current highest bid

    printf("Bid placed successfully!\n");
}

void initiate_auction(void) {
    // TODO: Implement the logic to initiate a new auction
    // For demonstration purposes, let's assume the user wants to initiate a new auction.

    char item_name[50];
    double starting_price;

    printf("Enter the name of the item: ");
    scanf("%s", item_name);

    printf("Enter the starting price: ");
    scanf("%lf", &starting_price);

    // TODO: Create a new auction and add it to the list of available auctions
    printf("Auction for %s initiated with a starting price of %.2f\n", item_name, starting_price);
}

void monitor_bidding_history(void) {
    // TODO: Implement the logic to display bidding history
    // For demonstration purposes, let's assume there is a bid history for the user.

    // Assume the user has bid on auction ID 1.
    printf("Bidding history for user:\n");
    printf("Auction ID: 1, Bid Amount: $150.00\n");
}

void view_won_items(void) {
    // TODO: Implement the logic to display won items
    // For demonstration purposes, let's assume the user has won an item in auction ID 2.

    printf("Viewing won items...\n");

    // Assume the user won an item in auction ID 2.
    printf("You won an item in auction ID 2!\n");
}

void exit_auction_system(void) {
    // TODO: Implement any necessary cleanup or finalization
    // Example: Save user data, close connections, etc.

    printf("Exiting the auction system...\n");
}
// ui.c
#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "auction.h"

extern Auction auctions[2];  // Assuming auctions is a global array in auction.c

void display_main_menu(void) {
    printf("\n=== AUCTION SYSTEM ===\n");
    printf("1. Browse Auctions\n");
    printf("2. Place Bid\n");
    printf("3. Initiate Auction\n");
    printf("4. Monitor Bidding History\n");
    printf("5. View Won Items\n");
    printf("6. Exit\n");
    printf("7. Creation Options\n");
    printf("Choose an option (1-7): ");
}

void browse_auctions(Auction *auctions) {
    printf("Browsing available auctions...\n");

    // TODO: Retrieve and display a list of available auctions
    // Example: Print auction details such as item name, starting price, and status
    // For demonstration purposes, let's assume there are two auctions.

    for (int i = 0; i < MAX_AUCTIONS; ++i) {
        if (auctions[i].is_open) {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Open\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        } else {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Closed\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        }
    }
}

void place_bid(void) {
    printf("Placing a bid...\n");

    // Display available auctions
    printf("Available Auctions:\n");
    for (int i = 0; i < 2; ++i) {
        if (auctions[i].is_open) {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Open\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        } else {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Closed\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        }
    }

    // Prompt user for the name of the item
    char item_name[50];
    printf("Enter the name of the item you want to bid on: ");
    scanf("%s", item_name);

    // Find the auction with the given item name
    int auction_id = -1;
    for (int i = 0; i < 2; ++i) {
        if (strcmp(auctions[i].item_name, item_name) == 0 && auctions[i].is_open) {
            auction_id = auctions[i].id;
            break;
        }
    }

    // Validate auction ID
    if (auction_id == -1) {
        printf("Invalid item name or the auction is closed. Please try again.\n");
        return;
    }

    // Prompt user for bid amount
    double bid_amount;
    printf("Enter your bid amount: $");
    scanf("%lf", &bid_amount);

    // Validate bid amount
    if (bid_amount <= auctions[auction_id - 1].current_highest_bid) {
        printf("Your bid amount must be higher than the current highest bid.\n");
        return;
    }

    // TODO: Update bid history and auction status
    // Example: Update bid history for the user and update the auction's current highest bid

    printf("Bid placed successfully!\n");
}

void initiate_auction(void) {
    // TODO: Implement the logic to initiate a new auction
    // For demonstration purposes, let's assume the user wants to initiate a new auction.

    char item_name[50];
    double starting_price;

    printf("Enter the name of the item: ");
    scanf("%s", item_name);

    printf("Enter the starting price: ");
    scanf("%lf", &starting_price);

    // TODO: Create a new auction and add it to the list of available auctions
    printf("Auction for %s initiated with a starting price of %.2f\n", item_name, starting_price);
}

void monitor_bidding_history(void) {
    // TODO: Implement the logic to display bidding history
    // For demonstration purposes, let's assume there is a bid history for the user.

    // Assume the user has bid on auction ID 1.
    printf("Bidding history for user:\n");
    printf("Auction ID: 1, Bid Amount: $150.00\n");
}

void view_won_items(void) {
    // TODO: Implement the logic to display won items
    // For demonstration purposes, let's assume the user has won an item in auction ID 2.

    printf("Viewing won items...\n");

    // Assume the user won an item in auction ID 2.
    printf("You won an item in auction ID 2!\n");
}

void exit_auction_system(void) {
    // TODO: Implement any necessary cleanup or finalization
    // Example: Save user data, close connections, etc.

    printf("Exiting the auction system...\n");
}
// ui.c
#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "auction.h"

extern Auction auctions[2];  // Assuming auctions is a global array in auction.c

void display_main_menu(void) {
    printf("\n=== AUCTION SYSTEM ===\n");
    printf("1. Browse Auctions\n");
    printf("2. Place Bid\n");
    printf("3. Initiate Auction\n");
    printf("4. Monitor Bidding History\n");
    printf("5. View Won Items\n");
    printf("6. Exit\n");
    printf("7. Creation Options\n");
    printf("Choose an option (1-7): ");
}

void browse_auctions(Auction *auctions) {
    printf("Browsing available auctions...\n");

    // TODO: Retrieve and display a list of available auctions
    // Example: Print auction details such as item name, starting price, and status
    // For demonstration purposes, let's assume there are two auctions.

    for (int i = 0; i < MAX_AUCTIONS; ++i) {
        if (auctions[i].is_open) {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Open\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        } else {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Closed\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        }
    }
}

void place_bid(void) {
    printf("Placing a bid...\n");

    // Display available auctions
    printf("Available Auctions:\n");
    for (int i = 0; i < 2; ++i) {
        if (auctions[i].is_open) {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Open\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        } else {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Closed\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        }
    }

    // Prompt user for the name of the item
    char item_name[50];
    printf("Enter the name of the item you want to bid on: ");
    scanf("%s", item_name);

    // Find the auction with the given item name
    int auction_id = -1;
    for (int i = 0; i < 2; ++i) {
        if (strcmp(auctions[i].item_name, item_name) == 0 && auctions[i].is_open) {
            auction_id = auctions[i].id;
            break;
        }
    }

    // Validate auction ID
    if (auction_id == -1) {
        printf("Invalid item name or the auction is closed. Please try again.\n");
        return;
    }

    // Prompt user for bid amount
    double bid_amount;
    printf("Enter your bid amount: $");
    scanf("%lf", &bid_amount);

    // Validate bid amount
    if (bid_amount <= auctions[auction_id - 1].current_highest_bid) {
        printf("Your bid amount must be higher than the current highest bid.\n");
        return;
    }

    // TODO: Update bid history and auction status
    // Example: Update bid history for the user and update the auction's current highest bid

    printf("Bid placed successfully!\n");
}

void initiate_auction(void) {
    // TODO: Implement the logic to initiate a new auction
    // For demonstration purposes, let's assume the user wants to initiate a new auction.

    char item_name[50];
    double starting_price;

    printf("Enter the name of the item: ");
    scanf("%s", item_name);

    printf("Enter the starting price: ");
    scanf("%lf", &starting_price);

    // TODO: Create a new auction and add it to the list of available auctions
    printf("Auction for %s initiated with a starting price of %.2f\n", item_name, starting_price);
}

void monitor_bidding_history(void) {
    // TODO: Implement the logic to display bidding history
    // For demonstration purposes, let's assume there is a bid history for the user.

    // Assume the user has bid on auction ID 1.
    printf("Bidding history for user:\n");
    printf("Auction ID: 1, Bid Amount: $150.00\n");
}

void view_won_items(void) {
    // TODO: Implement the logic to display won items
    // For demonstration purposes, let's assume the user has won an item in auction ID 2.

    printf("Viewing won items...\n");

    // Assume the user won an item in auction ID 2.
    printf("You won an item in auction ID 2!\n");
}

void exit_auction_system(void) {
    // TODO: Implement any necessary cleanup or finalization
    // Example: Save user data, close connections, etc.

    printf("Exiting the auction system...\n");
}
// ui.c
#include <stdio.h>
#include <string.h>
#include "ui.h"
#include "auction.h"

extern Auction auctions[2];  // Assuming auctions is a global array in auction.c

void display_main_menu(void) {
    printf("\n=== AUCTION SYSTEM ===\n");
    printf("1. Browse Auctions\n");
    printf("2. Place Bid\n");
    printf("3. Initiate Auction\n");
    printf("4. Monitor Bidding History\n");
    printf("5. View Won Items\n");
    printf("6. Exit\n");
    printf("7. Creation Options\n");
    printf("Choose an option (1-7): ");
}

void browse_auctions(Auction *auctions) {
    printf("Browsing available auctions...\n");

    // TODO: Retrieve and display a list of available auctions
    // Example: Print auction details such as item name, starting price, and status
    // For demonstration purposes, let's assume there are two auctions.

    for (int i = 0; i < MAX_AUCTIONS; ++i) {
        if (auctions[i].is_open) {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Open\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        } else {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Closed\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        }
    }
}

void place_bid(void) {
    printf("Placing a bid...\n");

    // Display available auctions
    printf("Available Auctions:\n");
    for (int i = 0; i < 2; ++i) {
        if (auctions[i].is_open) {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Open\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        } else {
            printf("ID: %d, Item: %s, Starting Price: %.2f, Status: Closed\n",
                   auctions[i].id, auctions[i].item_name, auctions[i].starting_price);
        }
    }

    // Prompt user for the name of the item
    char item_name[50];
    printf("Enter the name of the item you want to bid on: ");
    scanf("%s", item_name);

    // Find the auction with the given item name
    int auction_id = -1;
    for (int i = 0; i < 2; ++i) {
        if (strcmp(auctions[i].item_name, item_name) == 0 && auctions[i].is_open) {
            auction_id = auctions[i].id;
            break;
        }
    }

    // Validate auction ID
    if (auction_id == -1) {
        printf("Invalid item name or the auction is closed. Please try again.\n");
        return;
    }

    // Prompt user for bid amount
    double bid_amount;
    printf("Enter your bid amount: $");
    scanf("%lf", &bid_amount);

    // Validate bid amount
    if (bid_amount <= auctions[auction_id - 1].current_highest_bid) {
        printf("Your bid amount must be higher than the current highest bid.\n");
        return;
    }

    // TODO: Update bid history and auction status
    // Example: Update bid history for the user and update the auction's current highest bid

    printf("Bid placed successfully!\n");
}

void initiate_auction(void) {
    // TODO: Implement the logic to initiate a new auction
    // For demonstration purposes, let's assume the user wants to initiate a new auction.

    char item_name[50];
    double starting_price;

    printf("Enter the name of the item: ");
    scanf("%s", item_name);

    printf("Enter the starting price: ");
    scanf("%lf", &starting_price);

    // TODO: Create a new auction and add it to the list of available auctions
    printf("Auction for %s initiated with a starting price of %.2f\n", item_name, starting_price);
}

void monitor_bidding_history(void) {
    // TODO: Implement the logic to display bidding history
    // For demonstration purposes, let's assume there is a bid history for the user.

    // Assume the user has bid on auction ID 1.
    printf("Bidding history for user:\n");
    printf("Auction ID: 1, Bid Amount: $150.00\n");
}

void view_won_items(void) {
    // TODO: Implement the logic to display won items
    // For demonstration purposes, let's assume the user has won an item in auction ID 2.

    printf("Viewing won items...\n");

    // Assume the user won an item in auction ID 2.
    printf("You won an item in auction ID 2!\n");
}

void exit_auction_system(void) {
    // TODO: Implement any necessary cleanup or finalization
    // Example: Save user data, close connections, etc.

    printf("Exiting the auction system...\n");
}
