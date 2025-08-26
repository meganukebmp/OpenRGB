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
    controller                  = controller_ptr;

    name                        = controller->GetDeviceName();
    vendor                      = "PowerColor";
    description                 = "PowerColor Red Devil V2 GPU Device";
    location                    = controller->GetDeviceLocation();
    type                        = DEVICE_TYPE_GPU;

    mode Off;
    Off.name                    = "Off";
    Off.value                   = RED_DEVIL_V2_MODE_OFF;
    Off.flags                   = MODE_FLAG_AUTOMATIC_SAVE;
    Off.color_mode              = MODE_COLORS_NONE;
    modes.push_back(Off);

    mode Static;
    Static.name                 = "Static";
    Static.value                = RED_DEVIL_V2_MODE_STATIC;
    Static.flags                = MODE_FLAG_HAS_PER_LED_COLOR | MODE_FLAG_HAS_BRIGHTNESS | MODE_FLAG_AUTOMATIC_SAVE;
    Static.color_mode           = MODE_COLORS_PER_LED;
    Static.brightness_min       = RED_DEVIL_V2_BRIGHTNESS_MIN;
    Static.brightness_max       = RED_DEVIL_V2_BRIGHTNESS_MAX;
    Static.brightness           = RED_DEVIL_V2_BRIGHTNESS_MAX;
    modes.push_back(Static);

    mode Breathing;
    Breathing.name                 = "Breathing";
    Breathing.value                = RED_DEVIL_V2_MODE_BREATHING;
    Breathing.flags                = MODE_FLAG_HAS_SPEED | MODE_FLAG_HAS_PER_LED_COLOR | MODE_FLAG_HAS_BRIGHTNESS | MODE_FLAG_AUTOMATIC_SAVE;
    Breathing.color_mode           = MODE_COLORS_PER_LED;
    Breathing.brightness_min       = RED_DEVIL_V2_BRIGHTNESS_MIN;
    Breathing.brightness_max       = RED_DEVIL_V2_BRIGHTNESS_MAX;
    Breathing.brightness           = RED_DEVIL_V2_BRIGHTNESS_MAX;
    Breathing.speed_min            = RED_DEVIL_V2_SPEED_MIN;
    Breathing.speed_max            = RED_DEVIL_V2_SPEED_MAX;
    Breathing.speed                = RED_DEVIL_V2_SPEED_DEFAULT;
    modes.push_back(Breathing);

    SetupZones();

    // Read config
}

RGBController_PowerColorRedDevilV2::~RGBController_PowerColorRedDevilV2() {
    delete controller;
}

void RGBController_PowerColorRedDevilV2::SetupZones() {
    zone* new_zone = new zone();
    led*  new_led  = new led();

    new_zone->name          = "GPU Zone";
    new_zone->type          = ZONE_TYPE_SINGLE;
    new_zone->leds_min      = 1;
    new_zone->leds_max      = 1;
    new_zone->leds_count    = 1;
    new_zone->matrix_map    = NULL;

    new_led->name           = "GPU LED";

    /*---------------------------------------------------------*\
    | Push the zone and LED on to device vectors                |
    \*---------------------------------------------------------*/
    leds.push_back(*new_led);
    zones.push_back(*new_zone);

    SetupColors();
}

void RGBController_PowerColorRedDevilV2::ResizeZone(int zone, int new_size) {

}

void RGBController_PowerColorRedDevilV2::DeviceUpdateLEDs() {
    RGBColor      color = colors[0];

    controller->SetLedColorAll(color);
}

void RGBController_PowerColorRedDevilV2::UpdateZoneLEDs(int zone) {
    DeviceUpdateLEDs();
}

void RGBController_PowerColorRedDevilV2::UpdateSingleLED(int led) {
    DeviceUpdateLEDs();
}

void RGBController_PowerColorRedDevilV2::DeviceUpdateMode() {
    red_devil_v2_mode mode;
    mode.mode = (unsigned char)modes[active_mode].value;
    mode.brightness = (unsigned char)modes[active_mode].brightness;
    mode.speed = (unsigned char)modes[active_mode].speed;

    controller->SetMode(mode);
}
