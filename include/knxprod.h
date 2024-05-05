#pragma once

#define paramDelay(time) (uint32_t)( \
            (time & 0xC000) == 0xC000 ? (time & 0x3FFF) * 100 : \
            (time & 0xC000) == 0x0000 ? (time & 0x3FFF) * 1000 : \
            (time & 0xC000) == 0x4000 ? (time & 0x3FFF) * 60000 : \
            (time & 0xC000) == 0x8000 ? ((time & 0x3FFF) > 1000 ? 3600000 : \
                                            (time & 0x3FFF) * 3600000 ) : 0 )
#define PT_ir_receive_virtual1 0
#define PT_ir_receive_virtual2 1
#define PT_ir_receive_color 2
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
#define MAIN_ApplicationVersion 0x05
#define MAIN_OrderNumber "GW-UP1-IR.01"
#define MAIN_ParameterSize 2799
#define MAIN_MaxKoNumber 153

#define BTN_KoCalcNumber(index) (index + BTN_Templ_KoOffset + _channelIndex * BTN_Templ_KoBlockSize)
#define BTN_KoCalcIndex(number) ((number >= BTN_KoCalcNumber(0) && number < BTN_KoCalcNumber(BTN_Templ_KoBlockSize)) ? (number - BTN_Templ_KoOffset) % BTN_Templ_KoBlockSize : -1)



//---------------------Modules----------------------------

//-----Module specific starts
#define BASE_Share_ParamBlockOffset 0
#define BASE_Share_ParamBlockSize 45
#define IR_ParamBlockOffset 45
#define IR_ParamBlockSize 6
#define BTN_Share_ParamBlockOffset 105
#define BTN_Share_ParamBlockSize 4
#define BTN_Templ_ParamBlockOffset 109
#define BTN_Templ_ParamBlockSize 269
#define BASE_Share_KoOffset 1
#define BASE_Share_KoBlockSize 12
#define IR_KoOffset 13
#define IR_KoBlockSize 2
#define BTN_Share_KoOffset 33
#define BTN_Share_KoBlockSize 0
#define BTN_Templ_KoOffset 33
#define BTN_Templ_KoBlockSize 12

//-----Module: ir
#define IR_inOutType		0x0000
#define IR_inOutType_Shift	6
#define IR_inOutType_Mask	0x0003
// Offset: 0, Size: 2 Bit, Text: Kanal
#define ParamIR_inOutTypeIndex(X) ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_inOutType)) >> IR_inOutType_Shift) & IR_inOutType_Mask))
// Offset: 0, Size: 2 Bit, Text: Kanal
#define ParamIR_inOutType ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_inOutType)) >> IR_inOutType_Shift) & IR_inOutType_Mask))
#define IR_inType		0x0001
#define IR_inType_Shift	6
#define IR_inType_Mask	0x0003
// UnionOffset: 1, ParaOffset: 0, Size: 2 Bit, Text: Funktion
#define ParamIR_inTypeIndex(X) ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_inType)) >> IR_inType_Shift) & IR_inType_Mask))
// UnionOffset: 1, ParaOffset: 0, Size: 2 Bit, Text: Funktion
#define ParamIR_inType ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_inType)) >> IR_inType_Shift) & IR_inType_Mask))
#define IR_inBtnNumber		0x0001
#define IR_inBtnNumber_Mask	0x007F
// UnionOffset: 1, ParaOffset: 0, BitOffset: 1, Size: 7 Bit, Text: Virtueller Taster
#define ParamIR_inBtnNumberIndex(X) ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_inBtnNumber))) & IR_inBtnNumber_Mask))
// UnionOffset: 1, ParaOffset: 0, BitOffset: 1, Size: 7 Bit, Text: Virtueller Taster
#define ParamIR_inBtnNumber ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_inBtnNumber))) & IR_inBtnNumber_Mask))
#define IR_inColor_RGB		0x0002
// UnionOffset: 1, ParaOffset: 1, Size: 24 Bit (3 Byte), Text: Farbe
#define ParamIR_inColor_RGBIndex(X) knx.paramData((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_inColor_RGB))
// UnionOffset: 1, ParaOffset: 1, Size: 24 Bit (3 Byte), Text: Farbe
#define ParamIR_inColor_RGB knx.paramData((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_inColor_RGB))
#define IR_inColor_HSV		0x0002
// UnionOffset: 1, ParaOffset: 1, Size: 24 Bit (3 Byte), Text: Farbe
#define ParamIR_inColor_HSVIndex(X) knx.paramData((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_inColor_HSV))
// UnionOffset: 1, ParaOffset: 1, Size: 24 Bit (3 Byte), Text: Farbe
#define ParamIR_inColor_HSV knx.paramData((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_inColor_HSV))
#define IR_inColorType		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 5, Size: 1 Bit, Text: Ausgabe als
#define ParamIR_inColorTypeIndex(X) knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_inColorType), 5)
// UnionOffset: 1, ParaOffset: 0, BitOffset: 5, Size: 1 Bit, Text: Ausgabe als
#define ParamIR_inColorType knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_inColorType), 5)
#define IR_outType		0x0001
#define IR_outType_Shift	6
#define IR_outType_Mask	0x0003
// UnionOffset: 1, ParaOffset: 0, Size: 2 Bit, Text: Funktion
#define ParamIR_outTypeIndex(X) ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_outType)) >> IR_outType_Shift) & IR_outType_Mask))
// UnionOffset: 1, ParaOffset: 0, Size: 2 Bit, Text: Funktion
#define ParamIR_outType ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_outType)) >> IR_outType_Shift) & IR_outType_Mask))
#define IR_outValue		0x0002
// UnionOffset: 1, ParaOffset: 1, Size: 8 Bit (1 Byte), Text: Wert
#define ParamIR_outValueIndex(X) ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_outValue)))))
// UnionOffset: 1, ParaOffset: 1, Size: 8 Bit (1 Byte), Text: Wert
#define ParamIR_outValue ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_outValue)))))
#define IR_outSwitch		0x0002
#define IR_outSwitch_Shift	6
#define IR_outSwitch_Mask	0x0003
// UnionOffset: 1, ParaOffset: 1, Size: 2 Bit, Text: Senden bei
#define ParamIR_outSwitchIndex(X) ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_outSwitch)) >> IR_outSwitch_Shift) & IR_outSwitch_Mask))
// UnionOffset: 1, ParaOffset: 1, Size: 2 Bit, Text: Senden bei
#define ParamIR_outSwitch ((uint)((knx.paramByte((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_outSwitch)) >> IR_outSwitch_Shift) & IR_outSwitch_Mask))
#define IR_outScene1		0x0001
#define IR_outScene1_Shift	3
#define IR_outScene1_Mask	0x007F
// UnionOffset: 1, ParaOffset: 0, BitOffset: 6, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene1Index(X) ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_outScene1)) >> IR_outScene1_Shift) & IR_outScene1_Mask))
// UnionOffset: 1, ParaOffset: 0, BitOffset: 6, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene1 ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_outScene1)) >> IR_outScene1_Shift) & IR_outScene1_Mask))
#define IR_outScene2		0x0002
#define IR_outScene2_Shift	4
#define IR_outScene2_Mask	0x007F
// UnionOffset: 1, ParaOffset: 1, BitOffset: 5, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene2Index(X) ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_outScene2)) >> IR_outScene2_Shift) & IR_outScene2_Mask))
// UnionOffset: 1, ParaOffset: 1, BitOffset: 5, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene2 ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_outScene2)) >> IR_outScene2_Shift) & IR_outScene2_Mask))
#define IR_outScene3		0x0003
#define IR_outScene3_Shift	5
#define IR_outScene3_Mask	0x007F
// UnionOffset: 1, ParaOffset: 2, BitOffset: 4, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene3Index(X) ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_outScene3)) >> IR_outScene3_Shift) & IR_outScene3_Mask))
// UnionOffset: 1, ParaOffset: 2, BitOffset: 4, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene3 ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_outScene3)) >> IR_outScene3_Shift) & IR_outScene3_Mask))
#define IR_outScene4		0x0004
#define IR_outScene4_Shift	6
#define IR_outScene4_Mask	0x007F
// UnionOffset: 1, ParaOffset: 3, BitOffset: 3, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene4Index(X) ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_outScene4)) >> IR_outScene4_Shift) & IR_outScene4_Mask))
// UnionOffset: 1, ParaOffset: 3, BitOffset: 3, Size: 7 Bit, Text: Szenennummer
#define ParamIR_outScene4 ((uint)((knx.paramWord((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_outScene4)) >> IR_outScene4_Shift) & IR_outScene4_Mask))
#define IR_outSceneActive1		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text: Szene A
#define ParamIR_outSceneActive1Index(X) knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_outSceneActive1), 2)
// UnionOffset: 1, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text: Szene A
#define ParamIR_outSceneActive1 knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_outSceneActive1), 2)
#define IR_outSceneActive2		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 3, Size: 1 Bit, Text: Szene B
#define ParamIR_outSceneActive2Index(X) knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_outSceneActive2), 3)
// UnionOffset: 1, ParaOffset: 0, BitOffset: 3, Size: 1 Bit, Text: Szene B
#define ParamIR_outSceneActive2 knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_outSceneActive2), 3)
#define IR_outSceneActive3		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 4, Size: 1 Bit, Text: Szene C
#define ParamIR_outSceneActive3Index(X) knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_outSceneActive3), 4)
// UnionOffset: 1, ParaOffset: 0, BitOffset: 4, Size: 1 Bit, Text: Szene C
#define ParamIR_outSceneActive3 knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_outSceneActive3), 4)
#define IR_outSceneActive4		0x0001
// UnionOffset: 1, ParaOffset: 0, BitOffset: 5, Size: 1 Bit, Text: Szene D
#define ParamIR_outSceneActive4Index(X) knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * X + IR_outSceneActive4), 5)
// UnionOffset: 1, ParaOffset: 0, BitOffset: 5, Size: 1 Bit, Text: Szene D
#define ParamIR_outSceneActive4 knx.paramBit((IR_ParamBlockOffset + IR_ParamBlockSize * channelIndex() + IR_outSceneActive4), 5)
//!< Number: 0, Text: IR{{argChan}} <- {{0:}}, Function: Farbe
#define IR_Koco_n1 0
#define KoIR_co_n1Index(X) knx.getGroupObject(IR_KoOffset + IR_KoBlockSize * X + IR_Koco_n1)
#define KoIR_co_n1 knx.getGroupObject(IR_KoOffset + IR_KoBlockSize * channelIndex() + IR_Koco_n1)
//!< Number: 1, Text: IR{{argChan}} <- {{0:}}, Function: Status
#define IR_Koco_n2 1
#define KoIR_co_n2Index(X) knx.getGroupObject(IR_KoOffset + IR_KoBlockSize * X + IR_Koco_n2)
#define KoIR_co_n2 knx.getGroupObject(IR_KoOffset + IR_KoBlockSize * channelIndex() + IR_Koco_n2)

//-----Module: Common Share
#define BASE_StartupDelayBase		0x0000
#define BASE_StartupDelayBase_Shift	6
#define BASE_StartupDelayBase_Mask	0x0003
// UnionOffset: 0, ParaOffset: 0, Size: 2 Bit, Text: Zeitbasis
#define ParamBASE_StartupDelayBase ((uint)((knx.paramByte((BASE_Share_ParamBlockOffset + BASE_StartupDelayBase)) >> BASE_StartupDelayBase_Shift) & BASE_StartupDelayBase_Mask))
#define BASE_StartupDelayTime		0x0000
#define BASE_StartupDelayTime_Mask	0x3FFF
// UnionOffset: 0, ParaOffset: 0, BitOffset: 2, Size: 14 Bit, Text: Zeit
#define ParamBASE_StartupDelayTime ((uint)((knx.paramWord((BASE_Share_ParamBlockOffset + BASE_StartupDelayTime))) & BASE_StartupDelayTime_Mask))
#define ParamBASE_StartupDelayTimeMS (paramDelay(ParamBASE_StartupDelayTime))
#define BASE_HeartbeatDelayBase		0x0002
#define BASE_HeartbeatDelayBase_Shift	6
#define BASE_HeartbeatDelayBase_Mask	0x0003
// UnionOffset: 0, ParaOffset: 2, Size: 2 Bit, Text: Zeitbasis
#define ParamBASE_HeartbeatDelayBase ((uint)((knx.paramByte((BASE_Share_ParamBlockOffset + BASE_HeartbeatDelayBase)) >> BASE_HeartbeatDelayBase_Shift) & BASE_HeartbeatDelayBase_Mask))
#define BASE_HeartbeatDelayTime		0x0002
#define BASE_HeartbeatDelayTime_Mask	0x3FFF
// UnionOffset: 0, ParaOffset: 2, BitOffset: 2, Size: 14 Bit, Text: Zeit
#define ParamBASE_HeartbeatDelayTime ((uint)((knx.paramWord((BASE_Share_ParamBlockOffset + BASE_HeartbeatDelayTime))) & BASE_HeartbeatDelayTime_Mask))
#define ParamBASE_HeartbeatDelayTimeMS (paramDelay(ParamBASE_HeartbeatDelayTime))
#define BASE_Timezone		0x0004
#define BASE_Timezone_Shift	3
#define BASE_Timezone_Mask	0x001F
// UnionOffset: 4, ParaOffset: 0, Size: 5 Bit, Text: Zeitzone
#define ParamBASE_Timezone ((uint)((knx.paramByte((BASE_Share_ParamBlockOffset + BASE_Timezone)) >> BASE_Timezone_Shift) & BASE_Timezone_Mask))
#define BASE_CombinedTimeDate		0x0004
// UnionOffset: 4, ParaOffset: 0, BitOffset: 5, Size: 1 Bit, Text: Empfangen über
#define ParamBASE_CombinedTimeDate knx.paramBit((BASE_Share_ParamBlockOffset + BASE_CombinedTimeDate), 5)
#define BASE_SummertimeAll		0x0004
#define BASE_SummertimeAll_Mask	0x0003
// UnionOffset: 4, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text: Sommerzeit ermitteln durch
#define ParamBASE_SummertimeAll ((uint)((knx.paramByte((BASE_Share_ParamBlockOffset + BASE_SummertimeAll))) & BASE_SummertimeAll_Mask))
#define BASE_SummertimeDE		0x0004
#define BASE_SummertimeDE_Mask	0x0003
// UnionOffset: 4, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text: Sommerzeit ermitteln durch
#define ParamBASE_SummertimeDE ((uint)((knx.paramByte((BASE_Share_ParamBlockOffset + BASE_SummertimeDE))) & BASE_SummertimeDE_Mask))
#define BASE_SummertimeWorld		0x0004
#define BASE_SummertimeWorld_Mask	0x0003
// UnionOffset: 4, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text: Sommerzeit ermitteln durch
#define ParamBASE_SummertimeWorld ((uint)((knx.paramByte((BASE_Share_ParamBlockOffset + BASE_SummertimeWorld))) & BASE_SummertimeWorld_Mask))
#define BASE_SummertimeKO		0x0004
#define BASE_SummertimeKO_Mask	0x0003
// UnionOffset: 4, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text: Sommerzeit ermitteln durch
#define ParamBASE_SummertimeKO ((uint)((knx.paramByte((BASE_Share_ParamBlockOffset + BASE_SummertimeKO))) & BASE_SummertimeKO_Mask))
#define BASE_Latitude		0x0005
// UnionOffset: 5, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: Breitengrad
#define ParamBASE_Latitude knx.paramFloat((BASE_Share_ParamBlockOffset + BASE_Latitude), Float_Enc_IEEE754Single)
#define BASE_Longitude		0x0009
// UnionOffset: 5, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: Längengrad
#define ParamBASE_Longitude knx.paramFloat((BASE_Share_ParamBlockOffset + BASE_Longitude), Float_Enc_IEEE754Single)
#define BASE_Diagnose		0x000D
// UnionOffset: 13, ParaOffset: 0, Size: 1 Bit, Text: Diagnoseobjekt anzeigen
#define ParamBASE_Diagnose knx.paramBit((BASE_Share_ParamBlockOffset + BASE_Diagnose), 0)
#define BASE_Watchdog		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 1, Size: 1 Bit, Text: Watchdog aktivieren
#define ParamBASE_Watchdog knx.paramBit((BASE_Share_ParamBlockOffset + BASE_Watchdog), 1)
#define BASE_ReadTimeDate		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text: Bei Neustart vom Bus lesen
#define ParamBASE_ReadTimeDate knx.paramBit((BASE_Share_ParamBlockOffset + BASE_ReadTimeDate), 2)
#define BASE_HeartbeatExtended		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 3, Size: 1 Bit, Text: Erweitertes "In Betrieb"
#define ParamBASE_HeartbeatExtended knx.paramBit((BASE_Share_ParamBlockOffset + BASE_HeartbeatExtended), 3)
#define BASE_ManualSave		0x000D
#define BASE_ManualSave_Mask	0x0007
// UnionOffset: 13, ParaOffset: 0, BitOffset: 5, Size: 3 Bit, Text: Manuelles speichern
#define ParamBASE_ManualSave ((uint)((knx.paramByte((BASE_Share_ParamBlockOffset + BASE_ManualSave))) & BASE_ManualSave_Mask))
#define BASE_PeriodicSave		0x000E
// UnionOffset: 13, ParaOffset: 1, Size: 8 Bit (1 Byte), Text: Zyklisches speichern
#define ParamBASE_PeriodicSave ((uint)((knx.paramByte((BASE_Share_ParamBlockOffset + BASE_PeriodicSave)))))
//!< Number: 1, Text: In Betrieb, Function: Zyklisch
#define BASE_KoHeartbeat 1
#define KoBASE_Heartbeat knx.getGroupObject(BASE_KoHeartbeat + BASE_Share_KoOffset)
//!< Number: 2, Text: Uhrzeit/Datum, Function: Eingang
#define BASE_KoTime 2
#define KoBASE_Time knx.getGroupObject(BASE_KoTime + BASE_Share_KoOffset)
//!< Number: 3, Text: Datum, Function: Eingang
#define BASE_KoDate 3
#define KoBASE_Date knx.getGroupObject(BASE_KoDate + BASE_Share_KoOffset)
//!< Number: 7, Text: Diagnose, Function: Diagnoseobjekt
#define BASE_KoDiagnose 7
#define KoBASE_Diagnose knx.getGroupObject(BASE_KoDiagnose + BASE_Share_KoOffset)
//!< Number: 10, Text: Sommerzeit aktiv, Function: Eingang
#define BASE_KoIsSummertime 10
#define KoBASE_IsSummertime knx.getGroupObject(BASE_KoIsSummertime + BASE_Share_KoOffset)
//!< Number: 11, Text: Speichern, Function: Eingang
#define BASE_KoManualSave 11
#define KoBASE_ManualSave knx.getGroupObject(BASE_KoManualSave + BASE_Share_KoOffset)

//-----Module: VirtualButton Share
#define BTN_ReactionTimeMultiClick		0x0000
// UnionOffset: 0, ParaOffset: 0, Size: 8 Bit (1 Byte), Text:   Mehrfach-Klick
#define ParamBTN_ReactionTimeMultiClick ((uint)((knx.paramByte((BTN_Share_ParamBlockOffset + BTN_ReactionTimeMultiClick)))))
#define BTN_ReactionTimeLong		0x0001
// UnionOffset: 0, ParaOffset: 1, Size: 8 Bit (1 Byte), Text:   Langer Tasterdruck
#define ParamBTN_ReactionTimeLong ((uint)((knx.paramByte((BTN_Share_ParamBlockOffset + BTN_ReactionTimeLong)))))
#define BTN_ReactionTimeExtraLong		0x0002
// UnionOffset: 0, ParaOffset: 2, Size: 8 Bit (1 Byte), Text:   Extra langer Tastedruck
#define ParamBTN_ReactionTimeExtraLong ((uint)((knx.paramByte((BTN_Share_ParamBlockOffset + BTN_ReactionTimeExtraLong)))))

//-----Module: VirtualButton Templ
#define BTN_ChannelCount 10
#define BTN_ChannelMode		0x0000
#define BTN_ChannelMode_Shift	4
#define BTN_ChannelMode_Mask	0x000F
// UnionOffset: 0, ParaOffset: 0, Size: 4 Bit, Text: Modus
#define ParamBTN_ChannelModeIndex(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelMode)) >> BTN_ChannelMode_Shift) & BTN_ChannelMode_Mask))
// UnionOffset: 0, ParaOffset: 0, Size: 4 Bit, Text: Modus
#define ParamBTN_ChannelMode ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelMode)) >> BTN_ChannelMode_Shift) & BTN_ChannelMode_Mask))
#define BTN_ChannelLock		0x0000
#define BTN_ChannelLock_Shift	2
#define BTN_ChannelLock_Mask	0x0003
// UnionOffset: 0, ParaOffset: 0, BitOffset: 4, Size: 2 Bit, Text: Sperre
#define ParamBTN_ChannelLockIndex(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelLock)) >> BTN_ChannelLock_Shift) & BTN_ChannelLock_Mask))
// UnionOffset: 0, ParaOffset: 0, BitOffset: 4, Size: 2 Bit, Text: Sperre
#define ParamBTN_ChannelLock ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelLock)) >> BTN_ChannelLock_Shift) & BTN_ChannelLock_Mask))
#define BTN_ChannelMultiClickCount		0x0000
// UnionOffset: 0, ParaOffset: 0, BitOffset: 4, Size: 1 Bit, Text: Ausgabe der Klickanzahl
#define ParamBTN_ChannelMultiClickCountIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelMultiClickCount), 4)
// UnionOffset: 0, ParaOffset: 0, BitOffset: 4, Size: 1 Bit, Text: Ausgabe der Klickanzahl
#define ParamBTN_ChannelMultiClickCount knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelMultiClickCount), 4)
#define BTN_ChannelInputA		0x0001
// UnionOffset: 1, ParaOffset: 0, Size: 1 Bit, Text: 1. Taster
#define ParamBTN_ChannelInputAIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelInputA), 0)
// UnionOffset: 1, ParaOffset: 0, Size: 1 Bit, Text: 1. Taster
#define ParamBTN_ChannelInputA knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelInputA), 0)
#define BTN_ChannelInputB		0x0003
// UnionOffset: 1, ParaOffset: 2, Size: 1 Bit, Text: 2. Taster
#define ParamBTN_ChannelInputBIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelInputB), 0)
// UnionOffset: 1, ParaOffset: 2, Size: 1 Bit, Text: 2. Taster
#define ParamBTN_ChannelInputB knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelInputB), 0)
#define BTN_ChannelReactionTimeMultiClick		0x0005
// UnionOffset: 5, ParaOffset: 0, Size: 8 Bit (1 Byte), Text:   Mehrfach-Klick
#define ParamBTN_ChannelReactionTimeMultiClickIndex(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelReactionTimeMultiClick)))))
// UnionOffset: 5, ParaOffset: 0, Size: 8 Bit (1 Byte), Text:   Mehrfach-Klick
#define ParamBTN_ChannelReactionTimeMultiClick ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelReactionTimeMultiClick)))))
#define BTN_ChannelReactionTimeLong		0x0006
// UnionOffset: 5, ParaOffset: 1, Size: 8 Bit (1 Byte), Text:   Langer Tasterdruck
#define ParamBTN_ChannelReactionTimeLongIndex(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelReactionTimeLong)))))
// UnionOffset: 5, ParaOffset: 1, Size: 8 Bit (1 Byte), Text:   Langer Tasterdruck
#define ParamBTN_ChannelReactionTimeLong ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelReactionTimeLong)))))
#define BTN_ChannelReactionTimeExtraLong		0x0007
// UnionOffset: 5, ParaOffset: 2, Size: 8 Bit (1 Byte), Text:   Extra langer Tasterdruck
#define ParamBTN_ChannelReactionTimeExtraLongIndex(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelReactionTimeExtraLong)))))
// UnionOffset: 5, ParaOffset: 2, Size: 8 Bit (1 Byte), Text:   Extra langer Tasterdruck
#define ParamBTN_ChannelReactionTimeExtraLong ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelReactionTimeExtraLong)))))
#define BTN_ChannelOutputShort_DPT		0x0008
// UnionOffset: 8, ParaOffset: 0, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputShort_DPTIndex(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_DPT)))))
// UnionOffset: 8, ParaOffset: 0, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputShort_DPT ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_DPT)))))
#define BTN_ChannelOutputLong_DPT		0x0009
// UnionOffset: 8, ParaOffset: 1, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputLong_DPTIndex(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_DPT)))))
// UnionOffset: 8, ParaOffset: 1, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputLong_DPT ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_DPT)))))
#define BTN_ChannelOutputExtraLong_DPT		0x000A
// UnionOffset: 8, ParaOffset: 2, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputExtraLong_DPTIndex(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_DPT)))))
// UnionOffset: 8, ParaOffset: 2, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputExtraLong_DPT ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_DPT)))))
#define BTN_ChannelOutputMulti_DPT		0x000B
// UnionOffset: 8, ParaOffset: 3, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputMulti_DPTIndex(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_DPT)))))
// UnionOffset: 8, ParaOffset: 3, Size: 8 Bit (1 Byte), Text: Datentyp
#define ParamBTN_ChannelOutputMulti_DPT ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_DPT)))))
#define BTN_ChannelOutputMulti_Click1_Active		0x000C
// UnionOffset: 12, ParaOffset: 0, Size: 1 Bit, Text: 1. Klick
#define ParamBTN_ChannelOutputMulti_Click1_ActiveIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click1_Active), 0)
// UnionOffset: 12, ParaOffset: 0, Size: 1 Bit, Text: 1. Klick
#define ParamBTN_ChannelOutputMulti_Click1_Active knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click1_Active), 0)
#define BTN_ChannelOutputMulti_Click2_Active		0x000C
// UnionOffset: 12, ParaOffset: 0, BitOffset: 1, Size: 1 Bit, Text: 2. Klick
#define ParamBTN_ChannelOutputMulti_Click2_ActiveIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click2_Active), 1)
// UnionOffset: 12, ParaOffset: 0, BitOffset: 1, Size: 1 Bit, Text: 2. Klick
#define ParamBTN_ChannelOutputMulti_Click2_Active knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click2_Active), 1)
#define BTN_ChannelOutputMulti_Click3_Active		0x000C
// UnionOffset: 12, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text: 3. Klick
#define ParamBTN_ChannelOutputMulti_Click3_ActiveIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click3_Active), 2)
// UnionOffset: 12, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text: 3. Klick
#define ParamBTN_ChannelOutputMulti_Click3_Active knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click3_Active), 2)
#define BTN_ChannelOutputShort_Taster1_Active_Press		0x000D
// UnionOffset: 13, ParaOffset: 0, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputShort_Taster1_Active_PressIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Active_Press), 0)
// UnionOffset: 13, ParaOffset: 0, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputShort_Taster1_Active_Press knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Active_Press), 0)
#define BTN_ChannelOutputShort_Taster1_Active_Release		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputShort_Taster1_Active_ReleaseIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Active_Release), 1)
// UnionOffset: 13, ParaOffset: 0, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputShort_Taster1_Active_Release knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Active_Release), 1)
#define BTN_ChannelOutputShort_Taster2_Active_Press		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputShort_Taster2_Active_PressIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Active_Press), 2)
// UnionOffset: 13, ParaOffset: 0, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputShort_Taster2_Active_Press knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Active_Press), 2)
#define BTN_ChannelOutputShort_Taster2_Active_Release		0x000D
// UnionOffset: 13, ParaOffset: 0, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputShort_Taster2_Active_ReleaseIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Active_Release), 3)
// UnionOffset: 13, ParaOffset: 0, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputShort_Taster2_Active_Release knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Active_Release), 3)
#define BTN_ChannelOutputLong_Taster1_Active_Press		0x000E
// UnionOffset: 13, ParaOffset: 1, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputLong_Taster1_Active_PressIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Active_Press), 0)
// UnionOffset: 13, ParaOffset: 1, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputLong_Taster1_Active_Press knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Active_Press), 0)
#define BTN_ChannelOutputLong_Taster1_Active_Release		0x000E
// UnionOffset: 13, ParaOffset: 1, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputLong_Taster1_Active_ReleaseIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Active_Release), 1)
// UnionOffset: 13, ParaOffset: 1, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputLong_Taster1_Active_Release knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Active_Release), 1)
#define BTN_ChannelOutputLong_Taster2_Active_Press		0x000E
// UnionOffset: 13, ParaOffset: 1, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputLong_Taster2_Active_PressIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Active_Press), 2)
// UnionOffset: 13, ParaOffset: 1, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputLong_Taster2_Active_Press knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Active_Press), 2)
#define BTN_ChannelOutputLong_Taster2_Active_Release		0x000E
// UnionOffset: 13, ParaOffset: 1, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputLong_Taster2_Active_ReleaseIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Active_Release), 3)
// UnionOffset: 13, ParaOffset: 1, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputLong_Taster2_Active_Release knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Active_Release), 3)
#define BTN_ChannelOutputExtraLong_Taster1_Active_Press		0x000F
// UnionOffset: 13, ParaOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputExtraLong_Taster1_Active_PressIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Active_Press), 0)
// UnionOffset: 13, ParaOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputExtraLong_Taster1_Active_Press knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Active_Press), 0)
#define BTN_ChannelOutputExtraLong_Taster1_Active_Release		0x000F
// UnionOffset: 13, ParaOffset: 2, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputExtraLong_Taster1_Active_ReleaseIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Active_Release), 1)
// UnionOffset: 13, ParaOffset: 2, BitOffset: 1, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputExtraLong_Taster1_Active_Release knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Active_Release), 1)
#define BTN_ChannelOutputExtraLong_Taster2_Active_Press		0x000F
// UnionOffset: 13, ParaOffset: 2, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputExtraLong_Taster2_Active_PressIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Active_Press), 2)
// UnionOffset: 13, ParaOffset: 2, BitOffset: 2, Size: 1 Bit, Text:   Wert beim Drücken
#define ParamBTN_ChannelOutputExtraLong_Taster2_Active_Press knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Active_Press), 2)
#define BTN_ChannelOutputExtraLong_Taster2_Active_Release		0x000F
// UnionOffset: 13, ParaOffset: 2, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputExtraLong_Taster2_Active_ReleaseIndex(X) knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Active_Release), 3)
// UnionOffset: 13, ParaOffset: 2, BitOffset: 3, Size: 1 Bit, Text:   Wert beim Loslassen
#define ParamBTN_ChannelOutputExtraLong_Taster2_Active_Release knx.paramBit((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Active_Release), 3)
#define BTN_ChannelOutputShort_Taster1_Dpt1_Press		0x0010
// UnionOffset: 16, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt1_Press)))))
// UnionOffset: 16, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt1_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt1_Press)))))
#define BTN_ChannelOutputShort_Taster1_Dpt1_Release		0x0012
// UnionOffset: 16, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt1_Release)))))
// UnionOffset: 16, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt1_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt1_Release)))))
#define BTN_ChannelOutputShort_Taster2_Dpt1_Press		0x0014
// UnionOffset: 16, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt1_Press)))))
// UnionOffset: 16, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt1_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt1_Press)))))
#define BTN_ChannelOutputShort_Taster2_Dpt1_Release		0x0016
// UnionOffset: 16, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt1_Release)))))
// UnionOffset: 16, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt1_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt1_Release)))))
#define BTN_ChannelOutputLong_Taster1_Dpt1_Press		0x0018
// UnionOffset: 16, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt1_Press)))))
// UnionOffset: 16, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt1_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt1_Press)))))
#define BTN_ChannelOutputLong_Taster1_Dpt1_Release		0x001A
// UnionOffset: 16, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt1_Release)))))
// UnionOffset: 16, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt1_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt1_Release)))))
#define BTN_ChannelOutputLong_Taster2_Dpt1_Press		0x001C
// UnionOffset: 16, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt1_Press)))))
// UnionOffset: 16, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt1_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt1_Press)))))
#define BTN_ChannelOutputLong_Taster2_Dpt1_Release		0x001E
// UnionOffset: 16, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt1_Release)))))
// UnionOffset: 16, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt1_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt1_Release)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt1_Press		0x0020
// UnionOffset: 16, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt1_Press)))))
// UnionOffset: 16, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt1_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt1_Press)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt1_Release		0x0022
// UnionOffset: 16, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt1_Release)))))
// UnionOffset: 16, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt1_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt1_Release)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt1_Press		0x0024
// UnionOffset: 16, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt1_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt1_Press)))))
// UnionOffset: 16, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt1_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt1_Press)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt1_Release		0x0026
// UnionOffset: 16, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt1_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt1_Release)))))
// UnionOffset: 16, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt1_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt1_Release)))))
#define BTN_ChannelOutputMulti_Click1_Dpt1		0x0028
// UnionOffset: 16, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt1Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click1_Dpt1)))))
// UnionOffset: 16, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt1 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click1_Dpt1)))))
#define BTN_ChannelOutputMulti_Click2_Dpt1		0x002A
// UnionOffset: 16, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt1Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click2_Dpt1)))))
// UnionOffset: 16, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt1 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click2_Dpt1)))))
#define BTN_ChannelOutputMulti_Click3_Dpt1		0x002C
// UnionOffset: 16, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt1Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click3_Dpt1)))))
// UnionOffset: 16, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt1 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click3_Dpt1)))))
#define BTN_ChannelOutputShort_Taster1_Dpt2_Press		0x002F
// UnionOffset: 47, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt2_Press)))))
// UnionOffset: 47, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt2_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt2_Press)))))
#define BTN_ChannelOutputShort_Taster1_Dpt2_Release		0x0031
// UnionOffset: 47, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt2_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt2_Release)))))
// UnionOffset: 47, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt2_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt2_Release)))))
#define BTN_ChannelOutputShort_Taster2_Dpt2_Press		0x0033
// UnionOffset: 47, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt2_Press)))))
// UnionOffset: 47, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt2_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt2_Press)))))
#define BTN_ChannelOutputShort_Taster2_Dpt2_Release		0x0035
// UnionOffset: 47, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt2_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt2_Release)))))
// UnionOffset: 47, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt2_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt2_Release)))))
#define BTN_ChannelOutputLong_Taster1_Dpt2_Press		0x0037
// UnionOffset: 47, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt2_Press)))))
// UnionOffset: 47, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt2_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt2_Press)))))
#define BTN_ChannelOutputLong_Taster1_Dpt2_Release		0x0039
// UnionOffset: 47, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt2_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt2_Release)))))
// UnionOffset: 47, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt2_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt2_Release)))))
#define BTN_ChannelOutputLong_Taster2_Dpt2_Press		0x003B
// UnionOffset: 47, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt2_Press)))))
// UnionOffset: 47, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt2_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt2_Press)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt2_Press		0x003D
// UnionOffset: 47, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt2_Press)))))
// UnionOffset: 47, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt2_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt2_Press)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt2_Release		0x003F
// UnionOffset: 47, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt2_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt2_Release)))))
// UnionOffset: 47, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt2_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt2_Release)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt2_Press		0x0041
// UnionOffset: 47, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt2_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt2_Press)))))
// UnionOffset: 47, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt2_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt2_Press)))))
#define BTN_ChannelOutputMulti_Click1_Dpt2		0x0043
// UnionOffset: 47, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt2Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click1_Dpt2)))))
// UnionOffset: 47, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt2 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click1_Dpt2)))))
#define BTN_ChannelOutputMulti_Click2_Dpt2		0x0045
// UnionOffset: 47, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt2Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click2_Dpt2)))))
// UnionOffset: 47, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt2 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click2_Dpt2)))))
#define BTN_ChannelOutputMulti_Click3_Dpt2		0x0047
// UnionOffset: 47, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt2Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click3_Dpt2)))))
// UnionOffset: 47, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt2 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click3_Dpt2)))))
#define BTN_ChannelOutputShort_Taster1_Dpt5_Press		0x004E
// UnionOffset: 78, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt5_Press)))))
// UnionOffset: 78, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt5_Press)))))
#define BTN_ChannelOutputShort_Taster1_Dpt5_Release		0x0050
// UnionOffset: 78, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt5_Release)))))
// UnionOffset: 78, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt5_Release)))))
#define BTN_ChannelOutputShort_Taster2_Dpt5_Press		0x0052
// UnionOffset: 78, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt5_Press)))))
// UnionOffset: 78, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt5_Press)))))
#define BTN_ChannelOutputShort_Taster2_Dpt5_Release		0x0054
// UnionOffset: 78, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt5_Release)))))
// UnionOffset: 78, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt5_Release)))))
#define BTN_ChannelOutputLong_Taster1_Dpt5_Press		0x0056
// UnionOffset: 78, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt5_Press)))))
// UnionOffset: 78, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt5_Press)))))
#define BTN_ChannelOutputLong_Taster1_Dpt5_Release		0x0058
// UnionOffset: 78, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt5_Release)))))
// UnionOffset: 78, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt5_Release)))))
#define BTN_ChannelOutputLong_Taster2_Dpt5_Press		0x005A
// UnionOffset: 78, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt5_Press)))))
// UnionOffset: 78, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt5_Press)))))
#define BTN_ChannelOutputLong_Taster2_Dpt5_Release		0x005C
// UnionOffset: 78, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt5_Release)))))
// UnionOffset: 78, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt5_Release)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5_Press		0x005E
// UnionOffset: 78, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt5_Press)))))
// UnionOffset: 78, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt5_Press)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5_Release		0x0060
// UnionOffset: 78, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt5_Release)))))
// UnionOffset: 78, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt5_Release)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5_Press		0x0062
// UnionOffset: 78, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt5_Press)))))
// UnionOffset: 78, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt5_Press)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5_Release		0x0064
// UnionOffset: 78, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt5_Release)))))
// UnionOffset: 78, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt5_Release)))))
#define BTN_ChannelOutputMulti_Click1_Dpt5		0x0066
// UnionOffset: 78, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt5Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click1_Dpt5)))))
// UnionOffset: 78, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt5 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click1_Dpt5)))))
#define BTN_ChannelOutputMulti_Click2_Dpt5		0x0068
// UnionOffset: 78, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt5Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click2_Dpt5)))))
// UnionOffset: 78, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt5 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click2_Dpt5)))))
#define BTN_ChannelOutputMulti_Click3_Dpt5		0x006A
// UnionOffset: 78, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt5Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click3_Dpt5)))))
// UnionOffset: 78, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt5 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click3_Dpt5)))))
#define BTN_ChannelOutputShort_Taster1_Dpt5001_Press		0x006D
// UnionOffset: 109, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt5001_Press)))))
// UnionOffset: 109, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5001_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt5001_Press)))))
#define BTN_ChannelOutputShort_Taster1_Dpt5001_Release		0x006F
// UnionOffset: 109, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt5001_Release)))))
// UnionOffset: 109, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt5001_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt5001_Release)))))
#define BTN_ChannelOutputShort_Taster2_Dpt5001_Press		0x0071
// UnionOffset: 109, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt5001_Press)))))
// UnionOffset: 109, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5001_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt5001_Press)))))
#define BTN_ChannelOutputShort_Taster2_Dpt5001_Release		0x0073
// UnionOffset: 109, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt5001_Release)))))
// UnionOffset: 109, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt5001_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt5001_Release)))))
#define BTN_ChannelOutputLong_Taster1_Dpt5001_Press		0x0075
// UnionOffset: 109, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt5001_Press)))))
// UnionOffset: 109, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5001_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt5001_Press)))))
#define BTN_ChannelOutputLong_Taster1_Dpt5001_Release		0x0077
// UnionOffset: 109, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt5001_Release)))))
// UnionOffset: 109, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt5001_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt5001_Release)))))
#define BTN_ChannelOutputLong_Taster2_Dpt5001_Press		0x0079
// UnionOffset: 109, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt5001_Press)))))
// UnionOffset: 109, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5001_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt5001_Press)))))
#define BTN_ChannelOutputLong_Taster2_Dpt5001_Release		0x007B
// UnionOffset: 109, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt5001_Release)))))
// UnionOffset: 109, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt5001_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt5001_Release)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Press		0x007D
// UnionOffset: 109, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Press)))))
// UnionOffset: 109, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5001_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Press)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Release		0x007F
// UnionOffset: 109, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Release)))))
// UnionOffset: 109, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt5001_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt5001_Release)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Press		0x0081
// UnionOffset: 109, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5001_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Press)))))
// UnionOffset: 109, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5001_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Press)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Release		0x0083
// UnionOffset: 109, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5001_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Release)))))
// UnionOffset: 109, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt5001_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt5001_Release)))))
#define BTN_ChannelOutputMulti_Click1_Dpt5001		0x0085
// UnionOffset: 109, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt5001Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click1_Dpt5001)))))
// UnionOffset: 109, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt5001 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click1_Dpt5001)))))
#define BTN_ChannelOutputMulti_Click2_Dpt5001		0x0087
// UnionOffset: 109, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt5001Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click2_Dpt5001)))))
// UnionOffset: 109, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt5001 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click2_Dpt5001)))))
#define BTN_ChannelOutputMulti_Click3_Dpt5001		0x0089
// UnionOffset: 109, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt5001Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click3_Dpt5001)))))
// UnionOffset: 109, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt5001 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click3_Dpt5001)))))
#define BTN_ChannelOutputShort_Taster1_Dpt7_Press		0x008C
// UnionOffset: 140, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt7_Press)))))
// UnionOffset: 140, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt7_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt7_Press)))))
#define BTN_ChannelOutputShort_Taster1_Dpt7_Release		0x008E
// UnionOffset: 140, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt7_Release)))))
// UnionOffset: 140, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt7_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt7_Release)))))
#define BTN_ChannelOutputShort_Taster2_Dpt7_Press		0x0090
// UnionOffset: 140, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt7_Press)))))
// UnionOffset: 140, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt7_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt7_Press)))))
#define BTN_ChannelOutputShort_Taster2_Dpt7_Release		0x0092
// UnionOffset: 140, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt7_Release)))))
// UnionOffset: 140, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt7_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt7_Release)))))
#define BTN_ChannelOutputLong_Taster1_Dpt7_Press		0x0094
// UnionOffset: 140, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt7_Press)))))
// UnionOffset: 140, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt7_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt7_Press)))))
#define BTN_ChannelOutputLong_Taster1_Dpt7_Release		0x0096
// UnionOffset: 140, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt7_Release)))))
// UnionOffset: 140, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt7_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt7_Release)))))
#define BTN_ChannelOutputLong_Taster2_Dpt7_Press		0x0098
// UnionOffset: 140, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt7_Press)))))
// UnionOffset: 140, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt7_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt7_Press)))))
#define BTN_ChannelOutputLong_Taster2_Dpt7_Release		0x009A
// UnionOffset: 140, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt7_Release)))))
// UnionOffset: 140, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt7_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt7_Release)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt7_Press		0x009C
// UnionOffset: 140, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt7_Press)))))
// UnionOffset: 140, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt7_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt7_Press)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt7_Release		0x009E
// UnionOffset: 140, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt7_Release)))))
// UnionOffset: 140, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt7_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt7_Release)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt7_Press		0x00A0
// UnionOffset: 140, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt7_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt7_Press)))))
// UnionOffset: 140, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt7_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt7_Press)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt7_Release		0x00A2
// UnionOffset: 140, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt7_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt7_Release)))))
// UnionOffset: 140, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt7_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt7_Release)))))
#define BTN_ChannelOutputMulti_Click1_Dpt7		0x00A4
// UnionOffset: 140, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt7Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click1_Dpt7)))))
// UnionOffset: 140, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt7 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click1_Dpt7)))))
#define BTN_ChannelOutputMulti_Click2_Dpt7		0x00A6
// UnionOffset: 140, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt7Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click2_Dpt7)))))
// UnionOffset: 140, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt7 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click2_Dpt7)))))
#define BTN_ChannelOutputMulti_Click3_Dpt7		0x00A8
// UnionOffset: 140, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt7Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click3_Dpt7)))))
// UnionOffset: 140, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt7 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click3_Dpt7)))))
#define BTN_ChannelOutputShort_Taster1_Dpt18_Press		0x00AB
// UnionOffset: 171, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt18_Press)))))
// UnionOffset: 171, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt18_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt18_Press)))))
#define BTN_ChannelOutputShort_Taster1_Dpt18_Release		0x00AD
// UnionOffset: 171, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt18_Release)))))
// UnionOffset: 171, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt18_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt18_Release)))))
#define BTN_ChannelOutputShort_Taster2_Dpt18_Press		0x00AF
// UnionOffset: 171, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt18_Press)))))
// UnionOffset: 171, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt18_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt18_Press)))))
#define BTN_ChannelOutputShort_Taster2_Dpt18_Release		0x00B1
// UnionOffset: 171, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt18_Release)))))
// UnionOffset: 171, ParaOffset: 6, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt18_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt18_Release)))))
#define BTN_ChannelOutputLong_Taster1_Dpt18_Press		0x00B3
// UnionOffset: 171, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt18_Press)))))
// UnionOffset: 171, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt18_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt18_Press)))))
#define BTN_ChannelOutputLong_Taster1_Dpt18_Release		0x00B5
// UnionOffset: 171, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt18_Release)))))
// UnionOffset: 171, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt18_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt18_Release)))))
#define BTN_ChannelOutputLong_Taster2_Dpt18_Press		0x00B7
// UnionOffset: 171, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt18_Press)))))
// UnionOffset: 171, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt18_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt18_Press)))))
#define BTN_ChannelOutputLong_Taster2_Dpt18_Release		0x00B9
// UnionOffset: 171, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt18_Release)))))
// UnionOffset: 171, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt18_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt18_Release)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt18_Press		0x00BB
// UnionOffset: 171, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt18_Press)))))
// UnionOffset: 171, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt18_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt18_Press)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt18_Release		0x00BD
// UnionOffset: 171, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt18_Release)))))
// UnionOffset: 171, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt18_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt18_Release)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt18_Press		0x00BF
// UnionOffset: 171, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt18_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt18_Press)))))
// UnionOffset: 171, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt18_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt18_Press)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt18_Release		0x00C1
// UnionOffset: 171, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt18_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt18_Release)))))
// UnionOffset: 171, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt18_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt18_Release)))))
#define BTN_ChannelOutputMulti_Click1_Dpt18		0x00C3
// UnionOffset: 171, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt18Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click1_Dpt18)))))
// UnionOffset: 171, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click1_Dpt18 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click1_Dpt18)))))
#define BTN_ChannelOutputMulti_Click2_Dpt18		0x00C5
// UnionOffset: 171, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt18Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click2_Dpt18)))))
// UnionOffset: 171, ParaOffset: 26, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click2_Dpt18 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click2_Dpt18)))))
#define BTN_ChannelOutputMulti_Click3_Dpt18		0x00C7
// UnionOffset: 171, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt18Index(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputMulti_Click3_Dpt18)))))
// UnionOffset: 171, ParaOffset: 28, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputMulti_Click3_Dpt18 ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputMulti_Click3_Dpt18)))))
#define BTN_ChannelOutputShort_Taster1_Dpt3007_Press		0x00CA
// UnionOffset: 202, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt3007_Press)))))
// UnionOffset: 202, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3007_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt3007_Press)))))
#define BTN_ChannelOutputShort_Taster1_Dpt3007_Release		0x00CC
// UnionOffset: 202, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt3007_Release)))))
// UnionOffset: 202, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3007_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt3007_Release)))))
#define BTN_ChannelOutputShort_Taster2_Dpt3007_Press		0x00CE
// UnionOffset: 202, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt3007_Press)))))
// UnionOffset: 202, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3007_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt3007_Press)))))
#define BTN_ChannelOutputShort_Taster2_Dpt3007_Release		0x00D2
// UnionOffset: 202, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt3007_Release)))))
// UnionOffset: 202, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3007_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt3007_Release)))))
#define BTN_ChannelOutputLong_Taster1_Dpt3007_Press		0x00D4
// UnionOffset: 202, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt3007_Press)))))
// UnionOffset: 202, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3007_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt3007_Press)))))
#define BTN_ChannelOutputLong_Taster1_Dpt3007_Release		0x00D6
// UnionOffset: 202, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt3007_Release)))))
// UnionOffset: 202, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3007_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt3007_Release)))))
#define BTN_ChannelOutputLong_Taster2_Dpt3007_Press		0x00D8
// UnionOffset: 202, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt3007_Press)))))
// UnionOffset: 202, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3007_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt3007_Press)))))
#define BTN_ChannelOutputLong_Taster2_Dpt3007_Release		0x00DA
// UnionOffset: 202, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt3007_Release)))))
// UnionOffset: 202, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3007_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt3007_Release)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Press		0x00DC
// UnionOffset: 202, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Press)))))
// UnionOffset: 202, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3007_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Press)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Release		0x00DE
// UnionOffset: 202, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Release)))))
// UnionOffset: 202, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3007_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt3007_Release)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Press		0x00E0
// UnionOffset: 202, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3007_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Press)))))
// UnionOffset: 202, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3007_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Press)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Release		0x00E2
// UnionOffset: 202, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3007_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Release)))))
// UnionOffset: 202, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3007_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt3007_Release)))))
#define BTN_ChannelOutputShort_Taster1_Dpt3008_Press		0x00E9
// UnionOffset: 233, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt3008_Press)))))
// UnionOffset: 233, ParaOffset: 0, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3008_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt3008_Press)))))
#define BTN_ChannelOutputShort_Taster1_Dpt3008_Release		0x00EB
// UnionOffset: 233, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster1_Dpt3008_Release)))))
// UnionOffset: 233, ParaOffset: 2, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster1_Dpt3008_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster1_Dpt3008_Release)))))
#define BTN_ChannelOutputShort_Taster2_Dpt3008_Press		0x00ED
// UnionOffset: 233, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt3008_Press)))))
// UnionOffset: 233, ParaOffset: 4, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3008_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt3008_Press)))))
#define BTN_ChannelOutputShort_Taster2_Dpt3008_Release		0x00F1
// UnionOffset: 233, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputShort_Taster2_Dpt3008_Release)))))
// UnionOffset: 233, ParaOffset: 8, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputShort_Taster2_Dpt3008_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputShort_Taster2_Dpt3008_Release)))))
#define BTN_ChannelOutputLong_Taster1_Dpt3008_Press		0x00F3
// UnionOffset: 233, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt3008_Press)))))
// UnionOffset: 233, ParaOffset: 10, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3008_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt3008_Press)))))
#define BTN_ChannelOutputLong_Taster1_Dpt3008_Release		0x00F5
// UnionOffset: 233, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster1_Dpt3008_Release)))))
// UnionOffset: 233, ParaOffset: 12, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster1_Dpt3008_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster1_Dpt3008_Release)))))
#define BTN_ChannelOutputLong_Taster2_Dpt3008_Press		0x00F7
// UnionOffset: 233, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt3008_Press)))))
// UnionOffset: 233, ParaOffset: 14, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3008_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt3008_Press)))))
#define BTN_ChannelOutputLong_Taster2_Dpt3008_Release		0x00F9
// UnionOffset: 233, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputLong_Taster2_Dpt3008_Release)))))
// UnionOffset: 233, ParaOffset: 16, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputLong_Taster2_Dpt3008_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputLong_Taster2_Dpt3008_Release)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Press		0x00FB
// UnionOffset: 233, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Press)))))
// UnionOffset: 233, ParaOffset: 18, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3008_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Press)))))
#define BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Release		0x00FD
// UnionOffset: 233, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Release)))))
// UnionOffset: 233, ParaOffset: 20, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster1_Dpt3008_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster1_Dpt3008_Release)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Press		0x00FF
// UnionOffset: 233, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3008_PressIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Press)))))
// UnionOffset: 233, ParaOffset: 22, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3008_Press ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Press)))))
#define BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Release		0x0101
// UnionOffset: 233, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3008_ReleaseIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Release)))))
// UnionOffset: 233, ParaOffset: 24, Size: 16 Bit (2 Byte), Text: 
#define ParamBTN_ChannelOutputExtraLong_Taster2_Dpt3008_Release ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutputExtraLong_Taster2_Dpt3008_Release)))))
#define BTN_ChannelOutput2Short_Taster1		0x0108
#define BTN_ChannelOutput2Short_Taster1_Shift	6
#define BTN_ChannelOutput2Short_Taster1_Mask	0x0003
// UnionOffset: 264, ParaOffset: 0, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Short_Taster1Index(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutput2Short_Taster1)) >> BTN_ChannelOutput2Short_Taster1_Shift) & BTN_ChannelOutput2Short_Taster1_Mask))
// UnionOffset: 264, ParaOffset: 0, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Short_Taster1 ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutput2Short_Taster1)) >> BTN_ChannelOutput2Short_Taster1_Shift) & BTN_ChannelOutput2Short_Taster1_Mask))
#define BTN_ChannelOutput2Short_Taster2		0x0108
#define BTN_ChannelOutput2Short_Taster2_Shift	4
#define BTN_ChannelOutput2Short_Taster2_Mask	0x0003
// UnionOffset: 264, ParaOffset: 0, BitOffset: 2, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Short_Taster2Index(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutput2Short_Taster2)) >> BTN_ChannelOutput2Short_Taster2_Shift) & BTN_ChannelOutput2Short_Taster2_Mask))
// UnionOffset: 264, ParaOffset: 0, BitOffset: 2, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Short_Taster2 ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutput2Short_Taster2)) >> BTN_ChannelOutput2Short_Taster2_Shift) & BTN_ChannelOutput2Short_Taster2_Mask))
#define BTN_ChannelOutput2Long_Taster1		0x0108
#define BTN_ChannelOutput2Long_Taster1_Shift	2
#define BTN_ChannelOutput2Long_Taster1_Mask	0x0003
// UnionOffset: 264, ParaOffset: 0, BitOffset: 4, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Long_Taster1Index(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutput2Long_Taster1)) >> BTN_ChannelOutput2Long_Taster1_Shift) & BTN_ChannelOutput2Long_Taster1_Mask))
// UnionOffset: 264, ParaOffset: 0, BitOffset: 4, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Long_Taster1 ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutput2Long_Taster1)) >> BTN_ChannelOutput2Long_Taster1_Shift) & BTN_ChannelOutput2Long_Taster1_Mask))
#define BTN_ChannelOutput2Long_Taster2		0x0108
#define BTN_ChannelOutput2Long_Taster2_Mask	0x0003
// UnionOffset: 264, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Long_Taster2Index(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutput2Long_Taster2))) & BTN_ChannelOutput2Long_Taster2_Mask))
// UnionOffset: 264, ParaOffset: 0, BitOffset: 6, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2Long_Taster2 ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutput2Long_Taster2))) & BTN_ChannelOutput2Long_Taster2_Mask))
#define BTN_ChannelOutput2ExtraLong_Taster1		0x0109
#define BTN_ChannelOutput2ExtraLong_Taster1_Shift	6
#define BTN_ChannelOutput2ExtraLong_Taster1_Mask	0x0003
// UnionOffset: 264, ParaOffset: 1, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2ExtraLong_Taster1Index(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutput2ExtraLong_Taster1)) >> BTN_ChannelOutput2ExtraLong_Taster1_Shift) & BTN_ChannelOutput2ExtraLong_Taster1_Mask))
// UnionOffset: 264, ParaOffset: 1, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2ExtraLong_Taster1 ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutput2ExtraLong_Taster1)) >> BTN_ChannelOutput2ExtraLong_Taster1_Shift) & BTN_ChannelOutput2ExtraLong_Taster1_Mask))
#define BTN_ChannelOutput2ExtraLong_Taster2		0x0109
#define BTN_ChannelOutput2ExtraLong_Taster2_Shift	4
#define BTN_ChannelOutput2ExtraLong_Taster2_Mask	0x0003
// UnionOffset: 264, ParaOffset: 1, BitOffset: 2, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2ExtraLong_Taster2Index(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelOutput2ExtraLong_Taster2)) >> BTN_ChannelOutput2ExtraLong_Taster2_Shift) & BTN_ChannelOutput2ExtraLong_Taster2_Mask))
// UnionOffset: 264, ParaOffset: 1, BitOffset: 2, Size: 2 Bit, Text:   Zusatzausgang (DPT1 beim Loslassen)
#define ParamBTN_ChannelOutput2ExtraLong_Taster2 ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelOutput2ExtraLong_Taster2)) >> BTN_ChannelOutput2ExtraLong_Taster2_Shift) & BTN_ChannelOutput2ExtraLong_Taster2_Mask))
#define BTN_ChannelStatusThreshold		0x010A
// UnionOffset: 266, ParaOffset: 0, Size: 8 Bit (1 Byte), Text: Schwellwert
#define ParamBTN_ChannelStatusThresholdIndex(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelStatusThreshold)))))
// UnionOffset: 266, ParaOffset: 0, Size: 8 Bit (1 Byte), Text: Schwellwert
#define ParamBTN_ChannelStatusThreshold ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelStatusThreshold)))))
#define BTN_ChannelStatusFallbackBase		0x010B
#define BTN_ChannelStatusFallbackBase_Shift	6
#define BTN_ChannelStatusFallbackBase_Mask	0x0003
// UnionOffset: 266, ParaOffset: 1, Size: 2 Bit, Text: Zeitbasis
#define ParamBTN_ChannelStatusFallbackBaseIndex(X) ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelStatusFallbackBase)) >> BTN_ChannelStatusFallbackBase_Shift) & BTN_ChannelStatusFallbackBase_Mask))
// UnionOffset: 266, ParaOffset: 1, Size: 2 Bit, Text: Zeitbasis
#define ParamBTN_ChannelStatusFallbackBase ((uint)((knx.paramByte((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelStatusFallbackBase)) >> BTN_ChannelStatusFallbackBase_Shift) & BTN_ChannelStatusFallbackBase_Mask))
#define BTN_ChannelStatusFallbackTime		0x010B
#define BTN_ChannelStatusFallbackTime_Mask	0x3FFF
// UnionOffset: 266, ParaOffset: 1, BitOffset: 2, Size: 14 Bit, Text: Zeit
#define ParamBTN_ChannelStatusFallbackTimeIndex(X) ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * X + BTN_ChannelStatusFallbackTime))) & BTN_ChannelStatusFallbackTime_Mask))
// UnionOffset: 266, ParaOffset: 1, BitOffset: 2, Size: 14 Bit, Text: Zeit
#define ParamBTN_ChannelStatusFallbackTime ((uint)((knx.paramWord((BTN_Templ_ParamBlockOffset + BTN_Templ_ParamBlockSize * channelIndex() + BTN_ChannelStatusFallbackTime))) & BTN_ChannelStatusFallbackTime_Mask))
#define ParamBTN_ChannelStatusFallbackTimeMS (paramDelay(ParamBTN_ChannelStatusFallbackTime))
//!< Number: 0, Text: , Function: 
#define BTN_KoChannelLock 0
#define KoBTN_ChannelLockIndex(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelLock)
#define KoBTN_ChannelLock knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelLock)
//!< Number: 1, Text: , Function: Taster {{argChan}}, Eingang 1
#define BTN_KoChannelInput1 1
#define KoBTN_ChannelInput1Index(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelInput1)
#define KoBTN_ChannelInput1 knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelInput1)
//!< Number: 2, Text: , Function: Taster {{argChan}}, Eingang 2
#define BTN_KoChannelInput2 2
#define KoBTN_ChannelInput2Index(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelInput2)
#define KoBTN_ChannelInput2 knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelInput2)
//!< Number: 3, Text: , Function: Taster {{argChan}}, Status
#define BTN_KoChannelOutput1Status 3
#define KoBTN_ChannelOutput1StatusIndex(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelOutput1Status)
#define KoBTN_ChannelOutput1Status knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelOutput1Status)
//!< Number: 4, Text: , Function: Taster {{argChan}}, Status (Lang)
#define BTN_KoChannelOutput2Status 4
#define KoBTN_ChannelOutput2StatusIndex(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelOutput2Status)
#define KoBTN_ChannelOutput2Status knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelOutput2Status)
//!< Number: 5, Text: , Function: Taster {{argChan}}, Status (Extralang)
#define BTN_KoChannelOutput3Status 5
#define KoBTN_ChannelOutput3StatusIndex(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelOutput3Status)
#define KoBTN_ChannelOutput3Status knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelOutput3Status)
//!< Number: 6, Text: , Function: Taster {{argChan}}, Ausgang
#define BTN_KoChannelOutput1 6
#define KoBTN_ChannelOutput1Index(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelOutput1)
#define KoBTN_ChannelOutput1 knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelOutput1)
//!< Number: 7, Text: , Function: Taster {{argChan}}, Ausgang (Lang)
#define BTN_KoChannelOutput2 7
#define KoBTN_ChannelOutput2Index(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelOutput2)
#define KoBTN_ChannelOutput2 knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelOutput2)
//!< Number: 8, Text: , Function: Taster {{argChan}}, Ausgang (Extralang)
#define BTN_KoChannelOutput3 8
#define KoBTN_ChannelOutput3Index(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelOutput3)
#define KoBTN_ChannelOutput3 knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelOutput3)
//!< Number: 9, Text: , Function: Taster {{argChan}}, Zusatzausgang
#define BTN_KoChannelOutput4 9
#define KoBTN_ChannelOutput4Index(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelOutput4)
#define KoBTN_ChannelOutput4 knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelOutput4)
//!< Number: 10, Text: , Function: Taster {{argChan}}, Zusatzausgang (Lang)
#define BTN_KoChannelOutput5 10
#define KoBTN_ChannelOutput5Index(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelOutput5)
#define KoBTN_ChannelOutput5 knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelOutput5)
//!< Number: 11, Text: , Function: Taster {{argChan}}, Zusatzausgang (Extralang)
#define BTN_KoChannelOutput6 11
#define KoBTN_ChannelOutput6Index(X) knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * X + BTN_KoChannelOutput6)
#define KoBTN_ChannelOutput6 knx.getGroupObject(BTN_Templ_KoOffset + BTN_Templ_KoBlockSize * channelIndex() + BTN_KoChannelOutput6)

