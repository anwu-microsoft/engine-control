/*
 * engineclosed.h
 *
 * Code generation for model "engineclosed".
 *
 * Model version              : 1.132
 * Simulink Coder version : 9.0 (R2018b) 24-May-2018
 * C source code generated on : Thu Jun  6 13:30:26 2019
 *
 * Target selection: grt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: 32-bit Generic
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#ifndef RTW_HEADER_engineclosed_h_
#define RTW_HEADER_engineclosed_h_
#include <stddef.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#ifndef engineclosed_COMMON_INCLUDES_
# define engineclosed_COMMON_INCLUDES_
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "rtwtypes.h"
#include "zero_crossing_types.h"
#include "simstruc.h"
#include "fixedpoint.h"
#include "rt_logging.h"
#endif                                 /* engineclosed_COMMON_INCLUDES_ */

#include "engineclosed_types.h"

/* Shared type includes */
#include "multiword_types.h"
#include "rt_zcfcn.h"
#include "rtGetNaN.h"
#include "rt_nonfinite.h"
#include "rt_defines.h"

/* Macros for accessing real-time model data structure */
#ifndef rtmGetBlockIO
# define rtmGetBlockIO(rtm)            ((rtm)->blockIO)
#endif

#ifndef rtmSetBlockIO
# define rtmSetBlockIO(rtm, val)       ((rtm)->blockIO = (val))
#endif

#ifndef rtmGetChecksums
# define rtmGetChecksums(rtm)          ((rtm)->Sizes.checksums)
#endif

#ifndef rtmSetChecksums
# define rtmSetChecksums(rtm, val)     ((rtm)->Sizes.checksums = (val))
#endif

#ifndef rtmGetConstBlockIO
# define rtmGetConstBlockIO(rtm)       ((rtm)->constBlockIO)
#endif

#ifndef rtmSetConstBlockIO
# define rtmSetConstBlockIO(rtm, val)  ((rtm)->constBlockIO = (val))
#endif

#ifndef rtmGetContStateDisabled
# define rtmGetContStateDisabled(rtm)  ((rtm)->contStateDisabled)
#endif

#ifndef rtmSetContStateDisabled
# define rtmSetContStateDisabled(rtm, val) ((rtm)->contStateDisabled = (val))
#endif

#ifndef rtmGetContStates
# define rtmGetContStates(rtm)         ((rtm)->contStates)
#endif

#ifndef rtmSetContStates
# define rtmSetContStates(rtm, val)    ((rtm)->contStates = (val))
#endif

#ifndef rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmGetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm) ((rtm)->CTOutputIncnstWithState)
#endif

#ifndef rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag
# define rtmSetContTimeOutputInconsistentWithStateAtMajorStepFlag(rtm, val) ((rtm)->CTOutputIncnstWithState = (val))
#endif

#ifndef rtmGetCtrlRateMdlRefTiming
# define rtmGetCtrlRateMdlRefTiming(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTiming
# define rtmSetCtrlRateMdlRefTiming(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateMdlRefTimingPtr
# define rtmGetCtrlRateMdlRefTimingPtr(rtm) ()
#endif

#ifndef rtmSetCtrlRateMdlRefTimingPtr
# define rtmSetCtrlRateMdlRefTimingPtr(rtm, val) ()
#endif

#ifndef rtmGetCtrlRateNumTicksToNextHit
# define rtmGetCtrlRateNumTicksToNextHit(rtm) ()
#endif

#ifndef rtmSetCtrlRateNumTicksToNextHit
# define rtmSetCtrlRateNumTicksToNextHit(rtm, val) ()
#endif

#ifndef rtmGetDataMapInfo
# define rtmGetDataMapInfo(rtm)        ()
#endif

#ifndef rtmSetDataMapInfo
# define rtmSetDataMapInfo(rtm, val)   ()
#endif

#ifndef rtmGetDefaultParam
# define rtmGetDefaultParam(rtm)       ((rtm)->defaultParam)
#endif

#ifndef rtmSetDefaultParam
# define rtmSetDefaultParam(rtm, val)  ((rtm)->defaultParam = (val))
#endif

#ifndef rtmGetDerivCacheNeedsReset
# define rtmGetDerivCacheNeedsReset(rtm) ((rtm)->derivCacheNeedsReset)
#endif

#ifndef rtmSetDerivCacheNeedsReset
# define rtmSetDerivCacheNeedsReset(rtm, val) ((rtm)->derivCacheNeedsReset = (val))
#endif

#ifndef rtmGetDirectFeedThrough
# define rtmGetDirectFeedThrough(rtm)  ((rtm)->Sizes.sysDirFeedThru)
#endif

#ifndef rtmSetDirectFeedThrough
# define rtmSetDirectFeedThrough(rtm, val) ((rtm)->Sizes.sysDirFeedThru = (val))
#endif

#ifndef rtmGetErrorStatusFlag
# define rtmGetErrorStatusFlag(rtm)    ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatusFlag
# define rtmSetErrorStatusFlag(rtm, val) ((rtm)->errorStatus = (val))
#endif

#ifndef rtmGetFinalTime
# define rtmGetFinalTime(rtm)          ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetFinalTime
# define rtmSetFinalTime(rtm, val)     ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetFirstInitCondFlag
# define rtmGetFirstInitCondFlag(rtm)  ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmSetFirstInitCondFlag
# define rtmSetFirstInitCondFlag(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmGetIntgData
# define rtmGetIntgData(rtm)           ((rtm)->intgData)
#endif

#ifndef rtmSetIntgData
# define rtmSetIntgData(rtm, val)      ((rtm)->intgData = (val))
#endif

#ifndef rtmGetMdlRefGlobalTID
# define rtmGetMdlRefGlobalTID(rtm)    ()
#endif

#ifndef rtmSetMdlRefGlobalTID
# define rtmSetMdlRefGlobalTID(rtm, val) ()
#endif

#ifndef rtmGetMdlRefTriggerTID
# define rtmGetMdlRefTriggerTID(rtm)   ()
#endif

#ifndef rtmSetMdlRefTriggerTID
# define rtmSetMdlRefTriggerTID(rtm, val) ()
#endif

#ifndef rtmGetModelMappingInfo
# define rtmGetModelMappingInfo(rtm)   ((rtm)->SpecialInfo.mappingInfo)
#endif

#ifndef rtmSetModelMappingInfo
# define rtmSetModelMappingInfo(rtm, val) ((rtm)->SpecialInfo.mappingInfo = (val))
#endif

#ifndef rtmGetModelName
# define rtmGetModelName(rtm)          ((rtm)->modelName)
#endif

#ifndef rtmSetModelName
# define rtmSetModelName(rtm, val)     ((rtm)->modelName = (val))
#endif

#ifndef rtmGetNonInlinedSFcns
# define rtmGetNonInlinedSFcns(rtm)    ()
#endif

#ifndef rtmSetNonInlinedSFcns
# define rtmSetNonInlinedSFcns(rtm, val) ()
#endif

#ifndef rtmGetNumBlockIO
# define rtmGetNumBlockIO(rtm)         ((rtm)->Sizes.numBlockIO)
#endif

#ifndef rtmSetNumBlockIO
# define rtmSetNumBlockIO(rtm, val)    ((rtm)->Sizes.numBlockIO = (val))
#endif

#ifndef rtmGetNumBlockParams
# define rtmGetNumBlockParams(rtm)     ((rtm)->Sizes.numBlockPrms)
#endif

#ifndef rtmSetNumBlockParams
# define rtmSetNumBlockParams(rtm, val) ((rtm)->Sizes.numBlockPrms = (val))
#endif

#ifndef rtmGetNumBlocks
# define rtmGetNumBlocks(rtm)          ((rtm)->Sizes.numBlocks)
#endif

#ifndef rtmSetNumBlocks
# define rtmSetNumBlocks(rtm, val)     ((rtm)->Sizes.numBlocks = (val))
#endif

#ifndef rtmGetNumContStates
# define rtmGetNumContStates(rtm)      ((rtm)->Sizes.numContStates)
#endif

#ifndef rtmSetNumContStates
# define rtmSetNumContStates(rtm, val) ((rtm)->Sizes.numContStates = (val))
#endif

#ifndef rtmGetNumDWork
# define rtmGetNumDWork(rtm)           ((rtm)->Sizes.numDwork)
#endif

#ifndef rtmSetNumDWork
# define rtmSetNumDWork(rtm, val)      ((rtm)->Sizes.numDwork = (val))
#endif

#ifndef rtmGetNumInputPorts
# define rtmGetNumInputPorts(rtm)      ((rtm)->Sizes.numIports)
#endif

#ifndef rtmSetNumInputPorts
# define rtmSetNumInputPorts(rtm, val) ((rtm)->Sizes.numIports = (val))
#endif

#ifndef rtmGetNumNonSampledZCs
# define rtmGetNumNonSampledZCs(rtm)   ((rtm)->Sizes.numNonSampZCs)
#endif

#ifndef rtmSetNumNonSampledZCs
# define rtmSetNumNonSampledZCs(rtm, val) ((rtm)->Sizes.numNonSampZCs = (val))
#endif

#ifndef rtmGetNumOutputPorts
# define rtmGetNumOutputPorts(rtm)     ((rtm)->Sizes.numOports)
#endif

#ifndef rtmSetNumOutputPorts
# define rtmSetNumOutputPorts(rtm, val) ((rtm)->Sizes.numOports = (val))
#endif

#ifndef rtmGetNumPeriodicContStates
# define rtmGetNumPeriodicContStates(rtm) ((rtm)->Sizes.numPeriodicContStates)
#endif

#ifndef rtmSetNumPeriodicContStates
# define rtmSetNumPeriodicContStates(rtm, val) ((rtm)->Sizes.numPeriodicContStates = (val))
#endif

#ifndef rtmGetNumSFcnParams
# define rtmGetNumSFcnParams(rtm)      ((rtm)->Sizes.numSFcnPrms)
#endif

#ifndef rtmSetNumSFcnParams
# define rtmSetNumSFcnParams(rtm, val) ((rtm)->Sizes.numSFcnPrms = (val))
#endif

#ifndef rtmGetNumSFunctions
# define rtmGetNumSFunctions(rtm)      ((rtm)->Sizes.numSFcns)
#endif

#ifndef rtmSetNumSFunctions
# define rtmSetNumSFunctions(rtm, val) ((rtm)->Sizes.numSFcns = (val))
#endif

#ifndef rtmGetNumSampleTimes
# define rtmGetNumSampleTimes(rtm)     ((rtm)->Sizes.numSampTimes)
#endif

#ifndef rtmSetNumSampleTimes
# define rtmSetNumSampleTimes(rtm, val) ((rtm)->Sizes.numSampTimes = (val))
#endif

#ifndef rtmGetNumU
# define rtmGetNumU(rtm)               ((rtm)->Sizes.numU)
#endif

#ifndef rtmSetNumU
# define rtmSetNumU(rtm, val)          ((rtm)->Sizes.numU = (val))
#endif

#ifndef rtmGetNumY
# define rtmGetNumY(rtm)               ((rtm)->Sizes.numY)
#endif

#ifndef rtmSetNumY
# define rtmSetNumY(rtm, val)          ((rtm)->Sizes.numY = (val))
#endif

#ifndef rtmGetOdeF
# define rtmGetOdeF(rtm)               ((rtm)->odeF)
#endif

#ifndef rtmSetOdeF
# define rtmSetOdeF(rtm, val)          ((rtm)->odeF = (val))
#endif

#ifndef rtmGetOdeY
# define rtmGetOdeY(rtm)               ()
#endif

#ifndef rtmSetOdeY
# define rtmSetOdeY(rtm, val)          ()
#endif

#ifndef rtmGetOffsetTimeArray
# define rtmGetOffsetTimeArray(rtm)    ((rtm)->Timing.offsetTimesArray)
#endif

#ifndef rtmSetOffsetTimeArray
# define rtmSetOffsetTimeArray(rtm, val) ((rtm)->Timing.offsetTimesArray = (val))
#endif

#ifndef rtmGetOffsetTimePtr
# define rtmGetOffsetTimePtr(rtm)      ((rtm)->Timing.offsetTimes)
#endif

#ifndef rtmSetOffsetTimePtr
# define rtmSetOffsetTimePtr(rtm, val) ((rtm)->Timing.offsetTimes = (val))
#endif

#ifndef rtmGetOptions
# define rtmGetOptions(rtm)            ((rtm)->Sizes.options)
#endif

#ifndef rtmSetOptions
# define rtmSetOptions(rtm, val)       ((rtm)->Sizes.options = (val))
#endif

#ifndef rtmGetParamIsMalloced
# define rtmGetParamIsMalloced(rtm)    ()
#endif

#ifndef rtmSetParamIsMalloced
# define rtmSetParamIsMalloced(rtm, val) ()
#endif

#ifndef rtmGetPath
# define rtmGetPath(rtm)               ((rtm)->path)
#endif

#ifndef rtmSetPath
# define rtmSetPath(rtm, val)          ((rtm)->path = (val))
#endif

#ifndef rtmGetPerTaskSampleHits
# define rtmGetPerTaskSampleHits(rtm)  ()
#endif

#ifndef rtmSetPerTaskSampleHits
# define rtmSetPerTaskSampleHits(rtm, val) ()
#endif

#ifndef rtmGetPerTaskSampleHitsArray
# define rtmGetPerTaskSampleHitsArray(rtm) ((rtm)->Timing.perTaskSampleHitsArray)
#endif

#ifndef rtmSetPerTaskSampleHitsArray
# define rtmSetPerTaskSampleHitsArray(rtm, val) ((rtm)->Timing.perTaskSampleHitsArray = (val))
#endif

#ifndef rtmGetPerTaskSampleHitsPtr
# define rtmGetPerTaskSampleHitsPtr(rtm) ((rtm)->Timing.perTaskSampleHits)
#endif

#ifndef rtmSetPerTaskSampleHitsPtr
# define rtmSetPerTaskSampleHitsPtr(rtm, val) ((rtm)->Timing.perTaskSampleHits = (val))
#endif

#ifndef rtmGetPeriodicContStateIndices
# define rtmGetPeriodicContStateIndices(rtm) ((rtm)->periodicContStateIndices)
#endif

#ifndef rtmSetPeriodicContStateIndices
# define rtmSetPeriodicContStateIndices(rtm, val) ((rtm)->periodicContStateIndices = (val))
#endif

#ifndef rtmGetPeriodicContStateRanges
# define rtmGetPeriodicContStateRanges(rtm) ((rtm)->periodicContStateRanges)
#endif

#ifndef rtmSetPeriodicContStateRanges
# define rtmSetPeriodicContStateRanges(rtm, val) ((rtm)->periodicContStateRanges = (val))
#endif

#ifndef rtmGetPrevZCSigState
# define rtmGetPrevZCSigState(rtm)     ((rtm)->prevZCSigState)
#endif

#ifndef rtmSetPrevZCSigState
# define rtmSetPrevZCSigState(rtm, val) ((rtm)->prevZCSigState = (val))
#endif

#ifndef rtmGetRTWExtModeInfo
# define rtmGetRTWExtModeInfo(rtm)     ((rtm)->extModeInfo)
#endif

#ifndef rtmSetRTWExtModeInfo
# define rtmSetRTWExtModeInfo(rtm, val) ((rtm)->extModeInfo = (val))
#endif

#ifndef rtmGetRTWGeneratedSFcn
# define rtmGetRTWGeneratedSFcn(rtm)   ((rtm)->Sizes.rtwGenSfcn)
#endif

#ifndef rtmSetRTWGeneratedSFcn
# define rtmSetRTWGeneratedSFcn(rtm, val) ((rtm)->Sizes.rtwGenSfcn = (val))
#endif

#ifndef rtmGetRTWLogInfo
# define rtmGetRTWLogInfo(rtm)         ((rtm)->rtwLogInfo)
#endif

#ifndef rtmSetRTWLogInfo
# define rtmSetRTWLogInfo(rtm, val)    ((rtm)->rtwLogInfo = (val))
#endif

#ifndef rtmGetRTWRTModelMethodsInfo
# define rtmGetRTWRTModelMethodsInfo(rtm) ()
#endif

#ifndef rtmSetRTWRTModelMethodsInfo
# define rtmSetRTWRTModelMethodsInfo(rtm, val) ()
#endif

#ifndef rtmGetRTWSfcnInfo
# define rtmGetRTWSfcnInfo(rtm)        ((rtm)->sfcnInfo)
#endif

#ifndef rtmSetRTWSfcnInfo
# define rtmSetRTWSfcnInfo(rtm, val)   ((rtm)->sfcnInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfo
# define rtmGetRTWSolverInfo(rtm)      ((rtm)->solverInfo)
#endif

#ifndef rtmSetRTWSolverInfo
# define rtmSetRTWSolverInfo(rtm, val) ((rtm)->solverInfo = (val))
#endif

#ifndef rtmGetRTWSolverInfoPtr
# define rtmGetRTWSolverInfoPtr(rtm)   ((rtm)->solverInfoPtr)
#endif

#ifndef rtmSetRTWSolverInfoPtr
# define rtmSetRTWSolverInfoPtr(rtm, val) ((rtm)->solverInfoPtr = (val))
#endif

#ifndef rtmGetReservedForXPC
# define rtmGetReservedForXPC(rtm)     ((rtm)->SpecialInfo.xpcData)
#endif

#ifndef rtmSetReservedForXPC
# define rtmSetReservedForXPC(rtm, val) ((rtm)->SpecialInfo.xpcData = (val))
#endif

#ifndef rtmGetRootDWork
# define rtmGetRootDWork(rtm)          ((rtm)->dwork)
#endif

#ifndef rtmSetRootDWork
# define rtmSetRootDWork(rtm, val)     ((rtm)->dwork = (val))
#endif

#ifndef rtmGetSFunctions
# define rtmGetSFunctions(rtm)         ((rtm)->childSfunctions)
#endif

#ifndef rtmSetSFunctions
# define rtmSetSFunctions(rtm, val)    ((rtm)->childSfunctions = (val))
#endif

#ifndef rtmGetSampleHitArray
# define rtmGetSampleHitArray(rtm)     ((rtm)->Timing.sampleHitArray)
#endif

#ifndef rtmSetSampleHitArray
# define rtmSetSampleHitArray(rtm, val) ((rtm)->Timing.sampleHitArray = (val))
#endif

#ifndef rtmGetSampleHitPtr
# define rtmGetSampleHitPtr(rtm)       ((rtm)->Timing.sampleHits)
#endif

#ifndef rtmSetSampleHitPtr
# define rtmSetSampleHitPtr(rtm, val)  ((rtm)->Timing.sampleHits = (val))
#endif

#ifndef rtmGetSampleTimeArray
# define rtmGetSampleTimeArray(rtm)    ((rtm)->Timing.sampleTimesArray)
#endif

#ifndef rtmSetSampleTimeArray
# define rtmSetSampleTimeArray(rtm, val) ((rtm)->Timing.sampleTimesArray = (val))
#endif

#ifndef rtmGetSampleTimePtr
# define rtmGetSampleTimePtr(rtm)      ((rtm)->Timing.sampleTimes)
#endif

#ifndef rtmSetSampleTimePtr
# define rtmSetSampleTimePtr(rtm, val) ((rtm)->Timing.sampleTimes = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDArray
# define rtmGetSampleTimeTaskIDArray(rtm) ((rtm)->Timing.sampleTimeTaskIDArray)
#endif

#ifndef rtmSetSampleTimeTaskIDArray
# define rtmSetSampleTimeTaskIDArray(rtm, val) ((rtm)->Timing.sampleTimeTaskIDArray = (val))
#endif

#ifndef rtmGetSampleTimeTaskIDPtr
# define rtmGetSampleTimeTaskIDPtr(rtm) ((rtm)->Timing.sampleTimeTaskIDPtr)
#endif

#ifndef rtmSetSampleTimeTaskIDPtr
# define rtmSetSampleTimeTaskIDPtr(rtm, val) ((rtm)->Timing.sampleTimeTaskIDPtr = (val))
#endif

#ifndef rtmGetSelf
# define rtmGetSelf(rtm)               ()
#endif

#ifndef rtmSetSelf
# define rtmSetSelf(rtm, val)          ()
#endif

#ifndef rtmGetSimMode
# define rtmGetSimMode(rtm)            ((rtm)->simMode)
#endif

#ifndef rtmSetSimMode
# define rtmSetSimMode(rtm, val)       ((rtm)->simMode = (val))
#endif

#ifndef rtmGetSimTimeStep
# define rtmGetSimTimeStep(rtm)        ((rtm)->Timing.simTimeStep)
#endif

#ifndef rtmSetSimTimeStep
# define rtmSetSimTimeStep(rtm, val)   ((rtm)->Timing.simTimeStep = (val))
#endif

#ifndef rtmGetStartTime
# define rtmGetStartTime(rtm)          ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetStartTime
# define rtmSetStartTime(rtm, val)     ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetStepSize
# define rtmGetStepSize(rtm)           ((rtm)->Timing.stepSize)
#endif

#ifndef rtmSetStepSize
# define rtmSetStepSize(rtm, val)      ((rtm)->Timing.stepSize = (val))
#endif

#ifndef rtmGetStopRequestedFlag
# define rtmGetStopRequestedFlag(rtm)  ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequestedFlag
# define rtmSetStopRequestedFlag(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetTaskCounters
# define rtmGetTaskCounters(rtm)       ()
#endif

#ifndef rtmSetTaskCounters
# define rtmSetTaskCounters(rtm, val)  ()
#endif

#ifndef rtmGetTaskTimeArray
# define rtmGetTaskTimeArray(rtm)      ((rtm)->Timing.tArray)
#endif

#ifndef rtmSetTaskTimeArray
# define rtmSetTaskTimeArray(rtm, val) ((rtm)->Timing.tArray = (val))
#endif

#ifndef rtmGetTimePtr
# define rtmGetTimePtr(rtm)            ((rtm)->Timing.t)
#endif

#ifndef rtmSetTimePtr
# define rtmSetTimePtr(rtm, val)       ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTimingData
# define rtmGetTimingData(rtm)         ((rtm)->Timing.timingData)
#endif

#ifndef rtmSetTimingData
# define rtmSetTimingData(rtm, val)    ((rtm)->Timing.timingData = (val))
#endif

#ifndef rtmGetU
# define rtmGetU(rtm)                  ((rtm)->inputs)
#endif

#ifndef rtmSetU
# define rtmSetU(rtm, val)             ((rtm)->inputs = (val))
#endif

#ifndef rtmGetVarNextHitTimesListPtr
# define rtmGetVarNextHitTimesListPtr(rtm) ((rtm)->Timing.varNextHitTimesList)
#endif

#ifndef rtmSetVarNextHitTimesListPtr
# define rtmSetVarNextHitTimesListPtr(rtm, val) ((rtm)->Timing.varNextHitTimesList = (val))
#endif

#ifndef rtmGetY
# define rtmGetY(rtm)                  ((rtm)->outputs)
#endif

#ifndef rtmSetY
# define rtmSetY(rtm, val)             ((rtm)->outputs = (val))
#endif

#ifndef rtmGetZCCacheNeedsReset
# define rtmGetZCCacheNeedsReset(rtm)  ((rtm)->zCCacheNeedsReset)
#endif

#ifndef rtmSetZCCacheNeedsReset
# define rtmSetZCCacheNeedsReset(rtm, val) ((rtm)->zCCacheNeedsReset = (val))
#endif

#ifndef rtmGetZCSignalValues
# define rtmGetZCSignalValues(rtm)     ((rtm)->zcSignalValues)
#endif

#ifndef rtmSetZCSignalValues
# define rtmSetZCSignalValues(rtm, val) ((rtm)->zcSignalValues = (val))
#endif

#ifndef rtmGet_TimeOfLastOutput
# define rtmGet_TimeOfLastOutput(rtm)  ((rtm)->Timing.timeOfLastOutput)
#endif

#ifndef rtmSet_TimeOfLastOutput
# define rtmSet_TimeOfLastOutput(rtm, val) ((rtm)->Timing.timeOfLastOutput = (val))
#endif

#ifndef rtmGetdX
# define rtmGetdX(rtm)                 ((rtm)->derivs)
#endif

#ifndef rtmSetdX
# define rtmSetdX(rtm, val)            ((rtm)->derivs = (val))
#endif

#ifndef rtmGettimingBridge
# define rtmGettimingBridge(rtm)       ()
#endif

#ifndef rtmSettimingBridge
# define rtmSettimingBridge(rtm, val)  ()
#endif

#ifndef rtmGetChecksumVal
# define rtmGetChecksumVal(rtm, idx)   ((rtm)->Sizes.checksums[idx])
#endif

#ifndef rtmSetChecksumVal
# define rtmSetChecksumVal(rtm, idx, val) ((rtm)->Sizes.checksums[idx] = (val))
#endif

#ifndef rtmGetDWork
# define rtmGetDWork(rtm, idx)         ((rtm)->dwork[idx])
#endif

#ifndef rtmSetDWork
# define rtmSetDWork(rtm, idx, val)    ((rtm)->dwork[idx] = (val))
#endif

#ifndef rtmGetOffsetTime
# define rtmGetOffsetTime(rtm, idx)    ((rtm)->Timing.offsetTimes[idx])
#endif

#ifndef rtmSetOffsetTime
# define rtmSetOffsetTime(rtm, idx, val) ((rtm)->Timing.offsetTimes[idx] = (val))
#endif

#ifndef rtmGetSFunction
# define rtmGetSFunction(rtm, idx)     ((rtm)->childSfunctions[idx])
#endif

#ifndef rtmSetSFunction
# define rtmSetSFunction(rtm, idx, val) ((rtm)->childSfunctions[idx] = (val))
#endif

#ifndef rtmGetSampleTime
# define rtmGetSampleTime(rtm, idx)    ((rtm)->Timing.sampleTimes[idx])
#endif

#ifndef rtmSetSampleTime
# define rtmSetSampleTime(rtm, idx, val) ((rtm)->Timing.sampleTimes[idx] = (val))
#endif

#ifndef rtmGetSampleTimeTaskID
# define rtmGetSampleTimeTaskID(rtm, idx) ((rtm)->Timing.sampleTimeTaskIDPtr[idx])
#endif

#ifndef rtmSetSampleTimeTaskID
# define rtmSetSampleTimeTaskID(rtm, idx, val) ((rtm)->Timing.sampleTimeTaskIDPtr[idx] = (val))
#endif

#ifndef rtmGetVarNextHitTimeList
# define rtmGetVarNextHitTimeList(rtm, idx) ((rtm)->Timing.varNextHitTimesList[idx])
#endif

#ifndef rtmSetVarNextHitTimeList
# define rtmSetVarNextHitTimeList(rtm, idx, val) ((rtm)->Timing.varNextHitTimesList[idx] = (val))
#endif

#ifndef rtmIsContinuousTask
# define rtmIsContinuousTask(rtm, tid) ((tid) == 0)
#endif

#ifndef rtmGetErrorStatus
# define rtmGetErrorStatus(rtm)        ((rtm)->errorStatus)
#endif

#ifndef rtmSetErrorStatus
# define rtmSetErrorStatus(rtm, val)   ((rtm)->errorStatus = (val))
#endif

#ifndef rtmSetFirstInitCond
# define rtmSetFirstInitCond(rtm, val) ((rtm)->Timing.firstInitCondFlag = (val))
#endif

#ifndef rtmIsFirstInitCond
# define rtmIsFirstInitCond(rtm)       ((rtm)->Timing.firstInitCondFlag)
#endif

#ifndef rtmIsMajorTimeStep
# define rtmIsMajorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MAJOR_TIME_STEP)
#endif

#ifndef rtmIsMinorTimeStep
# define rtmIsMinorTimeStep(rtm)       (((rtm)->Timing.simTimeStep) == MINOR_TIME_STEP)
#endif

#ifndef rtmIsSampleHit
# define rtmIsSampleHit(rtm, sti, tid) ((rtmIsMajorTimeStep((rtm)) && (rtm)->Timing.sampleHits[(rtm)->Timing.sampleTimeTaskIDPtr[sti]]))
#endif

#ifndef rtmGetStopRequested
# define rtmGetStopRequested(rtm)      ((rtm)->Timing.stopRequestedFlag)
#endif

#ifndef rtmSetStopRequested
# define rtmSetStopRequested(rtm, val) ((rtm)->Timing.stopRequestedFlag = (val))
#endif

#ifndef rtmGetStopRequestedPtr
# define rtmGetStopRequestedPtr(rtm)   (&((rtm)->Timing.stopRequestedFlag))
#endif

#ifndef rtmGetT
# define rtmGetT(rtm)                  (rtmGetTPtr((rtm))[0])
#endif

#ifndef rtmSetT
# define rtmSetT(rtm, val)                                       /* Do Nothing */
#endif

#ifndef rtmGetTFinal
# define rtmGetTFinal(rtm)             ((rtm)->Timing.tFinal)
#endif

#ifndef rtmSetTFinal
# define rtmSetTFinal(rtm, val)        ((rtm)->Timing.tFinal = (val))
#endif

#ifndef rtmGetTPtr
# define rtmGetTPtr(rtm)               ((rtm)->Timing.t)
#endif

#ifndef rtmSetTPtr
# define rtmSetTPtr(rtm, val)          ((rtm)->Timing.t = (val))
#endif

#ifndef rtmGetTStart
# define rtmGetTStart(rtm)             ((rtm)->Timing.tStart)
#endif

#ifndef rtmSetTStart
# define rtmSetTStart(rtm, val)        ((rtm)->Timing.tStart = (val))
#endif

#ifndef rtmGetTaskTime
# define rtmGetTaskTime(rtm, sti)      (rtmGetTPtr((rtm))[(rtm)->Timing.sampleTimeTaskIDPtr[sti]])
#endif

#ifndef rtmSetTaskTime
# define rtmSetTaskTime(rtm, sti, val) (rtmGetTPtr((rtm))[sti] = (val))
#endif

#ifndef rtmGetTimeOfLastOutput
# define rtmGetTimeOfLastOutput(rtm)   ((rtm)->Timing.timeOfLastOutput)
#endif

#ifdef rtmGetRTWSolverInfo
#undef rtmGetRTWSolverInfo
#endif

#define rtmGetRTWSolverInfo(rtm)       &((rtm)->solverInfo)

/* Definition for use in the target main file */
#define engineclosed_rtModel           RT_MODEL_engineclosed_T

/* Block signals (default storage) */
typedef struct {
  real_T wTJw0209rads;                 /* '<S4>/w = T//J w0 = 209 rad//s' */
  real_T EngineSpeed;                  /* '<Root>/rad//s to rpm' */
  real_T Step;                         /* '<S6>/Step' */
  real_T Step1;                        /* '<S6>/Step1' */
  real_T LoadTorque;                   /* '<S6>/Sum1' */
  real_T SpeedSetpoint;                /* '<Root>/Speed Setpoint' */
  real_T SimulationInputs[2];
  real_T StoichiometricFuel;           /* '<S1>/Stoichiometric Fuel' */
  real_T TorqueGen;                    /* '<S1>/Torque Gen' */
  real_T TorqueGen2;                   /* '<S1>/Torque Gen2' */
  real_T Sum;                          /* '<S1>/Sum' */
  real_T Sum_k;                        /* '<S4>/Sum' */
  real_T InverseInertia1J;             /* '<S4>/Inverse Inertia, 1//J' */
  real_T Product;                      /* '<S4>/Product' */
  real_T Add;                          /* '<S4>/Add' */
  real_T utheta90;                     /* '<S5>/0 <= theta <= 90' */
  real_T Intake;                       /* '<S5>/Intake' */
  real_T p00543bar;                    /* '<S107>/p0 = 0.543 bar' */
  real_T Pumping;                      /* '<S107>/Pumping' */
  real_T ftheta;                       /* '<S108>/f(theta)' */
  real_T Product1;                     /* '<S108>/Product1' */
  real_T Product2;                     /* '<S108>/Product2' */
  real_T pratio;                       /* '<S108>/MinMax' */
  real_T Switch;                       /* '<S108>/Switch' */
  real_T Sum_a;                        /* '<S108>/Sum' */
  real_T flowdirection;                /* '<S108>/flow direction' */
  real_T Product_c;                    /* '<S108>/Product' */
  real_T Sum_h;                        /* '<S107>/Sum' */
  real_T RTVm;                         /* '<S107>/RT//Vm' */
  real_T GetCrankAngleIC0;             /* '<S109>/Get Crank Angle IC 0' */
  real_T Clock;                        /* '<Root>/Clock' */
  real_T UnitDelay;                    /* '<S110>/Unit Delay' */
  real_T Gain;                         /* '<S110>/Gain' */
  real_T gpratio;                      /* '<S108>/g(pratio)' */
  real_T dJ;                           /* '<S4>/MATLAB Function' */
  real_T rpmtorads;                    /* '<S3>/rpm to rad//s' */
  real_T Sum_n;                        /* '<S3>/Sum' */
  real_T PProdOut;                     /* '<S80>/PProd Out' */
  real_T Integrator;                   /* '<S64>/Integrator' */
  real_T Sum_f;                        /* '<S93>/Sum' */
  real_T ZeroGain;                     /* '<S37>/ZeroGain' */
  real_T DeadZone;                     /* '<S37>/DeadZone' */
  real_T SignPreSat;                   /* '<S37>/SignPreSat' */
  real_T IProdOut;                     /* '<S53>/IProd Out' */
  real_T SignPreIntegrator;            /* '<S37>/SignPreIntegrator' */
  real_T Switch_k;                     /* '<S37>/Switch' */
  real_T ThrottleAngle;                /* '<S85>/Saturation' */
  real_T kp;                           /* '<S3>/MATLAB Function' */
  real_T ki;                           /* '<S3>/MATLAB Function' */
  real_T Init;                         /* '<S2>/Init' */
  real_T UnitDelay_e;                  /* '<S2>/Unit Delay' */
  real_T Trigger;                      /* '<S2>/Trigger' */
  int8_T DataTypeConv1;                /* '<S37>/DataTypeConv1' */
  int8_T DataTypeConv2;                /* '<S37>/DataTypeConv2' */
  boolean_T RelationalOperator;        /* '<S109>/Relational Operator' */
  boolean_T NotEqual;                  /* '<S37>/NotEqual' */
  boolean_T Equal1;                    /* '<S37>/Equal1' */
  boolean_T AND3;                      /* '<S37>/AND3' */
} B_engineclosed_T;

/* Block states (default storage) for system '<Root>' */
typedef struct {
  real_T UnitDelay_DSTATE;             /* '<S110>/Unit Delay' */
  real_T Integrator_DSTATE;            /* '<S64>/Integrator' */
  real_T UnitDelay_DSTATE_g;           /* '<S2>/Unit Delay' */
  struct {
    void *LoggedData;
  } EngineSpeed_PWORK;                 /* '<Root>/EngineSpeed' */

  struct {
    void *LoggedData;
  } SimulationInputs_PWORK;            /* '<Root>/SimulationInputs' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK;                     /* '<Root>/To File1' */

  struct {
    void *LoggedData;
  } ToWorkspace2_PWORK;                /* '<Root>/To Workspace2' */

  struct {
    void *FilePtr;
  } ToFile1_PWORK_f;                   /* '<S3>/To File1' */

  uint32_T Controller_ELAPS_T[2];      /* '<Root>/Controller' */
  uint32_T Controller_PREV_T[2];       /* '<Root>/Controller' */
  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK;                     /* '<Root>/To File1' */

  struct {
    int_T Count;
    int_T Decimation;
  } ToFile1_IWORK_m;                   /* '<S3>/To File1' */

  boolean_T Init_FirstOutputTime;      /* '<S2>/Init' */
  FILE * eml_openfiles[20];            /* '<S3>/MATLAB Function' */
  FILE * eml_openfiles_a[20];          /* '<S4>/MATLAB Function' */
} DW_engineclosed_T;

/* Continuous states (default storage) */
typedef struct {
  real_T wTJw0209rads_CSTATE;          /* '<S4>/w = T//J w0 = 209 rad//s' */
  real_T Intake_CSTATE;                /* '<S5>/Intake' */
  real_T p00543bar_CSTATE;             /* '<S107>/p0 = 0.543 bar' */
  real_T GetCrankAngleIC0_CSTATE;      /* '<S109>/Get Crank Angle IC 0' */
} X_engineclosed_T;

/* State derivatives (default storage) */
typedef struct {
  real_T wTJw0209rads_CSTATE;          /* '<S4>/w = T//J w0 = 209 rad//s' */
  real_T Intake_CSTATE;                /* '<S5>/Intake' */
  real_T p00543bar_CSTATE;             /* '<S107>/p0 = 0.543 bar' */
  real_T GetCrankAngleIC0_CSTATE;      /* '<S109>/Get Crank Angle IC 0' */
} XDot_engineclosed_T;

/* State disabled  */
typedef struct {
  boolean_T wTJw0209rads_CSTATE;       /* '<S4>/w = T//J w0 = 209 rad//s' */
  boolean_T Intake_CSTATE;             /* '<S5>/Intake' */
  boolean_T p00543bar_CSTATE;          /* '<S107>/p0 = 0.543 bar' */
  boolean_T GetCrankAngleIC0_CSTATE;   /* '<S109>/Get Crank Angle IC 0' */
} XDis_engineclosed_T;

/* Zero-crossing (trigger) state */
typedef struct {
  ZCSigState Intake_Reset_ZCE;         /* '<S5>/Intake' */
  ZCSigState GetCrankAngleIC0_Reset_ZCE;/* '<S109>/Get Crank Angle IC 0' */
  ZCSigState positiveedgetodualedgeconversio;/* '<S7>/positive edge to dual edge conversion' */
  ZCSigState Controller_Trig_ZCE;      /* '<Root>/Controller' */
  ZCSigState Compression_Trig_ZCE;     /* '<Root>/Compression' */
} PrevZCX_engineclosed_T;

#ifndef ODE1_INTG
#define ODE1_INTG

/* ODE1 Integration Data */
typedef struct {
  real_T *f[1];                        /* derivatives */
} ODE1_IntgData;

#endif

/* External outputs (root outports fed by signals with default storage) */
typedef struct {
  real_T crankspeedradsec;             /* '<Root>/crank speed (rad//sec)' */
} ExtY_engineclosed_T;

/* Backward compatible GRT Identifiers */
#define rtB                            engineclosed_B
#define BlockIO                        B_engineclosed_T
#define rtX                            engineclosed_X
#define ContinuousStates               X_engineclosed_T
#define rtXdot                         engineclosed_XDot
#define StateDerivatives               XDot_engineclosed_T
#define tXdis                          engineclosed_XDis
#define StateDisabled                  XDis_engineclosed_T
#define rtY                            engineclosed_Y
#define ExternalOutputs                ExtY_engineclosed_T
#define rtP                            engineclosed_P
#define Parameters                     P_engineclosed_T
#define rtDWork                        engineclosed_DW
#define D_Work                         DW_engineclosed_T
#define rtPrevZCSigState               engineclosed_PrevZCX
#define PrevZCSigStates                PrevZCX_engineclosed_T

/* Parameters (default storage) */
struct P_engineclosed_T_ {
  real_T PIDController_InitialConditionF;/* Mask Parameter: PIDController_InitialConditionF
                                          * Referenced by: '<S64>/Integrator'
                                          */
  real_T PIDController_LowerSaturationLi;/* Mask Parameter: PIDController_LowerSaturationLi
                                          * Referenced by:
                                          *   '<S37>/DeadZone'
                                          *   '<S85>/Saturation'
                                          */
  real_T PIDController_UpperSaturationLi;/* Mask Parameter: PIDController_UpperSaturationLi
                                          * Referenced by:
                                          *   '<S37>/DeadZone'
                                          *   '<S85>/Saturation'
                                          */
  real_T massk_Y0;                     /* Expression: 0.152
                                        * Referenced by: '<S2>/mass(k)'
                                        */
  real_T trigger_Y0;                   /* Expression: -1
                                        * Referenced by: '<S2>/trigger'
                                        */
  real_T Init_Value;                   /* Expression: 0.152
                                        * Referenced by: '<S2>/Init'
                                        */
  real_T UnitDelay_InitialCondition;   /* Expression: 0.152
                                        * Referenced by: '<S2>/Unit Delay'
                                        */
  real_T ThrottleAng_Y0;               /* Expression: 8.973
                                        * Referenced by: '<S3>/Throttle Ang.'
                                        */
  real_T Constant_Value;               /* Expression: 0
                                        * Referenced by: '<S3>/Constant'
                                        */
  real_T rpmtorads_Gain;               /* Expression: pi/30
                                        * Referenced by: '<S3>/rpm to rad//s'
                                        */
  real_T Integrator_gainval;           /* Computed Parameter: Integrator_gainval
                                        * Referenced by: '<S64>/Integrator'
                                        */
  real_T ZeroGain_Gain;                /* Expression: 0
                                        * Referenced by: '<S37>/ZeroGain'
                                        */
  real_T Constant1_Value;              /* Expression: 0
                                        * Referenced by: '<S37>/Constant1'
                                        */
  real_T trigger_Y0_k;                 /* Expression: -1
                                        * Referenced by: '<S110>/trigger'
                                        */
  real_T UnitDelay_InitialCondition_n; /* Expression: 1
                                        * Referenced by: '<S110>/Unit Delay'
                                        */
  real_T Gain_Gain;                    /* Expression: -1
                                        * Referenced by: '<S110>/Gain'
                                        */
  real_T wTJw0209rads_IC;              /* Expression: 209.48
                                        * Referenced by: '<S4>/w = T//J w0 = 209 rad//s'
                                        */
  real_T radstorpm_Gain;               /* Expression: 30/pi
                                        * Referenced by: '<Root>/rad//s to rpm'
                                        */
  real_T Step_Time;                    /* Expression: 2
                                        * Referenced by: '<S6>/Step'
                                        */
  real_T Step_Y0;                      /* Expression: 25
                                        * Referenced by: '<S6>/Step'
                                        */
  real_T Step_YFinal;                  /* Expression: 20
                                        * Referenced by: '<S6>/Step'
                                        */
  real_T Step1_Time;                   /* Expression: 8
                                        * Referenced by: '<S6>/Step1'
                                        */
  real_T Step1_Y0;                     /* Expression: 0
                                        * Referenced by: '<S6>/Step1'
                                        */
  real_T Step1_YFinal;                 /* Expression: 5
                                        * Referenced by: '<S6>/Step1'
                                        */
  real_T SpeedSetpoint_Time;           /* Expression: 5
                                        * Referenced by: '<Root>/Speed Setpoint'
                                        */
  real_T SpeedSetpoint_Y0;             /* Expression: 2000
                                        * Referenced by: '<Root>/Speed Setpoint'
                                        */
  real_T SpeedSetpoint_YFinal;         /* Expression: 3000
                                        * Referenced by: '<Root>/Speed Setpoint'
                                        */
  real_T Constant_Value_g;             /* Expression: pi
                                        * Referenced by: '<S109>/Constant'
                                        */
  real_T SparkAdvancedegreesBTDC_Value;/* Expression: 15.0
                                        * Referenced by: '<S1>/Spark Advance (degrees BTDC)'
                                        */
  real_T StoichiometricFuel_Gain;      /* Expression: 1/14.6
                                        * Referenced by: '<S1>/Stoichiometric Fuel'
                                        */
  real_T Constant_Value_m;             /* Expression: 1
                                        * Referenced by: '<S4>/Constant'
                                        */
  real_T InverseInertia1J_Gain;        /* Expression: 1/0.14
                                        * Referenced by: '<S4>/Inverse Inertia, 1//J'
                                        */
  real_T utheta90_UpperSat;            /* Expression: 90
                                        * Referenced by: '<S5>/0 <= theta <= 90'
                                        */
  real_T utheta90_LowerSat;            /* Expression: 0
                                        * Referenced by: '<S5>/0 <= theta <= 90'
                                        */
  real_T AtmosphericPressurePabar_Value;/* Expression: 1.0
                                         * Referenced by: '<S5>/Atmospheric Pressure, Pa (bar)'
                                         */
  real_T Intake_IC;                    /* Expression: 0
                                        * Referenced by: '<S5>/Intake'
                                        */
  real_T p00543bar_IC;                 /* Expression: .543
                                        * Referenced by: '<S107>/p0 = 0.543 bar'
                                        */
  real_T SonicFlow_Value;              /* Expression: 1.0
                                        * Referenced by: '<S108>/Sonic Flow '
                                        */
  real_T Switch_Threshold;             /* Expression: 0.5
                                        * Referenced by: '<S108>/Switch'
                                        */
  real_T RTVm_Gain;                    /* Expression: 0.41328
                                        * Referenced by: '<S107>/RT//Vm'
                                        */
  real_T GetCrankAngleIC0_IC;          /* Expression: 0
                                        * Referenced by: '<S109>/Get Crank Angle IC 0'
                                        */
};

/* Real-time Model Data Structure */
struct tag_RTM_engineclosed_T {
  const char_T *path;
  const char_T *modelName;
  struct SimStruct_tag * *childSfunctions;
  const char_T *errorStatus;
  SS_SimMode simMode;
  RTWLogInfo *rtwLogInfo;
  RTWExtModeInfo *extModeInfo;
  RTWSolverInfo solverInfo;
  RTWSolverInfo *solverInfoPtr;
  void *sfcnInfo;
  void *blockIO;
  const void *constBlockIO;
  void *defaultParam;
  ZCSigState *prevZCSigState;
  real_T *contStates;
  int_T *periodicContStateIndices;
  real_T *periodicContStateRanges;
  real_T *derivs;
  void *zcSignalValues;
  void *inputs;
  void *outputs;
  boolean_T *contStateDisabled;
  boolean_T zCCacheNeedsReset;
  boolean_T derivCacheNeedsReset;
  boolean_T CTOutputIncnstWithState;
  real_T odeF[1][4];
  ODE1_IntgData intgData;
  void *dwork;

  /*
   * Sizes:
   * The following substructure contains sizes information
   * for many of the model attributes such as inputs, outputs,
   * dwork, sample times, etc.
   */
  struct {
    uint32_T checksums[4];
    uint32_T options;
    int_T numContStates;
    int_T numPeriodicContStates;
    int_T numU;
    int_T numY;
    int_T numSampTimes;
    int_T numBlocks;
    int_T numBlockIO;
    int_T numBlockPrms;
    int_T numDwork;
    int_T numSFcnPrms;
    int_T numSFcns;
    int_T numIports;
    int_T numOports;
    int_T numNonSampZCs;
    int_T sysDirFeedThru;
    int_T rtwGenSfcn;
  } Sizes;

  /*
   * SpecialInfo:
   * The following substructure contains special information
   * related to other components that are dependent on RTW.
   */
  struct {
    const void *mappingInfo;
    void *xpcData;
  } SpecialInfo;

  /*
   * Timing:
   * The following substructure contains information regarding
   * the timing information for the model.
   */
  struct {
    time_T stepSize;
    uint32_T clockTick0;
    uint32_T clockTickH0;
    time_T stepSize0;
    uint32_T clockTick1;
    uint32_T clockTickH1;
    time_T stepSize1;
    boolean_T firstInitCondFlag;
    time_T tStart;
    time_T tFinal;
    time_T timeOfLastOutput;
    void *timingData;
    real_T *varNextHitTimesList;
    SimTimeStep simTimeStep;
    boolean_T stopRequestedFlag;
    time_T *sampleTimes;
    time_T *offsetTimes;
    int_T *sampleTimeTaskIDPtr;
    int_T *sampleHits;
    int_T *perTaskSampleHits;
    time_T *t;
    time_T sampleTimesArray[2];
    time_T offsetTimesArray[2];
    int_T sampleTimeTaskIDArray[2];
    int_T sampleHitArray[2];
    int_T perTaskSampleHitsArray[4];
    time_T tArray[2];
  } Timing;
};

/* Block parameters (default storage) */
extern P_engineclosed_T engineclosed_P;

/* Block signals (default storage) */
extern B_engineclosed_T engineclosed_B;

/* Continuous states (default storage) */
extern X_engineclosed_T engineclosed_X;

/* Block states (default storage) */
extern DW_engineclosed_T engineclosed_DW;

/* External outputs (root outports fed by signals with default storage) */
extern ExtY_engineclosed_T engineclosed_Y;

/* Model entry point functions */
extern void engineclosed_initialize(void);
extern void engineclosed_output(void);
extern void engineclosed_update(void);
extern void engineclosed_terminate(void);

/*====================*
 * External functions *
 *====================*/
extern engineclosed_rtModel *engineclosed(void);
extern void MdlInitializeSizes(void);
extern void MdlInitializeSampleTimes(void);
extern void MdlInitialize(void);
extern void MdlStart(void);
extern void MdlOutputs(int_T tid);
extern void MdlUpdate(int_T tid);
extern void MdlTerminate(void);

/* Real-time Model object */
extern RT_MODEL_engineclosed_T *const engineclosed_M;

/*-
 * The generated code includes comments that allow you to trace directly
 * back to the appropriate location in the model.  The basic format
 * is <system>/block_name, where system is the system number (uniquely
 * assigned by Simulink) and block_name is the name of the block.
 *
 * Use the MATLAB hilite_system command to trace the generated code back
 * to the model.  For example,
 *
 * hilite_system('<S3>')    - opens system 3
 * hilite_system('<S3>/Kp') - opens and selects block Kp which resides in S3
 *
 * Here is the system hierarchy for this model
 *
 * '<Root>' : 'engineclosed'
 * '<S1>'   : 'engineclosed/Combustion'
 * '<S2>'   : 'engineclosed/Compression'
 * '<S3>'   : 'engineclosed/Controller'
 * '<S4>'   : 'engineclosed/Engine Dynamics'
 * '<S5>'   : 'engineclosed/Throttle & Manifold'
 * '<S6>'   : 'engineclosed/drag torque'
 * '<S7>'   : 'engineclosed/valve timing'
 * '<S8>'   : 'engineclosed/Controller/MATLAB Function'
 * '<S9>'   : 'engineclosed/Controller/PID Controller'
 * '<S10>'  : 'engineclosed/Controller/PID Controller/Anti-windup'
 * '<S11>'  : 'engineclosed/Controller/PID Controller/D Gain'
 * '<S12>'  : 'engineclosed/Controller/PID Controller/Filter'
 * '<S13>'  : 'engineclosed/Controller/PID Controller/Filter ICs'
 * '<S14>'  : 'engineclosed/Controller/PID Controller/I Gain'
 * '<S15>'  : 'engineclosed/Controller/PID Controller/Ideal P Gain'
 * '<S16>'  : 'engineclosed/Controller/PID Controller/Ideal P Gain Fdbk'
 * '<S17>'  : 'engineclosed/Controller/PID Controller/Integrator'
 * '<S18>'  : 'engineclosed/Controller/PID Controller/Integrator ICs'
 * '<S19>'  : 'engineclosed/Controller/PID Controller/N Copy'
 * '<S20>'  : 'engineclosed/Controller/PID Controller/N Gain'
 * '<S21>'  : 'engineclosed/Controller/PID Controller/P Copy'
 * '<S22>'  : 'engineclosed/Controller/PID Controller/Parallel P Gain'
 * '<S23>'  : 'engineclosed/Controller/PID Controller/Reset Signal'
 * '<S24>'  : 'engineclosed/Controller/PID Controller/Saturation'
 * '<S25>'  : 'engineclosed/Controller/PID Controller/Saturation Fdbk'
 * '<S26>'  : 'engineclosed/Controller/PID Controller/Sum'
 * '<S27>'  : 'engineclosed/Controller/PID Controller/Sum Fdbk'
 * '<S28>'  : 'engineclosed/Controller/PID Controller/Tracking Mode'
 * '<S29>'  : 'engineclosed/Controller/PID Controller/Tracking Mode Sum'
 * '<S30>'  : 'engineclosed/Controller/PID Controller/postSat Signal'
 * '<S31>'  : 'engineclosed/Controller/PID Controller/preSat Signal'
 * '<S32>'  : 'engineclosed/Controller/PID Controller/Anti-windup/Back Calculation'
 * '<S33>'  : 'engineclosed/Controller/PID Controller/Anti-windup/Cont. Clamping Ideal'
 * '<S34>'  : 'engineclosed/Controller/PID Controller/Anti-windup/Cont. Clamping Parallel'
 * '<S35>'  : 'engineclosed/Controller/PID Controller/Anti-windup/Disabled'
 * '<S36>'  : 'engineclosed/Controller/PID Controller/Anti-windup/Disc. Clamping Ideal'
 * '<S37>'  : 'engineclosed/Controller/PID Controller/Anti-windup/Disc. Clamping Parallel'
 * '<S38>'  : 'engineclosed/Controller/PID Controller/Anti-windup/Passthrough'
 * '<S39>'  : 'engineclosed/Controller/PID Controller/D Gain/Disabled'
 * '<S40>'  : 'engineclosed/Controller/PID Controller/D Gain/External Parameters'
 * '<S41>'  : 'engineclosed/Controller/PID Controller/D Gain/Internal Parameters'
 * '<S42>'  : 'engineclosed/Controller/PID Controller/Filter/Cont. Filter'
 * '<S43>'  : 'engineclosed/Controller/PID Controller/Filter/Differentiator'
 * '<S44>'  : 'engineclosed/Controller/PID Controller/Filter/Disabled'
 * '<S45>'  : 'engineclosed/Controller/PID Controller/Filter/Disc. Backward Euler Filter'
 * '<S46>'  : 'engineclosed/Controller/PID Controller/Filter/Disc. Forward Euler Filter'
 * '<S47>'  : 'engineclosed/Controller/PID Controller/Filter/Disc. Trapezoidal Filter'
 * '<S48>'  : 'engineclosed/Controller/PID Controller/Filter ICs/Disabled'
 * '<S49>'  : 'engineclosed/Controller/PID Controller/Filter ICs/External IC'
 * '<S50>'  : 'engineclosed/Controller/PID Controller/Filter ICs/Internal IC - Differentiator'
 * '<S51>'  : 'engineclosed/Controller/PID Controller/Filter ICs/Internal IC - Filter'
 * '<S52>'  : 'engineclosed/Controller/PID Controller/I Gain/Disabled'
 * '<S53>'  : 'engineclosed/Controller/PID Controller/I Gain/External Parameters'
 * '<S54>'  : 'engineclosed/Controller/PID Controller/I Gain/Internal Parameters'
 * '<S55>'  : 'engineclosed/Controller/PID Controller/Ideal P Gain/External Parameters'
 * '<S56>'  : 'engineclosed/Controller/PID Controller/Ideal P Gain/Internal Parameters'
 * '<S57>'  : 'engineclosed/Controller/PID Controller/Ideal P Gain/Passthrough'
 * '<S58>'  : 'engineclosed/Controller/PID Controller/Ideal P Gain Fdbk/Disabled'
 * '<S59>'  : 'engineclosed/Controller/PID Controller/Ideal P Gain Fdbk/External Parameters'
 * '<S60>'  : 'engineclosed/Controller/PID Controller/Ideal P Gain Fdbk/Internal Parameters'
 * '<S61>'  : 'engineclosed/Controller/PID Controller/Ideal P Gain Fdbk/Passthrough'
 * '<S62>'  : 'engineclosed/Controller/PID Controller/Integrator/Continuous'
 * '<S63>'  : 'engineclosed/Controller/PID Controller/Integrator/Disabled'
 * '<S64>'  : 'engineclosed/Controller/PID Controller/Integrator/Discrete'
 * '<S65>'  : 'engineclosed/Controller/PID Controller/Integrator ICs/Disabled'
 * '<S66>'  : 'engineclosed/Controller/PID Controller/Integrator ICs/External IC'
 * '<S67>'  : 'engineclosed/Controller/PID Controller/Integrator ICs/Internal IC'
 * '<S68>'  : 'engineclosed/Controller/PID Controller/N Copy/Disabled'
 * '<S69>'  : 'engineclosed/Controller/PID Controller/N Copy/Disabled wSignal Specification'
 * '<S70>'  : 'engineclosed/Controller/PID Controller/N Copy/External Parameters'
 * '<S71>'  : 'engineclosed/Controller/PID Controller/N Copy/Internal Parameters'
 * '<S72>'  : 'engineclosed/Controller/PID Controller/N Gain/Disabled'
 * '<S73>'  : 'engineclosed/Controller/PID Controller/N Gain/External Parameters'
 * '<S74>'  : 'engineclosed/Controller/PID Controller/N Gain/Internal Parameters'
 * '<S75>'  : 'engineclosed/Controller/PID Controller/N Gain/Passthrough'
 * '<S76>'  : 'engineclosed/Controller/PID Controller/P Copy/Disabled'
 * '<S77>'  : 'engineclosed/Controller/PID Controller/P Copy/External Parameters Ideal'
 * '<S78>'  : 'engineclosed/Controller/PID Controller/P Copy/Internal Parameters Ideal'
 * '<S79>'  : 'engineclosed/Controller/PID Controller/Parallel P Gain/Disabled'
 * '<S80>'  : 'engineclosed/Controller/PID Controller/Parallel P Gain/External Parameters'
 * '<S81>'  : 'engineclosed/Controller/PID Controller/Parallel P Gain/Internal Parameters'
 * '<S82>'  : 'engineclosed/Controller/PID Controller/Parallel P Gain/Passthrough'
 * '<S83>'  : 'engineclosed/Controller/PID Controller/Reset Signal/Disabled'
 * '<S84>'  : 'engineclosed/Controller/PID Controller/Reset Signal/External Reset'
 * '<S85>'  : 'engineclosed/Controller/PID Controller/Saturation/Enabled'
 * '<S86>'  : 'engineclosed/Controller/PID Controller/Saturation/Passthrough'
 * '<S87>'  : 'engineclosed/Controller/PID Controller/Saturation Fdbk/Disabled'
 * '<S88>'  : 'engineclosed/Controller/PID Controller/Saturation Fdbk/Enabled'
 * '<S89>'  : 'engineclosed/Controller/PID Controller/Saturation Fdbk/Passthrough'
 * '<S90>'  : 'engineclosed/Controller/PID Controller/Sum/Passthrough_I'
 * '<S91>'  : 'engineclosed/Controller/PID Controller/Sum/Passthrough_P'
 * '<S92>'  : 'engineclosed/Controller/PID Controller/Sum/Sum_PD'
 * '<S93>'  : 'engineclosed/Controller/PID Controller/Sum/Sum_PI'
 * '<S94>'  : 'engineclosed/Controller/PID Controller/Sum/Sum_PID'
 * '<S95>'  : 'engineclosed/Controller/PID Controller/Sum Fdbk/Disabled'
 * '<S96>'  : 'engineclosed/Controller/PID Controller/Sum Fdbk/Enabled'
 * '<S97>'  : 'engineclosed/Controller/PID Controller/Sum Fdbk/Passthrough'
 * '<S98>'  : 'engineclosed/Controller/PID Controller/Tracking Mode/Disabled'
 * '<S99>'  : 'engineclosed/Controller/PID Controller/Tracking Mode/Enabled'
 * '<S100>' : 'engineclosed/Controller/PID Controller/Tracking Mode Sum/Passthrough'
 * '<S101>' : 'engineclosed/Controller/PID Controller/Tracking Mode Sum/Tracking Mode'
 * '<S102>' : 'engineclosed/Controller/PID Controller/postSat Signal/Feedback_Path'
 * '<S103>' : 'engineclosed/Controller/PID Controller/postSat Signal/Forward_Path'
 * '<S104>' : 'engineclosed/Controller/PID Controller/preSat Signal/Feedback_Path'
 * '<S105>' : 'engineclosed/Controller/PID Controller/preSat Signal/Forward_Path'
 * '<S106>' : 'engineclosed/Engine Dynamics/MATLAB Function'
 * '<S107>' : 'engineclosed/Throttle & Manifold/Intake Manifold'
 * '<S108>' : 'engineclosed/Throttle & Manifold/Throttle'
 * '<S109>' : 'engineclosed/valve timing/TDC and BDC detection'
 * '<S110>' : 'engineclosed/valve timing/positive edge to dual edge conversion'
 */
#endif                                 /* RTW_HEADER_engineclosed_h_ */
