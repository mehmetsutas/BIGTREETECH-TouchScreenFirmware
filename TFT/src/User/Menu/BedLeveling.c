#include "BedLeveling.h"
#include "includes.h"

static inline void blUpdateState(MENUITEMS *menu)
{
  if (getParameter(P_ABL_STATE, 0) == ENABLED)
  {
    menu->items[3].icon = ICON_LEVELING_ON;
    menu->items[3].label.index = LABEL_BL_ENABLE;
  }
  else
  {
    menu->items[3].icon = ICON_LEVELING_OFF;
    menu->items[3].label.index = LABEL_BL_DISABLE;
  }
  menuDrawItem(&menu->items[3], 3);
}

void menuBedLeveling(void)
{
  MENUITEMS bedLevelingItems = {
    // title
    LABEL_ABL_SETTINGS,
    // icon                         label
    {{ICON_LEVELING,                LABEL_ABL},
     {ICON_MESH_EDITOR,             LABEL_MESH_EDITOR},
     {ICON_BACKGROUND,              LABEL_BACKGROUND},
     {ICON_BACKGROUND,              LABEL_BACKGROUND},
//     {ICON_Z_FADE,                  LABEL_ABL_Z}, //SUTAS
     {ICON_PROBE_OFFSET,            LABEL_P_OFFSET},
     {ICON_BACKGROUND,              LABEL_BACKGROUND},
     {ICON_BACKGROUND,              LABEL_BACKGROUND}, //SUTAS
     {ICON_BACK,                    LABEL_BACK},}
  };

  KEY_VALUES key_num = KEY_IDLE;
  void (*menuBL)(void) = menuABL;
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

      menuBL = menuMBL;
      break;

    default:
      break;
  }

/*  if (infoSettings.z_steppers_alignment)
  {
    bedLevelingItems.items[2].icon = ICON_Z_ALIGN;
    bedLevelingItems.items[2].label.index = LABEL_Z_ALIGN;
  }*/  //SUTAS

  if (getParameter(P_ABL_STATE, 0) == ENABLED)
  {
    bedLevelingItems.items[5].icon = ICON_LEVELING_ON;          //SUTAS
    bedLevelingItems.items[5].label.index = LABEL_BL_ENABLE;    //SUTAS
  }
  else
  {
    bedLevelingItems.items[5].icon = ICON_LEVELING_OFF;         //SUTAS
    bedLevelingItems.items[5].label.index = LABEL_BL_DISABLE;   //SUTAS
  }

/*  if (infoMachineSettings.zProbe == ENABLED)
  {
    bedLevelingItems.items[6].icon = ICON_PROBE_OFFSET;
    bedLevelingItems.items[6].label.index = LABEL_P_OFFSET;
  }*/   //SUTAS

  #ifdef ENABLE_BLTOUCH_MENU
    bedLevelingItems.items[3].icon = ICON_BLTOUCH;
    bedLevelingItems.items[3].label.index = LABEL_BLTOUCH;
  #endif
  
  #ifdef ENABLE_G26_VALIDATION
    bedLevelingItems.items[2].icon = ICON_BABYSTEP;
    bedLevelingItems.items[2].label.index = LABEL_TEST;
  #endif
  
  #ifdef ENABLE_FADE_HEIGHT_MENU
    bedLevelingItems.items[6].icon = ICON_Z_FADE;
    bedLevelingItems.items[6].label.index = LABEL_ABL_Z;
  #endif

  menuDrawPage(&bedLevelingItems);

  while (infoMenu.menu[infoMenu.cur] == menuBedLeveling)
  {
    key_num = menuKeyGetValue();
    switch (key_num)
    {
      case KEY_ICON_0:
//        infoMenu.menu[++infoMenu.cur] = menuBL;   //SUTAS
        switch (infoMachineSettings.leveling)
        {
          case BL_BBL:                                     // if Bilinear Bed Leveling
            popupReminder(DIALOG_TYPE_INFO, LABEL_BUSY, LABEL_LEVELLING_STARTED);
            storeCmd("M851 Z0\n");
            storeCmd("G28\n");
            storeCmd("M420 S0\n");
            storeCmd("M140 S60\n");
            storeCmd("M104 S235 T0\n");
            storeCmd("M190 S60\n");
            storeCmd("M109 S235 T0\n");
            storeCmd("M702\n");
            storeCmd("G4 S5\n");
            storeCmd("G29\n");
            storeCmd("G4 S5\n");
            storeCmd("M104 S0 T0\n");
            storeCmd("M140 S0\n");
//            storeCmd("M500\n");
            storeCmd("M118 A1 BBL Complete\n");
            break;

          case BL_UBL:                                     // if Unified Bed Leveling
            infoMenu.menu[++infoMenu.cur] = menuBL;
            //storeCmd("G29 P1\n");
            //storeCmd("G29 P3\n");
            //storeCmd("M118 A1 UBL Complete\n");
            break;
            
          case BL_MBL:                                    // if Mesh Bed Leveling
            infoMenu.menu[++infoMenu.cur] = menuBL;
            break;

          default:                                         // if any other Auto Bed Leveling
            storeCmd("G29\n");
            storeCmd("M118 A1 ABL Complete\n");
            break;
        }
        break;

      case KEY_ICON_1:
        infoMenu.menu[++infoMenu.cur] = menuMeshEditor;
        break;

/*      case KEY_ICON_2:
        if (infoSettings.z_steppers_alignment)
          storeCmd("G34\n");
        break;*/    //SUTAS
        
  #ifdef ENABLE_G26_VALIDATION
      case KEY_ICON_2:
        storeCmd("G28\n");
        storeCmd("G26 C P5\n");
        break;
  #endif
  
  #ifdef ENABLE_BLTOUCH_MENU
      case KEY_ICON_3:
        infoMenu.menu[++infoMenu.cur] = menuBLTouch;
        break;
  #endif

      case KEY_ICON_5:
        if (getParameter(P_ABL_STATE, 0) == ENABLED)
          storeCmd("M420 S0\n");
        else
          storeCmd("M420 S1\n");
        break;

      case KEY_ICON_6:    //SUTAS
      {
        char tempstr[30];
        sprintf(tempstr, "%Min:%.2f | Max:%.2f", Z_FADE_MIN_VALUE, Z_FADE_MAX_VALUE);

        float val = numPadFloat((u8 *) tempstr, getParameter(P_ABL_STATE, 1), 0.0f, false);
        storeCmd("M420 Z%.2f\n", NOBEYOND(Z_FADE_MIN_VALUE, val, Z_FADE_MAX_VALUE));

        menuDrawPage(&bedLevelingItems);
        break;
      }

/*      case KEY_ICON_5:
        storeCmd("M206\n");
        zOffsetSetMenu(false);  // use Home Offset menu
        infoMenu.menu[++infoMenu.cur] = menuZOffset;
        break;*/    //SUTAS

      case KEY_ICON_4:
        if (infoMachineSettings.zProbe == ENABLED)
        {
          storeCmd("M851\n");
          zOffsetSetMenu(true);  // use Probe Offset menu
          infoMenu.menu[++infoMenu.cur] = menuZOffset;
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
