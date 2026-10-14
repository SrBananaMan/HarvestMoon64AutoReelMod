#include "modding.h"
#include "recomputils.h"
#include "recompconfig.h"

#include "game/player.h"


static u8 phaseBefore;

RECOMP_HOOK("handleFishingAction") void auto_reel_before(void) {
    phaseBefore = gPlayer.actionPhase;
}

RECOMP_HOOK_RETURN("handleFishingAction") void auto_reel_after(void) {
    // During bite phases
    if (gPlayer.actionPhase >= 3 && gPlayer.actionPhase <= 5) {
        gPlayer.actionPhase = 6;
    }
    // After the bite, releasing B must NOT cancel the catch
    if (gPlayer.actionPhase == 8 && phaseBefore >= 6 && phaseBefore != 8) {
        gPlayer.actionPhase = phaseBefore;
    }
}
