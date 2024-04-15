#include "Goblin.h"

Goblin::Goblin() : Monster()
{
    setName("Goblin");
    setDescription("Groan!");
    setMonsterColor(GOBLIN_COLOR);

    setBaseHealth(GOBLIN_BASE_HEALTH);
    setHealth(GOBLIN_BASE_HEALTH);
    setDamage(GOBLIN_BASE_DAMAGE);

    cancel_chance = GOBLIN_CANCEL_ACTION_CHANCE;
    attack_chance = GOBLIN_ATK_DEF_CHANCE;

    setArtModel(GOBLIN_ART);
    setArtHeight(GOBLIN_HEIGHT);
    setArtWidth(GOBLIN_WIDTH);
}