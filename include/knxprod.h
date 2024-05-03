#pragma once

#define paramDelay(time) (uint32_t)( \
            (time & 0xC000) == 0xC000 ? (time & 0x3FFF) * 100 : \
            (time & 0xC000) == 0x0000 ? (time & 0x3FFF) * 1000 : \
            (time & 0xC000) == 0x4000 ? (time & 0x3FFF) * 60000 : \
            (time & 0xC000) == 0x8000 ? ((time & 0x3FFF) > 1000 ? 3600000 : \
                                            (time & 0x3FFF) * 3600000 ) : 0 )
#define PT_ir_receive_virtual 0
#define PT_ir_receive_color 1
#define PT_switch_type_in_um 0
#define PT_switch_type_in_on 1
#define PT_switch_type_in_off 2
#define PT_ir_send_switch 0
#define PT_ir_send_value 1
#define PT_ir_send_scene 2
#define PT_inout_off 0
#define PT_inout_in 1
#define PT_inout_out 2
#define PT_switch_type_out_any 0
#define PT_switch_type_out_on 1
#define PT_switch_type_out_off 2

//--------------------Allgemein---------------------------
#define MAIN_OpenKnxId 0xA4
#define MAIN_ApplicationNumber 0x00
#define MAIN_ApplicationVersion 0x03
#define MAIN_OrderNumber "GW-UP1-IR.01"
#define MAIN_ParameterSize 2799
#define MAIN_MaxKoNumber 163



//---------------------Modules----------------------------

//-----Module specific starts
#define BASE_ParamBlockOffset 0
#define BASE_ParamBlockSize 45
#define IR_ParamBlockOffset 45
#define IR_ParamBlockSize 6
#define BTN_ParamBlockOffset 105
#define BTN_ParamBlockSize 4
#define BASE_KoOffset 1
#define BASE_KoBlockSize 12
#define IR_KoOffset 13
#define IR_KoBlockSize 3
#define BTN_KoOffset 43
#define BTN_KoBlockSize 12


#define BTN_KoCalcNumber(index) (index + BTN_KoOffset + _channelIndex * BTN_KoBlockSize)
#define BTN_KoCalcIndex(number) ((number >= BTN_KoCalcNumber(0) && number < BTN_KoCalcNumber(BTN_KoBlockSize)) ? (number - BTN_KoOffset) % BTN_KoBlockSize : -1)


//-----Module: ir
#define IR_inOutType		0x0000
#define IR_inOutType_Shift	6
#define IR_inOutType_Mask	0x0003
// Offset: 0, Size: 2 Bit, Text: Kanal
#define ParamIR_inOutTypeIndex(X) ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * X + 0)) >> IR_inOutType_Shift) & IR_inOutType_Mask))
// Offset: 0, Size: 2 Bit, Text: Kanal
#define ParamIR_inOutType ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 0)) >> IR_inOutType_Shift) & IR_inOutType_Mask))
#define IR_inType		0x0001
// UnionOffset: 1, ParaOffset: 0, Size: 1 Bit, Text: Funktion
#define ParamIR_inTypeIndex(X) knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * X + 1), 0)
// UnionOffset: 1, ParaOffset: 0, Size: 1 Bit, Text: Funktion
#define ParamIR_inType knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 1), 0)
#define IR_inBtnNumber		0x0001
#define IR_inBtnNumber_Shift	7
#define IR_inBtnNumber_Mask	0x007F
// UnionOffset: 1, ParaOffset: 0, BitOffset: 2, Size: 7 Bit, Text: Virtueller Taster
#define ParamIR_inBtnNumberIndex(X) ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * X + 1)) >> IR_inBtnNumber_Shift) & IR_inBtnNumber_Mask))
// UnionOffset: 1, ParaOffset: 0, BitOffset: 2, Size: 7 Bit, Text: Virtueller Taster
#define ParamIR_inBtnNumber ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 1)) >> IR_inBtnNumber_Shift) & IR_inBtnNumber_Mask))
#define IR_inColor_RGB		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 6, Size: 24 Bit (3 Byte), Text: Farbe
#define ParamIR_inColor_RGBIndex(X) knx.paramData((IR_ParamBlockOffset + IR_ParamBlockSize * X + 1))
// UnionOffset: 1, ParaOffset: 0, BitOffset: 6, Size: 24 Bit (3 Byte), Text: Farbe
#define ParamIR_inColor_RGB knx.paramData((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 1))
#define IR_inColor_HSV		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 6, Size: 24 Bit (3 Byte), Text: Farbe
#define ParamIR_inColor_HSVIndex(X) knx.paramData((IR_ParamBlockOffset + IR_ParamBlockSize * X + 1))
// UnionOffset: 1, ParaOffset: 0, BitOffset: 6, Size: 24 Bit (3 Byte), Text: Farbe
#define ParamIR_inColor_HSV knx.paramData((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 1))
#define IR_inColorType		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 5, Size: 1 Bit, Text: Ausgabe als
#define ParamIR_inColorTypeIndex(X) knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * X + 1), 5)
// UnionOffset: 1, ParaOffset: 0, BitOffset: 5, Size: 1 Bit, Text: Ausgabe als
#define ParamIR_inColorType knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 1), 5)
#define IR_outType		0x0001
#define IR_outType_Shift	6
#define IR_outType_Mask	0x0003
// UnionOffset: 1, ParaOffset: 0, Size: 2 Bit, Text: Funktion
#define ParamIR_outTypeIndex(X) ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * X + 1)) >> IR_outType_Shift) & IR_outType_Mask))
// UnionOffset: 1, ParaOffset: 0, Size: 2 Bit, Text: Funktion
#define ParamIR_outType ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 1)) >> IR_outType_Shift) & IR_outType_Mask))
#define IR_outValue		0x0002
// UnionOffset: 1, ParaOffset: 1, Size: 8 Bit (1 Byte), Text: Wert
#define ParamIR_outValueIndex(X) ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * X + 2)))))
// UnionOffset: 1, ParaOffset: 1, Size: 8 Bit (1 Byte), Text: Wert
#define ParamIR_outValue ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 2)))))
#define IR_outSwitch		0x0002
#define IR_outSwitch_Shift	6
#define IR_outSwitch_Mask	0x0003
// UnionOffset: 1, ParaOffset: 1, Size: 2 Bit, Text: Senden bei
#define ParamIR_outSwitchIndex(X) ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * X + 2)) >> IR_outSwitch_Shift) & IR_outSwitch_Mask))
// UnionOffset: 1, ParaOffset: 1, Size: 2 Bit, Text: Senden bei
#define ParamIR_outSwitch ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 2)) >> IR_outSwitch_Shift) & IR_outSwitch_Mask))
#define IR_outScene1		0x0001
#define IR_outScene1_Shift	3
#define IR_outScene1_Mask	0x007F
// UnionOffset: 1, ParaOffset: 0, BitOffset: 6, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene1Index(X) ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * X + 1)) >> IR_outScene1_Shift) & IR_outScene1_Mask))
// UnionOffset: 1, ParaOffset: 0, BitOffset: 6, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene1 ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 1)) >> IR_outScene1_Shift) & IR_outScene1_Mask))
#define IR_outScene2		0x0002
#define IR_outScene2_Shift	4
#define IR_outScene2_Mask	0x007F
// UnionOffset: 1, ParaOffset: 1, BitOffset: 5, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene2Index(X) ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * X + 2)) >> IR_outScene2_Shift) & IR_outScene2_Mask))
// UnionOffset: 1, ParaOffset: 1, BitOffset: 5, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene2 ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 2)) >> IR_outScene2_Shift) & IR_outScene2_Mask))
#define IR_outScene3		0x0003
#define IR_outScene3_Shift	5
#define IR_outScene3_Mask	0x007F
// UnionOffset: 1, ParaOffset: 2, BitOffset: 4, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene3Index(X) ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * X + 3)) >> IR_outScene3_Shift) & IR_outScene3_Mask))
// UnionOffset: 1, ParaOffset: 2, BitOffset: 4, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene3 ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 3)) >> IR_outScene3_Shift) & IR_outScene3_Mask))
#define IR_outScene4		0x0004
#define IR_outScene4_Shift	6
#define IR_outScene4_Mask	0x007F
// UnionOffset: 1, ParaOffset: 3, BitOffset: 3, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene4Index(X) ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * X + 4)) >> IR_outScene4_Shift) & IR_outScene4_Mask))
// UnionOffset: 1, ParaOffset: 3, BitOffset: 3, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene4 ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 4)) >> IR_outScene4_Shift) & IR_outScene4_Mask))
#define IR_outSceneActive1		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text: Szene A
#define ParamIR_outSceneActive1Index(X) knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * X + 1), 2)
// UnionOffset: 1, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text: Szene A
#define ParamIR_outSceneActive1 knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 1), 2)
#define IR_outSceneActive2		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 3, Size: 1 Bit, Text: Szene B
#define ParamIR_outSceneActive2Index(X) knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * X + 1), 3)
// UnionOffset: 1, ParaOffset: 0, BitOffset: 3, Size: 1 Bit, Text: Szene B
#define ParamIR_outSceneActive2 knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 1), 3)
#define IR_outSceneActive3		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 4, Size: 1 Bit, Text: Szene C
#define ParamIR_outSceneActive3Index(X) knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * X + 1), 4)
// UnionOffset: 1, ParaOffset: 0, BitOffset: 4, Size: 1 Bit, Text: Szene C
#define ParamIR_outSceneActive3 knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 1), 4)
#define IR_outSceneActive4		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 5, Size: 1 Bit, Text: Szene D
#define ParamIR_outSceneActive4Index(X) knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * X + 1), 5)
// UnionOffset: 1, ParaOffset: 0, BitOffset: 5, Size: 1 Bit, Text: Szene D
#define ParamIR_outSceneActive4 knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + 1), 5)
//!< Number: 1, Text: IR{{argChan}} <- {{0:}}, Function: Farbe
#define IR_Koco_n1 1
#define KoIR_co_n1Index(X) knx.getGroupObject(IR_KoOffset + IR_KoBlockSize * X + 1)
#define KoIR_co_n1 knx.getGroupObject(IR_KoOffset + IR_KoBlockSize * channelIndex() + 1)
//!< Number: 2, Text: IR{{argChan}} <- {{0:}}, Function: Status
#define IR_Koco_n2 2
#define KoIR_co_n2Index(X) knx.getGroupObject(IR_KoOffset + IR_KoBlockSize * X + 2)
#define KoIR_co_n2 knx.getGroupObject(IR_KoOffset + IR_KoBlockSize * channelIndex() + 2)

//-----Module: Common Share
#define BASE_StartupDelayBase		0x0000
#define BASE_StartupDelayBase_Shift	6
#define BASE_StartupDelayBase_Mask	0x0003
// UnionOffset: 0, ParaOffset: 0, Size: 2 Bit, Text: Zeitbasis
#define ParamBASE_StartupDelayBase ((uint)((knx.paramByte((BASE_ParamBlockOffset + 0)) >> BASE_StartupDelayBase_Shift) & BASE_StartupDelayBase_Mask))
#define BASE_StartupDelayTime		0x0000
#define BASE_StartupDelayTime_Mask	0x3FFF
// UnionOffset: 0, ParaOffset: 0, BitOffset: 2, Size: 14 Bit, Text: Zeit
#define ParamBASE_StartupDelayTime ((uint)((knx.paramWord((BASE_ParamBlockOffset + 0))) & BASE_StartupDelayTime_Mask))
#define ParamBASE_StartupDelayTimeMS (paramDelay(ParamBASE_StartupDelayTime))
#define BASE_HeartbeatDelayBase		0x0002
#define BASE_HeartbeatDelayBase_Shift	6
#define BASE_HeartbeatDelayBase_Mask	0x0003
// UnionOffset: 0, ParaOffset: 2, Size: 2 Bit, Text: Zeitbasis
#define ParamBASE_HeartbeatDelayBase ((uint)((knx.paramByte((BASE_ParamBlockOffset + 2)) >> BASE_HeartbeatDelayBase_Shift) & BASE_HeartbeatDelayBase_Mask))
#define BASE_HeartbeatDelayTime		0x0002
#define BASE_HeartbeatDelayTime_Mask	0x3FFF
// UnionOffset: 0, ParaOffset: 2, BitOffset: 2, Size: 14 Bit, Text: Zeit
#define ParamBASE_HeartbeatDelayTime ((uint)((knx.paramWord((BASE_ParamBlockOffset + 2))) & BASE_HeartbeatDelayTime_Mask))
#define ParamBASE_HeartbeatDelayTimeMS (paramDelay(ParamBASE_HeartbeatDelayTime))
#define BASE_Timezone		0x0004
#define BASE_Timezone_Shift	3
#define BASE_Timezone_Mask	0x001F
// UnionOffset: 4, ParaOffset: 0, Size: 5 Bit, Text: Zeitzone
#define ParamBASE_Timezone ((uint)((knx.paramByte((BASE_ParamBlockOffset + 4)) >> BASE_Timezone_Shift) & BASE_Timezone_Mask))
#define BASE_CombinedTimeDate		0x0004
// UnionOffset: 4, ParaOffset: 0, BitOffset: 5, Size: 1 Bit, Text: Empfangen über
#define ParamBASE_CombinedTimeDate knx.paramBit((BASE_ParamBlockOffset + 4), 5)
#define BASE_SummertimeAll		0x0004
#define BASE_SummertimeAll_Mask	0x0003
// UnionOffset: 4, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text: Sommerzeit ermitteln durch
#define ParamBASE_SummertimeAll ((uint)((knx.paramByte((BASE_ParamBlockOffset + 4))) & BASE_SummertimeAll_Mask))
#define BASE_SummertimeDE		0x0004
#define BASE_SummertimeDE_Mask	0x0003
// UnionOffset: 4, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text: Sommerzeit ermitteln durch
#define ParamBASE_SummertimeDE ((uint)((knx.paramByte((BASE_ParamBlockOffset + 4))) & BASE_SummertimeDE_Mask))
#define BASE_SummertimeWorld		0x0004
#define BASE_SummertimeWorld_Mask	0x0003
// UnionOffset: 4, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text: Sommerzeit ermitteln durch
#define ParamBASE_SummertimeWorld ((uint)((knx.paramByte((BASE_ParamBlockOffset + 4))) & BASE_SummertimeWorld_Mask))
#define BASE_SummertimeKO		0x0004
#define BASE_SummertimeKO_Mask	0x0003
// UnionOffset: 4, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text: Sommerzeit ermitteln durch
#define ParamBASE_SummertimeKO ((uint)((knx.paramByte((BASE_ParamBlockOffset + 4))) & BASE_SummertimeKO_Mask))
#define BASE_Latitude		0x0005
// UnionOffset: 5, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: Breitengrad
#define ParamBASE_Latitude knx.paramFloat((BASE_ParamBlockOffset + 5), Float_Enc_IEEE754Single)
#define BASE_Longitude		0x0009
// UnionOffset: 5, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: Längengrad
#define ParamBASE_Longitude knx.paramFloat((BASE_ParamBlockOffset + 9), Float_Enc_IEEE754Single)
#define BASE_Diagnose		0x000D
// UnionOffset: 13, ParaOffset: 0, Size: 1 Bit, Text: Diagnoseobjekt anzeigen
#define ParamBASE_Diagnose knx.paramBit((BASE_ParamBlockOffset + 13), 0)
#define BASE_Watchdog		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 1, Size: 1 Bit, Text: Watchdog aktivieren
#define ParamBASE_Watchdog knx.paramBit((BASE_ParamBlockOffset + 13), 1)
#define BASE_ReadTimeDate		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text: Bei Neustart vom Bus lesen
#define ParamBASE_ReadTimeDate knx.paramBit((BASE_ParamBlockOffset + 13), 2)
#define BASE_HeartbeatExtended		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 3, Size: 1 Bit, Text: Erweitertes "In Betrieb"
#define ParamBASE_HeartbeatExtended knx.paramBit((BASE_ParamBlockOffset + 13), 3)
#define BASE_ManualSave		0x000D
#define BASE_ManualSave_Mask	0x0007
// UnionOffset: 13, ParaOffset: 0, BitOffset: 5, Size: 3 Bit, Text: Manuelles speichern
#define ParamBASE_ManualSave ((uint)((knx.paramByte((BASE_ParamBlockOffset + 13))) & BASE_ManualSave_Mask))
#define BASE_PeriodicSave		0x000E
// UnionOffset: 13, ParaOffset: 1, Size: 8 Bit (1 Byte), Text: Zyklisches speichern
#define ParamBASE_PeriodicSave ((uint)((knx.paramByte((BASE_ParamBlockOffset + 14)))))
//!< Number: 1, Text: In Betrieb, Function: Zyklisch
#define BASE_KoHeartbeat 1
#define KoBASE_Heartbeat knx.getGroupObject(1)
//!< Number: 2, Text: Uhrzeit/Datum, Function: Eingang
#define BASE_KoTime 2
#define KoBASE_Time knx.getGroupObject(2)
//!< Number: 3, Text: Datum, Function: Eingang
#define BASE_KoDate 3
#define KoBASE_Date knx.getGroupObject(3)
//!< Number: 7, Text: Diagnose, Function: Diagnoseobjekt
#define BASE_KoDiagnose 7
#define KoBASE_Diagnose knx.getGroupObject(7)
//!< Number: 10, Text: Sommerzeit aktiv, Function: Eingang
#define BASE_KoIsSummertime 10
#define KoBASE_IsSummertime knx.getGroupObject(10)
//!< Number: 11, Text: Speichern, Function: Eingang
#define BASE_KoManualSave 11
#define KoBASE_ManualSave knx.getGroupObject(11)

//-----Module: VirtualButton Share
#define BTN_ReactionTimeMultiClick		0x0000
// UnionOffset: 0, ParaOffset: 0, Size: 8 Bit (1 Byte), Text:   Mehrfach-Klick
#define ParamBTN_ReactionTimeMultiClick ((uint)((knx.paramByte((BTN_ParamBlockOffset + 0)))))
#define BTN_ReactionTimeLong		0x0001
// UnionOffset: 0, ParaOffset: 1, Size: 8 Bit (1 Byte), Text:   Langer Tasterdruck
#define ParamBTN_ReactionTimeLong ((uint)((knx.paramByte((BTN_ParamBlockOffset + 1)))))
#define BTN_ReactionTimeExtraLong		0x0002
// UnionOffset: 0, ParaOffset: 2, Size: 8 Bit (1 Byte), Text:   Extra langer Tastedruck
#define ParamBTN_ReactionTimeExtraLong ((uint)((knx.paramByte((BTN_ParamBlockOffset + 2)))))

//-----Module: VirtualButton Templ
#define BTN_ChannelCount 10
#define BTN_ChannelMode		0x0000
#define BTN_ChannelMode_Shift	4
#define BTN_ChannelMode_Mask	0x000F
// UnionOffset: 0, ParaOffset: 0, Size: 4 Bit, Text: Modus
#define ParamBTN_ChannelModeIndex(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 0)) >> BTN_ChannelMode_Shift) & BTN_ChannelMode_Mask))
// UnionOffset: 0, ParaOffset: 0, Size: 4 Bit, Text: Modus
#define ParamBTN_ChannelMode ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 0)) >> BTN_ChannelMode_Shift) & BTN_ChannelMode_Mask))
#define BTN_ChannelLock		0x0000
#define BTN_ChannelLock_Shift	2
#define BTN_ChannelLock_Mask	0x0003
// UnionOffset: 0, ParaOffset: 0, BitOffset: 4, Size: 2 Bit, Text: Sperre
#define ParamBTN_ChannelLockIndex(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 0)) >> BTN_ChannelLock_Shift) & BTN_ChannelLock_Mask))
// UnionOffset: 0, ParaOffset: 0, BitOffset: 4, Size: 2 Bit, Text: Sperre
#define ParamBTN_ChannelLock ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 0)) >> BTN_ChannelLock_Shift) & BTN_ChannelLock_Mask))
#define BTN_ChannelMultiClickCount		0x0000
// UnionOffset: 0, ParaOffset: 0, BitOffset: 4, Size: 1 Bit, Text: Ausgabe der Klickanzahl
#define ParamBTN_ChannelMultiClickCountIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 0), 4)
// UnionOffset: 0, ParaOffset: 0, BitOffset: 4, Size: 1 Bit, Text: Ausgabe der Klickanzahl
#define ParamBTN_ChannelMultiClickCount knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 0), 4)
#define BTN_ChannelInputA		0x0001
// UnionOffset: 1, ParaOffset: 0, Size: 1 Bit, Text: 1. Taster
#define ParamBTN_ChannelInputAIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 1), 0)
// UnionOffset: 1, ParaOffset: 0, Size: 1 Bit, Text: 1. Taster
#define ParamBTN_ChannelInputA knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 1), 0)
#define BTN_ChannelInputB		0x0003
// UnionOffset: 1, ParaOffset: 2, Size: 1 Bit, Text: 2. Taster
#define ParamBTN_ChannelInputBIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 3), 0)
// UnionOffset: 1, ParaOffset: 2, Size: 1 Bit, Text: 2. Taster
#define ParamBTN_ChannelInputB knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 3), 0)
#define BTN_ChannelReactionTimeMultiClick		0x0005
// UnionOffset: 5, ParaOffset: 0, Size: 8 Bit (1 Byte), Text:   Mehrfach-Klick
#define ParamBTN_ChannelReactionTimeMultiClickIndex(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 5)))))
// UnionOffset: 5, ParaOffset: 0, Size: 8 Bit (1 Byte), Text:   Mehrfach-Klick
#define ParamBTN_ChannelReactionTimeMultiClick ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 5)))))
#define BTN_ChannelReactionTimeLong		0x0006
// UnionOffset: 5, ParaOffset: 1, Size: 8 Bit (1 Byte), Text:   Langer Tasterdruck
#define ParamBTN_ChannelReactionTimeLongIndex(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 6)))))
// UnionOffset: 5, ParaOffset: 1, Size: 8 Bit (1 Byte), Text:   Langer Tasterdruck
#define ParamBTN_ChannelReactionTimeLong ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 6)))))
#define BTN_ChannelReactionTimeExtraLong		0x0007
// UnionOffset: 5, ParaOffset: 2, Size: 8 Bit (1 Byte), Text:   Extra langer Tasterdruck
#define ParamBTN_ChannelReactionTimeExtraLongIndex(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 7)))))
// UnionOffset: 5, ParaOffset: 2, Size: 8 Bit (1 Byte), Text:   Extra langer Tasterdruck
#define ParamBTN_ChannelReactionTimeExtraLong ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 7)))))
#define BTN_ChannelOutputShort_DPT		0x0008
// UnionOffset: 8, ParaOffset: 0, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputShort_DPTIndex(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 8)))))
// UnionOffset: 8, ParaOffset: 0, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputShort_DPT ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 8)))))
#define BTN_ChannelOutputLong_DPT		0x0009
// UnionOffset: 8, ParaOffset: 1, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputLong_DPTIndex(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 9)))))
// UnionOffset: 8, ParaOffset: 1, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputLong_DPT ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 9)))))
#define BTN_ChannelOutputExtraLong_DPT		0x000A
// UnionOffset: 8, ParaOffset: 2, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputExtraLong_DPTIndex(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 10)))))
// UnionOffset: 8, ParaOffset: 2, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputExtraLong_DPT ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 10)))))
#define BTN_ChannelOutputMulti_DPT		0x000B
// UnionOffset: 8, ParaOffset: 3, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputMulti_DPTIndex(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 11)))))
// UnionOffset: 8, ParaOffset: 3, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputMulti_DPT ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 11)))))
#define BTN_ChannelOutputMulti_Click1_Active		0x000C
// UnionOffset: 12, ParaOffset: 0, Size: 1 Bit, Text: 1. Klick
#define ParamBTN_ChannelOutputMulti_Click1_ActiveIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 12), 0)
// UnionOffset: 12, ParaOffset: 0, Size: 1 Bit, Text: 1. Klick
#define ParamBTN_ChannelOutputMulti_Click1_Active knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 12), 0)
#define BTN_ChannelOutputMulti_Click2_Active		0x000C
// UnionOffset: 12, ParaOffset: 0, BitOffset: 1, Size: 1 Bit, Text: 2. Klick
#define ParamBTN_ChannelOutputMulti_Click2_ActiveIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 12), 1)
// UnionOffset: 12, ParaOffset: 0, BitOffset: 1, Size: 1 Bit, Text: 2. Klick
#define ParamBTN_ChannelOutputMulti_Click2_Active knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 12), 1)
#define BTN_ChannelOutputMulti_Click3_Active		0x000C
// UnionOffset: 12, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text: 3. Klick
#define ParamBTN_ChannelOutputMulti_Click3_ActiveIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 12), 2)
// UnionOffset: 12, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text: 3. Klick
#define ParamBTN_ChannelOutputMulti_Click3_Active knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 12), 2)
#define BTN_ChannelOutputShort_Taster1_Active_Press		0x000D
// UnionOffset: 13, ParaOffset: 0, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputShort_Taster1_Active_PressIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 13), 0)
// UnionOffset: 13, ParaOffset: 0, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputShort_Taster1_Active_Press knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 13), 0)
#define BTN_ChannelOutputShort_Taster1_Active_Release		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputShort_Taster1_Active_ReleaseIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 13), 1)
// UnionOffset: 13, ParaOffset: 0, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputShort_Taster1_Active_Release knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 13), 1)
#define BTN_ChannelOutputShort_Taster2_Active_Press		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputShort_Taster2_Active_PressIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 13), 2)
// UnionOffset: 13, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputShort_Taster2_Active_Press knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 13), 2)
#define BTN_ChannelOutputShort_Taster2_Active_Release		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputShort_Taster2_Active_ReleaseIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 13), 3)
// UnionOffset: 13, ParaOffset: 0, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputShort_Taster2_Active_Release knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 13), 3)
#define BTN_ChannelOutputLong_Taster1_Active_Press		0x000E
// UnionOffset: 13, ParaOffset: 1, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputLong_Taster1_Active_PressIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 14), 0)
// UnionOffset: 13, ParaOffset: 1, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputLong_Taster1_Active_Press knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 14), 0)
#define BTN_ChannelOutputLong_Taster1_Active_Release		0x000E
// UnionOffset: 13, ParaOffset: 1, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputLong_Taster1_Active_ReleaseIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 14), 1)
// UnionOffset: 13, ParaOffset: 1, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputLong_Taster1_Active_Release knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 14), 1)
#define BTN_ChannelOutputLong_Taster2_Active_Press		0x000E
// UnionOffset: 13, ParaOffset: 1, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputLong_Taster2_Active_PressIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 14), 2)
// UnionOffset: 13, ParaOffset: 1, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputLong_Taster2_Active_Press knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 14), 2)
#define BTN_ChannelOutputLong_Taster2_Active_Release		0x000E
// UnionOffset: 13, ParaOffset: 1, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputLong_Taster2_Active_ReleaseIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 14), 3)
// UnionOffset: 13, ParaOffset: 1, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputLong_Taster2_Active_Release knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 14), 3)
#define BTN_ChannelOutputExtraLong_Taster1_Active_Press		0x000F
// UnionOffset: 13, ParaOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputExtraLong_Taster1_Active_PressIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 15), 0)
// UnionOffset: 13, ParaOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputExtraLong_Taster1_Active_Press knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 15), 0)
#define BTN_ChannelOutputExtraLong_Taster1_Active_Release		0x000F
// UnionOffset: 13, ParaOffset: 2, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputExtraLong_Taster1_Active_ReleaseIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 15), 1)
// UnionOffset: 13, ParaOffset: 2, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputExtraLong_Taster1_Active_Release knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 15), 1)
#define BTN_ChannelOutputExtraLong_Taster2_Active_Press		0x000F
// UnionOffset: 13, ParaOffset: 2, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputExtraLong_Taster2_Active_PressIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 15), 2)
// UnionOffset: 13, ParaOffset: 2, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputExtraLong_Taster2_Active_Press knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 15), 2)
#define BTN_ChannelOutputExtraLong_Taster2_Active_Release		0x000F
// UnionOffset: 13, ParaOffset: 2, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputExtraLong_Taster2_Active_ReleaseIndex(X) knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 15), 3)
// UnionOffset: 13, ParaOffset: 2, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputExtraLong_Taster2_Active_Release knx.paramBit((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 15), 3)
#define BTN_ChannelOutputShort_Taster1_Dpt1_Press		0x0010
// UnionOffset: 16, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 16)))))
// UnionOffset: 16, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt1_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 16)))))
#define BTN_ChannelOutputShort_Taster1_Dpt1_Release		0x0012
// UnionOffset: 16, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 18)))))
// UnionOffset: 16, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt1_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 18)))))
#define BTN_ChannelOutputShort_Taster2_Dpt1_Press		0x0014
// UnionOffset: 16, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 20)))))
// UnionOffset: 16, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt1_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 20)))))
#define BTN_ChannelOutputShort_Taster2_Dpt1_Release		0x0016
// UnionOffset: 16, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 22)))))
// UnionOffset: 16, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt1_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 22)))))
#define BTN_ChannelOutputLong_Taster1_Dpt1_Press		0x0018
// UnionOffset: 16, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 24)))))
// UnionOffset: 16, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt1_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 24)))))
#define BTN_ChannelOutputLong_Taster1_Dpt1_Release		0x001A
// UnionOffset: 16, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 26)))))
// UnionOffset: 16, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt1_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 26)))))
#define BTN_ChannelOutputLong_Taster2_Dpt1_Press		0x001C
// UnionOffset: 16, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 28)))))
// UnionOffset: 16, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt1_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 28)))))
#define BTN_ChannelOutputLong_Taster2_Dpt1_Release		0x001E
// UnionOffset: 16, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 30)))))
// UnionOffset: 16, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt1_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 30)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt1_Press		0x0020
// UnionOffset: 16, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 32)))))
// UnionOffset: 16, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt1_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 32)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt1_Release		0x0022
// UnionOffset: 16, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 34)))))
// UnionOffset: 16, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt1_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 34)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt1_Press		0x0024
// UnionOffset: 16, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 36)))))
// UnionOffset: 16, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt1_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 36)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt1_Release		0x0026
// UnionOffset: 16, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 38)))))
// UnionOffset: 16, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt1_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 38)))))
#define BTN_ChannelOutputMulti_Click1_Dpt1		0x0028
// UnionOffset: 16, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt1Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 40)))))
// UnionOffset: 16, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt1 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 40)))))
#define BTN_ChannelOutputMulti_Click2_Dpt1		0x002A
// UnionOffset: 16, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt1Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 42)))))
// UnionOffset: 16, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt1 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 42)))))
#define BTN_ChannelOutputMulti_Click3_Dpt1		0x002C
// UnionOffset: 16, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt1Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 44)))))
// UnionOffset: 16, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt1 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 44)))))
#define BTN_ChannelOutputShort_Taster1_Dpt2_Press		0x002F
// UnionOffset: 47, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 47)))))
// UnionOffset: 47, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt2_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 47)))))
#define BTN_ChannelOutputShort_Taster1_Dpt2_Release		0x0031
// UnionOffset: 47, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt2_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 49)))))
// UnionOffset: 47, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt2_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 49)))))
#define BTN_ChannelOutputShort_Taster2_Dpt2_Press		0x0033
// UnionOffset: 47, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 51)))))
// UnionOffset: 47, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt2_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 51)))))
#define BTN_ChannelOutputShort_Taster2_Dpt2_Release		0x0035
// UnionOffset: 47, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt2_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 53)))))
// UnionOffset: 47, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt2_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 53)))))
#define BTN_ChannelOutputLong_Taster1_Dpt2_Press		0x0037
// UnionOffset: 47, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 55)))))
// UnionOffset: 47, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt2_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 55)))))
#define BTN_ChannelOutputLong_Taster1_Dpt2_Release		0x0039
// UnionOffset: 47, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt2_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 57)))))
// UnionOffset: 47, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt2_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 57)))))
#define BTN_ChannelOutputLong_Taster2_Dpt2_Press		0x003B
// UnionOffset: 47, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 59)))))
// UnionOffset: 47, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt2_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 59)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt2_Press		0x003D
// UnionOffset: 47, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 61)))))
// UnionOffset: 47, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt2_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 61)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt2_Release		0x003F
// UnionOffset: 47, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt2_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 63)))))
// UnionOffset: 47, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt2_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 63)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt2_Press		0x0041
// UnionOffset: 47, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 65)))))
// UnionOffset: 47, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt2_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 65)))))
#define BTN_ChannelOutputMulti_Click1_Dpt2		0x0043
// UnionOffset: 47, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt2Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 67)))))
// UnionOffset: 47, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt2 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 67)))))
#define BTN_ChannelOutputMulti_Click2_Dpt2		0x0045
// UnionOffset: 47, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt2Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 69)))))
// UnionOffset: 47, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt2 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 69)))))
#define BTN_ChannelOutputMulti_Click3_Dpt2		0x0047
// UnionOffset: 47, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt2Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 71)))))
// UnionOffset: 47, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt2 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 71)))))
#define BTN_ChannelOutputShort_Taster1_Dpt5_Press		0x004E
// UnionOffset: 78, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 78)))))
// UnionOffset: 78, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 78)))))
#define BTN_ChannelOutputShort_Taster1_Dpt5_Release		0x0050
// UnionOffset: 78, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 80)))))
// UnionOffset: 78, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 80)))))
#define BTN_ChannelOutputShort_Taster2_Dpt5_Press		0x0052
// UnionOffset: 78, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 82)))))
// UnionOffset: 78, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 82)))))
#define BTN_ChannelOutputShort_Taster2_Dpt5_Release		0x0054
// UnionOffset: 78, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 84)))))
// UnionOffset: 78, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 84)))))
#define BTN_ChannelOutputLong_Taster1_Dpt5_Press		0x0056
// UnionOffset: 78, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 86)))))
// UnionOffset: 78, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 86)))))
#define BTN_ChannelOutputLong_Taster1_Dpt5_Release		0x0058
// UnionOffset: 78, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 88)))))
// UnionOffset: 78, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 88)))))
#define BTN_ChannelOutputLong_Taster2_Dpt5_Press		0x005A
// UnionOffset: 78, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 90)))))
// UnionOffset: 78, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 90)))))
#define BTN_ChannelOutputLong_Taster2_Dpt5_Release		0x005C
// UnionOffset: 78, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 92)))))
// UnionOffset: 78, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 92)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5_Press		0x005E
// UnionOffset: 78, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 94)))))
// UnionOffset: 78, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 94)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5_Release		0x0060
// UnionOffset: 78, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 96)))))
// UnionOffset: 78, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 96)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5_Press		0x0062
// UnionOffset: 78, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 98)))))
// UnionOffset: 78, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 98)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5_Release		0x0064
// UnionOffset: 78, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 100)))))
// UnionOffset: 78, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 100)))))
#define BTN_ChannelOutputMulti_Click1_Dpt5		0x0066
// UnionOffset: 78, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt5Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 102)))))
// UnionOffset: 78, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt5 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 102)))))
#define BTN_ChannelOutputMulti_Click2_Dpt5		0x0068
// UnionOffset: 78, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt5Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 104)))))
// UnionOffset: 78, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt5 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 104)))))
#define BTN_ChannelOutputMulti_Click3_Dpt5		0x006A
// UnionOffset: 78, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt5Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 106)))))
// UnionOffset: 78, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt5 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 106)))))
#define BTN_ChannelOutputShort_Taster1_Dpt5001_Press		0x006D
// UnionOffset: 109, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 109)))))
// UnionOffset: 109, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5001_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 109)))))
#define BTN_ChannelOutputShort_Taster1_Dpt5001_Release		0x006F
// UnionOffset: 109, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 111)))))
// UnionOffset: 109, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5001_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 111)))))
#define BTN_ChannelOutputShort_Taster2_Dpt5001_Press		0x0071
// UnionOffset: 109, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 113)))))
// UnionOffset: 109, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5001_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 113)))))
#define BTN_ChannelOutputShort_Taster2_Dpt5001_Release		0x0073
// UnionOffset: 109, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 115)))))
// UnionOffset: 109, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5001_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 115)))))
#define BTN_ChannelOutputLong_Taster1_Dpt5001_Press		0x0075
// UnionOffset: 109, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 117)))))
// UnionOffset: 109, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5001_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 117)))))
#define BTN_ChannelOutputLong_Taster1_Dpt5001_Release		0x0077
// UnionOffset: 109, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 119)))))
// UnionOffset: 109, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5001_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 119)))))
#define BTN_ChannelOutputLong_Taster2_Dpt5001_Press		0x0079
// UnionOffset: 109, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 121)))))
// UnionOffset: 109, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5001_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 121)))))
#define BTN_ChannelOutputLong_Taster2_Dpt5001_Release		0x007B
// UnionOffset: 109, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 123)))))
// UnionOffset: 109, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5001_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 123)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Press		0x007D
// UnionOffset: 109, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 125)))))
// UnionOffset: 109, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5001_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 125)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Release		0x007F
// UnionOffset: 109, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 127)))))
// UnionOffset: 109, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5001_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 127)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Press		0x0081
// UnionOffset: 109, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 129)))))
// UnionOffset: 109, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5001_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 129)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Release		0x0083
// UnionOffset: 109, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 131)))))
// UnionOffset: 109, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5001_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 131)))))
#define BTN_ChannelOutputMulti_Click1_Dpt5001		0x0085
// UnionOffset: 109, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt5001Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 133)))))
// UnionOffset: 109, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt5001 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 133)))))
#define BTN_ChannelOutputMulti_Click2_Dpt5001		0x0087
// UnionOffset: 109, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt5001Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 135)))))
// UnionOffset: 109, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt5001 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 135)))))
#define BTN_ChannelOutputMulti_Click3_Dpt5001		0x0089
// UnionOffset: 109, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt5001Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 137)))))
// UnionOffset: 109, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt5001 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 137)))))
#define BTN_ChannelOutputShort_Taster1_Dpt7_Press		0x008C
// UnionOffset: 140, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 140)))))
// UnionOffset: 140, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt7_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 140)))))
#define BTN_ChannelOutputShort_Taster1_Dpt7_Release		0x008E
// UnionOffset: 140, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 142)))))
// UnionOffset: 140, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt7_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 142)))))
#define BTN_ChannelOutputShort_Taster2_Dpt7_Press		0x0090
// UnionOffset: 140, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 144)))))
// UnionOffset: 140, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt7_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 144)))))
#define BTN_ChannelOutputShort_Taster2_Dpt7_Release		0x0092
// UnionOffset: 140, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 146)))))
// UnionOffset: 140, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt7_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 146)))))
#define BTN_ChannelOutputLong_Taster1_Dpt7_Press		0x0094
// UnionOffset: 140, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 148)))))
// UnionOffset: 140, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt7_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 148)))))
#define BTN_ChannelOutputLong_Taster1_Dpt7_Release		0x0096
// UnionOffset: 140, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 150)))))
// UnionOffset: 140, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt7_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 150)))))
#define BTN_ChannelOutputLong_Taster2_Dpt7_Press		0x0098
// UnionOffset: 140, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 152)))))
// UnionOffset: 140, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt7_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 152)))))
#define BTN_ChannelOutputLong_Taster2_Dpt7_Release		0x009A
// UnionOffset: 140, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 154)))))
// UnionOffset: 140, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt7_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 154)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt7_Press		0x009C
// UnionOffset: 140, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 156)))))
// UnionOffset: 140, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt7_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 156)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt7_Release		0x009E
// UnionOffset: 140, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 158)))))
// UnionOffset: 140, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt7_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 158)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt7_Press		0x00A0
// UnionOffset: 140, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 160)))))
// UnionOffset: 140, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt7_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 160)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt7_Release		0x00A2
// UnionOffset: 140, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 162)))))
// UnionOffset: 140, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt7_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 162)))))
#define BTN_ChannelOutputMulti_Click1_Dpt7		0x00A4
// UnionOffset: 140, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt7Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 164)))))
// UnionOffset: 140, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt7 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 164)))))
#define BTN_ChannelOutputMulti_Click2_Dpt7		0x00A6
// UnionOffset: 140, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt7Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 166)))))
// UnionOffset: 140, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt7 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 166)))))
#define BTN_ChannelOutputMulti_Click3_Dpt7		0x00A8
// UnionOffset: 140, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt7Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 168)))))
// UnionOffset: 140, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt7 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 168)))))
#define BTN_ChannelOutputShort_Taster1_Dpt18_Press		0x00AB
// UnionOffset: 171, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 171)))))
// UnionOffset: 171, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt18_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 171)))))
#define BTN_ChannelOutputShort_Taster1_Dpt18_Release		0x00AD
// UnionOffset: 171, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 173)))))
// UnionOffset: 171, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt18_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 173)))))
#define BTN_ChannelOutputShort_Taster2_Dpt18_Press		0x00AF
// UnionOffset: 171, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 175)))))
// UnionOffset: 171, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt18_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 175)))))
#define BTN_ChannelOutputShort_Taster2_Dpt18_Release		0x00B1
// UnionOffset: 171, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 177)))))
// UnionOffset: 171, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt18_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 177)))))
#define BTN_ChannelOutputLong_Taster1_Dpt18_Press		0x00B3
// UnionOffset: 171, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 179)))))
// UnionOffset: 171, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt18_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 179)))))
#define BTN_ChannelOutputLong_Taster1_Dpt18_Release		0x00B5
// UnionOffset: 171, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 181)))))
// UnionOffset: 171, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt18_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 181)))))
#define BTN_ChannelOutputLong_Taster2_Dpt18_Press		0x00B7
// UnionOffset: 171, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 183)))))
// UnionOffset: 171, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt18_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 183)))))
#define BTN_ChannelOutputLong_Taster2_Dpt18_Release		0x00B9
// UnionOffset: 171, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 185)))))
// UnionOffset: 171, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt18_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 185)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt18_Press		0x00BB
// UnionOffset: 171, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 187)))))
// UnionOffset: 171, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt18_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 187)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt18_Release		0x00BD
// UnionOffset: 171, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 189)))))
// UnionOffset: 171, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt18_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 189)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt18_Press		0x00BF
// UnionOffset: 171, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 191)))))
// UnionOffset: 171, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt18_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 191)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt18_Release		0x00C1
// UnionOffset: 171, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 193)))))
// UnionOffset: 171, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt18_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 193)))))
#define BTN_ChannelOutputMulti_Click1_Dpt18		0x00C3
// UnionOffset: 171, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt18Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 195)))))
// UnionOffset: 171, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt18 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 195)))))
#define BTN_ChannelOutputMulti_Click2_Dpt18		0x00C5
// UnionOffset: 171, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt18Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 197)))))
// UnionOffset: 171, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt18 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 197)))))
#define BTN_ChannelOutputMulti_Click3_Dpt18		0x00C7
// UnionOffset: 171, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt18Index(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 199)))))
// UnionOffset: 171, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt18 ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 199)))))
#define BTN_ChannelOutputShort_Taster1_Dpt3007_Press		0x00CA
// UnionOffset: 202, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 202)))))
// UnionOffset: 202, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3007_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 202)))))
#define BTN_ChannelOutputShort_Taster1_Dpt3007_Release		0x00CC
// UnionOffset: 202, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 204)))))
// UnionOffset: 202, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3007_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 204)))))
#define BTN_ChannelOutputShort_Taster2_Dpt3007_Press		0x00CE
// UnionOffset: 202, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 206)))))
// UnionOffset: 202, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3007_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 206)))))
#define BTN_ChannelOutputShort_Taster2_Dpt3007_Release		0x00D2
// UnionOffset: 202, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 210)))))
// UnionOffset: 202, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3007_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 210)))))
#define BTN_ChannelOutputLong_Taster1_Dpt3007_Press		0x00D4
// UnionOffset: 202, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 212)))))
// UnionOffset: 202, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3007_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 212)))))
#define BTN_ChannelOutputLong_Taster1_Dpt3007_Release		0x00D6
// UnionOffset: 202, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 214)))))
// UnionOffset: 202, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3007_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 214)))))
#define BTN_ChannelOutputLong_Taster2_Dpt3007_Press		0x00D8
// UnionOffset: 202, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 216)))))
// UnionOffset: 202, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3007_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 216)))))
#define BTN_ChannelOutputLong_Taster2_Dpt3007_Release		0x00DA
// UnionOffset: 202, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 218)))))
// UnionOffset: 202, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3007_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 218)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Press		0x00DC
// UnionOffset: 202, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 220)))))
// UnionOffset: 202, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3007_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 220)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Release		0x00DE
// UnionOffset: 202, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 222)))))
// UnionOffset: 202, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3007_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 222)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Press		0x00E0
// UnionOffset: 202, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 224)))))
// UnionOffset: 202, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3007_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 224)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Release		0x00E2
// UnionOffset: 202, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 226)))))
// UnionOffset: 202, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3007_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 226)))))
#define BTN_ChannelOutputShort_Taster1_Dpt3008_Press		0x00E9
// UnionOffset: 233, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 233)))))
// UnionOffset: 233, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3008_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 233)))))
#define BTN_ChannelOutputShort_Taster1_Dpt3008_Release		0x00EB
// UnionOffset: 233, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 235)))))
// UnionOffset: 233, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3008_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 235)))))
#define BTN_ChannelOutputShort_Taster2_Dpt3008_Press		0x00ED
// UnionOffset: 233, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 237)))))
// UnionOffset: 233, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3008_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 237)))))
#define BTN_ChannelOutputShort_Taster2_Dpt3008_Release		0x00F1
// UnionOffset: 233, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 241)))))
// UnionOffset: 233, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3008_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 241)))))
#define BTN_ChannelOutputLong_Taster1_Dpt3008_Press		0x00F3
// UnionOffset: 233, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 243)))))
// UnionOffset: 233, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3008_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 243)))))
#define BTN_ChannelOutputLong_Taster1_Dpt3008_Release		0x00F5
// UnionOffset: 233, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 245)))))
// UnionOffset: 233, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3008_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 245)))))
#define BTN_ChannelOutputLong_Taster2_Dpt3008_Press		0x00F7
// UnionOffset: 233, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 247)))))
// UnionOffset: 233, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3008_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 247)))))
#define BTN_ChannelOutputLong_Taster2_Dpt3008_Release		0x00F9
// UnionOffset: 233, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 249)))))
// UnionOffset: 233, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3008_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 249)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Press		0x00FB
// UnionOffset: 233, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 251)))))
// UnionOffset: 233, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3008_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 251)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Release		0x00FD
// UnionOffset: 233, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 253)))))
// UnionOffset: 233, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3008_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 253)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Press		0x00FF
// UnionOffset: 233, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 255)))))
// UnionOffset: 233, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3008_Press ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 255)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Release		0x0101
// UnionOffset: 233, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 257)))))
// UnionOffset: 233, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3008_Release ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 257)))))
#define BTN_ChannelOutput2Short_Taster1		0x0108
#define BTN_ChannelOutput2Short_Taster1_Shift	6
#define BTN_ChannelOutput2Short_Taster1_Mask	0x0003
// UnionOffset: 264, ParaOffset: 0, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Short_Taster1Index(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 264)) >> BTN_ChannelOutput2Short_Taster1_Shift) & BTN_ChannelOutput2Short_Taster1_Mask))
// UnionOffset: 264, ParaOffset: 0, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Short_Taster1 ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 264)) >> BTN_ChannelOutput2Short_Taster1_Shift) & BTN_ChannelOutput2Short_Taster1_Mask))
#define BTN_ChannelOutput2Short_Taster2		0x0108
#define BTN_ChannelOutput2Short_Taster2_Shift	4
#define BTN_ChannelOutput2Short_Taster2_Mask	0x0003
// UnionOffset: 264, ParaOffset: 0, BitOffset: 2, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Short_Taster2Index(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 264)) >> BTN_ChannelOutput2Short_Taster2_Shift) & BTN_ChannelOutput2Short_Taster2_Mask))
// UnionOffset: 264, ParaOffset: 0, BitOffset: 2, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Short_Taster2 ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 264)) >> BTN_ChannelOutput2Short_Taster2_Shift) & BTN_ChannelOutput2Short_Taster2_Mask))
#define BTN_ChannelOutput2Long_Taster1		0x0108
#define BTN_ChannelOutput2Long_Taster1_Shift	2
#define BTN_ChannelOutput2Long_Taster1_Mask	0x0003
// UnionOffset: 264, ParaOffset: 0, BitOffset: 4, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Long_Taster1Index(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 264)) >> BTN_ChannelOutput2Long_Taster1_Shift) & BTN_ChannelOutput2Long_Taster1_Mask))
// UnionOffset: 264, ParaOffset: 0, BitOffset: 4, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Long_Taster1 ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 264)) >> BTN_ChannelOutput2Long_Taster1_Shift) & BTN_ChannelOutput2Long_Taster1_Mask))
#define BTN_ChannelOutput2Long_Taster2		0x0108
#define BTN_ChannelOutput2Long_Taster2_Mask	0x0003
// UnionOffset: 264, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Long_Taster2Index(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 264))) & BTN_ChannelOutput2Long_Taster2_Mask))
// UnionOffset: 264, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Long_Taster2 ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 264))) & BTN_ChannelOutput2Long_Taster2_Mask))
#define BTN_ChannelOutput2ExtraLong_Taster1		0x0109
#define BTN_ChannelOutput2ExtraLong_Taster1_Shift	6
#define BTN_ChannelOutput2ExtraLong_Taster1_Mask	0x0003
// UnionOffset: 264, ParaOffset: 1, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2ExtraLong_Taster1Index(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 265)) >> BTN_ChannelOutput2ExtraLong_Taster1_Shift) & BTN_ChannelOutput2ExtraLong_Taster1_Mask))
// UnionOffset: 264, ParaOffset: 1, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2ExtraLong_Taster1 ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 265)) >> BTN_ChannelOutput2ExtraLong_Taster1_Shift) & BTN_ChannelOutput2ExtraLong_Taster1_Mask))
#define BTN_ChannelOutput2ExtraLong_Taster2		0x0109
#define BTN_ChannelOutput2ExtraLong_Taster2_Shift	4
#define BTN_ChannelOutput2ExtraLong_Taster2_Mask	0x0003
// UnionOffset: 264, ParaOffset: 1, BitOffset: 2, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2ExtraLong_Taster2Index(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 265)) >> BTN_ChannelOutput2ExtraLong_Taster2_Shift) & BTN_ChannelOutput2ExtraLong_Taster2_Mask))
// UnionOffset: 264, ParaOffset: 1, BitOffset: 2, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2ExtraLong_Taster2 ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 265)) >> BTN_ChannelOutput2ExtraLong_Taster2_Shift) & BTN_ChannelOutput2ExtraLong_Taster2_Mask))
#define BTN_ChannelStatusThreshold		0x010A
// UnionOffset: 266, ParaOffset: 0, Size: 8 Bit (1 Byte), Text: Schwellwert
#define ParamBTN_ChannelStatusThresholdIndex(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 266)))))
// UnionOffset: 266, ParaOffset: 0, Size: 8 Bit (1 Byte), Text: Schwellwert
#define ParamBTN_ChannelStatusThreshold ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 266)))))
#define BTN_ChannelStatusFallbackBase		0x010B
#define BTN_ChannelStatusFallbackBase_Shift	6
#define BTN_ChannelStatusFallbackBase_Mask	0x0003
// UnionOffset: 266, ParaOffset: 1, Size: 2 Bit, Text: Zeitbasis
#define ParamBTN_ChannelStatusFallbackBaseIndex(X) ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 267)) >> BTN_ChannelStatusFallbackBase_Shift) & BTN_ChannelStatusFallbackBase_Mask))
// UnionOffset: 266, ParaOffset: 1, Size: 2 Bit, Text: Zeitbasis
#define ParamBTN_ChannelStatusFallbackBase ((uint)((knx.paramByte((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 267)) >> BTN_ChannelStatusFallbackBase_Shift) & BTN_ChannelStatusFallbackBase_Mask))
#define BTN_ChannelStatusFallbackTime		0x010B
#define BTN_ChannelStatusFallbackTime_Mask	0x3FFF
// UnionOffset: 266, ParaOffset: 1, BitOffset: 2, Size: 14 Bit, Text: Zeit
#define ParamBTN_ChannelStatusFallbackTimeIndex(X) ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * X + 267))) & BTN_ChannelStatusFallbackTime_Mask))
// UnionOffset: 266, ParaOffset: 1, BitOffset: 2, Size: 14 Bit, Text: Zeit
#define ParamBTN_ChannelStatusFallbackTime ((uint)((knx.paramWord((BTN_ParamBlockOffset + BTN_ParamBlockSize * channelIndex() + 267))) & BTN_ChannelStatusFallbackTime_Mask))
#define ParamBTN_ChannelStatusFallbackTimeMS (paramDelay(ParamBTN_ChannelStatusFallbackTime))
//!< Number: 0, Text: , Function: 
#define BTN_KoChannelLock 0
#define KoBTN_ChannelLockIndex(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 0)
#define KoBTN_ChannelLock knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 0)
//!< Number: 1, Text: , Function: Taster {{argChan}}, Eingang 1
#define BTN_KoChannelInput1 1
#define KoBTN_ChannelInput1Index(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 1)
#define KoBTN_ChannelInput1 knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 1)
//!< Number: 2, Text: , Function: Taster {{argChan}}, Eingang 2
#define BTN_KoChannelInput2 2
#define KoBTN_ChannelInput2Index(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 2)
#define KoBTN_ChannelInput2 knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 2)
//!< Number: 3, Text: , Function: Taster {{argChan}}, Status
#define BTN_KoChannelOutput1Status 3
#define KoBTN_ChannelOutput1StatusIndex(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 3)
#define KoBTN_ChannelOutput1Status knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 3)
//!< Number: 4, Text: , Function: Taster {{argChan}}, Status (Lang)
#define BTN_KoChannelOutput2Status 4
#define KoBTN_ChannelOutput2StatusIndex(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 4)
#define KoBTN_ChannelOutput2Status knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 4)
//!< Number: 5, Text: , Function: Taster {{argChan}}, Status (Extralang)
#define BTN_KoChannelOutput3Status 5
#define KoBTN_ChannelOutput3StatusIndex(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 5)
#define KoBTN_ChannelOutput3Status knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 5)
//!< Number: 6, Text: , Function: Taster {{argChan}}, Ausgang
#define BTN_KoChannelOutput1 6
#define KoBTN_ChannelOutput1Index(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 6)
#define KoBTN_ChannelOutput1 knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 6)
//!< Number: 7, Text: , Function: Taster {{argChan}}, Ausgang (Lang)
#define BTN_KoChannelOutput2 7
#define KoBTN_ChannelOutput2Index(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 7)
#define KoBTN_ChannelOutput2 knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 7)
//!< Number: 8, Text: , Function: Taster {{argChan}}, Ausgang (Extralang)
#define BTN_KoChannelOutput3 8
#define KoBTN_ChannelOutput3Index(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 8)
#define KoBTN_ChannelOutput3 knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 8)
//!< Number: 9, Text: , Function: Taster {{argChan}}, Zusatzausgang
#define BTN_KoChannelOutput4 9
#define KoBTN_ChannelOutput4Index(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 9)
#define KoBTN_ChannelOutput4 knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 9)
//!< Number: 10, Text: , Function: Taster {{argChan}}, Zusatzausgang (Lang)
#define BTN_KoChannelOutput5 10
#define KoBTN_ChannelOutput5Index(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 10)
#define KoBTN_ChannelOutput5 knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 10)
//!< Number: 11, Text: , Function: Taster {{argChan}}, Zusatzausgang (Extralang)
#define BTN_KoChannelOutput6 11
#define KoBTN_ChannelOutput6Index(X) knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * X + 11)
#define KoBTN_ChannelOutput6 knx.getGroupObject(BTN_KoOffset + BTN_KoBlockSize * channelIndex() + 11)

