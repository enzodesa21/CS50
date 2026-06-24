#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main(int argc, char *argv[])
{
    //Abrir arquivo
    FILE *file = fopen("card.raw", "r");

    //Verificação
    if (file == NULL)
    {
        printf("Erro ao abrir ");
        return 1;
    }

    //Area temporaria para armazenar dados
    unsigned char buffer[512];

    //Verificar se ja esta excrevendo um arquibo ou nao (Flag)
    bool writing = false;

    //Nome dos arquivos
    char filename[8];

    //Imagem
    FILE *img;

    //Contador de imagem
    int count = 0;
    //Procurar até o fim do cartão
    while(fread(buffer, 1, 512, file) == 512)
    {
        //Se detectar um JPEG, criar um novo JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            //Se já tiver JPEG
            if (writing == true)
            {
                //Fechar antigo e abrir um novo
                fclose(img);
            }

            //Se não, abrir novo e writing == true
            sprintf(filename, "%03i.jpg", count);

            img = fopen(filename, "w");
            writing = true;

            count++;
        }

        //If fora para continuar escrevendo até achar uma nova JPEG
        if(writing == true)
        {
            fwrite(buffer, 1, 512, img);
        }
    }

    if (writing)
    {
        fclose(img);
    }

    fclose(file);
}
