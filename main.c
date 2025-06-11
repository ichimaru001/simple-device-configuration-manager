// TITLE          :       SIMPLE DEVICE CONFIGURATION MANAGER
// AUTHOR         :       ichimaru001       
// DATE                   11/06/25
// -
// DESCRIPTION    :       SIMULATES WRITING FIRMWARE FOR A TINY DEVICE
//                        WHICH HAS A CONFIGURATION REGISTER. 
//                        PRACTICE USING BITFIELDS AND ".c" AND ".h" FILES.          
// -
// TIME TAKEN     :       (started at 2HR 36MIN)
// TO COMPLETE


#include <stdio.h>
#include <stdint.h>


int main() {
  printf("\n*** SIMPLE DEVICE CONFIGURATION MANAGER ***\n");

  typedef struct {
    uint16_t powerOn : 1;
    uint16_t mode : 2;
    uint16_t error : 1;
    uint16_t reserved : 8;
    uint16_t version : 4;
  } DeviceBits;

  typedef union {
    uint16_t rawValue;
    DeviceBits bits;
  } DeviceConfig;

  DeviceConfig sampleDevice;

  // ** INITIALIZING THE DEVICE
  sampleDevice.rawValue = 0;

  // ** SETTING STATES OF DEVICE
  sampleDevice.bits.powerOn = 0x01; // on
  sampleDevice.bits.mode = 0x03; // value = 3
  sampleDevice.bits.error = 0x00; // no error occurred 
  sampleDevice.bits.version = 0x0C; // version = 12

  // ** PRINTING CONFIGS
  printf("Hex format of status: %04X\n", sampleDevice.rawValue);
  printf("\nPower On : %s\nMode : %u\nError : %u\nVersion : %u\n", (sampleDevice.bits.powerOn) == 0x01 ? "ON" : "OFF", sampleDevice.bits.mode, sampleDevice.bits.error, sampleDevice.bits.version);

  printf("\nSuccessfully loaded the configuration of the device!\n");

  return 0;
}