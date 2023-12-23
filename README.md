# Auction System

This is a simple command-line auction system implemented in C. The program allows users to register, authenticate, browse auctions, place bids, initiate new auctions, monitor bidding history, view won items, and exit the auction system.

## Features

- **User Registration:** Users can register by providing a username and password. The registration data is stored in the `database.txt` file.

- **User Authentication:** Users need to log in with their registered credentials to access the auction system.

- **Auction Operations:**
  - **Browse Auctions:** View a list of available auctions.
  - **Place Bid:** Bid on an auction.
  - **Initiate Auction:** Start a new auction by providing details such as item name, starting price, bid deadline, etc.
  - **Monitor Bidding History:** View bidding history for auctions the user has participated in.
  - **View Won Items:** Display a list of items the user has won.
  - **Exit Auction System:** Terminate the program.

- **Networking and Real-time Features:** The program includes placeholder functions for networking and real-time updates, allowing for future enhancements.

## How to Compile and Run

To compile the program, use the following command:

```bash
gcc -Wall -Werror -pthread -Iinclude src/main.c src/auction.c src/auth.c src/ui.c src/network.c src/realtime.c -o auction_system
./auction_system
