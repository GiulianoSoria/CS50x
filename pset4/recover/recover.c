#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    //We check if two command-line arguments were written
    if (argc == 2)
    {
        char *infile = argv[1];
        FILE *inptr = fopen(infile, "r");

        //We check if the input file is corrupted or empty
        if (inptr == NULL)
        {
            fprintf(stderr, "%s file could not be opened for reading\n", infile);
            return 2;
        }

        else
        {
            unsigned char buffer[512];
            char *filename = malloc(8 * sizeof(char));
            int filecount = 0;
            FILE *image = fopen(filename, "w");

            //We check 512 bytes at a time, if its size is smaller, it will finish reading.
            while (fread(buffer, sizeof(buffer), 1, inptr) == 1)
            {
                //We check if the first four bytes are the ones from a JPEG file.
                if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
                {
                    //We check if a file has been previously opened, if so, we close it.
                    if (filecount > 0)
                    {
                        fclose(image);
                    }
                    //We create a new file so we can start writing in it the block of 512 bytes.
                    sprintf(filename, "%03i.jpg", filecount);
                    filecount++;
                    image = fopen(filename, "w");
                }

                //We check if the previous block belongs to a JPEG file, if so, we continue writing in the output file.
                if (filecount > 0)
                {
                    fwrite(&buffer, sizeof(buffer), 1, image);
                }
            }
            fclose(inptr);
            fclose(image);
        }
    }

    else
    {
        fprintf(stderr, "Usage: ./recover filename\n");
        return 1;
    }
}