#include "Foot.h"

Foot::Foot() : Monster()
{
    setName("Foot");
    setDescription("Stomp, stomp, stomp!!");
    setColor(FOOT_COLOR);

    setBaseHealth(FOOT_BASE_HEALTH);
    setHealth(FOOT_BASE_HEALTH);
    setDamage(FOOT_BASE_DAMAGE);

    setCancelChance(FOOT_CANCEL_ACTION_CHANCE);
    setAttackChance(FOOT_ATK_DEF_CHANCE);

    setArtModel(FOOT_ART);
    setArtHeight(FOOT_HEIGHT);
    setArtWidth(FOOT_WIDTH);
}