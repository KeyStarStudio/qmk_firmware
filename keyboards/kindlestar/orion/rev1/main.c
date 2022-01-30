#include "keyboard.h"
#include <ch.h>
#include <hal.h>

#include "usb_main.h"

/* TMK includes */
#include "report.h"
#include "host.h"
#include "host_driver.h"
#include "action.h"
#include "action_util.h"
#include "mousekey.h"
#include "led.h"
#include "sendchar.h"
#include "debug.h"
#include "print.h"
#include "suspend.h"
#include "wait.h"
#include "orion_output_auto_select.h"

void custom_kbd_leds(void);

host_driver_t orion_driver = {keyboard_leds, send_keyboard, send_mouse, send_system, send_consumer};

void platform_setup(void);
void protocol_setup(void);

// usb protocol init
void protocol_initV2(void);
void protocol_task(void);

int main(void) {
    platform_setup();
    protocol_setup();

    protocol_initV2();

    /* Main loop */
    while (true) {
        protocol_task();
        housekeeping_task();
    }
}

// choose init usb or not depending on eeprom val
void protocol_initV2(void) {

    /* Init USB */
    usb_event_queue_init();
    init_usb_driver(&USB_DRIVER);

#ifdef MIDI_ENABLE
    setup_midi();
#endif

#ifdef SERIAL_LINK_ENABLE
    init_serial_link();
#endif

#ifdef VISUALIZER_ENABLE
    visualizer_init();
#endif

    host_driver_t *driver = NULL;

    /* Wait until the USB or serial link is active */
    while (true) {
#if defined(WAIT_FOR_USB) || defined(SERIAL_LINK_ENABLE)
        if (USB_DRIVER.state == USB_ACTIVE) {
            driver = &orion_driver;
            break;
        }
#else
        driver = &orion_driver;
        break;
#endif
#ifdef SERIAL_LINK_ENABLE
        if (is_serial_link_connected()) {
            driver = get_serial_link_driver();
            break;
        }
        serial_link_update();
#endif
        wait_ms(50);
    }

    /* Do need to wait here!
     * Otherwise the next print might start a transfer on console EP
     * before the USB is completely ready, which sometimes causes
     * HardFaults.
     */
    wait_ms(50);

    print("USB configured.\n");

    /* init TMK modules */
    keyboard_init();
    host_set_driver(driver);

#ifdef SLEEP_LED_ENABLE
    sleep_led_init();
#endif

    print("Keyboard start.\n");
}
