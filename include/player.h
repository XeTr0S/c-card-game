#ifndef PLAYER_H
#define PLAYER_H 

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

    float luck;

    int upgrades[UPG_NB];
    int pack_reserved;
} Player;

#endif