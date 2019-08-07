#include <stdio.h>
#include "noise_suppression.h"
#include "noise_suppression_x.h"

#define FRAMESIZE 80
int main(int argc, char** argv)
{
    printf("function exec ...");
    FILE *fpinput, *fpoutput;
    int samples = 8000;
    int status;
    NsHandle *nsHandle;
    short audioframe[FRAMESIZE];
    short outframe[FRAMESIZE];
    
    status = WebRtcNs_Create(&nsHandle);
    if (status != 0)
    {
        printf("Create Failure\n");
        return -1;
    }
    
    status = WebRtcNs_Init(nsHandle, samples);
    if (status != 0)
    {
        printf("Init Failure\n");
        return -1;
    }
    status = WebRtcNs_set_policy(nsHandle, 2);
    if (status != 0)
    {
        printf("set_policy Failure\n");
        return -1;
    }
    char *inpath = argv[1];
    char *outpath = argv[2];
    fpinput = fopen(inpath, "rb");
    fpoutput = fopen(outpath, "wb");
    while (!feof(fpinput))
    {
        fread(audioframe, sizeof(short), FRAMESIZE, fpinput);
        status = WebRtcNs_Process(nsHandle, audioframe, NULL, outframe, NULL);
        if (status != 0)
        {
            printf("WebRtcNs_Process Failure\n");
            return -1;
        }
        printf("#");
        fwrite(outframe, sizeof(short), FRAMESIZE, fpoutput);
    }
    
    fclose(fpinput);
    fclose(fpoutput);
    status = WebRtcNs_Free(nsHandle);
    if (status != 0)
    {
        printf("WebRtcNs_Free Failure\n");
        return -1;
    }
    printf("done! \n");
    return 0;
}

