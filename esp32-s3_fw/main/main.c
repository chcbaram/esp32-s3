#include "main.h"






void app_main(void)
{
  printf("ESP32-S3 !\n");

  /* Print chip information */
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);
  printf("This is %s chip with %d CPU core(s), WiFi%s%s, ",
          CONFIG_IDF_TARGET,
          chip_info.cores,
          (chip_info.features & CHIP_FEATURE_BT) ? "/BT" : "",
          (chip_info.features & CHIP_FEATURE_BLE) ? "/BLE" : "");

  printf("silicon revision %d\n", chip_info.revision);

  printf("SPI FLASH : %uMB %s flash\n", spi_flash_get_chip_size() / (1024 * 1024),
          (chip_info.features & CHIP_FEATURE_EMB_FLASH) ? "embedded" : "external");
  printf("SPI PSRAM : %dMB\n", esp_psram_get_size()/1024/1024);

  printf("Free heap : %d KB\n", esp_get_free_heap_size()/1024);
  printf("CPU Freq  : %d Mhz\n", bspGetCpuFreqMhz());
  delay(50);

  hwInit();
  apInit();
  apMain();
}
