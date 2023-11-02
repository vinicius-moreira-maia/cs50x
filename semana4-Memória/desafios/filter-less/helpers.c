#include "helpers.h"
#include <math.h>
#include <stdio.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++) // linha
    {
        for (int j = 0; j < width; j++) // coluna
        {
            float media_aux = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0;

            int media = round(media_aux);

            image[i][j].rgbtBlue = media;
            image[i][j].rgbtGreen = media;
            image[i][j].rgbtRed = media;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
      for (int i = 0; i < height; i++) // linha
      {
        for (int j = 0; j < width; j++) // coluna
        {
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
              if (sepiaRed > 255)
              {
                 sepiaRed = 255.0;
              }

            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
              if (sepiaGreen > 255)
              {
                sepiaGreen = 255.0;
              }

            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;
              if (sepiaBlue > 255)
              {
                sepiaBlue = 255.0;
              }

            image[i][j].rgbtBlue = round(sepiaBlue);
            image[i][j].rgbtGreen = round(sepiaGreen);
            image[i][j].rgbtRed = round(sepiaRed);
        }
      }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        int cont = width - 1;
        for (int j = 0; j - cont <= 0; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            image[i][j].rgbtRed = image[i][cont].rgbtRed;
            image[i][j].rgbtGreen = image[i][cont].rgbtGreen;
            image[i][j].rgbtBlue = image[i][cont].rgbtBlue;

            image[i][cont].rgbtRed = red;
            image[i][cont].rgbtGreen = green;
            image[i][cont].rgbtBlue = blue;

            cont --;
        }
    }
}

// Blur image  -> NÃO IMPLEMENTEI O BLUR DOS PIXELS DAS MARGENS <-
void blur(int height, int width, RGBTRIPLE image[height][width])
{
      for (int i = 0; i < height; i++) // linha
      {
        for (int j = 0; j < width; j++) // coluna
        {
          int red = image[i][j].rgbtRed;
          int blue = image[i][j].rgbtBlue;
          int green = image[i][j].rgbtGreen;

          if ((i - 1 >= 0) && (j - 1 >= 0) && (i + 1 <= height - 1) && (j + 1 <= width - 1)) // pixels do meio
          {
                red += image[i - 1][j - 1].rgbtRed;
                red += image[i - 1][j].rgbtRed;
                red += image[i - 1][j + 1].rgbtRed;
                red += image[i][j - 1].rgbtRed;
                red += image[i][j + 1].rgbtRed;
                red += image[i + 1][j - 1].rgbtRed;
                red += image[i + 1][j].rgbtRed;
                red += image[i + 1][j + 1].rgbtRed;

                green += image[i - 1][j - 1].rgbtGreen;
                green += image[i - 1][j].rgbtGreen;
                green += image[i - 1][j + 1].rgbtGreen;
                green += image[i][j - 1].rgbtGreen;
                green += image[i][j + 1].rgbtGreen;
                green += image[i + 1][j - 1].rgbtGreen;
                green += image[i + 1][j].rgbtGreen;
                green += image[i + 1][j + 1].rgbtGreen;

                blue += image[i - 1][j - 1].rgbtBlue;
                blue += image[i - 1][j].rgbtBlue;
                blue += image[i - 1][j + 1].rgbtBlue;
                blue += image[i][j - 1].rgbtBlue;
                blue += image[i][j + 1].rgbtBlue;
                blue += image[i + 1][j - 1].rgbtBlue;
                blue += image[i + 1][j].rgbtBlue;
                blue += image[i + 1][j + 1].rgbtBlue;

                image[i][j].rgbtRed = round(red / 9.0);
                image[i][j].rgbtGreen = round(green / 9.0);
                image[i][j].rgbtBlue = round(blue / 9.0);
          }
          else
          {
              if ((i - 1 < 0) && (j - 1 < 0)) // canto sup esq
              {
                  red += image[i][j + 1].rgbtRed;
                  red += image[i + 1][j].rgbtRed;
                  red += image[i + 1][j + 1].rgbtRed;

                  green += image[i][j + 1].rgbtGreen;
                  green += image[i + 1][j].rgbtGreen;
                  green += image[i + 1][j + 1].rgbtGreen;

                  blue += image[i][j + 1].rgbtBlue;
                  blue += image[i + 1][j].rgbtBlue;
                  blue += image[i + 1][j + 1].rgbtBlue;
              }
              else if ((i - 1 < 0) && (j + 1 > width - 1))// canto sup dir
              {
                  red += image[i][j - 1].rgbtRed;
                  red += image[i + 1][j - 1].rgbtRed;
                  red += image[i + 1][j].rgbtRed;

                  green += image[i][j + 1].rgbtGreen;
                  green += image[i + 1][j].rgbtGreen;
                  green += image[i + 1][j + 1].rgbtGreen;

                  blue += image[i][j + 1].rgbtBlue;
                  blue += image[i + 1][j].rgbtBlue;
                  blue += image[i + 1][j + 1].rgbtBlue;
              }
              else if ((j - 1 < 0) && (i + 1 > height - 1)) // canto inf esq
              {
                  red += image[i - 1][j].rgbtRed;
                  red += image[i - 1][j + 1].rgbtRed;
                  red += image[i][j + 1].rgbtRed;

                  green += image[i][j + 1].rgbtGreen;
                  green += image[i + 1][j].rgbtGreen;
                  green += image[i + 1][j + 1].rgbtGreen;

                  blue += image[i][j + 1].rgbtBlue;
                  blue += image[i + 1][j].rgbtBlue;
                  blue += image[i + 1][j + 1].rgbtBlue;
              }
              else if ((j + 1 > width - 1) && (i + 1 > height - 1)) // canto inf dir
              {
                  red += image[i - 1][j - 1].rgbtRed;
                  red += image[i - 1][j].rgbtRed;
                  red += image[i][j - 1].rgbtRed;

                  green += image[i][j + 1].rgbtGreen;
                  green += image[i + 1][j].rgbtGreen;
                  green += image[i + 1][j + 1].rgbtGreen;

                  blue += image[i][j + 1].rgbtBlue;
                  blue += image[i + 1][j].rgbtBlue;
                  blue += image[i + 1][j + 1].rgbtBlue;
              }
                image[i][j].rgbtRed = round(red / 4.0);
                image[i][j].rgbtGreen = round(green / 4.0);
                image[i][j].rgbtBlue = round(blue / 4.0);
         }
      }
   }
 }


