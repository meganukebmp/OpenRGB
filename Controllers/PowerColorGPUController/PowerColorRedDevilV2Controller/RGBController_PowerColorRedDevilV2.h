/*---------------------------------------------------------*\
| RGBController_PowerColorRedDevilV2.h                      |
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
#include "PowerColorRedDevilV2Controller.h"

class RGBController_PowerColorRedDevilV2 : public RGBController
{
public:
    RGBController_PowerColorRedDevilV2(PowerColorRedDevilV2Controller* controller_ptr);
    ~RGBController_PowerColorRedDevilV2();

    void        SetupZones();

    void        ResizeZone(int zone, int new_size);

    void        DeviceUpdateLEDs();
    void        UpdateZoneLEDs(int zone);
    void        UpdateSingleLED(int led);

    void        DeviceUpdateMode();

private:
    PowerColorRedDevilV2Controller* controller;
};
