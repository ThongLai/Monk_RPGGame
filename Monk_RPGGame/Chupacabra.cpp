#include "Chupacabra.h"

Chupacabra::Chupacabra() : Monster()
{
    setName("Chupacabra");
    setDescription("Roarrrrrr!!");
    setColor(CHUPACABRA_COLOR);

    setBaseHealth(CHUPACABRA_BASE_HEALTH);
    setHealth(CHUPACABRA_BASE_HEALTH);
    setDamage(CHUPACABRA_BASE_DAMAGE);

    setCancelChance(CHUPACABRA_CANCEL_ACTION_CHANCE);
    setAttackChance(CHUPACABRA_ATK_DEF_CHANCE);

    setArtModel(CHUPACABRA_ART);
    setArtHeight(CHUPACABRA_HEIGHT);
    setArtWidth(CHUPACABRA_WIDTH);
}