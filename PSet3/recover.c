#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover infile\n");
        return 1;
    }

    char *infile = argv[1];
    FILE *card = fopen(infile, "r"); // open the infile
    if (card == NULL) // check if it can be opened
    {
        fprintf(stderr, "Could not open %s\n", infile);
        return 2;
    }

    unsigned char buffer[512]; // create temporary storage
    int count = 0;  // set the image counter
    char image_name[10]; // create a variable to hold image name
    FILE *image = NULL; // set the outnput image file to NULL (as it hasn't been created yet)

    // read the infile
    while (fread(buffer, sizeof(buffer), 1, card) == 1) // check EOF
    {
        // find beginning of JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {

            if (image != NULL) // check if there's already a jpg file opened
            {
                fclose(image); // close the previous jpg
            }

            sprintf(image_name, "%03i.jpg", count); // create image name
            image = fopen(image_name, "w"); // open a new jpg file
            fwrite(buffer, sizeof(buffer), 1, image); // write to that image file
            count++; // increment the image counter
        }
        else if (image != NULL) // if there's already a jpg file opened and no new image found continue writing to the opened file
        {
            fwrite(buffer, sizeof(buffer), 1, image);
        }
    }

    fclose(card);
    fclose(image);
    return 0;
}
