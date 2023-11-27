#include <zint.h>
#include <string.h>
int main() {
struct zint_symbol *zintSymbol = ZBarcode_Create();
zintSymbol->input_mode = 32; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1008 
unsigned char bgcolour[]={30,0,0,0,1,239,255,255,255,255,255,255,255,239,255};
memcpy(zintSymbol->bgcolour, bgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1533 
zintSymbol->output_options = -10591; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1539 
zintSymbol->border_width = 33554687; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->option_2 = -62907681; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1572 
zintSymbol->option_3 = 1111968314; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1588 
zintSymbol->dot_size = 2; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1597 
zintSymbol->border_width = 100; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1553 
zintSymbol->eci = -1593835359; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
unsigned char fgcolour[]={125,0,161,161,0,0,12,0,0,0,0,239,215,4,0};
memcpy(zintSymbol->fgcolour, fgcolour, 15); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1634 
zintSymbol->eci = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1617 
zintSymbol->guard_descent = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1684 
zintSymbol->height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1698 
zintSymbol->option_1 = 3; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1736 
zintSymbol->show_hrt = 1073741824; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1750 
unsigned char primary[]={91,93,50,56,0,0,0,0,0,9,0,253,0,0,0,82,82,82,82,82,82,82,82,82,82,82,0,54,0,82,82,0,0,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,82,48,53,82,82,82,82,82,82,0,154,157,0,102,84,1,0,64,252,189,0,0,160,154,154,159,154,154,64,0,59,255,161,255,0,255,255,103,255,255,255,255,255,255,255,255,255,255,255,255,8,8,255,255,255,255,255,255,255,4,0,0,0,0,0,30,4,0,0,1,0,0,247};
memcpy(zintSymbol->primary, primary, 127); // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1754 
zintSymbol->scale = 11; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1806 
zintSymbol->text_gap = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1917 
zintSymbol->debug = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1925 
zintSymbol->whitespace_height = 0; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1946 
zintSymbol->warn_level = 256; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1954 
zintSymbol->symbology = 131; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:1979 
zintSymbol->dpmm = 2; // https://github.com/zint/zint/blob/6d015d6a8ff5f66e8c2d4a838ba5e3000ac64776/frontend/main.c:2117 
unsigned char barcodeData[]={91,93,82,82,82,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,95,75,75,75,82,82,82,48,48,48,48};
ZBarcode_Encode(zintSymbol, barcodeData, 34);
ZBarcode_Delete(zintSymbol);
return 0;
}
