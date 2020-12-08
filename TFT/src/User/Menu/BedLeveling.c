#include "BedLeveling.h"
#include "includes.h"

void blUpdateState(MENUITEMS *menu)
{
  if (getParameter(P_ABL_STATE, 0) == ENABLED)
  {
    menu->items[2].icon = ICON_LEVELING_ON;
    menu->items[2].label.index = LABEL_BL_ENABLE;
  }
  else
  {
    menu->items[2].icon = ICON_LEVELING_OFF;
    menu->items[2].label.index = LABEL_BL_DISABLE;
  }
  menuDrawItem(&menu->items[2], 2);
}

void menuBedLeveling(void)
{
  MENUITEMS bedLevelingItems = {
    // title
    LABEL_ABL_SETTINGS,
    // icon                         label
    {{ICON_LEVELING,                LABEL_ABL},
     {ICON_PROBE_OFFSET,            LABEL_Z_OFFSET},
     {ICON_BACKGROUND,              LABEL_BACKGROUND},
     {ICON_BACKGROUND,              LABEL_BACKGROUND},
     {ICON_BACKGROUND,              LABEL_BACKGROUND},
     {ICON_BACKGROUND,              LABEL_BACKGROUND},
     {ICON_BACKGROUND,              LABEL_BACKGROUND},
     {ICON_BACK,                    LABEL_BACK},}
  };

  KEY_VALUES key_num = KEY_IDLE;
//  void (*menuBL)(void) = menuABL;
  int8_t levelStateOld = -1;

  switch (infoMachineSettings.leveling)
  {
    case BL_BBL:
      bedLevelingItems.title.index = LABEL_ABL_SETTINGS_BBL;
      bedLevelingItems.items[0].label.index = LABEL_BBL;
      break;

    case BL_UBL:
      bedLevelingItems.title.index = LABEL_ABL_SETTINGS_UBL;
      bedLevelingItems.items[0].label.index = LABEL_UBL;
      break;

    case BL_MBL:
      bedLevelingItems.title.index = LABEL_MBL_SETTINGS;
      bedLevelingItems.items[0].label.index = LABEL_MBL;

//      menuBL = menuMBL;
      break;

    default:
      break;
  }

  if (getParameter(P_ABL_STATE, 0) == ENABLED)
  {
    bedLevelingItems.items[2].icon = ICON_LEVELING_ON;
    bedLevelingItems.items[2].label.index = LABEL_BL_ENABLE;
  }
  else
  {
    bedLevelingItems.items[2].icon = ICON_LEVELING_OFF;
    bedLevelingItems.items[2].label.index = LABEL_BL_DISABLE;
  }

  menuDrawPage(&bedLevelingItems);

  while (infoMenu.menu[infoMenu.cur] == menuBedLeveling)
  {
    key_num = menuKeyGetValue();
    switch (key_num)
    {
      case KEY_ICON_0:
        infoMenu.cur = 0;
        storeCmd("G92 E0\n");
        storeCmd("M109 S235 T0\n");
        storeCmd("G1 E6 F60\n");
        storeCmd("G1 E0 F4800\n");
        storeCmd("G1 E-100 F4800\n");
        storeCmd("G92 E0\n");
        storeCmd("G4 S5\n");
        storeCmd("G28\n");
        storeCmd("G29\n");
        storeCmd("G4 S5\n");
        storeCmd("M104 S0 T0\n");
        storeCmd("M140 S0\n");
        storeCmd("M500\n");
        break;

      case KEY_ICON_1:
        storeCmd("M851\n");
        infoMenu.menu[++infoMenu.cur] = menuProbeOffset;
        break;

      case KEY_ICON_2:
        if (getParameter(P_ABL_STATE, 0) == ENABLED)
        {
          storeCmd("M420 S0\n");
        }
        else
        {
          storeCmd("M420 S1\n");
        }
        break;

      case KEY_ICON_7:
        infoMenu.cur--;
        break;

      default:
        break;
    }

    if (levelStateOld != getParameter(P_ABL_STATE, 0))
    {
      levelStateOld = getParameter(P_ABL_STATE, 0);
      blUpdateState(&bedLevelingItems);
    }

    loopProcess();
  }
}
