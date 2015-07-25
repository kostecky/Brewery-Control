ARDMK_DIR     = ../Arduino-Makefile
BOARD_TAG     = uno

ifeq ($(CURRENT_OS),LINUX)
	MONITOR_PORT = /dev/ttyACM0
else
	MONITOR_PORT = /dev/tty.usbmodem1411
endif

include $(ARDMK_DIR)/Arduino.mk
