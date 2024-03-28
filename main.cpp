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
        neb_vec.emplace_back(screen_width + (i * 400.0));
    }

    float finish_line{neb_vec[neb_vec.size() - 1].get_neb_pos_x() + 100};

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
        draw_background(bg_x, far_bg);
        //draw mid ground
        draw_background(mid_x, mid_ground);
        //draw foreground
        draw_background(fore_x, fore_ground);


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

        bool collision{false};

        check_collisions(neb_vec, scarfy, collision);

        if (!collision) {
            for (Nebula &neb: neb_vec) {
                neb.set_neb_pos_x(Nebula::velocity * dT);
                neb.draw_neb();
            }
        }

        finish_line += Nebula::velocity * dT;

        scarfy.set_scarfy_pos_y(scarfy.get_vel_y() * dT);

        if (!collision)
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
