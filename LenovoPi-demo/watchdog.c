#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <linux/types.h>
#include <linux/watchdog.h>

int main(int argc, const char *argv[])
{
    int watchdog_fd = 0;
    int status = 0;

    watchdog_fd = open("/dev/watchdog", O_RDWR);
    if (watchdog_fd < 0) {
        printf("%d: open error\n", __LINE__);
        return -1;
    }

    int timeout = 5;
    status = ioctl(watchdog_fd, WDIOC_SETTIMEOUT, &timeout);
    if (status < 0) {
        printf("%d: ioctl error\n", __LINE__);
        return -1;
    }

    int flag = WDIOS_ENABLECARD;
    status = ioctl(watchdog_fd, WDIOC_SETOPTIONS, &flag);
    if (status < 0) {
        printf("%d: ioctl error\n", __LINE__);
        return -1;
    }

    int number = 0;
    while (1) {
        status = ioctl(watchdog_fd, WDIOC_KEEPALIVE, 0);
        if (status < 0) {
            printf("%d: ioctl error\n", __LINE__);
            return -1;
        }

        number ++;
        printf("number is %d\n", number);
        printf("watchdog keep alive\n");
        if (number == 10)
            sleep(6);
        else
            sleep(1);
    }

    close(watchdog_fd);
    return 0;
}
