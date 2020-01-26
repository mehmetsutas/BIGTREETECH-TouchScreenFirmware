#include "UnifiedHeat.h"
#include "includes.h"

//1 title, ITEM_PER_PAGE items(icon + label)
const MENUITEMS UnifiedHeatItems = {
// title
lABEL_UNIFIEDHEAT,
// icon                       label
 {{ICON_HEAT,                 LABEL_PREHEAT},
  {ICON_HEAT,                 LABEL_HEAT},
  {ICON_FAN,                  LABEL_FAN},
  {ICON_COOLDOWN,             LABEL_COOLDOWN},
  {ICON_LOAD,                 LABEL_FILAMENT_LOAD},
  {ICON_UNLOAD,               LABEL_FILAMENT_UNLOAD},
  {ICON_BACKGROUND,           LABEL_BACKGROUND},
  {ICON_BACK,                 LABEL_BACK},}
};

void menuUnifiedHeat(void)
{
  KEY_VALUES key_num = KEY_IDLE;	
  menuDrawPage(&UnifiedHeatItems);
  while(infoMenu.menu[infoMenu.cur] == menuUnifiedHeat)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
      case KEY_ICON_0: infoMenu.menu[++infoMenu.cur] = menuPreheat;   break;
      case KEY_ICON_1: infoMenu.menu[++infoMenu.cur] = menuHeat;    break;
      case KEY_ICON_2: infoMenu.menu[++infoMenu.cur] = menuFan;    break;
      case KEY_ICON_3:
        for(TOOL i = BED; i < HEATER_NUM; i++)
        {
          heatSetTargetTemp(i, 0);
        }
        break;
      case KEY_ICON_4: 
			infoMenu.cur--;
			storeCmd("G28 O\n");
			storeCmd("G1 Z50 F1200\n");
			storeCmd("G1 X100 Y100 F6000\n"); 
			storeCmd("M109 S220\n"); 
			storeCmd("M701\n"); 
			storeCmd("M400\n");
			storeCmd("M104 S0\n");
			storeCmd("M300 S880 P300\n");
			break;
      case KEY_ICON_5:	
			infoMenu.cur--;
			storeCmd("G28 O\n");
			storeCmd("G1 Z50 F1200\n");
			storeCmd("G1 X100 Y100 F6000\n");
			storeCmd("M109 S220\n"); 
			storeCmd("M702\n"); 
			storeCmd("M400\n");
			storeCmd("M104 S0\n");
			storeCmd("M300 S880 P300\n");
			break;	  
      case KEY_ICON_7: infoMenu.cur--;      break;
      default:break;            
    }
    loopProcess();
  }
}
