#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>
#include <bn_log.h>
#include <bn_vector.h>
#include <bn_math.h>
#include <bn_fixed.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(31, 12, 12));
  
    // bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(20, -10);
    // bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(-20, -10);
    // bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(25, 30);
    // bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(-25, 30);
    // bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(0, 35);

    // bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(-40, 40);
    // bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(-30, 40);
    // bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(-20, 40);
    // bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(-10, 40);
    // bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(0, 40);
    // bn::sprite_ptr myCircle6 = bn::sprite_items::dot.create_sprite(10, 40);
    // bn::sprite_ptr myCircle7 = bn::sprite_items::dot.create_sprite(20, 40);
    // bn::sprite_ptr myCircle8 = bn::sprite_items::dot.create_sprite(30, 40);
    // bn::sprite_ptr myCircle9 = bn::sprite_items::dot.create_sprite(40, 40);

    bn::vector<bn::sprite_ptr, 20> circles = {};

    for(int x = -40; x <= 40; x += 10) {
        bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(x, 40);
        BN_LOG("x value", x);
        
        bn::fixed degrees = bn::fixed(x * 4);
        bn::fixed angle = degrees * bn::fixed(20) / 360;
        
        myCircle.set_position(bn::sin(angle) * 40, bn::cos(angle) * 40);
        circles.push_back(myCircle);
    }

    while (true)
    {
        if (bn::keypad::a_held())
        {
            bn::backdrop::set_color(bn::color(1, 31, 1));
        }

        else if (bn::keypad::b_held())
        {
            bn::backdrop::set_color(bn::color(1, 1, 31));
        }

        else
            (bn::backdrop::set_color(bn::color(31, 12, 12)));

        if (bn::keypad::a_held() && bn::keypad::b_held())
        {
            bn::backdrop::set_color(bn::color(1, 15, 15));
        }

        if (bn::keypad::r_held())
        {
            bn::backdrop::set_color(bn::color(31, 31, 1));
        }

        bn::core::update();
    }
}