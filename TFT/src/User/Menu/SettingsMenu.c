#include "SettingsMenu.h"
#include "includes.h"

const MENUITEMS settingsItems = {
  // title
  LABEL_SETTINGS,
  // icon                         label
  {{ICON_SCREEN_SETTINGS,         LABEL_SCREEN_SETTINGS},
//   {ICON_MACHINE_SETTINGS,        LABEL_MACHINE_SETTINGS},    //SUTAS
   {ICON_PARAMETER,               LABEL_PARAMETER_SETTING},
   {ICON_FEATURE_SETTINGS,        LABEL_FEATURE_SETTINGS},
   {ICON_SCREEN_INFO,             LABEL_SCREEN_INFO},
//   {ICON_CONNECTION_SETTINGS,     LABEL_CONNECTION_SETTINGS},
   {ICON_PID,                     LABEL_PID},
   {ICON_EEPROM_SAVE,             LABEL_EEPROM_SETTINGS},
   {ICON_BACKGROUND,              LABEL_BACKGROUND},
   {ICON_BACK,                    LABEL_BACK},}
};

// const GUI_POINT clocks[] = {
//   {0 * LCD_WIDTH / 3, 0 * BYTE_HEIGHT},
//   {1 * LCD_WIDTH / 3, 0 * BYTE_HEIGHT},
//   {2 * LCD_WIDTH / 3, 0 * BYTE_HEIGHT},
//   {0 * LCD_WIDTH / 3, 1 * BYTE_HEIGHT},
//   {1 * LCD_WIDTH / 3, 1 * BYTE_HEIGHT},
//   {2 * LCD_WIDTH / 3, 1 * BYTE_HEIGHT},};

static uint8_t firmare_name[64] = "Unknown system";  // Marlin firmware version
uint8_t machine_type[64] = "3D Printer";  // Marlin machine type
uint8_t access_point[64] = "Connecting...";  // Access point for RepRapFirmware
uint8_t ip_address[20] = "0.0.0.0";  // IP address for RepRapFirmware

bool m78_waiting;

PRINTSTATS printCounter;

void counterSet(uint8_t *param, uint8_t stat[], uint8_t len)
{
  uint8_t i;
  for (i = 0; ((i < 20) && (param[i] != '\0') && (param[i] != '\n') && (i < len)); i++) {
    stat[i] = param[i];
  }
  stat[i] = '\0';
}

void infoSetFirmwareName(uint8_t *name, uint8_t name_len)
{
  if (name_len > sizeof(firmare_name) - 1)
    name_len = sizeof(firmare_name) - 1;
  uint8_t i;
  for (i = 0; i < name_len; i++)
  {
    firmare_name[i] = name[i];
  }
  firmare_name[i] = 0;
}

void infoSetMachineType(uint8_t *machine, uint8_t type_len)
{
  if (type_len > sizeof(machine_type) - 1)
    type_len = sizeof(machine_type) - 1;
  uint8_t i;
  for (i = 0; i < type_len; i++)
  {
    machine_type[i] = machine[i];
  }
  machine_type[i] = 0;
  statusScreen_setReady();
}

void infoSetAccessPoint(uint8_t *ssid, uint8_t ssid_len)
{
  if (ssid_len > sizeof(access_point) - 1)
    ssid_len = sizeof(access_point) - 1;
  uint8_t i;
  for (i = 0; i < ssid_len; i++)
  {
    access_point[i] = ssid[i];
  }
  access_point[i] = 0;
}

void infoSetIPAddress(uint8_t *ip, uint8_t ip_len)
{
  if (ip_len > sizeof(ip_address) - 1)
    ip_len = sizeof(ip_address) - 1;
  uint8_t i;
  for (i = 0; i < ip_len; i++)
  {
    ip_address[i] = ip[i];
  }
  ip_address[i] = 0;
}

void drawMenuService(void)   //SUTAS
{
  char buf[128];

  GUI_Clear(infoSettings.bg_color);
  
  GUI_SetColor(0xDB40);

  const uint16_t top_y = 0;
  uint8_t start_x = 18 * BYTE_WIDTH +10; //sizeof("1200 Saat Bakımı:") * BYTE_WIDTH;
  const GUI_RECT version[7] = {
    {start_x, top_y + 1.5*BYTE_HEIGHT +3 , LCD_WIDTH, top_y + 3*BYTE_HEIGHT},
    {start_x, top_y + 3*BYTE_HEIGHT +3, LCD_WIDTH, top_y + 4.5*BYTE_HEIGHT},
    {start_x, top_y + 4.5*BYTE_HEIGHT +3, LCD_WIDTH, top_y + 6*BYTE_HEIGHT},
    {start_x, top_y + 6*BYTE_HEIGHT +3, LCD_WIDTH, top_y + 7.5*BYTE_HEIGHT},
    {start_x, top_y + 7.5*BYTE_HEIGHT +3, LCD_WIDTH, top_y + 9*BYTE_HEIGHT},
    {start_x, top_y + 9*BYTE_HEIGHT +3, LCD_WIDTH, top_y + 10.5*BYTE_HEIGHT},
    {start_x, top_y + 10.5*BYTE_HEIGHT +3, LCD_WIDTH, top_y + 12*BYTE_HEIGHT}
    };
  //draw titles
  GUI_DispString(10, version[0].y0, (uint8_t *)"Toplam Baskı    :");
  GUI_DispString(10, version[1].y0, (uint8_t *)"Toplam Süre     :");
  GUI_DispString(10, version[2].y0, (uint8_t *)"En Uzun Baskı   :");
  GUI_DispString(10, version[3].y0, (uint8_t *)"Toplam Filaman  :");
#ifdef SERVICE1
  sprintf(buf, "%-17s : ", SERVICE1);
  GUI_DispString(10, version[4].y0, (uint8_t *)buf);
#endif
#ifdef SERVICE2
  sprintf(buf, "%-17s: ", SERVICE2);
  GUI_DispString(10, version[5].y0, (uint8_t *)buf);
#endif
#ifdef SERVICE3
  sprintf(buf, "%-17s: ", SERVICE3);
  GUI_DispString(10, version[6].y0, (uint8_t *)buf);
#endif
  //draw info
  GUI_SetColor(GRAY);
  GUI_HLine(0, version[0].y0 - 1, LCD_WIDTH);
  GUI_HLine(0, version[4].y0 - 3, LCD_WIDTH);
  GUI_HLine(0, (LCD_HEIGHT - 1.5 * BYTE_HEIGHT -4), LCD_WIDTH);
  
  GUI_DispLenString(10, (TITLE_END_Y - BYTE_HEIGHT) / 2, LABEL_INFO, LCD_WIDTH - 20, true);

  sprintf(buf, "%u", printCounter.prints);
  GUI_DispStringInPrectEOL(&version[0], (uint8_t *)buf);
  GUI_DispStringInPrectEOL(&version[1], (uint8_t *)printCounter.total_time);
  GUI_DispStringInPrectEOL(&version[2], (uint8_t *)printCounter.longest_job);
  GUI_DispStringInPrectEOL(&version[3], (uint8_t *)printCounter.filament_used);

#ifdef SERVICE1
  GUI_DispStringInPrectEOL(&version[4], (uint8_t *)printCounter.service1);
#endif
#ifdef SERVICE2
  GUI_DispStringInPrectEOL(&version[5], (uint8_t *)printCounter.service2);
#endif
#ifdef SERVICE3
  GUI_DispStringInPrectEOL(&version[6], (uint8_t *)printCounter.service3);
#endif
  
  GUI_DispStringCenter((LCD_WIDTH / 2), (LCD_HEIGHT - 1.5 * BYTE_HEIGHT + 4), LABEL_TOUCH_TO_EXIT);
}

void menuService(void)   //SUTAS
{
  uint32_t m78_refresh_wait = OS_GetTimeMs() + 5000;
  
  while (m78_waiting && (m78_refresh_wait > OS_GetTimeMs())) loopBackEnd();

  drawMenuService();
  
  while(!isPress()) loopBackEnd();

  while(isPress())  loopBackEnd();

  GUI_RestoreColorDefault();
  infoMenu.cur--;
}

// Version infomation
void menuInfo(void)
{
  char buf[128];

  const char *const hardware = "BIGTREETECH_" HARDWARE_VERSION;
  const char *const firmware = HARDWARE_VERSION"." STRINGIFY(SOFTWARE_VERSION) " " __DATE__;

  GUI_Clear(infoSettings.bg_color);
  GUI_SetColor(GRAY);

  // sprintf(buf, "SYS:%dMhz", mcuClocks.rccClocks.SYSCLK_Frequency / 1000000);
  // GUI_DispString(clocks[0].x, clocks[0].y, (uint8_t *)buf);

  // sprintf(buf, "APB1:%dMhz", mcuClocks.rccClocks.PCLK1_Frequency / 1000000);
  // GUI_DispString(clocks[1].x, clocks[1].y, (uint8_t *)buf);

  // sprintf(buf, "P1Tim:%dMhz", mcuClocks.PCLK1_Timer_Frequency / 1000000);
  // GUI_DispString(clocks[2].x, clocks[2].y, (uint8_t *)buf);

  // sprintf(buf, "AHB:%dMhz", mcuClocks.rccClocks.HCLK_Frequency / 1000000);
  // GUI_DispString(clocks[3].x, clocks[3].y, (uint8_t *)buf);

  // sprintf(buf, "APB2:%dMhz", mcuClocks.rccClocks.PCLK2_Frequency / 1000000);
  // GUI_DispString(clocks[4].x, clocks[4].y, (uint8_t *)buf);

  // sprintf(buf, "P2Tim:%dMhz", mcuClocks.PCLK2_Timer_Frequency / 1000000);
  // GUI_DispString(clocks[5].x, clocks[5].y, (uint8_t *)buf);

  // GUI_HLine(0, clocks[5].y + BYTE_HEIGHT, LCD_WIDTH);

  // spi flash info
  float usedMB = (float)FLASH_USED/1048576;
  sprintf(buf, "Used %.2f%% (%.2fMB/%uMB)", flashUsedPercentage(), usedMB, (W25Qxx_ReadCapacity()/1048576));

  const uint16_t top_y = 0; //(LCD_HEIGHT - (7 * BYTE_HEIGHT)) / 2;  // 8 firmware info lines + 1 SPI flash info line
  const uint16_t start_x = strlen("Firmware:") * BYTE_WIDTH;
  const GUI_RECT version[7] = {
    {start_x, top_y + 0*BYTE_HEIGHT, LCD_WIDTH, top_y + 2*BYTE_HEIGHT},
    {start_x, top_y + 2*BYTE_HEIGHT, LCD_WIDTH, top_y + 4*BYTE_HEIGHT},
    {start_x, top_y + 4*BYTE_HEIGHT, LCD_WIDTH, top_y + 5*BYTE_HEIGHT},
    {start_x, top_y + 5*BYTE_HEIGHT, LCD_WIDTH, top_y + 6*BYTE_HEIGHT},
    {start_x, top_y + 6*BYTE_HEIGHT, LCD_WIDTH, top_y + 7*BYTE_HEIGHT},
    {start_x, top_y + 7*BYTE_HEIGHT, LCD_WIDTH, top_y + 8*BYTE_HEIGHT},
    {start_x, top_y + 8*BYTE_HEIGHT, LCD_WIDTH, top_y + 9*BYTE_HEIGHT},
  };

  // draw titles
  GUI_DispString(0, version[0].y0, (uint8_t *)"System  :");
  GUI_DispString(0, version[1].y0, (uint8_t *)"Machine :");
  GUI_DispString(0, version[2].y0, (uint8_t *)"Board   :");
  GUI_DispString(0, version[3].y0, (uint8_t *)"Firmware:");
  GUI_DispString(0, version[4].y0, (uint8_t *)"SPIFlash:");
  if (infoMachineSettings.firmwareType == FW_REPRAPFW)
  {
    GUI_DispString(0, version[5].y0, (uint8_t *)"WIFI    :");
    GUI_DispString(0, version[6].y0, (uint8_t *)"IP      :");
  }

  // draw info
  GUI_SetColor(0xDB40);
  GUI_DispStringInPrectEOL(&version[0], firmare_name);
  GUI_DispStringInPrectEOL(&version[1], machine_type);
  GUI_DispStringInPrectEOL(&version[2], (uint8_t *)hardware);
  GUI_DispStringInPrectEOL(&version[3], (uint8_t *)firmware);
  GUI_DispStringInPrectEOL(&version[4], (uint8_t *)buf);
  if (infoMachineSettings.firmwareType == FW_REPRAPFW)
  {
    GUI_DispStringInPrectEOL(&version[5], (uint8_t *)access_point);
    GUI_DispStringInPrectEOL(&version[6], (uint8_t *)ip_address);
  }

  GUI_SetColor(GRAY);

  GUI_HLine(0, LCD_HEIGHT - (BYTE_HEIGHT*2), LCD_WIDTH);

  GUI_DispStringInRect(20, LCD_HEIGHT - (BYTE_HEIGHT*2), LCD_WIDTH-20, LCD_HEIGHT, textSelect(LABEL_TOUCH_TO_EXIT));

  while (!isPress()) loopBackEnd();
  BUZZER_PLAY(sound_keypress);
  while (isPress()) loopBackEnd();

  GUI_RestoreColorDefault();
  infoMenu.cur--;
}

void menuSettings(void)
{
  KEY_VALUES key_num = KEY_IDLE;

  menuDrawPage(&settingsItems);

  while (infoMenu.menu[infoMenu.cur] == menuSettings)
  {
    key_num = menuKeyGetValue();
    switch (key_num)
    {
      case KEY_ICON_0:
        infoMenu.menu[++infoMenu.cur] = menuScreenSettings;
        break;

      case KEY_ICON_1:
        mustStoreCmd("M503 S0\n");
        infoMenu.menu[++infoMenu.cur] = menuParameterSettings;    //SUTAS
        break;

      case KEY_ICON_2:
        infoMenu.menu[++infoMenu.cur] = menuFeatureSettings;
        break;

      case KEY_ICON_3:
        #ifdef PRINT_COUNTER      //SUTAS
          storeCmd("M78\n");
          m78_waiting = true;
          infoMenu.menu[++infoMenu.cur] = menuService;
        #else
          infoMenu.menu[++infoMenu.cur] = menuInfo;
        #endif
        break;

/*      case KEY_ICON_4:
        infoMenu.menu[++infoMenu.cur] = menuConnectionSettings;
        break;*/
        
      case KEY_ICON_4:
        infoMenu.menu[++infoMenu.cur] = menuPid;
        break;
		
      case KEY_ICON_5:
        infoMenu.menu[++infoMenu.cur] = menuEepromSettings;
        break;

      case KEY_ICON_7:
        infoMenu.cur--;
        break;

      default:
        break;
    }

    loopProcess();
  }
}
