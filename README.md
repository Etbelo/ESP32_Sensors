# bno055-esp-component

This repository contains an esp-idf component for bno055 imu sensor using i2c communication. An easy to use docker workflow and example project is provided to show how to include the component into any other esp-idf project.

## Content

The included bno055 component is forked from [christianjc/ESP32_Sensors](https://github.com/christianjc/ESP32_Sensors) and was only sligthly modified. However, the original component library description remains unchanged:

This library provides an interface to the BNO055 sensor via the i2c communication protocol. BNO055 is a System in Package (SiP), integrating a triaxial 14-bit accelerometer, a triaxial 16-bit gyroscope with a range of ±2000 degrees per second, a triaxial geomagnetic sensor and a 32-bit cortex M0+ microcontroller running Bosch Sensortec sensor fusion software, in a single package.

Furthermore, a docker workflow for the example project was included to briefly and robustly verify the component in different esp-idf versions.

## Compatibility

This project was tested on the following hardware and software configurations

### Hardware

* Adafruit 9-DOF Absolute Orientation IMU Fusion Breakout - BNO055
* ESP32 Module WiFi Dev Kit C Development Board with CP2102

### Operating system

* Ubuntu 22.04: Native support
* Windows 11: Using [WSL2](https://ubuntu.com/tutorials/install-ubuntu-on-wsl2-on-windows-11-with-gui-support#1-overview) and [usbipd](https://github.com/dorssel/usbipd-win)

### ESP-IDF

* Releases: 5.0, 5.1

## Getting Started

### Install Prerequisites

* Install [docker engine](https://docs.docker.com/engine/install/)
* Install [make](https://www.gnu.org/software/make/)

### Usage

* Select ESP32 target in [Makefile](Makefile#L1)

* Select esp-idf version in [Makefile](Makefile#L3) by consulting available docker image tags at [hub.docker.com](https://hub.docker.com/r/espressif/idf/tags)

* Configure project: Menu component settings (I2C Pins, Frequency, Address) are available under `Component config`>`bno055_IMU`, Default settings are available in [Kconfig](components/bno055_IMU/Kconfig)

```
make config
```

* Build project

```
make build
```

* Flash firmware

```
make flash
```

* Clean workspace

```
make clean
```
## Further Work

This project is currently incorporated into a ROS2 and micro-ROS application using Raspberry Pi and ESP32.

## Contributing

Contributions are welcome! Whether you want to add more sensor libraries, improve existing ones, or fix bugs, your help is greatly appreciated. Please make sure to read the contributing guide before making a pull request.

## License

This project is licensed under the MIT License. See `LICENSE` file for more details.

## Contact

If you have any questions or run into any trouble, feel free to open an issue or contact the repository owner. You can typically expect a response within a couple of business days.

