#include <stdio.h>
#include <time.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_timer.h"

#include "esp_bno055.h"

#define APP_STACK 16000
#define APP_TASK_PRIO 5

static void timer_callback(void *arg)
{
    // measure imu
    double quat[4];
    double vec[3];

    get_quat(quat);
    print_quat(quat);

    get_vector(VECTOR_GYROSCOPE, vec);
    print_vector(VECTOR_GYROSCOPE, vec);

    get_vector(VECTOR_ACCELEROMETER, vec);
    print_vector(VECTOR_ACCELEROMETER, vec);
}

void imu_task(void * arg)
{
    // initialize bno055
    esp_err_t err = bno055_begin_i2c(OPERATION_MODE_IMUPLUS);
    if (err != ESP_OK)
    {
        printf("ERROR: could not initiate 12c comunication\n");
    }

    set_external_crystal(true);

    // initialize timer
    const esp_timer_create_args_t my_timer_args = {
      .callback = &timer_callback,
      .name = "imu_timer"};

    esp_timer_handle_t timer_handler;
  
    ESP_ERROR_CHECK(esp_timer_create(&my_timer_args, &timer_handler));
    ESP_ERROR_CHECK(esp_timer_start_periodic(timer_handler, 1000));

    while(1)
    {
        esp_timer_dump(stdout);
        vTaskDelay(pdMS_TO_TICKS(1000));
    }
}

void app_main(void)
{
    xTaskCreate(imu_task, 
            "imu_task", 
            APP_STACK, 
            NULL, 
            APP_TASK_PRIO, 
            NULL);
}
