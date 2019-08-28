// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // remember filenames
    int n = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    // check the 'n' factor so it is a positive integer
    if ((n >= 1) && (n <= 100))
    {
        // open input file
        FILE *inptr = fopen(infile, "r");
        if (inptr == NULL)
        {
            fprintf(stderr, "%s could not be opened for reading.\n", infile);
            return 2;
        }

        // open output file
        FILE *outptr = fopen(outfile, "w");
        if (outptr == NULL)
        {
            fclose(inptr);
            fprintf(stderr, "%s could not be opened for writing.\n", outfile);
            return 3;
        }

        // read infile's BITMAPFILEHEADER
        BITMAPFILEHEADER bf;
        fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

        // read infile's BITMAPINFOHEADER
        BITMAPINFOHEADER bi;
        fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

        // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
        if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
            bi.biBitCount != 24 || bi.biCompression != 0)
        {
            fclose(outptr);
            fclose(inptr);
            fprintf(stderr, "Unsupported file format.\n");
            return 4;
        }

        BITMAPINFOHEADER biOut = bi;
        BITMAPFILEHEADER bfOut = bf;

        biOut.biWidth = biOut.biWidth * n;
        biOut.biHeight = biOut.biHeight * n;

        // padding the resulting image
        int paddingOut = (4 - ((biOut.biWidth) * sizeof(RGBTRIPLE)) % 4) % 4;

        biOut.biSizeImage = ((sizeof(RGBTRIPLE) * biOut.biWidth) + paddingOut) * abs(biOut.biHeight);
        bfOut.bfSize = biOut.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

        // write outfile's BITMAPFILEHEADER
        fwrite(&bfOut, sizeof(BITMAPFILEHEADER), 1, outptr);

        // write outfile's BITMAPINFOHEADER
        fwrite(&biOut, sizeof(BITMAPINFOHEADER), 1, outptr);

        // determine padding for scanlines
        int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

        RGBTRIPLE *scanline = malloc(sizeof(RGBTRIPLE) * biOut.biWidth);

        // iterate over infile's scanlines
        for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
        {

            // iterate over pixels in scanline
            for (int j = 0, biWidth = bi.biWidth; j < biWidth; j++)
            {

                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                // multiply each pixel 'n' times horizontally
                for (int m = 0; m < n; m++)
                {
                    scanline[m + (j * n)] = triple;

                }
            }

            for (int m = 0; m < n; m++)
            {
                // write RGB triple to outfile
                fwrite(scanline, sizeof(RGBTRIPLE), biOut.biWidth, outptr);

                for (int k = 0; k < paddingOut; k++)
                {
                    fputc(0x00, outptr);
                }
            }


            // skip over padding, if any
            fseek(inptr, padding, SEEK_CUR);

            //free(scanline);
        }

        // close infile
        fclose(inptr);

        // close outfile
        fclose(outptr);

        // success
        return 0;
    }

    else
    {
        fprintf(stderr, "%i must be a positive integer lower or equal to 100.\n", n);
        return 1;
    }
}
