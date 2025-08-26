/*---------------------------------------------------------*\
| PowerColorRedDevilV2Controller.h                          |
|                                                           |
|   Driver for PowerColor Red Devil GPU                     |
|                                                           |
|   Nexrem                                      15 Aug 2025 |
|                                                           |
|   This file is part of the OpenRGB project                |
|   SPDX-License-Identifier: GPL-2.0-only                   |
\*---------------------------------------------------------*/

#include <string>
#include "i2c_smbus.h"
#include "RGBController.h"

#pragma once


class PowerColorRedDevilV2Controller
{
public:
    PowerColorRedDevilV2Controller(i2c_smbus_interface* bus, char dev);
    ~PowerColorRedDevilV2Controller();
};
