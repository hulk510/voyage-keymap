FROM debian:latest

RUN apt update && apt install -y git python3 python3-pip sudo \
    gcc-arm-none-eabi binutils-arm-none-eabi libnewlib-arm-none-eabi \
    gcc-avr avr-libc avrdude \
    dfu-programmer dfu-util dos2unix make

RUN python3 -m pip install qmk appdirs --break-system-packages

WORKDIR /root
