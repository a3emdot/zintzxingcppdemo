#include <zint.h>
#include <string.h>
int main() {
struct zint_symbol *zintSymbol = ZBarcode_Create();
zintSymbol->input_mode = 538968064; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1008 
unsigned char bgcolour[]={32,74,232,141,141,101,141,141,141,141,141,141,141,0,0};
memcpy(zintSymbol->bgcolour, bgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1533 
zintSymbol->output_options = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1539 
zintSymbol->border_width = 2293760; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->option_2 = -1; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1572 
zintSymbol->option_3 = -1583218744; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1588 
zintSymbol->dot_size = 2; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1597 
zintSymbol->border_width = 100; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->eci = 41377; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
unsigned char fgcolour[]={255,161,161,8,161,0,0,37,94,0,41,1,0,0,0};
memcpy(zintSymbol->fgcolour, fgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1634 
zintSymbol->eci = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
zintSymbol->guard_descent = 7; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1684 
zintSymbol->height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1698 
zintSymbol->option_1 = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1736 
zintSymbol->show_hrt = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1750 
unsigned char primary[]={161,0,0,0,0,0,0,0,161,167,94,94,94,255,255,255,0,0,0,0,0,0,0,0,49,0,0,0,0,0,0,0,0,0,94,255,0,255,0,0,127,94,78,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,251,255,255,255,161,161,154,154,154,154,199,154,154,154,0,0,0,16,0,36,0,0,255,255,147,38,0,9,255,255,255,0,0,0,0,0,0,0,8,255,255,255,255,255,255,255,255,255,0,0,0,0,0,0,0,254,255,255,255,255,255,255,255,255,255,255,255,255,39};
memcpy(zintSymbol->primary, primary, 127); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1754 
zintSymbol->scale = 30; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1806 
zintSymbol->text_gap = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1917 
zintSymbol->debug = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1925 
zintSymbol->whitespace_height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1946 
zintSymbol->warn_level = 4; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1954 
zintSymbol->symbology = 58; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1979 
zintSymbol->dpmm = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:2117 
unsigned char barcodeData[]={141,141,232,141,54,55,53,48,141,141,141,141,141,141,0,0,0,21,141,141,141,141,141,154,141,154,154,1,241,141,141,141,141,141,145,141,141,141,141,74,74,74,74,74,74,78,74,74,74,74,74,74,141,141,141,141,57,57,57,57,141,141,141,141,141,141,141,141,141,157,141,141,141,141,141,29,4,0,0,64,0,0,0,0,253,0,0,0,0,0,0,0,0,0,0,0,0,0,161,0,0,0,0,0,0,0,161,167,94,94,94,255,255,255,0,32,0,0,0,0,0,0,255,255,117,0,0,0,0,0,0,0,94,255,255,94,94,0,58,0,127,255,255,255,63,255,255,255,255,255,255,255,255,255,255,255,255,255,255,161,161,154,154,154,154,154,154,154,154,0,255,255,255,162,3,0,0,255,255,47,0,65,65,0,0,0,0,0,0,0,0,0,0,0,0,84,0,0,0,0,0,0,0,0,87,87,87,159,168,87,87,87,87,87,87,255,255,82,51,48,32,32,32,32,32,32,255,255,0,0,0};
ZBarcode_Encode(zintSymbol, barcodeData, 231);
ZBarcode_Delete(zintSymbol);
return 0;
}

