#include <zint.h>
#include <string.h>
int main() {
struct zint_symbol *zintSymbol = ZBarcode_Create();
zintSymbol->input_mode = -262152; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1008 
unsigned char bgcolour[]={255,255,255,255,255,255,255,255,64,255,255,255,255,255,8};
memcpy(zintSymbol->bgcolour, bgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1533 
zintSymbol->output_options = 452984834; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1539 
zintSymbol->border_width = 1090519045; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->option_2 = 17449281; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1572 
zintSymbol->option_3 = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1588 
zintSymbol->dot_size = 12; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1597 
zintSymbol->border_width = 65; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->eci = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
unsigned char fgcolour[]={0,0,0,0,0,0,0,0,0,211,0,0,0,0,0};
memcpy(zintSymbol->fgcolour, fgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1634 
zintSymbol->eci = 8; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
zintSymbol->fontsize = 29952; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1656 
zintSymbol->guard_descent = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1684 
zintSymbol->height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1698 
zintSymbol->option_1 = 3014656; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1736 
zintSymbol->show_hrt = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1750 
unsigned char primary[]={0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,253,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,65,65,65,65,65,65,65,65,65,65,65,65,65,45,65,65,65,65,65,65,65,65,65,65,65,65,48,105,3,0,0,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,95,65,65,65,65,65,65,65,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,65,65,65};
memcpy(zintSymbol->primary, primary, 127); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1754 
zintSymbol->scale = 12; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1806 
zintSymbol->text_gap = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1917 
zintSymbol->debug = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1925 
zintSymbol->whitespace_height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1946 
zintSymbol->warn_level = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1954 
zintSymbol->symbology = 56; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1979 
zintSymbol->dpmm = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:2117 
unsigned char barcodeData[]={0,0,0,255,255,8,2,0,0,27,5,25,0,0,2,0,0,0,0,65,65,65,65,65,65,65,65,0,0,0,0,0,0,0,252,0,65,65,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,211,0,0,0,0,0,8,0,0,0,0,117,0,0,0,0,0,0,0,0,0,0,0,0,46,0,0,0,0,0,0,0,0,0,0,64,0,0,65,65,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,211,0,0,0,0,0,8,0,0,0,0,0,0,0,0,0,0,0,0,211,0,0,0,0,0,8,0,0,0,0,117,0,0,0,0,0,0,0,0,0,0,0,0,46,0,0,0,0,0,0,0,0,0,0,0,0,65,65,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,211,0,8,0,0,0,8,0,0,0,0,117,0,0,0,0,0,0,0,0,0,0,0,0,46,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,253,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0,0,0,65,65,65,65,65,65,65,65,65,65,65,45,65,65,65,65,65,65,65,65,65,65,65,65,48,105,3,0,0,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,95,65,65,65,65,65,65,65,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,65,65,65,65,65,65,65,65,65,65,0,0,0,0,0,0,0,0,0,56,0,0,0,0,0,0,0,0,0,0,255,255,8,2,0,0,27,5,25,0,0,2,0,0,0,0,65,65,65,65,65,65,65,65,0,0,0,0,0,0,0,252,0,65,65,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,211,0,0,0,0,0,8,0,0,0,0,117,0,0,0,0,0,0,0,0,0,0,0,0,46,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,253,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,255,255,255,255,255,255,255,253,0,0,0,0,0,0,0,0,0,0,0,0,0,32,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,65,65,65,65,65,65,65,65,65,65,65,65,65,45,65,65,65,65,65,65,65,65,65,65,65,65,48,105,3,0,0,65,65,65,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,251,255,255,255,255,48,48,48,48,48,48,48,48,48,48,48,48,41,48,48,48,48,48,48,255,255,255,255,0,0,0,0,255,113,0,105,105,168,82,97,10,255,255,17,17,17,17,17,17,113,17,0,212,212,212,212,212,212,212,212,212,212,212,0,0,0,0,74,0,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,208,212,212,212,212,17,126,10,0,0,0,0,0,0,212,212,212,212,212,212,212,65,65,65,65,65,65,65,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,234,0,0,0,0,0,65,65,65,65,65,65,65,65,65,65,65,65,65,95,65,65,65,65,65,65,65,65,0,0,0,0,0,0,0,0,0,0,0,0,65,65,65,65,33,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,212,212,212,212,212,212,212,212,212,63,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,212,0,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,48,41,48,48,48,48,48,48,255,255,255,255,0,0,0,0,255,113,0,105,105,168,82,97,10,255,255,17,17,17,17,17,17,113,17,0,212,212,212,212,212,212,212,212,212,212,212,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,65,95,65,65,65,65,65,65,0,0,0,0,252,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,211,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,211,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
ZBarcode_Encode(zintSymbol, barcodeData, 1048);
ZBarcode_Delete(zintSymbol);
return 0;
}
