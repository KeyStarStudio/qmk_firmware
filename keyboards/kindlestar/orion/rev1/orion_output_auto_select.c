#include "orion_output_auto_select.h"
#include "orion_usb_sender.h"

static bool internal = true; // usb mode is internal and 2.4g and ble is other
void output_select_init()
{
    // read eeprom to judge output
    internal = true;
}

bool internal_moode(void)
{
    return internal;
}

uint8_t keyboard_leds(void)
{
    return 0;
}
void    send_keyboard(report_keyboard_t *report)
{
    if (internal)
    {
        usb_send_keyboard(report);
    } else {

    }

}
void    send_mouse(report_mouse_t *report)
{
    if (internal)
    {
        usb_send_mouse(report);
    } else {

    }
}
void    send_system(uint16_t data)
{
    if (internal)
    {
        usb_send_system(data);
    } else {

    }
}
void    send_consumer(uint16_t data)
{
    if (internal)
    {
        usb_send_consumer(data);
    } else {

    }
}

void    send_digitizer(report_digitizer_t *report)
{
    if (internal)
    {
        usb_send_digitizer(report);
    } else {

    }
}
