#pragma once

#include "IController.h"

//References used:
//https://cs.chromium.org/chromium/src/device/gamepad/xbox_controller_mac.mm

struct Xbox360ButtonData
{
    uint8_t type;
    uint8_t length;

    bool dpad_up : 1;
    bool dpad_down : 1;
    bool dpad_left : 1;
    bool dpad_right : 1;

    bool start : 1;
    bool back : 1;
    bool stick_left_click : 1;
    bool stick_right_click : 1;

    bool bumper_left : 1;
    bool bumper_right : 1;
    bool guide : 1;
    bool dummy1 : 1; // Always 0.

    bool a : 1;
    bool b : 1;
    bool x : 1;
    bool y : 1;

    uint8_t trigger_left;
    uint8_t trigger_right;

    int16_t stick_left_x;
    int16_t stick_left_y;
    int16_t stick_right_x;
    int16_t stick_right_y;

    // Always 0.
    uint32_t dummy2;
    uint16_t dummy3;
};

struct Xbox360RumbleData
{
    uint8_t command;
    uint8_t size;
    uint8_t dummy1;
    uint8_t big;
    uint8_t little;
    uint8_t dummy2[3];
};

enum Xbox360InputPacketType
{
    XBOX360INPUT_BUTTON = 0,
    XBOX360INPUT_LED = 1,
    XBOX360INPUT_RUMBLE = 3,
};

class Xbox360Controller : public IController
{
private:
    IUSBEndpoint *m_inPipe = nullptr;
    IUSBEndpoint *m_outPipe = nullptr;

    Xbox360ButtonData m_buttonData;

    int16_t kLeftThumbDeadzone = 0;  //7849;
    int16_t kRightThumbDeadzone = 0; //8689;
    uint16_t kTriggerMax = 0;        //1023;
    uint16_t kTriggerDeadzone = 0;   //120;

public:
    Xbox360Controller(std::unique_ptr<IUSBDevice> &&interface);
    virtual ~Xbox360Controller();

    virtual Status Initialize();
    virtual void Exit();

    Status OpenInterfaces();
    void CloseInterfaces();

    virtual Status GetInput();

    virtual NormalizedButtonData GetNormalizedButtonData();

    virtual ControllerType GetType() { return CONTROLLER_XBOX360; }

    inline const Xbox360ButtonData &GetButtonData() { return m_buttonData; };

    float NormalizeTrigger(uint16_t value);
    void NormalizeAxis(int16_t x, int16_t y, int16_t deadzone, float *x_out, float *y_out);

    Status SendInitBytes();
    Status SetRumble(uint8_t strong_magnitude, uint8_t weak_magnitude);
};