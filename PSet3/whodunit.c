#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
  // make sure there's only 3 command line arguments
  if (argc != 3)
  {
    printf("Usage: ./whodunit infile outfile\n");
    return 1;
  }

  // rememeber filenames
  char *infile = argv[1];
  char *outfile = argv[2];

  //open input file
  FILE *inptr = fopen(infile, "r");
  if (inptr == NULL)
  {
    printf("Couldn't open %s\n", infile);
    return 2;
  }

  // open output file
  FILE *outptr = fopen(outfile, "w");
  if (outptr == NULL)
  {
    fclose(outptr);
    fprintf(stderr, "Couldn't create %s\n", outfile);
    return 3;
  }

  // read infile's BITMAPFILEHEADER
  BITMAPFILEHEADER bf;
  fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

  // read infile's BITMAPINFOHEADER
  BITMAPINFOHEADER bi;
  fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

  // write outfile's BITMAPFILEHEADER
  fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

  // write outfile's BITMAPINFOHEADER
  fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

  // padding
  int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

  // iterate over each line in infile
  for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
  {
    // iterate over each pixel in line
    for (int j = 0; j < bi.biWidth; j++)
    {
      // temporary storage
      RGBTRIPLE triple;

      // read RGB triple from infile
      fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

      // enhance blue and green pixels' saturation to match the red pixels' saturation to get a black and white image
      if (triple.rgbtRed == 0xff)
      {
        triple.rgbtBlue = 0xff;
        triple.rgbtGreen = 0xff;
      }
      else if (triple.rgbtRed < 250 && triple.rgbtRed > 230)
      {
        triple.rgbtBlue = 250;
        triple.rgbtGreen = 250;
        triple.rgbtRed = 250;
      }
      else if (triple.rgbtRed < 240 && triple.rgbtRed > 220)
      {
        triple.rgbtBlue = 240;
        triple.rgbtGreen = 240;
        triple.rgbtRed = 240;
      }
      else if (triple.rgbtRed < 230 && triple.rgbtRed > 210)
      {
        triple.rgbtBlue = 230;
        triple.rgbtGreen = 230;
        triple.rgbtRed = 230;
      }
      else if (triple.rgbtRed < 220 && triple.rgbtRed > 200)
      {
        triple.rgbtBlue = 220;
        triple.rgbtGreen = 220;
        triple.rgbtRed = 220;
      }
      else if (triple.rgbtRed < 210 && triple.rgbtRed > 190)
      {
        triple.rgbtBlue = 210;
        triple.rgbtGreen = 210;
        triple.rgbtRed = 210;
      }
      else if (triple.rgbtRed < 200 && triple.rgbtRed > 180)
      {
        triple.rgbtBlue = 200;
        triple.rgbtGreen = 200;
        triple.rgbtRed = 200;
      }
      else if (triple.rgbtRed < 190 && triple.rgbtRed > 170)
      {
        triple.rgbtBlue = 190;
        triple.rgbtGreen = 190;
        triple.rgbtRed = 190;
      }
      else if (triple.rgbtRed < 180 && triple.rgbtRed > 160)
      {
        triple.rgbtBlue = 180;
        triple.rgbtGreen = 180;
        triple.rgbtRed = 180;
      }
      else if (triple.rgbtRed < 170 && triple.rgbtRed > 150)
      {
        triple.rgbtBlue = 170;
        triple.rgbtGreen = 170;
        triple.rgbtRed = 170;
      }
      else if (triple.rgbtRed < 160 && triple.rgbtRed > 140)
      {
        triple.rgbtBlue = 160;
        triple.rgbtGreen = 160;
        triple.rgbtRed = 160;
      }
      else if (triple.rgbtRed < 150 && triple.rgbtRed > 130)
      {
        triple.rgbtBlue = 150;
        triple.rgbtGreen = 150;
        triple.rgbtRed = 150;
      }
      else if (triple.rgbtRed < 140 && triple.rgbtRed > 120)
      {
        triple.rgbtBlue = 140;
        triple.rgbtGreen = 140;
        triple.rgbtRed = 140;
      }
      else if (triple.rgbtRed < 130 && triple.rgbtRed > 110)
      {
        triple.rgbtBlue = 130;
        triple.rgbtGreen = 130;
        triple.rgbtRed = 130;
      }
      else if (triple.rgbtRed < 120 && triple.rgbtRed > 100)
      {
        triple.rgbtBlue = 120;
        triple.rgbtGreen = 120;
        triple.rgbtGreen = 120;
      }
      else if (triple.rgbtRed < 110 && triple.rgbtRed > 90)
      {
        triple.rgbtBlue = 110;
        triple.rgbtGreen = 110;
        triple.rgbtRed = 110;
      }
      else if (triple.rgbtRed < 100 && triple.rgbtRed > 80)
      {
        triple.rgbtBlue = 100;
        triple.rgbtGreen = 100;
        triple.rgbtRed = 100;
      }
      else if (triple.rgbtRed < 90 && triple.rgbtRed > 70)
      {
        triple.rgbtBlue = 90;
        triple.rgbtGreen = 90;
        triple.rgbtRed = 90;
      }
      else if (triple.rgbtRed < 80 && triple.rgbtRed > 60)
      {
        triple.rgbtBlue = 80;
        triple.rgbtGreen = 80;
        triple.rgbtRed = 80;
      }
      else if (triple.rgbtRed < 70 && triple.rgbtRed > 50)
      {
        triple.rgbtBlue = 70;
        triple.rgbtGreen = 70;
        triple.rgbtRed = 70;
      }
      else if (triple.rgbtRed < 60 && triple.rgbtRed > 40)
      {
        triple.rgbtBlue = 60;
        triple.rgbtGreen = 60;
        triple.rgbtRed = 60;
      }
      else if (triple.rgbtRed < 50 && triple.rgbtRed > 30)
      {
        triple.rgbtBlue = 50;
        triple.rgbtGreen = 50;
        triple.rgbtRed = 50;
      }
      else if (triple.rgbtRed < 40 && triple.rgbtRed > 20)
      {
        triple.rgbtBlue = 40;
        triple.rgbtGreen = 40;
        triple.rgbtRed = 40;
      }
      else if (triple.rgbtRed < 30 && triple.rgbtRed > 10)
      {
        triple.rgbtBlue = 30;
        triple.rgbtGreen = 30;
        triple.rgbtRed = 30;
      }
      else if (triple.rgbtRed < 20 && triple.rgbtRed > 0)
      {
        triple.rgbtBlue = 20;
        triple.rgbtGreen = 20;
        triple.rgbtRed = 20;
      }
      // write RGB triple to outfile
      fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
    }
    // skip over padding, if any
    fseek(inptr, padding, SEEK_CUR);

    // then add it back
    for (int k = 0; k < padding; k++)
    {
      fputc(0x00, outptr);
    }
  }

  // close infile
  fclose(inptr);

  // close outfile
  fclose(outptr);

  return 0;
}
