//
// Created by dougl on 3/25/2024.
//

#ifndef DAPPER_DASHER_NEBULA_H
#define DAPPER_DASHER_NEBULA_H
#include <raylib.h>


class Nebula {
private:
    Texture2D neb_text = LoadTexture("../textures/12_nebula_spritesheet.png");
    Rectangle neb_rec{};
    Vector2 neb_pos{};

    float neb_vel{-300};
    int neb_frame;
    float neb_running_time;

public:
    constexpr static const float velocity{-400};

    Nebula(float pos_x);

    void set_neb_pos_x(float val);

    [[nodiscard]]
    float get_neb_pos_x() const;

    [[nodiscard]]
    float get_neb_pos_y() const;

    [[nodiscard]]
    float get_neb_rec_width() const;

    [[nodiscard]]
    float get_neb_rec_height() const;

    [[nodiscard]]
    float get_rec_x() const;

    Texture2D get_neb_text();

    void set_neb_rec_x(float val);

    [[nodiscard]]
    float get_neb_run_time() const;

    void set_neb_run_time(float val);

    void increment_run_time(float val);

    [[nodiscard]]
    int get_frame() const;

    void increase_frame();

    void reset_frame();

    void draw_neb();
};


#endif //DAPPER_DASHER_NEBULA_H
