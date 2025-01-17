#pragma once

enum ControllerType : uint8_t
{
    CONTROLLER_UNDEFINED,
    CONTROLLER_XBOX360,
    CONTROLLER_XBOX360W,
    CONTROLLER_XBOXONE,
    CONTROLLER_XBOXONEW,
    CONTROLLER_DUALSHOCK3,
    CONTROLLER_DUALSHOCK4,
    CONTROLLER_STEERINGWHEELSDKSIMPLE
};

enum VendorIDs : uint16_t
{
    VENDOR_MICROSOFT = 0x45e,
    VENDOR_SONY = 0x54c,
    VENDOR_LOGITECH = 0x046d,
};

enum ProductIDs : uint16_t
{
    PRODUCT_XBOX360 = 0x28e,
    PRODUCT_XBOXONE2013 = 0x2d1,
    PRODUCT_XBOXONE2015 = 0x2dd,
    PRODUCT_XBOXONEELITE = 0x2e3,
    PRODUCT_XBOXONES = 0x2ea,
    PRODUCT_XBOXADAPTIVE = 0xb0a,
    PRODUCT_STEERINGWHEELSDKSIMPLE = 0xc261,
    PRODUCT_DUALSHOCK3 = 0x268,
    PRODUCT_DUALSHOCK4_1X = 0x5c4,
    PRODUCT_DUALSHOCK4_2X = 0x9cc,
};

enum ControllerSupport : uint8_t
{
    SUPPORTS_RUMBLE,
    SUPPORTS_BLUETOOTH,
    SUPPORTS_PAIRING,
    SUPPORTS_NOTHING,
    SUPPORTS_SIXAXIS,
    SUPPORTS_SEVENAXIS,
    SUPPORTS_PRESSUREBUTTONS,
};
