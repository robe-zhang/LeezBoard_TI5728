#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <CL/cl.h>
  
#define dim_x 4
#define dim_y 4
  
int get_ocl_string(const char *file_name, char *ocl_string)
{
    FILE *fp;
    int file_length;
    int status = 0;
    
    fp = fopen(file_name, "r");
    if (fp == NULL)
        return -1;
    
    fseek(fp, 0, SEEK_END);
    file_length = ftell(fp);
    fseek(fp, 0, SEEK_SET);
    
    status = fread(ocl_string, 1, file_length, fp);
    if (status == -1)
        return -1;

    return file_length;
}

int main()
{
    cl_device_id device;
    cl_platform_id platform_id = NULL;
    cl_context context;
    cl_command_queue cmdQueue;
    cl_mem bufferA,bufferB;
    cl_program program;
    cl_kernel kernel = NULL;
    
    size_t ocl_string_size;
    char *ocl_string;

    ocl_string = (char *)malloc(1024*1024);

    size_t globalWorkSize[2];
    globalWorkSize[0] = dim_x ;
    globalWorkSize[1] = dim_y;
  
  
    int buf_A[dim_x][dim_y];
    int buf_B[dim_x][dim_y];
  
    size_t datasize = sizeof(int) * dim_x * dim_y;
  
    int n=0;
    int m=0;
  
    for(n=0;n<dim_x;n++)
    {
        for(m=0;m<dim_y;m++)
        {
            buf_A[m][n] = m + n*dim_x;
        }
    }
  
    ocl_string_size = get_ocl_string("matrix_transposition.cl", ocl_string);
    clGetPlatformIDs(1, &platform_id, NULL);
    clGetDeviceIDs(platform_id, CL_DEVICE_TYPE_ACCELERATOR, 1, &device, NULL);
  
    context = clCreateContext(NULL,1,&device,NULL,NULL,NULL);
    cmdQueue = clCreateCommandQueue(context,device,0,NULL);

    bufferA = clCreateBuffer(context,
                             CL_MEM_READ_ONLY,
                             datasize,NULL,NULL);
  
    bufferB = clCreateBuffer(context,
                             CL_MEM_WRITE_ONLY,
                             datasize,NULL,NULL);
  
    clEnqueueWriteBuffer(cmdQueue,
                         bufferA,CL_FALSE,
                         0,datasize,
                         buf_A,0,
                         NULL,NULL);
  
    program = clCreateProgramWithSource(context,1,
                                        (const char**)&ocl_string,
                                        &ocl_string_size,NULL);
  
    clBuildProgram(program,1,&device,NULL,NULL,NULL);
  
    kernel = clCreateKernel(program,"matrix_transposition",NULL);
  
    clSetKernelArg(kernel,0,sizeof(cl_mem),&bufferA);
    clSetKernelArg(kernel,1,sizeof(cl_mem),&bufferB);
  
    clEnqueueNDRangeKernel(cmdQueue,kernel,
                           2,NULL,
                           globalWorkSize,
                           NULL,0,NULL,NULL);
  
    clEnqueueReadBuffer(cmdQueue,bufferB,CL_TRUE,0,
                        datasize,buf_B,0,NULL,NULL);
  
    for(n=0;n<dim_x;n++)
    {
        for(m=0;m<dim_y;m++)
        {
            printf("%d ", buf_A[m][n]);
        }
        printf("\n");
    }
  
  
    for(n=0;n<dim_x;n++)
    {
        for(m=0;m<dim_y;m++)
        {
            printf("%d ", buf_B[m][n]);
        }
        printf("\n");
    }
  
    clReleaseKernel(kernel);
    clReleaseProgram(program);
    clReleaseCommandQueue(cmdQueue);
    clReleaseMemObject(bufferA);
    clReleaseMemObject(bufferB);
    clReleaseContext(context);

    return 0;
}
