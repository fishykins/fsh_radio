//======================================================================================================//
#define ARRAY_CYCLE(_arr)     _arr pushBack (_arr deleteAt 0)

//======================================================================================================//

#define FSM(var1)                       TRIPLES(ADDON,fsm,var1)
#define QFSM(var1)                      QUOTE(FSM(var1))

//======================================================================================================//

#define RADIOVAR(var1)                  (format ["fsh_radio_%1", var1])
#define RADIOVAR_PROGRAM(var1)          (format ["fsh_radio_%1_program", var1])
#define RADIOVAR_CATS(var1)             (format ["fsh_radio_%1_categories", var1])

#define GET_RADIO_DATA(var1)            missionnameSpace getVariable [RADIOVAR(var1), []]
#define SET_RADIO_DATA(var1,var2)       missionnameSpace setVariable [RADIOVAR(var1), var2, true]; publicVariable RADIOVAR(var1)

#define GET_RADIO_PROGRAM(var1)         missionnameSpace getVariable [RADIOVAR_PROGRAM(var1), []]
#define SET_RADIO_PROGRAM(var1,var2)    missionnameSpace setVariable [RADIOVAR_PROGRAM(var1), var2, false]

#define GET_RADIO_CATS(var1)            missionnameSpace getVariable [RADIOVAR_CATS(var1), []]
#define SET_RADIO_CATS(var1,var2)       missionnameSpace setVariable [RADIOVAR_CATS(var1), var2, false]

#define GET_OBJECT_AUDIO(var1)          var1 getVariable [QGVAR(audio), []]
#define SET_OBJECT_AUDIO(var1,var2)     var1 setVariable [QGVAR(audio), var2, true]


#define DEF_AUDIO_TYPE(var1,var2)       if (isNil QGVARMAIN(audioTypes)) then {GVARMAIN(audioTypes) = [];}; GVARMAIN(audioTypes) pushBack (var1,var2)

#define PVEH                         (vehicle player)
#define PVEH_SV(var1,var2)           PVEH setVariable [var1, var2, true]
#define PVEH_GV(var1,var2)           PVEH getVariable [var1, var2]
#define PVEH_AUDIODATA               PVEH_GV(QGVARMAIN(audioData), [])
#define PVEH_SET_AUDIODATA(var1)     PVEH_SV(QGVARMAIN(audioData), var1)
    
//======================================================================================================//
//======================================================================================================//

#define DEFAULT_SONG_LENTGH 300


