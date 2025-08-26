/*---------------------------------------------------------*\
| RGBController_PowerColorRedDevilV2.cpp                    |
|                                                           |
|   Driver for PowerColor Red Devil GPU                     |
|                                                           |
|   Nexrem                                      15 Aug 2025 |
|                                                           |
|   This file is part of the OpenRGB project                |
|   SPDX-License-Identifier: GPL-2.0-only                   |
\*---------------------------------------------------------*/

#pragma once

#include "RGBController.h"
#include "RGBController_PowerColorRedDevilV2.h"

RGBController_PowerColorRedDevilV2::RGBController_PowerColorRedDevilV2(PowerColorRedDevilV2Controller* controller_ptr) {
    name                        = "TEST NAME";
    vendor                      = "PowerColor";
    description                 = "PowerColor Red Devil GPU Device";
    location                    = "TEST LOCATION";
    type                        = DEVICE_TYPE_GPU;

    mode Off;
    Off.name                    = "Off";
    Off.value                   = 0;
    Off.flags                   = MODE_FLAG_AUTOMATIC_SAVE;
    Off.color_mode              = MODE_COLORS_NONE;
    modes.push_back(Off);

    mode Static;
    Static.name                 = "Static";
    Static.value                = 0;
    Static.flags                = MODE_FLAG_HAS_PER_LED_COLOR | MODE_FLAG_HAS_BRIGHTNESS | MODE_FLAG_AUTOMATIC_SAVE;
    Static.color_mode           = MODE_COLORS_PER_LED;
    Static.brightness_min       = 0;
    Static.brightness_max       = 3;
    Static.brightness           = 2;
    modes.push_back(Static);
}

RGBController_PowerColorRedDevilV2::~RGBController_PowerColorRedDevilV2() {

}

void RGBController_PowerColorRedDevilV2::SetupZones() {

}

void RGBController_PowerColorRedDevilV2::ResizeZone(int zone, int new_size) {

}

void RGBController_PowerColorRedDevilV2::DeviceUpdateLEDs() {

}

void RGBController_PowerColorRedDevilV2::UpdateZoneLEDs(int zone) {

}

void RGBController_PowerColorRedDevilV2::UpdateSingleLED(int led) {

}

void RGBController_PowerColorRedDevilV2::DeviceUpdateMode() {

}
