#include <iostream>
#include <raylib.h>
#include <vector>
#include "constants.h"
#include "classes/Scarfy.h"
#include "classes/Nebula.h"
#include "functions.h"

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

        animate_scarfy(scarfy, dT);

        animate_nebulae(neb_vec, dT);

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
