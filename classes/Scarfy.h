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

    bool is_in_air{false};
    int frame;
    float velocity_y;
    float running_time;
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

    [[nodiscard]]
    bool get_is_in_air() const;

    void set_is_in_air(bool val);

    float get_vel_y() const;

    void set_velocity_y(float val);

    void increment_vel_y(float val);

    void increment_run_time(float val);

    void jump();

    void draw_scarfy();

    [[nodiscard]]
    float get_run_time() const;

    void set_run_time(float val);

    [[nodiscard]]
    int get_frame() const;

    void reset_frame();

    void increment_frame();

};


#endif //DAPPER_DASHER_SCARFY_H
