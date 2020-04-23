#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

#define BUFFER_SIZE 512
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    /* Checking whether the program has passed just one argument*/
    if (argc != 2)
    {
        printf("Usage: %s image\n", argv[0]);
        return 1;
    }

    FILE *fp;

    /* Checking can the program open the first argument as a readonly file */
    if ((fp = fopen(argv[1], "r")) == NULL)
    {
        printf("Error: Unable to open %s\n", argv[1]);
        return 1;
    }

    BYTE buffer[BUFFER_SIZE];
    
    int fileCount = 0;
    char filename[8];
    int open = 0;

    FILE *pout;

    /* Reading the input file in a chunk of 512 bytes */
    while (fread(buffer, BUFFER_SIZE, 1, fp) > 0)
    {
        /* Checking whether first 4 bytes of 512 bytes have Jpeg header or not */
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xe0) == 0xe0)
        {
            /* If file already open, close it */
            if (open == 1)
            {
                fclose(pout);
                open = 0;
            }
            sprintf(filename, "%03d.jpg", fileCount);
            if ((pout = fopen(filename, "w")) == NULL)
            {
                printf("Error: Unable to open %s\n", filename);
                exit(1);
            }
            /* Write jpeg data to jpg file */
            fwrite(buffer, sizeof(buffer), 1, pout);
            fileCount++;
            open = 1;
        }
        else
        {
            if (open == 1)
            {
                fwrite(buffer, sizeof(buffer), 1, pout);
            }
        }        
    }
    fclose(pout);
    fclose(fp);
}
