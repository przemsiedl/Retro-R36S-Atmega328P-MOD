#include <pins_arduino.h>

#define uint unsigned int

#define UART_RX                 0
#define UART_TX                 1
#define ARROW_LEFT              2
#define ARROW_UP                3
#define ARROW_RIGHT             4
#define ARROW_DOWN              5
#define SELECT                  6
#define FN                      7
#define START                   8
#define Y                       9
#define X                       10
#define A                       11
#define B                       12
#define WIFI                    13
#define BLUETOOTH               PIN_A0
#define FREE                    PIN_A1
#define ANALOG_LEFT_VERTICAL    PIN_A2
#define ANALOG_LEFT_HORIZONTAL  PIN_A3
#define ANALOG_RIGHT_VERTICAL   PIN_A4
#define ANALOG_RIGHT_HORIZONTAL PIN_A5

#define BUTTONS_LEN 20

enum PinMode {
    PIN_INPUT,
    PIN_OUTPUT,
    PIN_ANALOG_INPUT,
    PIN_ANALOG_OUTPUT,
    PIN_SKIP
};

struct ButtonDef {
    int PressMs;
    const char* Name;
    const uint Pin;
    const PinMode Mode;
};

ButtonDef Buttons[] = {
    {0, "UART_RX", UART_RX, PIN_SKIP},
    {0, "UART_TX", UART_TX, PIN_SKIP},
    {0, "ARROW_LEFT", ARROW_LEFT, PIN_INPUT},
    {0, "ARROW_UP", ARROW_UP, PIN_INPUT},
    {0, "ARROW_RIGHT", ARROW_RIGHT, PIN_INPUT},
    {0, "ARROW_DOWN", ARROW_DOWN, PIN_INPUT},
    {0, "SELECT", SELECT, PIN_INPUT},
    {0, "FN", FN, PIN_INPUT},
    {0, "START", START, PIN_INPUT},
    {0, "Y", Y, PIN_INPUT},
    {0, "X", X, PIN_INPUT},
    {0, "A", A, PIN_INPUT},
    {0, "B", B, PIN_INPUT},
    {0, "WIFI", WIFI, PIN_OUTPUT},
    {0, "BLUETOOTH", BLUETOOTH, PIN_OUTPUT},
    {0, "FREE", FREE, PIN_SKIP},
    {0, "ANALOG_LEFT_VERTICAL", ANALOG_LEFT_VERTICAL, PIN_ANALOG_INPUT},
    {0, "ANALOG_LEFT_HORIZONTAL", ANALOG_LEFT_HORIZONTAL, PIN_ANALOG_INPUT},
    {0, "ANALOG_RIGHT_VERTICAL", ANALOG_RIGHT_VERTICAL, PIN_ANALOG_INPUT},
    {0, "ANALOG_RIGHT_HORIZONTAL", ANALOG_RIGHT_HORIZONTAL, PIN_ANALOG_INPUT}
};

#define BUTTON_DEFAULT_STATE HIGH
