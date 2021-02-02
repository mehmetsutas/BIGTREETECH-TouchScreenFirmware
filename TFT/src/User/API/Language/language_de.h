#ifndef _LANGUAGE_DE_H_
#define _LANGUAGE_DE_H_

    // config.ini Parameter Settings / Feature Settings
    #define STRING_STATUS_SCREEN          "Enable Status Screen"
    #define STRING_BAUDRATE               "Baudrate"
    #define STRING_LANGUAGE               "Deutsch"
    #define STRING_ROTATE_UI              "UI drehen"
    #define STRING_TERMINAL_ACK           "Zeige ACK im Terminal"
    #define STRING_INVERT_X_AXIS          "Invertiere X-Achse"
    #define STRING_INVERT_Y_AXIS          "Invertiere Y-Achse"
    #define STRING_INVERT_Z_AXIS          "Invertiere Z-Achse"
    #define STRING_PERSISTENT_INFO        "Speicherungs-Status"
    #define STRING_FILE_LIST_MODE         "Dateien als Liste"
    #define STRING_ACK_NOTIFICATION       "ACK Benachrichtigungs-Stil"
    #define STRING_DEFAULT_MODE           "Default Mode"
    #define STRING_SERIAL_ALWAYS_ON       "Serial Always ON"
    #define STRING_MARLIN_SHOW_TITLE      "Marlin Mode Title Support"
    #define STRING_MARLIN_FULLSCREEN      "Marlin Modus im Vollbild"
    #define STRING_MARLIN_TYPE            "Marlin Mode Type"
    #define STRING_MOVE_SPEED             "Geschwindigkeit (XYZ)"
    #define STRING_AUTO_LOAD_LEVELING     "Auto Save Load Leveling"
    #define STRING_TOUCHMI_SENSOR         "TouchMI"
    #define STRING_ONBOARD_SD_SUPPORT     "Onboard SD Card Support"
    #define STRING_M27_ALWAYS_ACTIVE      "M27 Always Active"
    #define STRING_LONG_FILENAME_SUPPORT  "Long File Names Support"
    #define STRING_FAN_SPEED_PERCENT      "Fan Speed As Percentage"
    #define STRING_XY_OFFSET_PROBING      "XY Offset Probing Support"
    #define STRING_Z_STEPPERS_ALIGNMENT   "Z Steppers Auto-Alignment"
    #define STRING_PS_ON                  "Automatisch AUS (PS_ON)"
    #define STRING_PS_ON_ACTIVE_HIGH      "Power Supply Active HIGH"
    #define STRING_FIL_RUNOUT             "Filament Sensor"
    #define STRING_FIL_RUNOUT_INVERTING   "Inverted Filament Runout Logic"
    #define STRING_PL_RECOVERY_EN         "Wiederherstellung nach Stromausfall"
    #define STRING_PL_RECOVERY_HOME       "Power Loss Recovery Homing"
    #define STRING_BTT_MINI_UPS           "BTT UPS Support"
    #define STRING_TOUCH_SOUND            "Eingabe"
    #define STRING_TOAST_SOUND            "Toasts"
    #define STRING_ALERT_SOUND            "Popups & Alarme"
    #define STRING_HEATER_SOUND           "Heater notification"
    #define STRING_KNOB_LED_COLOR         "Drehknopf LED Farbe"
    #define STRING_KNOB_LED_IDLE          "Drehknopf LED idle Farbe"
    #define STRING_LCD_BRIGHTNESS         "LCD Helligkeit"
    #define STRING_LCD_IDLE_BRIGHTNESS    "LCD Helligkeit (Standby)"
    #define STRING_LCD_IDLE_DELAY         "LCD Timer Standby"
    #define STRING_START_GCODE_ENABLED    "Gcode vor Druck"
    #define STRING_END_GCODE_ENABLED      "Gcode nach Druck"
    #define STRING_CANCEL_GCODE_ENABLED   "Gcode bei Abbruch"

    // Machine Parameter Settings
    #define STRING_STEPS_SETTING          "Steps pro mm"
    #define STRING_MAXFEEDRATE            "max. Geschwindigkeit"
    #define STRING_MAXACCELERATION        "max. Beschleunigung"
    #define STRING_ACCELERATION           "Beschleunigung"
    #define STRING_JERK                   "Jerk"
    #define STRING_JUNCTION_DEVIATION     "Junction Deviation"
    #define STRING_HOME_OFFSET            "Home Offset"
    #define STRING_FWRETRACT              "FW Rückzug"
    #define STRING_FWRECOVER              "FW Rückeinschub"
    #define STRING_RETRACT_AUTO           "Auto-Rückzug über Firmware"
    #define STRING_OFFSET_TOOL            "Abstand 2te Düse"
    #define STRING_PROBE_OFFSET           "Sensor Offset"
    #define STRING_LIN_ADVANCE            "Linear Advance"
    #define STRING_CURRENT_SETTING        "Treiber Strom (mA)"
    #define STRING_BUMP_SENSITIVITY       "TMC Empfindlichkeit"
    #define STRING_HYBRID_THRESHOLD       "TMC HybridThreshold"
    #define STRING_PRINT_ACCELERATION     "Beschleunigung (Druck)"
    #define STRING_RETRACT_ACCELERATION   "Beschleunigung (Rückzug)"
    #define STRING_TRAVEL_ACCELERATION    "Beschleunigung (Fahrt)"
    #define STRING_RETRACT_LENGTH         "Rückzugslänge"
    #define STRING_RETRACT_SWAP_LENGTH    "Rückzugslänge (Wechsel)"
    #define STRING_RETRACT_FEEDRATE       "Rückzugsgeschwindigkeit"
    #define STRING_RETRACT_Z_LIFT         "Z-Anhebung bei Rückzug"
    #define STRING_RECOVER_LENGTH         "zus. Länge Rückeinschub"
    #define STRING_SWAP_RECOVER_LENGTH    "zus. Länge Rückeinschub (Wechsel)"
    #define STRING_RECOVER_FEEDRATE       "Geschw. Rückeinschub"
    #define STRING_SWAP_RECOVER_FEEDRATE  "Geschw. Rückeinschub (Wechsel)"
    #define STRING_MBL_OFFSET             "MBL Offset"

    // Save / Load
    #define STRING_SAVE                   "Apeichern"
    #define STRING_RESTORE                "Laden"
    #define STRING_RESET                  "Zurücksetzen"
    #define STRING_EEPROM_SAVE_INFO       "Einstellungen im\nEEPROM speichern?"
    #define STRING_EEPROM_RESTORE_INFO    "Einstellungen aus\nEEPROM laden?"
    #define STRING_EEPROM_RESET_INFO      "Standardeinstellungen des Druckers wiederherstellen?"
    #define STRING_SETTINGS_SAVE          "Einstellungen speichern"
    #define STRING_SETTINGS_RESTORE       "Einstellungen wiederherstellen"
    #define STRING_SETTINGS_RESET         "Einstellungen zurücksetzten"
    #define STRING_SETTINGS_RESET_INFO    "Hiermit werden alle\nEinstellungen zurückgesetzt. Fortfahren?"
    #define STRING_SETTINGS_RESET_DONE    "Einstellungen wurden\nerfolgreich zurückgesetzt.\nBitte neustarten."

    // Navigation Buttons
    #define STRING_PAGE_UP                "Seite hoch"
    #define STRING_PAGE_DOWN              "Seite runter"
    #define STRING_UP                     "Auf"
    #define STRING_DOWN                   "Ab"
    #define STRING_NEXT                   "Nächster"
    #define STRING_BACK                   "Zurück"

    // Value Buttons
    #define STRING_INC                    "Erhöhen"
    #define STRING_DEC                    "Verringern"
    #define STRING_LOAD                   "Laden"
    #define STRING_UNLOAD                 "Entladen"
    #define STRING_ON                     "AN"
    #define STRING_OFF                    "AUS"
    #define STRING_AUTO                   "AUTO"
    #define STRING_SMART                  "SMART"
    #define STRING_SLOW                   "Langsam"
    #define STRING_NORMAL                 "Normal"
    #define STRING_FAST                   "Schnell"
    #define STRING_ZERO                   "0"
    #define STRING_HALF                   "Halb"
    #define STRING_FULL                   "Voll"
    #define STRING_CUSTOM                 "Extras"
    #define STRING_CLEAR                  "Löschen"
    #define STRING_DEFAULT                "Standard"

    // Action Buttons
    #define STRING_START                  "Start"
    #define STRING_STOP                   "Stop"
    #define STRING_PAUSE                  "Pause"
    #define STRING_RESUME                 "Wiederaufnahme"
    #define STRING_INIT                   "Init"
    #define STRING_DISCONNECT             "Trennen"
    #define STRING_SHUT_DOWN              "Auschalten (PS_ON)"
    #define STRING_FORCE_SHUT_DOWN        "Erzwinge"
    #define STRING_EMERGENCYSTOP          "NOT AUS!"
    #define STRING_PREHEAT                "Vorheizen"
    #define STRING_PREHEAT_BOTH           "Beide"
    #define STRING_COOLDOWN               "Abkühlen"

    // Dialog Buttons
    #define STRING_CONFIRM                "OK" //Confirm Sign
    #define STRING_CANCEL                 "Abbruch" //Cancel Sign
    #define STRING_WARNING                "Warnung" //Exclamation Sign
    #define STRING_CONTINUE               "Fortsetzen"
    #define STRING_CONFIRMATION           "Sicher?"

    // Process Status
    #define STRING_STATUS                 "Status"
    #define STRING_READY                  "bereit"
    #define STRING_BUSY                   "Bitte warten ..."
    #define STRING_LOADING                "Lade ..."
    #define STRING_UNCONNECTED            "Keine Verbindung zum Drucker!"

    // Process Info
    #define STRING_INFO                   "Info" //Info Sign
    #define STRING_INVALID_VALUE          "Ungültige(r) Wert(e)"
    #define STRING_TIMEOUT_REACHED        "Timeout erreicht!"
    #define STRING_DISCONNECT_INFO        "Verbindung getrennt!"
    #define STRING_SHUTTING_DOWN          "Fahre herunter..."
    #define STRING_WAIT_TEMP_SHUT_DOWN    "Warte bis Hotend-\nTemperatur unter\n %d℃ fällt." // Wait for the temperature of hotend to be lower than 50℃
    #define STRING_POWER_FAILED           "Druck fortsetzen?" //Question Sign
    #define STRING_PROCESS_RUNNING        "Prozess läuft bereits!"
    #define STRING_PROCESS_COMPLETED      "Prozess fertiggestellt!"
    #define STRING_PROCESS_ABORTED        "Prozess abgebrochen!"

    // TFT SD, U_DISK, Onboard SD, Filament Runout Process Commands / Status / Info
    #define STRING_TFTSD                  "TFT SD"
    #define STRING_READ_TFTSD_ERROR       "TFT SD Lesefehler!"
    #define STRING_TFTSD_INSERTED         "SD-Karte eingesteckt!"
    #define STRING_TFTSD_REMOVED          "SD-Karte entfernt!"
    #define STRING_U_DISK                 "USB-Stick"
    #define STRING_READ_U_DISK_ERROR      "USB-Stick Lesefehler!"
    #define STRING_U_DISK_INSERTED        "USB-Stick eingesteckt!"
    #define STRING_U_DISK_REMOVED         "USB-Stick entfernt!"
    #define STRING_ONBOARDSD              "Onboard SD"
    #define STRING_READ_ONBOARDSD_ERROR   "Onboard SD Lesefehler!"
    #define STRING_FILAMENT_RUNOUT        "Filament leer!"

    // Steppers, Print, Probe Process Commands / Status / Info
    #define STRING_DISABLE_STEPPERS       "Deaktiv."
    #define STRING_XY_UNLOCK              "Löse XY"

    #define STRING_START_PRINT            "Druck starten:\n %s?"
    #define STRING_STOP_PRINT             "Druck abbrechen?"
    #define STRING_IS_PAUSE               "Extrudieren während\nDruckvorgang nicht\nmöglich!\nDruck pausieren?"
    #define STRING_M0_PAUSE               "Pause durch M0 Befehl"

    #define STRING_TEST                   "Testen"
    #define STRING_DEPLOY                 "Ausfahren"
    #define STRING_STOW                   "Einziehen"
    #define STRING_REPEAT                 "Wiederholen"

    // Printer Tools
    #define STRING_NOZZLE                 "Düse"
    #define STRING_BED                    "Heizbett"
    #define STRING_CHAMBER                "Kammer"
    #define STRING_FAN                    "Lüfter"

    #define STRING_BLTOUCH                "BLTouch"
    #define STRING_TOUCHMI                "TouchMi"

    // Values
    #define STRING_1_DEGREE               "1℃"
    #define STRING_5_DEGREE               "5℃"
    #define STRING_10_DEGREE              "10℃"

    #define STRING_001_MM                 "0.01mm"
    #define STRING_01_MM                  "0.1mm"
    #define STRING_1_MM                   "1mm"
    #define STRING_5_MM                   "5mm"
    #define STRING_10_MM                  "10mm"
    #define STRING_100_MM                 "100mm"
    #define STRING_200_MM                 "200mm"

    #define STRING_1_PERCENT              "1%"
    #define STRING_5_PERCENT              "5%"
    #define STRING_10_PERCENT             "10%"
    #define STRING_PERCENT_VALUE          "%d%%"

    #define STRING_5_SECONDS              "5 Sek."
    #define STRING_10_SECONDS             "10 Sek."
    #define STRING_30_SECONDS             "30 Sek."
    #define STRING_60_SECONDS             "1 Min."
    #define STRING_120_SECONDS            "2 Min."
    #define STRING_300_SECONDS            "5 Min."

    // Colors
    #define STRING_WHITE                  "weiß"
    #define STRING_BLACK                  "schwarz"
    #define STRING_BLUE                   "blau"
    #define STRING_RED                    "rot"
    #define STRING_GREEN                  "grün"
    #define STRING_CYAN                   "cyan"
    #define STRING_YELLOW                 "gelb"
    #define STRING_BROWN                  "braun"
    #define STRING_GRAY                   "grau"
    #define STRING_ORANGE                 "orange"
    #define STRING_INDIGO                 "indigo"
    #define STRING_VIOLET                 "violet"
    #define STRING_MAGENTA                "magenta"
    #define STRING_PURPLE                 "lila"
    #define STRING_LIME                   "grüngelb"
    #define STRING_DARKBLUE               "dunkelblau"
    #define STRING_DARKGREEN              "dunkelgrün"
    #define STRING_DARKGRAY               "dunkelgrau"

    // Menus
    #define STRING_HEAT                   "Heizen"
    #define STRING_MOVE                   "Bewegen"
    #define STRING_HOME                   "Home XYZ"
    #define STRING_PRINT                  "Drucken"
    #define STRING_EXTRUDE                "Extruder"
    #define STRING_SETTINGS               "Einstellungen"
    #define STRING_SCREEN_SETTINGS        "Bildschirm"
    #define STRING_MACHINE_SETTINGS       "Drucker"
    #define STRING_FEATURE_SETTINGS       "Andere"
    #define STRING_SOUND                  "Töne"
    #define STRING_RGB_SETTINGS           "LED Farbe"
    #define STRING_RGB_OFF                "LED aus"
    #define STRING_TERMINAL               "Terminal"
    #define STRING_LEVELING               "Leveln"
    #define STRING_POINT_1                "Punkt 1"
    #define STRING_POINT_2                "Punkt 2"
    #define STRING_POINT_3                "Punkt 3"
    #define STRING_POINT_4                "Punkt 4"
    #define STRING_POINT_5                "Punkt 5"
    #define STRING_BED_LEVELING           "Leveln"
    #define STRING_BL_COMPLETE            "Bett-Vermessung ausgeführt"
    #define STRING_BL_SMART_FILL          "Fehlende Messpunkte\nwurden berechent.\n \nHinweis: Bitte speichern!"
    #define STRING_BL_ENABLE              "BL: an"
    #define STRING_BL_DISABLE             "BL: aus"
    #define STRING_ABL                    "ABL"
    #define STRING_BBL                    "BBL"
    #define STRING_UBL                    "UBL"
    #define STRING_MBL                    "MBL"
    #define STRING_MBL_SETTINGS           "Bett Vermessung (Raster)"
    #define STRING_ABL_SETTINGS           "Bett Vermessung (auto)"
    #define STRING_ABL_SETTINGS_BBL       "Bett Vermessung (bilinear)"
    #define STRING_ABL_SETTINGS_UBL       "Bett Vermessung (Unified)"
    #define STRING_ABL_SETTINGS_UBL_SAVE  "Im Slot speichern"
    #define STRING_ABL_SETTINGS_UBL_LOAD  "Aus Slot laden"
    #define STRING_ABL_SLOT0              "Slot 0"
    #define STRING_ABL_SLOT1              "Slot 1"
    #define STRING_ABL_SLOT2              "Slot 2"
    #define STRING_ABL_SLOT3              "Slot 3"
    #define STRING_ABL_SLOT_EEPROM        "Slot für den nächsten\nNeustart merken?(Im EEPROM speichern)"
    #define STRING_ABL_Z                  "Z Fade"
    #define STRING_P_OFFSET               "P Offset"
    #define STRING_H_OFFSET               "H Offset"
    #define STRING_DISTANCE               "Abstand"
    #define STRING_LOAD_UNLOAD            "Laden/Entladen"  // needs translation
    #define STRING_LOAD_UNLOAD_SHORT      "(Ent)Laden"  // needs translation
    #define STRING_TOUCHSCREEN_ADJUST     "TSC kalib."
    #define STRING_MORE                   "Mehr"
    #define STRING_SCREEN_INFO            "Info"
    #define STRING_SIMULATOR_BG_COLOR     "Hintergrundfarbe Marlin"
    #define STRING_SIMULATOR_FONT_COLOR   "Schriftfarbe Marlin"
    #define STRING_PERCENTAGE             "Prozent"
    #define STRING_PERCENTAGE_SPEED       "Geschw."
    #define STRING_PERCENTAGE_FLOW        "Fluss"
    #define STRING_BABYSTEP               "BabyStep"
    #define STRING_X_INC                  "X+"
    #define STRING_Y_INC                  "Y+"
    #define STRING_Z_INC                  "Z+"
    #define STRING_X_DEC                  "X-"
    #define STRING_Y_DEC                  "Y-"
    #define STRING_Z_DEC                  "Z-"
    #define STRING_X                      "X"
    #define STRING_Y                      "Y"
    #define STRING_Z                      "Z"
    #define STRING_ADJUST_TITLE           "Touchscreen kalibrieren"
    #define STRING_ADJUST_INFO            "Roten Punkt antippen"
    #define STRING_ADJUST_OK              "Erfolgreich kalibriert"
    #define STRING_ADJUST_FAILED          "Kalibrierung fehlgeschlagen, erneut versuchen."
    #define STRING_UNIFIEDMOVE            "Bewegung"
    #define STRING_UNIFIEDHEAT            "Heiz.Lüft."
    #define STRING_TOUCH_TO_EXIT          "Zum Verlassen, Bildschirm berühren."
    #define STRING_MAINMENU               "Menü"
    #define STRING_PARAMETER_SETTING      "Parameter"
    #define STRING_EEPROM_SETTINGS        "EEPROM"
    #define STRING_LEVELING_EDGE_DISTANCE "Bettecken-Abstand"
    #define STRING_TUNING                 "Tuning"
    #define STRING_PID                    "PID"
    #define STRING_PID_TITLE              "PID autotune"
    #define STRING_PID_START_INFO         "PID autotune benötigt\neinige Zeit.\nWeitermachen?"
    #define STRING_PID_START_INFO_2       "PID autotune läuft!"
    #define STRING_PID_START_INFO_3       "Berühren Sie den Bildschirm erst bei Fertigstellung (Grüne LED)!"
    #define STRING_TUNE_EXTRUDER          "Steps anp."
    #define STRING_TUNE_EXT_EXTRUDE_100   "100mm ext."
    #define STRING_TUNE_EXT_TEMP          "Ext. Kalib. Temp."
    #define STRING_TUNE_EXT_TEMPLOW       "Temparatur zu niedrig!\nMinimale Temparatur: %d C"
    #define STRING_TUNE_EXT_DESIREDVAL    "Temparatur hat gewünschten Wert noch nicht erreicht"
    #define STRING_TUNE_EXT_MARK120MM     "Filament 120 mm über Einlass markieren,\ndann '%s' drücken & nach Extrusion\nerneut messen"
    #define STRING_TUNE_EXT_HEATOFF       "Heizung abschalten?"
    #define STRING_TUNE_EXT_ADJ_ESTEPS    "E-Steps einstellen"
    #define STRING_TUNE_EXT_ESTEPS_SAVED  "Neue E-Steps gespeichert!\nBitte auch im EEPROM speichern.\nNeuer Wert: %0.2f"
    #define STRING_TUNE_EXT_MEASURED      "Restliche Länge:"
    #define STRING_TUNE_EXT_OLD_ESTEP     "Alte E-Steps: %0.2f"
    #define STRING_TUNE_EXT_NEW_ESTEP     "Neue E-Steps: %0.2f"
    #define STRING_CONNECTION_SETTINGS    "Verbindung"
    #define STRING_NOTIFICATIONS          "Benachrichtigungen"
    #define STRING_MESH_EDITOR            "Mesh edit."
    #define STRING_MESH_TUNER             "Mesh anp."
    #define STRING_CASE_LIGHT             "Case Licht"
    #define STRING_LOAD_STARTED           "Lade Filament.\nBitte auf Abschluss des\nVorgangs warten."
    #define STRING_UNLOAD_STARTED         "Entlade Filament.\nBitte auf Abschluss des\nVorgangs warten."
    #define STRING_HEATERS_ON             "Einige Heizer sind noch eingeschaltet.\nSollen diese deaktiviert werden?"
    #define STRING_PRINT_FINISHED         "Druck beendet"
    #define STRING_MAIN_SCREEN            "Hauptmenü"
    #define STRING_PREVIOUS_PRINT_DATA    "Info"
    #define STRING_PRINT_TIME             "Druck Zeit: %02u:%02u:%02u\n"
    #define STRING_FILAMENT_LENGTH        "Filament Länge: %1.2fm\n"
    #define STRING_FILAMENT_WEIGHT        "Filament Gewicht: %1.2fg\n"
    #define STRING_FILAMENT_COST          "Filament Kosten: %1.2f\n"
    #define STRING_NO_FILAMENT_STATS      "Filament Daten nicht verfügbar."
    #define STRING_CLICK_FOR_MORE         "Klick für Statistik"
    #define STRING_EXT_TEMPLOW            "Hotend Temperatur ist unter\nminimum Temperatur (%d℃)."
    #define STRING_HEAT_HOTEND            "Heize Hotend auf %d℃?"
    #define STRING_Z_ALIGN                "Z Align"
    #define STRING_LEVELLING_STARTED      "Levelling started. Heating.\nDo not start another operation\nuntil it's done." 

#endif
