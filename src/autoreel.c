#include "modding.h"
#include "recomputils.h"
#include "recompconfig.h"

#include "game/player.h"


RECOMP_HOOK_RETURN("handleFishingAction") void auto_reel_fish(void) {
    if (gPlayer.actionHandler == FISHING &&
        gPlayer.actionPhase >= 3 &&
        gPlayer.actionPhase <= 5) {
        gPlayer.actionPhase = 6;
    }
}