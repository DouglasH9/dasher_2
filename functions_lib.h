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

void draw_background(float bg_x, Texture bg_text) {
    Vector2 bg1_pos{bg_x, 0.0};
    DrawTextureEx(bg_text, bg1_pos, 0.0, 4.7, WHITE);
    Vector2 bg2_pos{bg_x + ((float)bg_text.width * 2.0), 0.0};
    DrawTextureEx(bg_text, bg2_pos, 0.0, 4.7, WHITE);
}

void check_collisions(const std::vector<Nebula>& neb_vec, const Scarfy& scarfy, bool& collision) {
    for (const Nebula& neb: neb_vec) {
        float padding{40.0};
        Rectangle nebby { neb.get_neb_pos_x() + padding, neb.get_neb_pos_y() + padding,
                          neb.get_neb_rec_width() - 2*padding, neb.get_neb_rec_height() - 2*padding };

        Rectangle scarf_rec { scarfy.get_scarfy_pos_x(), scarfy.get_scarfy_pos_y(),
                              scarfy.get_rec_height(), scarfy.get_scarfy_rec_width()};

        if (CheckCollisionRecs(nebby, scarf_rec)) {
            collision = true;
        }
    }
}

#endif //DAPPER_DASHER_FUNCTIONS_H
