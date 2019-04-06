#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <CL/cl.h>

int main(void)
{
    char strings[512];
    cl_uint num_platform;
    cl_platform_id platform_id[20];
    cl_uint num_device;
    cl_device_id device_id[20];
    cl_device_type device_type;
    cl_ulong tmp;

    clGetPlatformIDs(0, NULL, &num_platform);
    clGetPlatformIDs(num_platform, platform_id, NULL);

    for (int i = 0; i < num_platform; i ++) {
        
        clGetPlatformInfo(platform_id[i], CL_PLATFORM_NAME, 512, strings, NULL);
        printf("platform name [%s]\n", strings);
        
        clGetPlatformInfo(platform_id[i], CL_PLATFORM_VENDOR, 512, strings, NULL);
        printf("platform vendor [%s]\n", strings);
        
        clGetPlatformInfo(platform_id[i], CL_PLATFORM_VERSION, 512, strings, NULL);
        printf("platform version [%s]\n", strings);
        
        clGetPlatformInfo(platform_id[i], CL_PLATFORM_PROFILE, 512, strings, NULL);
        printf("platform profile [%s]\n", strings);
        
        clGetDeviceIDs(platform_id[i], CL_DEVICE_TYPE_ALL, 20, device_id, &num_device);
        for (int j = 0; j < num_device; j ++) {
            clGetDeviceInfo(device_id[j], CL_DEVICE_TYPE, sizeof(cl_device_type), 
                            &device_type, NULL);
            if (device_type == CL_DEVICE_TYPE_CPU)
                printf("device type [cpu]\n");
            else if (device_type == CL_DEVICE_TYPE_GPU)
                printf("device type [gpu]\n");
            else if (device_type == CL_DEVICE_TYPE_ACCELERATOR)
                printf("device type [accelerator]\n");
            
            clGetDeviceInfo(device_id[j], CL_DEVICE_NAME, 512, strings, NULL);
            printf("device name [%s]\n", strings);
            
            clGetDeviceInfo(device_id[j], CL_DEVICE_GLOBAL_MEM_SIZE,
                            sizeof(cl_ulong), &tmp, NULL);
            printf("device global mem [%lld]MB\n", tmp/1024/1024);
            
            clGetDeviceInfo(device_id[j], CL_DEVICE_GLOBAL_MEM_CACHE_SIZE,
                            sizeof(cl_ulong), &tmp, NULL);
            printf("device global mem cache [%lld]KB\n", tmp/1024);
            
            clGetDeviceInfo(device_id[j], CL_DEVICE_LOCAL_MEM_SIZE,
                            sizeof(cl_ulong), &tmp, NULL);
            printf("device local mem [%lld]KB\n", tmp/1024);
            
            clGetDeviceInfo(device_id[j], CL_DEVICE_MAX_MEM_ALLOC_SIZE,
                            sizeof(cl_ulong), &tmp, NULL);
            printf("device max mem alloc [%lld]MB\n", tmp/1024/1024);
            
            clGetDeviceInfo(device_id[j], CL_DEVICE_MAX_CLOCK_FREQUENCY,
                            sizeof(cl_ulong), &tmp, NULL);
            printf("device max clock frequency [%lld]MHZ\n", tmp);
            
            clGetDeviceInfo(device_id[j], CL_DEVICE_MAX_COMPUTE_UNITS,
                            sizeof(cl_ulong), &tmp, NULL);
            printf("device max compute unit [%lld]\n", tmp);
        }
    }

    return 0;
}
