# BNO055-IMU

This idf-component provides a C Interface for Bosch-Sensortec's BNO055 compatible with Espressif's ESP32 (running esp-idf).
This code allows the esp32 to read vector measurements from the bon055 IMU sensor. If there are any questions or need further functionality
please feel free message me.

NOTE: this code is not production ready yet.

# Supported Interfaces

I²C - fully supported

## I2C Wiring

Wiring must be appropriately changed based on configured settings in [Kconfig](Kconfig)

* ADR -> logic HIGH (3v0) enables bno055 default address (0x29), logic LOW enables alternative address (0x28)

* SCL -> SCL (Default: GPIO_NUM_22)

* SDA -> SDA (Default: GPIO_NUM_21)
