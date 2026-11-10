#ifndef CARDS_H
#define CARDS_H 

typedef enum {
    RARITY_COMMON, 
    RARITY_RARE, 
    RARITY_EPIC,
    RARITY_LEGENDARY, 
    RARITY_MYTHIC, 
    RARITY_HEAVEN,
    RARITY_NB
} Rarity;

typedef enum {
    BORDER_NONE, 
    BORDER_SILVER, 
    BORDER_GOLD,
    BORDER_DIAMOND, 
    BORDER_RAINBOW, 
    BORDER_DARKNESS,
    BORDER_NB
} Border;

typedef enum {
    TRIGGER_NONE, 
    TRIGGER_BATTLE_START, 
    TRIGGER_ON_ATTACK,
    TRIGGER_ON_HIT, 
    TRIGGER_ON_DEATH,
    TRIGGER_ON_ROUND_START,
    TRIGGER_ON_ROUND_END
} Trigger;

typedef enum {
    EFFECT_NONE,
    EFFECT_DAMAGE_BOOST,
    EFFECT_HEAL,
    EFFECT_SHIELD,
    EFFECT_FREEZE,
    EFFECT_STUN
} Effect;

typedef struct {
    Trigger trigger;
    Effect effect;

    int value;
} Ability;

typedef struct {
    int id;
    char name[64];
    char anime[64];
    int atk;
    int hp;
    Rarity rarity;
    Ability ability;
    char image_path[128];
} Card;

#endif