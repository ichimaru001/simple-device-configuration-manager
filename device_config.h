#ifndef DEVICE_CONFIG_H
#define DEVICE_CONFIG_H

#include <stdint.h>

// ** BITFIELDS DEFINED
typedef struct {
    uint16_t powerOn : 1;
    uint16_t mode : 2;
    uint16_t error : 1;
    uint16_t reserved : 8;
    uint16_t version : 4;
  } DeviceBits;
// ** DEVICE CONFIG DEFINED
  typedef union {
    uint16_t rawValue;
    DeviceBits bits;
  } DeviceConfig;
// ** MAIN FUNCTIONS DECLARED
  void initConfig(DeviceConfig *device);
  void printConfig(const DeviceConfig *device);
  void powerOnOffConfig(DeviceConfig *device, uint16_t value);
  void modeConfig(DeviceConfig *device, uint16_t value);
  void errorConfig(DeviceConfig *device, uint16_t value);
  void versionConfig(DeviceConfig *device, uint16_t value);
  void reservedConfig(DeviceConfig *device, uint16_t value);

#endif