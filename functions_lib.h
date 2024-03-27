//
// Created by dougl on 3/27/2024.
//
#include "classes/Scarfy.h"
#include "classes/Nebula.h"

#ifndef DAPPER_DASHER_FUNCTIONS_H

#define DAPPER_DASHER_FUNCTIONS_H

void update_animation_scarfy(Scarfy& scarfy, const float dT) {
    scarfy.increment_run_time(dT);
    if (scarfy.get_run_time() >= animate_update_time && !scarfy.get_is_in_air()) {
        scarfy.set_run_time(0.0);

        scarfy.set_scarfy_rec_x((float) scarfy.get_frame() * scarfy.get_scarfy_rec_width());
        scarfy.increment_frame();
        if (scarfy.get_frame() > 5)
            scarfy.reset_frame();
    }
}

void update_animation_nebulae(std::vector<Nebula>& neb_vec, const float dT) {
    for (Nebula& neb: neb_vec) {
        neb.increment_run_time(dT);
        if (neb.get_neb_run_time() >= animate_update_time) {
            neb.set_neb_run_time(0.0);

            neb.set_neb_rec_x((float) neb.get_frame() * neb.get_neb_rec_width());
            neb.increase_frame();
            if (neb.get_frame() > 7)
                neb.reset_frame();
        }
    }
}

#endif //DAPPER_DASHER_FUNCTIONS_H
