#include <iostream>
#include <raylib.h>
#include <vector>
#include "constants.h"
#include "classes/Scarfy.h"
#include "classes/Nebula.h"

int main() {

    InitWindow(screen_width, screen_height, "Dapper Dasher");


    Scarfy scarfy{};
    //Nebula neb{screen_width};
    std::vector<Nebula> neb_vec;

    for (int i{0}; i < number_of_nebs; ++i) {
        neb_vec.emplace_back(screen_width + (i * 200.0));
    }


    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        const float dT{GetFrameTime()};

        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawText("Henlo World!", (screen_width - 300.0)/2.0, (screen_height - 50)/2.0,
                 50, LIGHTGRAY);

        if (scarfy.get_scarfy_pos_y() >= screen_height - scarfy.get_rec_height()) {
            scarfy.set_is_in_air(false);
            scarfy.set_velocity_y(0.0);
        } else {
            scarfy.increment_vel_y(gravity * dT);
        }

        if (IsKeyPressed(KEY_SPACE) && !scarfy.get_is_in_air()) {
            scarfy.jump();
        }

        //update scarfy animation frame
        scarfy.increment_run_time(dT);
        if (scarfy.get_run_time() >= animate_update_time && !scarfy.get_is_in_air()) {
            scarfy.set_run_time(0.0);

            scarfy.set_scarfy_rec_x((float) scarfy.get_frame() * scarfy.get_scarfy_rec_width());
            scarfy.increment_frame();
            if (scarfy.get_frame() > 5)
                scarfy.reset_frame();
        }


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

        for (Nebula& neb: neb_vec) {
            neb.set_neb_pos_x( Nebula::velocity * dT);
            neb.draw_neb();
        }

        scarfy.set_scarfy_pos_y(scarfy.get_vel_y() * dT);

        scarfy.draw_scarfy();

        EndDrawing();
    }

    //De-Initialization
    UnloadTexture(scarfy.get_scarfy_text());
    for (Nebula neb: neb_vec)
        UnloadTexture(neb.get_neb_text());
    CloseWindow();

    return 0;
}
