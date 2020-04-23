#include <stdio.h>
#include <math.h>
#include "helpers.h"

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            float avg = image[h][w].rgbtBlue + image[h][w].rgbtGreen + image[h][w].rgbtRed;
            avg = roundf(avg / 3);
            image[h][w].rgbtBlue = avg;
            image[h][w].rgbtGreen = avg;
            image[h][w].rgbtRed = avg;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int h = 0; h < height; h++)
    {
        for (int w = 0; w < width; w++)
        {
            int sepiaBlue = round(.272 * image[h][w].rgbtRed + .534 * image[h][w].rgbtGreen + .131 * image[h][w].rgbtBlue);
            int sepiaGreen = round(.349 * image[h][w].rgbtRed + .686 * image[h][w].rgbtGreen + .168 * image[h][w].rgbtBlue);
            int sepiaRed = round(.393 * image[h][w].rgbtRed + .769 * image[h][w].rgbtGreen + .189 * image[h][w].rgbtBlue);

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            image[h][w].rgbtBlue = sepiaBlue;
            image[h][w].rgbtGreen = sepiaGreen;
            image[h][w].rgbtRed = sepiaRed;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int wMiddle = (int)width / 2;
    int Pixel = 0;
    RGBTRIPLE currentPixel;
    for (int h = 0; h < height; h++) 
    {
        for (int w = 0; w < wMiddle; w++) 
        {
            Pixel = width - (w + 1);
            currentPixel = image[h][w];

            image[h][w] = image[h][Pixel];
            image[h][Pixel] = currentPixel;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE newImage[height][width]; 

    for (int h = 0; h < height; h++) 
    { 
        for (int w = 0; w < width; w++) 
        { 
            int redAvg = 0; 
            int greenAvg = 0; 
            int blueAvg = 0; 
            double count = 0.0; 
            for (int y = -1; y <= 1; y++) 
            { 
                for (int x = -1; x <= 1; x++) 
                { 
                    int h_1 = h + y; 
                    int w_1 = w + x; 

                    if (h_1 >= 0 && h_1 < height && w_1 >= 0 && w_1 < width) 
                    { 
                        RGBTRIPLE img = image[h_1][w_1]; 
                        count++; 
                        redAvg += img.rgbtRed; 
                        greenAvg += img.rgbtGreen; 
                        blueAvg += img.rgbtBlue; 
                    } 
                } 
            } 
            newImage[h][w].rgbtRed = round(redAvg / count); 
            newImage[h][w].rgbtGreen = round(greenAvg / count); 
            newImage[h][w].rgbtBlue = round(blueAvg / count); 
        } 
    } 

    for (int x = 0; x < height; x++) 
    { 
        for (int y = 0; y < width; y++) 
        { 
            image[x][y] = newImage[x][y]; 
        } 
    } 
    return; 

}