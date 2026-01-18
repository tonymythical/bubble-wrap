#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>
#include <bn_sprite_ptr.h>
#include <bn_sprite_items_dot.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(31, 12, 12));
    bn::sprite_ptr myCircle = bn::sprite_items::dot.create_sprite(20, -10);
    bn::sprite_ptr myCircle2 = bn::sprite_items::dot.create_sprite(-20, -10);
    bn::sprite_ptr myCircle3 = bn::sprite_items::dot.create_sprite(25, 30);
    bn::sprite_ptr myCircle4 = bn::sprite_items::dot.create_sprite(-25, 30);
    bn::sprite_ptr myCircle5 = bn::sprite_items::dot.create_sprite(0, 35);



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