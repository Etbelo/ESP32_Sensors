TARGET=esp32

DOCKER_IMG=espressif/idf:release-v5.0

DOCKER_CMD=docker run -it --rm --name esp_idf \
			-v /dev:/dev --privileged \
			-v ${shell pwd}:/bno055_imu \
			--workdir /bno055_imu \
			$(DOCKER_IMG)

.PHONY: all config build flash clean

all: config build flash clean

config:
	$(DOCKER_CMD) /bin/bash -c "idf.py set-target $(TARGET);idf.py menuconfig"

build:
	$(DOCKER_CMD) /bin/bash -c "idf.py build"

flash:
	$(DOCKER_CMD) /bin/bash -c "idf.py flash"
	
clean:
	$(DOCKER_CMD) /bin/bash -c "idf.py clean;rm -rf build sdkconfig.old"
