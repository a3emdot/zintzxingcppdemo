#include <zint.h>
#include <string.h>
int main() {
struct zint_symbol *zintSymbol = ZBarcode_Create();
zintSymbol->input_mode = 12255232; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1008 
unsigned char bgcolour[]={0,0,0,0,0,0,186,0,0,0,0,0,0,0,0};
memcpy(zintSymbol->bgcolour, bgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1533 
zintSymbol->output_options = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1539 
zintSymbol->border_width = 16776960; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->option_2 = -458752; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1572 
zintSymbol->option_3 = -1583217720; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1588 
zintSymbol->dot_size = 2; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1597 
zintSymbol->border_width = 100; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->eci = 41377; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
unsigned char fgcolour[]={255,161,161,161,0,0,0,167,94,0,45,0,0,0,0};
memcpy(zintSymbol->fgcolour, fgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1634 
zintSymbol->eci = 35; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
zintSymbol->guard_descent = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1684 
zintSymbol->height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1698 
zintSymbol->option_1 = -16712192; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1736 
zintSymbol->show_hrt = -16711936; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1750 
unsigned char primary[]={255,255,255,255,255,255,255,255,255,255,47,0,65,65,0,0,0,0,0,0,0,0,0,0,0,1,56,0,0,0,3,0,33,61,61,46,61,151,192,249,255,52,52,52,52,52,52,52,0,0,0,91,253,0,252,0,0,0,40,255,191,255,161,161,154,154,164,154,154,154,154,154,0,0,0,16,0,36,0,0,255,255,147,38,0,9,255,255,255,6,0,0,0,63,0,0,8,255,255,255,255,255,255,252,255,255,0,0,0,0,0,0,255,255,0,255,0,0,0,96,36,255,251,255,255,49,39};
memcpy(zintSymbol->primary, primary, 127); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1754 
zintSymbol->scale = 30; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1806 
zintSymbol->text_gap = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1917 
zintSymbol->debug = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1925 
zintSymbol->whitespace_height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1946 
zintSymbol->warn_level = 4; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1954 
zintSymbol->symbology = 58; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1979 
zintSymbol->dpmm = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:2117 
unsigned char barcodeData[]={141,141,141,141,141,232,141,141,57,57,57,141,141,48,48,48,48,48,141,141,141,141,141,141,255,79,0,0,30,0,0,0,0,239,254,22,255,255,255,255,161,161,154,154,154,154,154,154,157,26,64,252,58,74,71,66,32,0,0,64,100,0,0,0,161,161,0,0,23,2,161,161,0,0,12,0,0,0,0,239,215,4,0,0,0,0,0,0,0,253,0,0,0,0,0,0,0,0,0,0,0,0,0,48,50,53,51,93,57,82,52,82,52,52,44,52,52,44,52,52,48,52,91,50,53,53,232,57,57,57,141,141,57,57,57,57,57,141,141,141,141,48,48,48,48,141,141,141,141,141,141,141,141,141,93,57,52,52,52,52,52,50,60,52,52,52,52,44,52,48,52,52,37,52,52,118,65,0,0,2,0,39,0,0,141,255,64,141,141,232,141,141,141,141,141,141,141,199,198,198,110,141,141,0,0,1,0,0,131,0,0,0,0,0,0,64,141,141,141,91,141,52,51,49,53,64,93,82,48};
ZBarcode_Encode(zintSymbol, barcodeData, 229);
ZBarcode_Delete(zintSymbol);
return 0;
}
