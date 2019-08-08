#include <stdio.h>
#include "noise_suppression.h"
#include "noise_suppression_x.h"
#include "gain_control.h"
#include "external_resampler.h"
#include<stdlib.h>
#define FRAMESIZE 160

void AgNSProcess(char * inpath, char  * outpath){
    
    //ANS solve
    FILE *fpinput, *fpoutput;
    int samples = 16000;
    int status;
    NsHandle *nsHandle;
    short audioframe[FRAMESIZE];
    short outframe[FRAMESIZE];
    
    status = WebRtcNs_Create(&nsHandle);
    if (status != 0)
    {
        printf("Create Failure\n");
        return;
    }
    
    status = WebRtcNs_Init(nsHandle, samples);
    if (status != 0)
    {
        printf("Init Failure\n");
        return;
    }
    status = WebRtcNs_set_policy(nsHandle, 2);
    if (status != 0)
    {
        printf("set_policy Failure\n");
        return;
    }
    fpinput = fopen(inpath, "rb");
    fpoutput = fopen(outpath, "wb");
    while (!feof(fpinput))
    {
        fread(audioframe, sizeof(short), FRAMESIZE, fpinput);
        status = WebRtcNs_Process(nsHandle, audioframe, NULL, outframe, NULL);
        if (status != 0)
        {
            printf("WebRtcNs_Process Failure\n");
            return;
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
        return;
    }
    printf("AgNS done! \n");

}
// AGC solve
void AgAGCProcess(char * inpath,char * outpath){
    
    FILE *fApInput,*fAOutput;
    void *Agchandle;
    int status;
    int maxLevel = 255;
    int minLevel = 0;
    int fs = 16000;
    short agc_audioFrame[FRAMESIZE];
    short agc_outFrame[FRAMESIZE];
    int inMicLevel = 0;
    int outMicLevel = 0;
    WebRtcAgc_config_t config;
    WebRtc_UWord8 saturationWarning = 0;
    config.compressionGaindB = 9;
    config.limiterEnable = kAgcTrue;
    config.targetLevelDbfs = 9;
    status = WebRtcAgc_Create(&Agchandle);
    if (status != 0) {
        printf("Create Failure\n");
        return;
    }
    status = WebRtcAgc_Init(Agchandle, minLevel, maxLevel, kAgcModeAdaptiveDigital, fs);
    if (status != 0) {
        printf("Init Failure\n");
        return;
    }
    status = WebRtcAgc_set_config(Agchandle, config);
    if (status != 0) {
        printf("Set_config Failure");
        return ;
    }
    fApInput = fopen(outpath, "rb");
    fAOutput = fopen(inpath, "wb");
    while (!feof(fApInput)) {
        fread(agc_audioFrame,sizeof(short),FRAMESIZE,fApInput);
        status = WebRtcAgc_Process(Agchandle,agc_audioFrame,NULL,FRAMESIZE,agc_outFrame,NULL,inMicLevel,&outMicLevel,1,&saturationWarning);
        if (status != 0) {
            printf("WebRtcAgc_Process is error\n");
            return;
        }
        printf("//");
        fwrite(agc_outFrame,sizeof(short),FRAMESIZE,fAOutput);
    }
    fclose(fApInput);
    fclose(fAOutput);
    status = WebRtcAgc_Free(Agchandle);
    if (status != 0 ) {
        printf("WebRtcAgc_Free Failure\n");
        return ;
    }
    printf("AGC Finish!\n");
    
}
void AgResampler(char * inpath,char * outpath){
    external_resampler * doResampler = new external_resampler();
    FILE *fApInput,*fAOutput;
    fApInput = fopen(inpath, "rb");
    fAOutput = fopen(outpath, "wb");
    int status;
    int srcSize = 160  ;
    int dstSize = 320  ;
    int src_samplerate = 16000;
    int dst_samplerate = 32000;
    short audioframe[srcSize];
    short outframe[dstSize];
    while (!feof(fApInput)) {
        fread(audioframe, sizeof(short), srcSize, fApInput);
        status = doResampler->do_resample(audioframe,src_samplerate * 0.01,1,src_samplerate,outframe,dst_samplerate * 0.01,1,dst_samplerate);
        printf("=");
        fwrite(outframe,sizeof(short),dstSize,fAOutput);
    }
    fclose(fApInput);
    fclose(fAOutput);

    delete doResampler;
}
int main(int argc, char** argv)
{
    AgNSProcess(argv[1],argv[2]);
    AgAGCProcess(argv[2],argv[1]);
    AgNSProcess(argv[1],argv[2]);
    AgResampler(argv[2],argv[1]);
    printf("Fininsh !");
    return 0;
}

