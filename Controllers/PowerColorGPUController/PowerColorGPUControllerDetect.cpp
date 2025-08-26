/*---------------------------------------------------------*\
| PowerColorGPUControllerDetect.cpp                         |
|                                                           |
|   Driver for PowerColor GPUs                              |
|                                                           |
|   Nexrem                                      15 Aug 2025 |
|                                                           |
|   This file is part of the OpenRGB project                |
|   SPDX-License-Identifier: GPL-2.0-only                   |
\*---------------------------------------------------------*/

#include "Detector.h"
#include "pci_ids.h"
#include "PowerColorRedDevilV2Controller/RGBController_PowerColorRedDevilV2.h"
#include "PowerColorRedDevilV2Controller/PowerColorRedDevilV2Controller.h"

void DetectPowerColorRedDevilGPUControllersV2(i2c_smbus_interface* bus, uint8_t i2c_addr, const std::string& name)
{
    //unsigned char data[3] = {0};
    //int ret = bus->i2c_smbus_read_i2c_block_data(i2c_addr, 0x90, 3, data);
    //if(ret == 3 && memcmp(data, indicator, 3) == 0)
    //{
        PowerColorRedDevilV2Controller* controller         = new PowerColorRedDevilV2Controller(bus, i2c_addr);
        RGBController_PowerColorRedDevilV2* rgb_controller = new RGBController_PowerColorRedDevilV2(controller);

        ResourceManager::get()->RegisterRGBController(rgb_controller);
    //}
}

REGISTER_I2C_PCI_DETECTOR("PowerColor Red Devil RX9070XT", DetectPowerColorRedDevilGPUControllersV2, AMD_GPU_VEN, AMD_NAVI48_DEV, POWERCOLOR_SUB_VEN, POWERCOLOR_RED_DEVIL_RX9070XT_SUB_DEV, 0x22);