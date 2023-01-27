extern "C" {
  #include <FreeRTOS.h>   //  For portTICK_PERIOD_MS
  #include <task.h>       //  For vTaskDelay
}

void delay(uint32_t ms) {
  vTaskDelay(ms / portTICK_PERIOD_MS);
}