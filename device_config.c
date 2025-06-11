#include <stdio.h>
#include "device_config.h"

// * INITIALIZE FUNCTION
void initConfig(DeviceConfig *device) {
  device->rawValue = 0;
};
// * PRINT FUNCTION
void printConfig(const DeviceConfig *device) {
  printf("Hex format of status: %04X\n", device->rawValue);
  printf("\nPower On : %s\nMode : %u\nError : %u\nVersion : %u\nReserved : %u\n",
    (device->bits.powerOn) == 0x01 ? "ON" : "OFF",
    device->bits.mode,
    device->bits.error,
    device->bits.version,
    device->bits.reserved);
};
// * STATUS FUNCTIONS
void powerOnOffConfig(DeviceConfig *device, uint16_t value) {
  if (value > 1) {
    printf("Warning: Invalid power (on or off) value has been entered.\n");
  }
  device->bits.powerOn = value ? 1 : 0;
}
void modeConfig(DeviceConfig *device, uint16_t value) {
  if (value > 0x03) {
    printf("Warning: Invalid mode value has been entered.\n");
  }
  device->bits.mode = value & 0x03;
}
void errorConfig(DeviceConfig *device, uint16_t value) {
  if (value > 1) {
    printf("Warning: Invalid error value has been entered.\n");
  }
  device->bits.error = value ? 1 : 0;
}
void versionConfig(DeviceConfig *device, uint16_t value) {
  if (value > 0x0F) {
    printf("Warning: Invalid config value has been entered.\n");
  }
  device->bits.version = value & 0x0F;
}
void reservedConfig(DeviceConfig *device, uint16_t value) {
  if (value > 0xFF) {
    printf("Warning: Invalid reserved value has been entered.\n");
  }
  device->bits.reserved = value & 0xFF;
}
