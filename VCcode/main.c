#include <stdio.h> 
#include "vc.h"

// Abrir imagem, alterar e gravar em novo ficheiro
int main(void)
{
    IVC* image_src;
    IVC* image_dst;
    int i;


    image_src = vc_read_image("C:/Users/allan/Desktop/projeto/VisaoPorComputador/Images/Additional/fruits.ppm");
    if (image_src == NULL) {
        printf("ERROR -> vc_read_image():\n\tFile not found! \n");
        getchar();
        return 0;
    }

    image_dst = vc_image_new(image_src->width, image_src->height, 1, 255); //CRIAR IMAGEM NOVA PARA RGB TO GRAY
    
   
    
    //vc_rgb_get_blue_gray(image);
    //vc_rgb_get_green_gray(image);
    //vc_rgb_get_red_gray(image);
    //vc_rgb_get_red(image);
    //vc_rgb_get_blue(image);
    //vc_rgb_get_green(image);
    vc_rgb_to_gray(image_src, image_dst);

    //inverter imagem
    /*for (i=0; i < image->bytesperline*image->height; i+=image->channels){
        image->data [i] = 255 - image->data[i];
    }*/

    vc_write_image("rgbtogray.pgm", image_dst); //SALVAR NA IMAGEM CRIADA PARA RGB TO GRAY

    //vc_rgb_get_blue_gray(image);
    //vc_rgb_get_green_gray(image);
    //vc_rgb_get_red_gray(image);

    system("cmd /c start C:\\Users\\allan\\Desktop\\projeto\\VisaoPorComputador\\Aulas\\VCcode\\VCcode\\FilterGear.exe C:\\Users\\allan\\Desktop\\projeto\\VisaoPorComputador\\aulas\\VCcode\\VCcode\\Images\\Additional\\fruits.ppm"); // Input
    system("C:\\Users\\allan\\Desktop\\projeto\\VisaoPorComputador\\Aulas\\VCcode\\VCcode\\FilterGear.exe C:\\Users\\allan\\Desktop\\projeto\\VisaoPorComputador\\aulas\\VCcode\\VCcode\\Images\\Additional\\rgbtogray.pgm"); // Output


    vc_image_free(image_src);
    vc_image_free(image_dst);

    printf("Press any key to exit... In");

    getchar();

    return 0;
}