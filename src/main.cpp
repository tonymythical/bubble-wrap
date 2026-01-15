#include <bn_core.h>
#include <bn_backdrop.h>
#include <bn_color.h>
#include <bn_keypad.h>

int main()
{
    bn::core::init();
    bn::backdrop::set_color(bn::color(31, 12, 12));

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
        bn::core::update();
    }
}