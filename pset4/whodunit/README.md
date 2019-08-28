# Questions

## What's `stdint.h`?

It is a library that allows to write code by giving typedefs that limit biggest and smallest values allowed for each type of integer.

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

The use of each one depends on the type of bmp file that is used.
'uint8_t' can be when the bmp file has two colors.
'uint16_t' can be used when the bmp file has pow(2,16) colors.
'uint32_t' and 'int32t' can be used when the bmp file has pow(2,32) colors.


## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

Type  | Description
------|-------------
BYTE  | A BYTE is 8-bit unsigned value, or 1 byte.
DWORD | A DWORD is a 32-bit unsigned integer, or 8 bytes.
LONG  | A LONG is a 32-bit signed integer, or 8 bytes.
WORD  | A WORD is a 16-bit unsigned integer, or 4 bytes.

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

The first two bytes of a BMP file are '0x424d' which stands for 'BM' (in ASCII). That gives us the information that the file format.

## What's the difference between `bfSize` and `biSize`?

bfSize: It is the size of the bitmap file, in bytes, which includes the headers and the image per se.
biSize: It is the number of bytes required by the structure BITMAPINFOHEADER.

## What does it mean if `biHeight` is negative?

biHeight: It is the height of the bitmap, in pixels.
If its value is negative, the bitmap is structured from the top-down, starting in the upper-left hand corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

biBitCount: It determines the number of bits of each pixel and the maximum amount of colors in the bitmap.
It must be one of the following values:

Value | Meaning
----- | -------
0     | The number of bits-per-pixel in implied by the format (JPEG or PNG).
1     | The bitmap is monochrome, and the bmiColors member contains the two colors entries.
4     | The bitmap has a maximum of 16 colors. bmiColors has 16 entries.
8     | The bitmap has a maximum of 256 colors. bmiColors has 256 entries.
16    | The bitmap has a maximum of pow(2,16) colors. If bmiCompression is BG_RGB, bmiColors is NULL.
24    | The bitmap has a maximum of pow(2,24) colors. bmiColors is NULL.
32    | The bitmap has a maximum of pow(2,32) colors. If bmiCompression is BI_RGB, bmiColors is NULL

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

Becuase there was an error, either when opening the input file so it could be read, or when opening the output file so it could be written.

## Why is the third argument to `fread` always `1` in our code?

Because the code is reading the information of each pixel, one-by-one.

## What value does line 65 of `copy.c` assign to `padding` if `bi.biWidth` is `3`?

The line 63 (in the copy of copy.c that I have) assigns the value of '3' bytes to the padding variable if bi.biWidth is '3', because the RGBTRIPLE has a length of 3 (bytes),
which is multiplied by bi.biWidth '3', this result is modded by 4, which gives us '1', this result substracts '4', which gives us '3'; and '3' modded by 4 gives us '3'.
This means that a file that has a width of '3' bytes, needs '3 bytes' (1 pixel) to be multiple of '4'.

## What does `fseek` do?

The fseek() function allows us to go back or forward within the file.

## What is `SEEK_CUR`?

It is the argument that is used by the fseek() function to move to a desired position from the current position we are in the file.
In this case, the function moves 'padding' places into the 'inptr' stream from the current position 'SEEK_CUR'.

## Whodunit?

It was professor Plum with the candlestick in the library.
