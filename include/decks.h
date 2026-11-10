#ifndef DECKS_H
#define DECKS_H

#define DECK_SIZE 4

typedef struct {
    char name[32];
    int terrain[DECK_SIZE];
    int support[DECK_SIZE];
} Deck;

#endif