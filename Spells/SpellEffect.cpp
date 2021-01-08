#include "SpellEffect.h"

bool SpellEffect::isActive() const {
    return active;
}

void SpellEffect::activate(int duration) {
    active = true;
    durationRounds = duration;
}

void SpellEffect::disable() {
    active = false;
    durationRounds = 0;
}

void SpellEffect::reduceRound() {
    durationRounds--;
}

bool SpellEffect::mustDisable() const {
    return (active && durationRounds == 0);
}