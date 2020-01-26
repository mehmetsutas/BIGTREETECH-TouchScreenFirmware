#include "UnifiedMove.h"
#include "includes.h"

//1 title, ITEM_PER_PAGE items(icon + label)
const MENUITEMS UnifiedMoveItems = {
// title
{LABEL_UNIFIEDMOVE},
// icon                       label
 {{ICON_HOME,                 LABEL_HOME},
  {ICON_MOVE,                 LABEL_MOVE},
  {ICON_LEVELING,             LABEL_ABL},
  {ICON_MANUAL_LEVEL,         LABEL_LEVELING},
  {ICON_PROBE_OFFSET,          LABEL_PROBE_OFFSET},
  {ICON_BABYSTEP,              LABEL_BABYSTEP},
  {ICON_BACKGROUND,           LABEL_BACKGROUND},
  {ICON_BACK,                 LABEL_BACK},}
};

void menuUnifiedMove(void)
{
  KEY_VALUES key_num = KEY_IDLE;	
  menuDrawPage(&UnifiedMoveItems);
  while(infoMenu.menu[infoMenu.cur] == menuUnifiedMove)
  {
    key_num = menuKeyGetValue();
    switch(key_num)
    {
      case KEY_ICON_0: infoMenu.menu[++infoMenu.cur] = menuHome; break;
      case KEY_ICON_1: infoMenu.menu[++infoMenu.cur] = menuMove; break;
      case KEY_ICON_2: //infoMenu.menu[++infoMenu.cur] = menuAutoLeveling; break;
	    storeCmd("G28\n");
        storeCmd("G29\n");
        storeCmd("M500\n");
        break;
      case KEY_ICON_3: infoMenu.menu[++infoMenu.cur] = menuManualLeveling; break;
	  case KEY_ICON_4:
        storeCmd("M851\n");
        infoMenu.menu[++infoMenu.cur] = menuProbeOffset;
        break;      
      case KEY_ICON_5:
        infoMenu.menu[++infoMenu.cur] = menuBabyStep;
        break; 
      case KEY_ICON_7: infoMenu.cur--; break;
      default: break;            
    }
    loopProcess();
  }
}

