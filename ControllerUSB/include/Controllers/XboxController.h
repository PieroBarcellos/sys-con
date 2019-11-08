#pragma once

#include "IController.h"

//References used:
//http://euc.jp/periphs/xbox-controller.ja.html

struct XboxButtonData
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

    uint8_t reserved;

    bool a;
    bool b;
    bool x;
    bool y;

    bool black_buttton;
    bool white_button;

    bool trigger_left;
    bool trigger_right;

    int16_t stick_left_x;
    int16_t stick_left_y;
    int16_t stick_right_x;
    int16_t stick_right_y;
};

struct XboxRumbleData
{
    uint8_t command;
    uint8_t size;
    uint8_t dummy1;
    uint8_t big;
    uint8_t dummy2;
    uint8_t little;
};

class XboxController : public IController
{
private:
    IUSBEndpoint *m_inPipe = nullptr;
    IUSBEndpoint *m_outPipe = nullptr;

    XboxButtonData m_buttonData;

public:
    XboxController(std::unique_ptr<IUSBDevice> &&interface);
    virtual ~XboxController();

    virtual Status Initialize();
    virtual void Exit();

    Status OpenInterfaces();
    void CloseInterfaces();

    virtual Status GetInput();

    virtual NormalizedButtonData GetNormalizedButtonData();

    virtual ControllerType GetType() { return CONTROLLER_XBOX360; }

    inline const XboxButtonData &GetButtonData() { return m_buttonData; };

    float NormalizeTrigger(uint8_t value);
    void NormalizeAxis(int16_t x, int16_t y, uint8_t deadzonePercent, float *x_out, float *y_out);

    Status SetRumble(uint8_t strong_magnitude, uint8_t weak_magnitude);

    static void LoadConfig(const ControllerConfig *config);
};