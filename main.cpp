#include <iostream>
#include <raylib.h>
#include <vector>
#include "constants.h"
#include "classes/Scarfy.h"
#include "classes/Nebula.h"
#include "functions_lib.h"

int main() {

    InitWindow(screen_width, screen_height, "Dapper Dasher");

    Scarfy scarfy{};

    std::vector<Nebula> neb_vec;

    Texture2D far_bg = LoadTexture("../textures/far-buildings.png");
    Texture2D mid_ground = LoadTexture("../textures/back-buildings.png");
    Texture2D fore_ground = LoadTexture("../textures/foreground.png");
    float bg_x{};
    float mid_x{};
    float fore_x{};

    for (int i{0}; i < number_of_nebs; ++i) {
        neb_vec.emplace_back(screen_width + (i * 200.0));
    }


    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        const float dT{GetFrameTime()};

        BeginDrawing();
        ClearBackground(WHITE);
        bg_x -= 20 * dT;
        if (bg_x <= -far_bg.width*2.0)
            bg_x = 0.0;

        mid_x -= 60 * dT;
        if (mid_x <= -mid_ground.width*2.0)
            mid_x = 0.0;

        fore_x -= 100 * dT;
        if (fore_x <= -fore_ground.width*2.0)
            fore_x = 0.0;

        //draw background
        Vector2 bg1_pos{bg_x, 0.0};
        DrawTextureEx(far_bg, bg1_pos, 0.0, 4.7, WHITE);
        Vector2 bg2_pos{bg_x + ((float)far_bg.width * 2.0), 0.0};
        DrawTextureEx(far_bg, bg2_pos, 0.0, 4.7, WHITE);
        //draw mid ground
        Vector2 mg1_pos{mid_x, 0.0};
        DrawTextureEx(mid_ground, mg1_pos, 0.0, 4.7, WHITE);
        Vector2 mg2_pos{mid_x + ((float)mid_ground.width * 2.0), 0.0};
        DrawTextureEx(mid_ground, mg2_pos, 0.0, 4.7, WHITE);
        //draw fore ground
        Vector2 fg1_pos{fore_x, 0.0};
        DrawTextureEx(fore_ground, fg1_pos, 0.0, 4.7, WHITE);
        Vector2 fg2_pos{fore_x + ((float)fore_ground.width * 2.0), 0.0};
        DrawTextureEx(fore_ground, fg2_pos, 0.0, 4.7, WHITE);


        if (scarfy.get_scarfy_pos_y() >= screen_height - scarfy.get_rec_height()) {
            scarfy.set_is_in_air(false);
            scarfy.set_velocity_y(0.0);
        } else {
            scarfy.increment_vel_y(gravity * dT);
        }

        if (IsKeyPressed(KEY_SPACE) && !scarfy.get_is_in_air()) {
            scarfy.jump();
        }

        update_animation_scarfy(scarfy, dT);

        update_animation_nebulae(neb_vec, dT);

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
    UnloadTexture(far_bg);
    UnloadTexture(mid_ground);
    UnloadTexture(fore_ground);
    CloseWindow();

    return 0;
}
