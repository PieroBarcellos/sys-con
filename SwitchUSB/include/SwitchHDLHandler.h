#pragma once

#include "switch.h"
#include "IController.h"
#include "SwitchControllerHandler.h"
#include "SwitchVirtualGamepadHandler.h"
#include <thread>

//Wrapper for HDL functions for switch versions [7.0.0+]
class SwitchHDLHandler : public SwitchVirtualGamepadHandler
{
private:
    u32 m_vibrationDeviceHandle;
    u64 m_hdlHandle;
    HiddbgHdlsDeviceInfo m_deviceInfo;
    HiddbgHdlsState m_hdlState;

public:
    //Initialize the class with specified controller
    SwitchHDLHandler(std::unique_ptr<IController> &&controller);
    ~SwitchHDLHandler();

    //Initialize controller handler, HDL state
    Result Initialize() override;
    void Exit() override;

    //This will be called periodically by the input threads
    void UpdateInput() override;
    //This will be called periodically by the output threads
    void UpdateOutput() override;

    //Separately init and close the HDL state
    Result InitHdlState();
    Result ExitHdlState();

    //Fills out the HDL state with the specified button data
    void FillHdlState(const NormalizedButtonData &data);
    //Passes the HDL state to HID so that it could register the inputs
    Result UpdateHdlState();

    inline u32 *GetVibrationHandle() { return &m_vibrationDeviceHandle; }
};