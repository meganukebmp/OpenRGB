/*---------------------------------------------------------*\
| PowerColorRedDevilV2Controller.cpp                        |
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
#include "PowerColorRedDevilV2Controller.h"


PowerColorRedDevilV2Controller::PowerColorRedDevilV2Controller(i2c_smbus_interface* bus, red_devil_v2_dev_id dev, std::string dev_name) {
    this->bus   = bus;
    this->dev   = dev;
    this->name  = dev_name;
}

PowerColorRedDevilV2Controller::~PowerColorRedDevilV2Controller() {
// stub
}

std::string PowerColorRedDevilV2Controller::GetDeviceLocation()
{
    std::string return_string(bus->device_name);
    char addr[5];
    snprintf(addr, 5, "0x%02X", dev);
    return_string.append(", address ");
    return_string.append(addr);
    return("I2C:" + return_string);
}

std::string PowerColorRedDevilV2Controller::GetDeviceName()
{
    return(name);
}