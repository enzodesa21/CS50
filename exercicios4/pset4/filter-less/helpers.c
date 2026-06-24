#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
       for (int j = 0; j < width; j++)
       {
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;

            float average = (red + green + blue) / 3.0;

            average = round(average);

            image[i][j].rgbtRed = average;
            image[i][j].rgbtGreen = average;
            image[i][j].rgbtBlue = average;
       }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            BYTE red = image[i][j].rgbtRed;
            BYTE green = image[i][j].rgbtGreen;
            BYTE blue = image[i][j].rgbtBlue;

            BYTE new_red = 0.393 * red + 0.769 * green + 0.189 * blue;
            BYTE new_green = 0.349 * red + 0.686 * green + 0.168 * blue;
            BYTE new_blue = 0.272 * red + 0.534 * green + 0.131 * blue;

            new_red = round(new_red);
            new_green = round(new_green);
            new_blue = round(new_blue);

            image[i][j].rgbtRed = new_red;
            image[i][j].rgbtGreen = new_green;
            image[i][j].rgbtBlue = new_blue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height / 2; i++)
    {
        for (int j = 0; j < width; j++)
        {
            RGBTRIPLE now = image[i][j];
            RGBTRIPLE temp;
            RGBTRIPLE new = image[i][width - j - 1];

            temp = now;
            now = new;
            new = temp;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    //Cria uma cópia
    RGBTRIPLE copy[height][width];

    //Copia todos os pixels da imagem original
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int somaRed = 0;
            int somaGreen = 0;
            int somaBlue = 0;

            int contador = 0;

            //Percorre os pixels(3x3)
            for (int k = - 1; k <= 1; k++)    //Vertical
            {
                for (int l = - 1; l <= 1; l++)  //Horizontal
                {
                    int nova_linha = i + k;
                    int nova_coluna = j + l;

                    //Verifica se o pixel é válido
                    if (nova_linha >= 0 && nova_linha < height && nova_coluna >= 0 && nova_coluna < width)
                    {
                        somaRed += copy[nova_linha][nova_coluna].rgbtRed;
                        somaGreen += copy[nova_linha][nova_coluna].rgbtGreen;
                        somaBlue += copy[nova_linha][nova_coluna].rgbtBlue;

                        contador++;
                    }
                }
            }

            //Calcula a média
            image[i][j].rgbtRed = round((float)somaRed / contador);
            image[i][j].rgbtGreen = round((float)somaGreen / contador);
            image[i][j].rgbtBlue = round((float)somaBlue / contador);
        }
    }
}
