//
// Created by dougl on 3/22/2024.
//

#ifndef DAPPER_DASHER_SCARFY_H
#define DAPPER_DASHER_SCARFY_H
#include <raylib.h>

class Scarfy {
private:
    Texture2D scarfy_text = LoadTexture("../textures/scarfy.png");
    Rectangle scarfy_rec{};
    Vector2 scarfy_pos{};
public:
    Scarfy();

    void set_scarfy_pos_y(float velocity_y);

    void set_scarfy_velocity_y_zero();

    [[nodiscard]]
    float get_scarfy_pos_y() const;

    [[nodiscard]]
    float get_rec_height() const;

    [[nodiscard]]
    Texture2D get_scarfy_text() const;

    void set_scarfy_rec_x(float val);

    [[nodiscard]]
    float get_scarfy_rec_width() const;

    void draw_scarfy();
};


#endif //DAPPER_DASHER_SCARFY_H
