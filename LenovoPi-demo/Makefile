CC = arm-linux-gnueabihf-gcc
CXX = arm-linux-gnueabihf-g++
EXE1 = v4l2_capture
EXE2 = watchdog
EXE3 = temperature
CFLAGS = -O3 -Wall
CFLAGS += -Wl,-rpath-link,../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/usr/lib \
		  -Wl,-rpath-link,../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/lib \
		  -Wl,-rpath-link,../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/usr/lib/gstreamer-1.0 \
		  -I../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/usr/include \
		  -I../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/usr/include/gstreamer-1.0 \
		  -I../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/usr/include/libxml2 \
		  -I../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/usr/include/glib-2.0 \
		  -I../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/usr/lib/glib-2.0/include \
		  -I../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/usr/lib/gstreamer-1.0/include \
		  -L../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/usr/lib \
		  -L../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/lib \
		  -L../../linux-devkit/sysroots/armv7ahf-neon-linux-gnueabi/usr/lib/gstreamer-1.0
CFLAGS += -lopencv_core -lopencv_highgui -lopencv_videoio -lopencv_imgproc -lopencv_imgcodecs -lopencv_video
CFLAGS += -lgstreamer-1.0 -lgobject-2.0 -lgmodule-2.0 -lgthread-2.0 -lglib-2.0 -lxml2
CFLAGS += -lOpenCL -locl_util
CFLAGS += -lpthread -lasound -lrt

all:
	@$(CC) -o $(EXE1) $(EXE1).c $(CFLAGS)
	@$(CC) -o $(EXE2) $(EXE2).c $(CFLAGS)
	@$(CC) -o $(EXE3) $(EXE3).c $(CFLAGS)

clean:
	rm -rf $(EXE1) $(EXE2) $(EXE3) *.o
