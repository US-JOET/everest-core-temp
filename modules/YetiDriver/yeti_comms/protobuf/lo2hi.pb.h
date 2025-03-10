/* Automatically generated nanopb header */
/* Generated by nanopb-0.4.5 */

#ifndef PB_LO2HI_PB_H_INCLUDED
#define PB_LO2HI_PB_H_INCLUDED
#include <everest/3rd_party/nanopb/pb.h>
#include "common.pb.h"

#if PB_PROTO_HEADER_VERSION != 40
#error Regenerate this file with the current version of nanopb generator.
#endif

/* Enum definitions */
typedef enum _Event_InterfaceEvent { 
    Event_InterfaceEvent_CAR_PLUGGED_IN = 0, 
    Event_InterfaceEvent_CAR_REQUESTED_POWER = 1, 
    Event_InterfaceEvent_POWER_ON = 2, 
    Event_InterfaceEvent_POWER_OFF = 3, 
    Event_InterfaceEvent_CAR_REQUESTED_STOP_POWER = 4, 
    Event_InterfaceEvent_CAR_UNPLUGGED = 5, 
    Event_InterfaceEvent_ERROR_E = 6, 
    Event_InterfaceEvent_ERROR_DF = 7, 
    Event_InterfaceEvent_ERROR_RELAIS = 8, 
    Event_InterfaceEvent_ERROR_RCD = 9, 
    Event_InterfaceEvent_ERROR_VENTILATION_NOT_AVAILABLE = 10, 
    Event_InterfaceEvent_ERROR_OVER_CURRENT = 11, 
    Event_InterfaceEvent_ENTER_BCD = 12, 
    Event_InterfaceEvent_LEAVE_BCD = 13, 
    Event_InterfaceEvent_PERMANENT_FAULT = 14, 
    Event_InterfaceEvent_EVSE_REPLUG_STARTED = 15, 
    Event_InterfaceEvent_EVSE_REPLUG_FINISHED = 16 
} Event_InterfaceEvent;

typedef enum _StateUpdate_State { 
    StateUpdate_State_DISABLED = 0, 
    StateUpdate_State_IDLE = 1, 
    StateUpdate_State_WAITING_FOR_AUTHENTICATION = 2, 
    StateUpdate_State_CHARGING = 3, 
    StateUpdate_State_CHARGING_PAUSED_EV = 4, 
    StateUpdate_State_CHARGING_PAUSED_EVSE = 5, 
    StateUpdate_State_CHARGING_FINSIHED = 6, 
    StateUpdate_State_ERROR = 7, 
    StateUpdate_State_FAULTED = 8 
} StateUpdate_State;

typedef enum _ErrorFlags_ErrorType { 
    ErrorFlags_ErrorType_ERROR_F = 0, 
    ErrorFlags_ErrorType_ERROR_E = 1, 
    ErrorFlags_ErrorType_ERROR_DF = 2, 
    ErrorFlags_ErrorType_ERROR_RELAIS = 3, 
    ErrorFlags_ErrorType_ERROR_VENTILATION_NOT_AVAILABLE = 4, 
    ErrorFlags_ErrorType_ERROR_RCD = 5, 
    ErrorFlags_ErrorType_ERROR_OVER_CURRENT = 6 
} ErrorFlags_ErrorType;

typedef enum _DebugUpdate_LoLevelState { 
    DebugUpdate_LoLevelState_DISABLED = 0, 
    DebugUpdate_LoLevelState_A = 1, 
    DebugUpdate_LoLevelState_B = 2, 
    DebugUpdate_LoLevelState_C = 3, 
    DebugUpdate_LoLevelState_D = 4, 
    DebugUpdate_LoLevelState_E = 5, 
    DebugUpdate_LoLevelState_F = 6, 
    DebugUpdate_LoLevelState_DF = 7 
} DebugUpdate_LoLevelState;

/* Struct definitions */
typedef struct _ResetDone { 
    char dummy_field;
} ResetDone;

typedef struct _ChargingFlags { 
    bool ventilation; 
} ChargingFlags;

typedef struct _DebugUpdate { 
    uint32_t time_stamp; 
    float evse_pwm_voltage_hi; 
    float evse_pwm_voltage_lo; 
    float supply_voltage_12V; 
    float supply_voltage_N12V; 
    DebugUpdate_LoLevelState lowlevel_state; 
    bool evse_pwm_running; 
    bool ev_simplified_mode; 
    bool has_ventilation; 
    bool ventilated_charging_active; 
    bool rcd_reclosing_allowed; 
    bool authorized; 
    float cpu_temperature; 
    bool rcd_enabled; 
    float evse_pp_voltage; 
    float max_current_cable; 
    uint32_t watchdog_reset_count; 
    bool simulation; 
    InterfaceControlMode control_mode; 
    float max_current; 
    bool use_three_phases; 
    float rcd_current; 
    bool relais_on; 
} DebugUpdate;

typedef struct _ErrorFlags { 
    ErrorFlags_ErrorType type; 
} ErrorFlags;

typedef struct _Event { 
    Event_InterfaceEvent type; 
} Event;

typedef struct _KeepAliveLo { 
    uint32_t time_stamp; 
    uint32_t hw_type; 
    uint32_t hw_revision; 
    uint32_t protocol_version_major; 
    uint32_t protocol_version_minor; 
    char sw_version_string[51]; 
    float hwcap_max_current; 
    float hwcap_min_current; 
    uint32_t hwcap_max_phase_count; 
    uint32_t hwcap_min_phase_count; 
    bool supports_changing_phases_during_charging; 
} KeepAliveLo;

typedef struct _PowerMeter { 
    uint32_t time_stamp; 
    float vrmsL1; 
    float vrmsL2; 
    float vrmsL3; 
    float irmsL1; 
    float irmsL2; 
    float irmsL3; 
    float irmsN; 
    float wattHrL1; 
    float wattHrL2; 
    float wattHrL3; 
    float totalWattHr; 
    float tempL1; 
    float tempL2; 
    float tempL3; 
    float tempN; 
    float wattL1; 
    float wattL2; 
    float wattL3; 
    float freqL1; 
    float freqL2; 
    float freqL3; 
    bool phaseSeqError; 
} PowerMeter;

typedef struct _SimulationFeedback { 
    float pwmDutyCycle; 
    float evse_pwm_voltage_hi; 
    float evse_pwm_voltage_lo; 
    bool evse_pwm_running; 
    uint32_t relais_on; 
} SimulationFeedback;

typedef struct _StateUpdate { 
    uint32_t time_stamp; 
    StateUpdate_State state; 
    pb_size_t which_state_flags;
    union {
        ErrorFlags error_type;
        ChargingFlags charging_flags;
    } state_flags; 
} StateUpdate;

/* This container message is send from Lo Level to Hi level and may contain any allowed message in that direction. */
typedef struct _LoToHi { 
    /* Common Packets */
    pb_size_t which_payload;
    union {
        StateUpdate state_update;
        DebugUpdate debug_update;
        KeepAliveLo keep_alive;
        PowerMeter power_meter;
        SimulationFeedback simulation_feedback;
        Event event;
        ResetDone reset_done;
    } payload; 
} LoToHi;


/* Helper constants for enums */
#define _Event_InterfaceEvent_MIN Event_InterfaceEvent_CAR_PLUGGED_IN
#define _Event_InterfaceEvent_MAX Event_InterfaceEvent_EVSE_REPLUG_FINISHED
#define _Event_InterfaceEvent_ARRAYSIZE ((Event_InterfaceEvent)(Event_InterfaceEvent_EVSE_REPLUG_FINISHED+1))

#define _StateUpdate_State_MIN StateUpdate_State_DISABLED
#define _StateUpdate_State_MAX StateUpdate_State_FAULTED
#define _StateUpdate_State_ARRAYSIZE ((StateUpdate_State)(StateUpdate_State_FAULTED+1))

#define _ErrorFlags_ErrorType_MIN ErrorFlags_ErrorType_ERROR_F
#define _ErrorFlags_ErrorType_MAX ErrorFlags_ErrorType_ERROR_OVER_CURRENT
#define _ErrorFlags_ErrorType_ARRAYSIZE ((ErrorFlags_ErrorType)(ErrorFlags_ErrorType_ERROR_OVER_CURRENT+1))

#define _DebugUpdate_LoLevelState_MIN DebugUpdate_LoLevelState_DISABLED
#define _DebugUpdate_LoLevelState_MAX DebugUpdate_LoLevelState_DF
#define _DebugUpdate_LoLevelState_ARRAYSIZE ((DebugUpdate_LoLevelState)(DebugUpdate_LoLevelState_DF+1))


#ifdef __cplusplus
extern "C" {
#endif

/* Initializer values for message structs */
#define LoToHi_init_default                      {0, {StateUpdate_init_default}}
#define Event_init_default                       {_Event_InterfaceEvent_MIN}
#define SimulationFeedback_init_default          {0, 0, 0, 0, 0}
#define PowerMeter_init_default                  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define KeepAliveLo_init_default                 {0, 0, 0, 0, 0, "", 0, 0, 0, 0, 0}
#define StateUpdate_init_default                 {0, _StateUpdate_State_MIN, 0, {ErrorFlags_init_default}}
#define ErrorFlags_init_default                  {_ErrorFlags_ErrorType_MIN}
#define ChargingFlags_init_default               {0}
#define ResetDone_init_default                   {0}
#define DebugUpdate_init_default                 {0, 0, 0, 0, 0, _DebugUpdate_LoLevelState_MIN, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _InterfaceControlMode_MIN, 0, 0, 0, 0}
#define LoToHi_init_zero                         {0, {StateUpdate_init_zero}}
#define Event_init_zero                          {_Event_InterfaceEvent_MIN}
#define SimulationFeedback_init_zero             {0, 0, 0, 0, 0}
#define PowerMeter_init_zero                     {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
#define KeepAliveLo_init_zero                    {0, 0, 0, 0, 0, "", 0, 0, 0, 0, 0}
#define StateUpdate_init_zero                    {0, _StateUpdate_State_MIN, 0, {ErrorFlags_init_zero}}
#define ErrorFlags_init_zero                     {_ErrorFlags_ErrorType_MIN}
#define ChargingFlags_init_zero                  {0}
#define ResetDone_init_zero                      {0}
#define DebugUpdate_init_zero                    {0, 0, 0, 0, 0, _DebugUpdate_LoLevelState_MIN, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, _InterfaceControlMode_MIN, 0, 0, 0, 0}

/* Field tags (for use in manual encoding/decoding) */
#define ChargingFlags_ventilation_tag            1
#define DebugUpdate_time_stamp_tag               1
#define DebugUpdate_evse_pwm_voltage_hi_tag      2
#define DebugUpdate_evse_pwm_voltage_lo_tag      3
#define DebugUpdate_supply_voltage_12V_tag       4
#define DebugUpdate_supply_voltage_N12V_tag      5
#define DebugUpdate_lowlevel_state_tag           6
#define DebugUpdate_evse_pwm_running_tag         7
#define DebugUpdate_ev_simplified_mode_tag       8
#define DebugUpdate_has_ventilation_tag          9
#define DebugUpdate_ventilated_charging_active_tag 10
#define DebugUpdate_rcd_reclosing_allowed_tag    12
#define DebugUpdate_authorized_tag               15
#define DebugUpdate_cpu_temperature_tag          17
#define DebugUpdate_rcd_enabled_tag              18
#define DebugUpdate_evse_pp_voltage_tag          21
#define DebugUpdate_max_current_cable_tag        22
#define DebugUpdate_watchdog_reset_count_tag     23
#define DebugUpdate_simulation_tag               24
#define DebugUpdate_control_mode_tag             25
#define DebugUpdate_max_current_tag              26
#define DebugUpdate_use_three_phases_tag         27
#define DebugUpdate_rcd_current_tag              28
#define DebugUpdate_relais_on_tag                29
#define ErrorFlags_type_tag                      1
#define Event_type_tag                           1
#define KeepAliveLo_time_stamp_tag               1
#define KeepAliveLo_hw_type_tag                  2
#define KeepAliveLo_hw_revision_tag              3
#define KeepAliveLo_protocol_version_major_tag   4
#define KeepAliveLo_protocol_version_minor_tag   5
#define KeepAliveLo_sw_version_string_tag        6
#define KeepAliveLo_hwcap_max_current_tag        7
#define KeepAliveLo_hwcap_min_current_tag        8
#define KeepAliveLo_hwcap_max_phase_count_tag    9
#define KeepAliveLo_hwcap_min_phase_count_tag    10
#define KeepAliveLo_supports_changing_phases_during_charging_tag 11
#define PowerMeter_time_stamp_tag                1
#define PowerMeter_vrmsL1_tag                    2
#define PowerMeter_vrmsL2_tag                    3
#define PowerMeter_vrmsL3_tag                    4
#define PowerMeter_irmsL1_tag                    5
#define PowerMeter_irmsL2_tag                    6
#define PowerMeter_irmsL3_tag                    7
#define PowerMeter_irmsN_tag                     8
#define PowerMeter_wattHrL1_tag                  9
#define PowerMeter_wattHrL2_tag                  10
#define PowerMeter_wattHrL3_tag                  11
#define PowerMeter_totalWattHr_tag               12
#define PowerMeter_tempL1_tag                    13
#define PowerMeter_tempL2_tag                    14
#define PowerMeter_tempL3_tag                    15
#define PowerMeter_tempN_tag                     16
#define PowerMeter_wattL1_tag                    17
#define PowerMeter_wattL2_tag                    18
#define PowerMeter_wattL3_tag                    19
#define PowerMeter_freqL1_tag                    20
#define PowerMeter_freqL2_tag                    21
#define PowerMeter_freqL3_tag                    22
#define PowerMeter_phaseSeqError_tag             23
#define SimulationFeedback_pwmDutyCycle_tag      1
#define SimulationFeedback_evse_pwm_voltage_hi_tag 2
#define SimulationFeedback_evse_pwm_voltage_lo_tag 3
#define SimulationFeedback_evse_pwm_running_tag  4
#define SimulationFeedback_relais_on_tag         5
#define StateUpdate_time_stamp_tag               1
#define StateUpdate_state_tag                    2
#define StateUpdate_error_type_tag               3
#define StateUpdate_charging_flags_tag           4
#define LoToHi_state_update_tag                  1
#define LoToHi_debug_update_tag                  2
#define LoToHi_keep_alive_tag                    3
#define LoToHi_power_meter_tag                   4
#define LoToHi_simulation_feedback_tag           5
#define LoToHi_event_tag                         6
#define LoToHi_reset_done_tag                    7

/* Struct field encoding specification for nanopb */
#define LoToHi_FIELDLIST(X, a) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,state_update,payload.state_update),   1) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,debug_update,payload.debug_update),   2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,keep_alive,payload.keep_alive),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,power_meter,payload.power_meter),   4) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,simulation_feedback,payload.simulation_feedback),   5) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,event,payload.event),   6) \
X(a, STATIC,   ONEOF,    MESSAGE,  (payload,reset_done,payload.reset_done),   7)
#define LoToHi_CALLBACK NULL
#define LoToHi_DEFAULT NULL
#define LoToHi_payload_state_update_MSGTYPE StateUpdate
#define LoToHi_payload_debug_update_MSGTYPE DebugUpdate
#define LoToHi_payload_keep_alive_MSGTYPE KeepAliveLo
#define LoToHi_payload_power_meter_MSGTYPE PowerMeter
#define LoToHi_payload_simulation_feedback_MSGTYPE SimulationFeedback
#define LoToHi_payload_event_MSGTYPE Event
#define LoToHi_payload_reset_done_MSGTYPE ResetDone

#define Event_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    type,              1)
#define Event_CALLBACK NULL
#define Event_DEFAULT NULL

#define SimulationFeedback_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, FLOAT,    pwmDutyCycle,      1) \
X(a, STATIC,   SINGULAR, FLOAT,    evse_pwm_voltage_hi,   2) \
X(a, STATIC,   SINGULAR, FLOAT,    evse_pwm_voltage_lo,   3) \
X(a, STATIC,   SINGULAR, BOOL,     evse_pwm_running,   4) \
X(a, STATIC,   SINGULAR, UINT32,   relais_on,         5)
#define SimulationFeedback_CALLBACK NULL
#define SimulationFeedback_DEFAULT NULL

#define PowerMeter_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   time_stamp,        1) \
X(a, STATIC,   SINGULAR, FLOAT,    vrmsL1,            2) \
X(a, STATIC,   SINGULAR, FLOAT,    vrmsL2,            3) \
X(a, STATIC,   SINGULAR, FLOAT,    vrmsL3,            4) \
X(a, STATIC,   SINGULAR, FLOAT,    irmsL1,            5) \
X(a, STATIC,   SINGULAR, FLOAT,    irmsL2,            6) \
X(a, STATIC,   SINGULAR, FLOAT,    irmsL3,            7) \
X(a, STATIC,   SINGULAR, FLOAT,    irmsN,             8) \
X(a, STATIC,   SINGULAR, FLOAT,    wattHrL1,          9) \
X(a, STATIC,   SINGULAR, FLOAT,    wattHrL2,         10) \
X(a, STATIC,   SINGULAR, FLOAT,    wattHrL3,         11) \
X(a, STATIC,   SINGULAR, FLOAT,    totalWattHr,      12) \
X(a, STATIC,   SINGULAR, FLOAT,    tempL1,           13) \
X(a, STATIC,   SINGULAR, FLOAT,    tempL2,           14) \
X(a, STATIC,   SINGULAR, FLOAT,    tempL3,           15) \
X(a, STATIC,   SINGULAR, FLOAT,    tempN,            16) \
X(a, STATIC,   SINGULAR, FLOAT,    wattL1,           17) \
X(a, STATIC,   SINGULAR, FLOAT,    wattL2,           18) \
X(a, STATIC,   SINGULAR, FLOAT,    wattL3,           19) \
X(a, STATIC,   SINGULAR, FLOAT,    freqL1,           20) \
X(a, STATIC,   SINGULAR, FLOAT,    freqL2,           21) \
X(a, STATIC,   SINGULAR, FLOAT,    freqL3,           22) \
X(a, STATIC,   SINGULAR, BOOL,     phaseSeqError,    23)
#define PowerMeter_CALLBACK NULL
#define PowerMeter_DEFAULT NULL

#define KeepAliveLo_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   time_stamp,        1) \
X(a, STATIC,   SINGULAR, UINT32,   hw_type,           2) \
X(a, STATIC,   SINGULAR, UINT32,   hw_revision,       3) \
X(a, STATIC,   SINGULAR, UINT32,   protocol_version_major,   4) \
X(a, STATIC,   SINGULAR, UINT32,   protocol_version_minor,   5) \
X(a, STATIC,   SINGULAR, STRING,   sw_version_string,   6) \
X(a, STATIC,   SINGULAR, FLOAT,    hwcap_max_current,   7) \
X(a, STATIC,   SINGULAR, FLOAT,    hwcap_min_current,   8) \
X(a, STATIC,   SINGULAR, UINT32,   hwcap_max_phase_count,   9) \
X(a, STATIC,   SINGULAR, UINT32,   hwcap_min_phase_count,  10) \
X(a, STATIC,   SINGULAR, BOOL,     supports_changing_phases_during_charging,  11)
#define KeepAliveLo_CALLBACK NULL
#define KeepAliveLo_DEFAULT NULL

#define StateUpdate_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   time_stamp,        1) \
X(a, STATIC,   SINGULAR, UENUM,    state,             2) \
X(a, STATIC,   ONEOF,    MESSAGE,  (state_flags,error_type,state_flags.error_type),   3) \
X(a, STATIC,   ONEOF,    MESSAGE,  (state_flags,charging_flags,state_flags.charging_flags),   4)
#define StateUpdate_CALLBACK NULL
#define StateUpdate_DEFAULT NULL
#define StateUpdate_state_flags_error_type_MSGTYPE ErrorFlags
#define StateUpdate_state_flags_charging_flags_MSGTYPE ChargingFlags

#define ErrorFlags_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UENUM,    type,              1)
#define ErrorFlags_CALLBACK NULL
#define ErrorFlags_DEFAULT NULL

#define ChargingFlags_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, BOOL,     ventilation,       1)
#define ChargingFlags_CALLBACK NULL
#define ChargingFlags_DEFAULT NULL

#define ResetDone_FIELDLIST(X, a) \

#define ResetDone_CALLBACK NULL
#define ResetDone_DEFAULT NULL

#define DebugUpdate_FIELDLIST(X, a) \
X(a, STATIC,   SINGULAR, UINT32,   time_stamp,        1) \
X(a, STATIC,   SINGULAR, FLOAT,    evse_pwm_voltage_hi,   2) \
X(a, STATIC,   SINGULAR, FLOAT,    evse_pwm_voltage_lo,   3) \
X(a, STATIC,   SINGULAR, FLOAT,    supply_voltage_12V,   4) \
X(a, STATIC,   SINGULAR, FLOAT,    supply_voltage_N12V,   5) \
X(a, STATIC,   SINGULAR, UENUM,    lowlevel_state,    6) \
X(a, STATIC,   SINGULAR, BOOL,     evse_pwm_running,   7) \
X(a, STATIC,   SINGULAR, BOOL,     ev_simplified_mode,   8) \
X(a, STATIC,   SINGULAR, BOOL,     has_ventilation,   9) \
X(a, STATIC,   SINGULAR, BOOL,     ventilated_charging_active,  10) \
X(a, STATIC,   SINGULAR, BOOL,     rcd_reclosing_allowed,  12) \
X(a, STATIC,   SINGULAR, BOOL,     authorized,       15) \
X(a, STATIC,   SINGULAR, FLOAT,    cpu_temperature,  17) \
X(a, STATIC,   SINGULAR, BOOL,     rcd_enabled,      18) \
X(a, STATIC,   SINGULAR, FLOAT,    evse_pp_voltage,  21) \
X(a, STATIC,   SINGULAR, FLOAT,    max_current_cable,  22) \
X(a, STATIC,   SINGULAR, UINT32,   watchdog_reset_count,  23) \
X(a, STATIC,   SINGULAR, BOOL,     simulation,       24) \
X(a, STATIC,   SINGULAR, UENUM,    control_mode,     25) \
X(a, STATIC,   SINGULAR, FLOAT,    max_current,      26) \
X(a, STATIC,   SINGULAR, BOOL,     use_three_phases,  27) \
X(a, STATIC,   SINGULAR, FLOAT,    rcd_current,      28) \
X(a, STATIC,   SINGULAR, BOOL,     relais_on,        29)
#define DebugUpdate_CALLBACK NULL
#define DebugUpdate_DEFAULT NULL

extern const pb_msgdesc_t LoToHi_msg;
extern const pb_msgdesc_t Event_msg;
extern const pb_msgdesc_t SimulationFeedback_msg;
extern const pb_msgdesc_t PowerMeter_msg;
extern const pb_msgdesc_t KeepAliveLo_msg;
extern const pb_msgdesc_t StateUpdate_msg;
extern const pb_msgdesc_t ErrorFlags_msg;
extern const pb_msgdesc_t ChargingFlags_msg;
extern const pb_msgdesc_t ResetDone_msg;
extern const pb_msgdesc_t DebugUpdate_msg;

/* Defines for backwards compatibility with code written before nanopb-0.4.0 */
#define LoToHi_fields &LoToHi_msg
#define Event_fields &Event_msg
#define SimulationFeedback_fields &SimulationFeedback_msg
#define PowerMeter_fields &PowerMeter_msg
#define KeepAliveLo_fields &KeepAliveLo_msg
#define StateUpdate_fields &StateUpdate_msg
#define ErrorFlags_fields &ErrorFlags_msg
#define ChargingFlags_fields &ChargingFlags_msg
#define ResetDone_fields &ResetDone_msg
#define DebugUpdate_fields &DebugUpdate_msg

/* Maximum encoded size of messages (where known) */
#define ChargingFlags_size                       2
#define DebugUpdate_size                         92
#define ErrorFlags_size                          2
#define Event_size                               2
#define KeepAliveLo_size                         106
#define LoToHi_size                              123
#define PowerMeter_size                          121
#define ResetDone_size                           0
#define SimulationFeedback_size                  23
#define StateUpdate_size                         12

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif
