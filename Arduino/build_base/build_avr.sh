#!/bin/bash
echo "Enter Arduino.app Base Location if its not on You mac book pro Desktop"
read -s base
echo $base
if [[ $base -eq "" ]]
then
	base=~/Desktop/Arduino.app/Contents/Java/hardware/tools/avr/bin	 
fi 
$base/avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -MMD -flto -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10807 -DARDUINO_AVR_DUEMILANOVE -DARDUINO_ARCH_AVR -I. -gstabs -Os -Wall $1 -o $1.o 
$base/avr-gcc -w -Os -g -flto -fuse-linker-plugin -Wl,--gc-sections -mmcu=atmega328p -o $1.elf $1.o ./compiled/core/core.a -L./compiled  -lm
$base/avr-objcopy -O ihex -R .eeprom $1.elf $1.hex
if [[ $? -eq 0 ]]
then 
	$base/avrdude -C ./avrdude.conf -F -V -c arduino -p ATMEGA328 -P /dev/cu.wchusbserial1410 -b 57600 -U flash:w:$1.hex:i	
fi 
