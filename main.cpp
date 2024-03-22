#include <iostream>
#include <raylib.h>
#include "constants.h"
#include "classes/Scarfy.h"

int main() {

    bool is_in_air{false};
    float velocity_y{0.0};

    InitWindow(screen_width, screen_height, "Dapper Dasher");


    Scarfy scarfy{};

    SetTargetFPS(60);

    while(!WindowShouldClose()) {
        const float dT{GetFrameTime()};

        BeginDrawing();
        ClearBackground(DARKBLUE);
        DrawText("Henlo World!", (screen_width - 300.0)/2.0, (screen_height - 50)/2.0,
                 50, LIGHTGRAY);

        if (scarfy.get_scarfy_pos_y() >= screen_height - scarfy.get_rec_height()) {
            is_in_air = false;
            velocity_y = 0.0;
        } else {
            velocity_y += gravity * dT;
        }

        if (IsKeyPressed(KEY_SPACE) && !is_in_air) {
            is_in_air = true;
            scarfy.set_scarfy_pos_y(jump_velocity);
        }

        scarfy.set_scarfy_pos_y(velocity_y * dT);

        scarfy.draw_scarfy();

        EndDrawing();
    }

    //De-Initialization
    UnloadTexture(scarfy.get_scarfy_text());
    CloseWindow();

    return 0;
}
