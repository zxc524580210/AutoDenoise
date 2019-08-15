#include <stdio.h>
#include "noise_suppression.h"
#include "noise_suppression_x.h"
#include "gain_control.h"
#include "external_resampler.h"
#include "signal_processing_library.h"
#include<stdlib.h>
#define FRAMESIZE 320

void AgNSProcess16(char * inpath, char  * outpath){
    
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
    int fs = 32000;
    short agc_audioFrame[FRAMESIZE];
    short agc_outFrame[FRAMESIZE];
    int inMicLevel = 0;
    int outMicLevel = 0;
    WebRtcAgc_config_t config;
    uint8_t saturationWarning = 0;
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
void AgNSProcess32(char *inpath,char *outPath){
    int nRet = 0;
    NsHandle *pNS_inst = NULL;

    FILE *fpIn = NULL;
    FILE *fpOut = NULL;

    char *pInBuffer =NULL;
    char *pOutBuffer = NULL;

    do
    {
        int i = 0;
        int nFileSize = 0;
        int nTime = 0;
        if (0 != WebRtcNs_Create(&pNS_inst))
        {
            printf("Noise_Suppression WebRtcNs_Create err! \n");
            break;
        }

        if (0 !=  WebRtcNs_Init(pNS_inst,32000))
        {
            printf("Noise_Suppression WebRtcNs_Init err! \n");
            break;
        }
        if (0 !=  WebRtcNs_set_policy(pNS_inst,2))
        {
            printf("Noise_Suppression WebRtcNs_set_policy err! \n");
            break;
        }
        fpIn = fopen(inpath, "rb");
        if (NULL == fpIn)
        {
            printf("open src file err \n");
            break;
        }
        fseek(fpIn,0,SEEK_END);
        nFileSize = ftell(fpIn);
        fseek(fpIn,0,SEEK_SET);

        pInBuffer = (char*)malloc(nFileSize);
        memset(pInBuffer,0,nFileSize);
        fread(pInBuffer, sizeof(char), nFileSize, fpIn);

        pOutBuffer = (char*)malloc(nFileSize);
        memset(pOutBuffer,0,nFileSize);

        int  filter_state1[6],filter_state12[6];
        int  Synthesis_state1[6],Synthesis_state12[6];

        memset(filter_state1,0,sizeof(filter_state1));
        memset(filter_state12,0,sizeof(filter_state12));
        memset(Synthesis_state1,0,sizeof(Synthesis_state1));
        memset(Synthesis_state12,0,sizeof(Synthesis_state12));

        for (i = 0;i < nFileSize;i+=640)
        {
            if (nFileSize - i >= 640)
            {
                short shBufferIn[320] = {0};

                short shInL[160],shInH[160];
                short shOutL[160] = {0},shOutH[160] = {0};

                memcpy(shBufferIn,(char*)(pInBuffer+i),320*sizeof(short));
                WebRtcSpl_AnalysisQMF(shBufferIn,320,shInL,shInH,filter_state1,filter_state12);
                printf("**");
                if (0 == WebRtcNs_Process(pNS_inst ,shInL  ,shInH ,shOutL , shOutH))
                {
                    short shBufferOut[320];
                    WebRtcSpl_SynthesisQMF(shOutL,shOutH,160,shBufferOut,Synthesis_state1,Synthesis_state12);
                    memcpy(pOutBuffer+i,shBufferOut,320*sizeof(short));
                }
            }
        }
        fpOut = fopen(outPath, "wb");
        if (NULL == fpOut)
        {
            printf("open out file err! \n");
            break;
        }
        fwrite(pOutBuffer, sizeof(char), nFileSize, fpOut);
    } while (0);

    WebRtcNs_Free(pNS_inst);
    fclose(fpIn);
    fclose(fpOut);
    free(pInBuffer);
    free(pOutBuffer);

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
    AgNSProcess32(argv[1],argv[2]);
    AgNSProcess32(argv[2],argv[1]);
    printf("Fininsh !");
    return 0;
}

