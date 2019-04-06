#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include <errno.h>
#include <linux/input.h>  

int main(int argc, char **argv)
{
    FILE *fp;
    int status = 0;
    char temp1_input[128];

    fp = fopen("/sys/class/hwmon/hwmon1/temp1_input", "r");
    if (fp == NULL) {
        printf("%d: fopen error\n", __LINE__);
        return -1;
    }

    while (1) {
        memset(temp1_input, 0x00, 128);
        status = fseek(fp, 0, SEEK_SET);
        if (status < 0) {
            printf("%d: fseek error\n", __LINE__);
            return -1;
        }
        status = fread(temp1_input, sizeof(temp1_input), 1, fp);
        if (status < 0) {
            printf("%d: fread error\n", __LINE__);
            return -1;
        }
        float temperature = 0;
        temperature = atoll(temp1_input);
        temperature = temperature/1000;
        printf("temperature %f\n", temperature);
        sleep(10);
    }

    fclose(fp);

    return status;
}
