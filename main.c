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
#include "device_config.h"


int main() {
  printf("\n*** SIMPLE DEVICE CONFIGURATION MANAGER ***\n");

  DeviceConfig sampleDevice;

  // ** INITIALIZING THE DEVICE
  initConfig(&sampleDevice);

  // ** SETTING STATES OF DEVICE
  powerOnOffConfig(&sampleDevice, 0x01);    // on
  modeConfig(&sampleDevice, 0x03);          // value = 3
  errorConfig(&sampleDevice, 0x00);         // no error occurred
  versionConfig(&sampleDevice, 0x0C);       // no error occurred 

  // ** PRINTING CONFIGS
  printConfig(&sampleDevice);

  printf("\nSuccessfully loaded the configuration of the device!\n");

  return 0;
}