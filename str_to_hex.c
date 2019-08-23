#include <stdio.h>
#include <errno.h>
#include <stdlib.h>


int main(int argc, char **argv)
{
    if(argc < 3)
    {
        printf(" Usage: str_to_hex file hexfile\n");
        printf(" Convert files into hex file.\n");
        exit(EXIT_FAILURE);
    }
     FILE *strfile_fp;
     strfile_fp = fopen(argv[1], "r");
     if(NULL == strfile_fp)
     {
         printf("fopen %s ERROR:%m\n",argv[1],errno);
         return -1;
     }
    
     FILE *hexfile_fp;
     hexfile_fp = fopen(argv[2], "w+");
     if(NULL == hexfile_fp)
     {
         printf("fopen %s ERROR:%m\n",argv[2],errno);
         return -1;
     }
    
     size_t r_len = 0;
     unsigned char tmp_buf = 0;
     do{
         r_len = fread(&tmp_buf, 1, 1, strfile_fp);
    }while(r_len > 0 && fprintf(hexfile_fp, "%02X", tmp_buf));
    fclose(hexfile_fp);
    fclose(strfile_fp);
    return 0;
}

