#ifndef PLAYERS_H
#define PLAYERS_H

#include <time.h>
#include "cards.h"
#include "decks.h"

#define MAX_COLLECTION (MAX_CARDS * BORDER_NB)
#define MAX_DECKS 5

typedef enum { 
    UPG_LUCK, 
    UPG_LOOT, 
    UPG_CARDS_PER_PACK,
    UPG_RECHARGE_SPEED, 
    UPG_BORDER_LUCK,
    UPG_NB
} UpgradeType;

typedef struct {
    char name[32];

    int level;
    int xp;
    int currency;

    OwnedCard collection[MAX_COLLECTION];
    int collection_count;

    Deck decks[MAX_DECKS];
    int deck_count;
    int active_deck;

    int upgrades[UPG_NB];

    int pack_reserved;
    time_t last_login;
} Player;

#endif