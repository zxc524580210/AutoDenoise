#include <iostream>
#include <zconf.h>
char command[256];
char command1[256];
int main(int argc, char * argv[]) {
    int rtn;
    printf(">> \n");
    char *ffmpegPath = "./ffmpeg";
    char *videoDenoisePath = "./AudioDenoise";
    int length = strlen(ffmpegPath);
    int length1 = strlen(videoDenoisePath);
    memcpy(command,ffmpegPath,length);
    memcpy(command1,videoDenoisePath,length1);
    char *srcPath = argv[1];
    std::string srcP(srcPath);
    std::string dstP = srcP.substr(0,strlen(srcPath)-4) + "_.mp4";
    std::cout<<dstP<<std::endl;
    if(fork()==0)
    {
        execlp(command,"","-i",srcPath,"-vcodec","copy","-bsf","h264_mp4toannexb","-f","h264","./12.h264",NULL);
        perror(command);
        exit(errno);
    }
    else
    {
        wait(&rtn);
        printf("child process return %d\n", rtn);
    }
    if(fork()==0)
    {
        execlp(command,"","-i",srcPath,"-acodec","pcm_s16le_planar","-ar","32000","-ac","1","-f","s16le","./12.pcm",NULL);
        perror(command);
        exit(errno);
    }
    else
    {
        wait(&rtn);
        printf("child process return %d\n", rtn);
    }
    if(fork()==0)
    {
        execlp(command1,"","./12.pcm","./13.pcm",NULL);
        perror(command1);
        exit(errno);
    }
    else
    {
        wait(&rtn);
        printf("child process return %d\n", rtn);
    }
    if(fork()==0)
    {
        execlp(command,"","-f","s16le","-ar","32000","-ac","1","-i","./13.pcm","-i","./12.h264","-vcodec","copy","-f","mp4",dstP.c_str(),NULL);
        perror(command);
        exit(errno);
    }
    else
    {
        wait(&rtn);
        printf("child process return %d\n", rtn);
    }
    FILE *fstream = NULL ;
    char buffer[1024];
    int found = -1;
    memset(buffer,0, sizeof(buffer));
    sprintf(buffer,"rm ./12.pcm ./12.h264 ./13.pcm",NULL);
    if(NULL == (fstream = popen(buffer,"r"))){
        return -1;
    }
    fgets(buffer, sizeof(buffer),fstream);
    pclose(fstream);
    return 0;
}
