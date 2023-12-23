// auction.h
#ifndef AUCTION_H
#define AUCTION_H

typedef struct {
    char item_name[256];  // Adjust the size as needed
    double starting_price;
    double current_highest_bid;
    // Add other parameters as needed
} Auction;

void initialize_auction(Auction* auction);
void create_auction(Auction* auction, const char* item_name, double starting_price);
void update_auction_status(Auction* auction);
void manage_bidding_process(Auction* auction);
void close_auction(Auction* auction);
void bid_history(Auction* auction);

#endif /* AUCTION_H */
